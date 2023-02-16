#include <Arduino.h>
#include <Wire.h>
#include <HTTPClient.h>

#include <SPI.h>
#include <TFT_eSPI.h>
#include "FT62XXTouchScreen.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "Adafruit_SHTC3.h"
#include <WiFi.h>
#include <EEPROM.h>
#include <MQTT.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

TFT_eSPI tft = TFT_eSPI();
FT62XXTouchScreen touchScreen = FT62XXTouchScreen(TFT_WIDTH, PIN_SDA, PIN_SCL);

#include "common.h"
#include "mockup.h"
#include "esp_freertos_hooks.h"
#include "ui/ui.h"

static const uint16_t screenWidth = 480;
static const uint16_t screenHeight = 320;

static lv_disp_draw_buf_t disp_buf;
static lv_color_t buf[screenWidth * 10];

static void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
static void touchpad_read(lv_indev_drv_t *drv, lv_indev_data_t *data);

static void lv_tick_task(void *arg);
static void lv_handler_task(void *arg);
static void ui_update_task(void *arg);

esp_timer_handle_t ticker_timer;
esp_timer_handle_t handler_timer;
esp_timer_handle_t ui_update_timer;
const esp_timer_create_args_t ticker_timer_args = {
    .callback = &lv_tick_task,
    .name = "lv_tick_task"};
const esp_timer_create_args_t ticker_handler_args = {
    .callback = &lv_handler_task,
    .name = "lv_handler_task"};
const esp_timer_create_args_t ui_update_args = {
    .callback = &ui_update_task,
    .name = "ui_update_task"};

#define SSID_MAXLENGTH (64)
#define WIFIPW_MAXLENGTH (32)

#define EEPROM_WRITE
#define EEPROM_HEADER_KEY (0b1011110010100000010001001110010000111101010001111001100011110011L)
#define EEPROM_HEADER_ADDR (0)
#define EEPROM_SSID_ADDR (EEPROM_HEADER_ADDR + sizeof(uint64_t))
#define EEPROM_WIFIPW_ADDR (EEPROM_SSID_ADDR + SSID_MAXLENGTH)
#define EEPROM_GPSLAT_ADDR (EEPROM_WIFIPW_ADDR + WIFIPW_MAXLENGTH)
#define EEPROM_GPSLONG_ADDR (EEPROM_GPSLAT_ADDR + sizeof(double))
#define EEPROM_TOTAL_BYTES (EEPROM_GPSLONG_ADDR + sizeof(double))

#define ONE_WIRE_BUS (32)
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature ds18b20(&oneWire);
Adafruit_SHTC3 shtc3 = Adafruit_SHTC3();

unsigned long dataReadTs;
wl_status_t currentWifiStatus;
#define DATA_READ_DELAY (1000)

#define DATASET_LENGTH (25)
chart_type currentSelectDataChart = TEMP_CHART;
double tempDataSeries[DATASET_LENGTH];
double humidDataSeries[DATASET_LENGTH];

lv_chart_series_t *seriesTemp;
lv_chart_series_t *seriesHumid;

String ssid;
String wifiPw;
String macAddress;
double gpsLatitude;
double gpsLongtitude;

lv_obj_t *textareaRef;
bool mqttSentSuccess = true;

MQTTClient mqttClient;
WiFiClient wifiClient;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);
String mqttClientName;

static void initEEPROM();
static void initUI2();
static void beginWifi();
static void connectMqtt();
static void emitMqtt(double temp, double humid);
void switchVisibleChartTo(chart_type type);
static void partialUpdateChartData(chart_type type);
static void updateDataStatus();
void updateSettingPage();
void boundEditText(lv_obj_t *target, lv_keyboard_mode_t mode, bool isPassword);
void validateEditText();
void confirmEditSetting();
static void updateEEPROM();

static double getTemp();
static double getHumidity();

void setup()
{
  Serial.begin(115200);
  Wire.setPins(PIN_SDA, PIN_SCL);

  ds18b20.begin();
  shtc3.begin();

  macAddress = WiFi.macAddress();
  macAddress.replace(":", "");
  macAddress.toUpperCase();

  mqttClientName = String("w32_s01-hotel-");
  mqttClientName.concat(macAddress);

  initEEPROM();

  mqttClient.begin("coldsenses.com", 9100, wifiClient);

  beginWifi();

  lv_init();
  ESP_ERROR_CHECK(esp_timer_create(&ticker_timer_args, &ticker_timer));
  ESP_ERROR_CHECK(esp_timer_start_periodic(ticker_timer, portTICK_RATE_MS * 1000));

  // Enable TFT
  tft.begin();
  tft.setRotation(1);

  // Enable Backlight
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, 1);

  // Start TouchScreen
  touchScreen.begin();

  // Display Buffer
  lv_disp_draw_buf_init(&disp_buf, buf, NULL, screenWidth * 10);

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &disp_buf;
  lv_disp_drv_register(&disp_drv);

  // Init Touchscreen
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = touchpad_read;
  lv_indev_drv_register(&indev_drv);

  ui_init();
  initUI2();
  lv_disp_load_scr(ui_DataScreen);

  ESP_ERROR_CHECK(esp_timer_create(&ticker_handler_args, &handler_timer));
  ESP_ERROR_CHECK(esp_timer_start_periodic(handler_timer, 10 * portTICK_RATE_MS * 1000));

  ESP_ERROR_CHECK(esp_timer_create(&ui_update_args, &ui_update_timer));
  ESP_ERROR_CHECK(esp_timer_start_periodic(ui_update_timer, 1000 * portTICK_RATE_MS * 1000));
}

void loop()
{
  timeClient.update();
  mqttClient.loop();

  wl_status_t wifiStatus = WiFi.status();
  if (currentWifiStatus != wifiStatus)
  {
    currentWifiStatus = wifiStatus;
    updateDataStatus();
  }

  if (wifiStatus == WL_CONNECTED)
  {
    connectMqtt();
    timeClient.begin();
  }

  if (millis() - dataReadTs >= DATA_READ_DELAY)
  {
    dataReadTs = millis();

    double temp = getTemp();
    double humid = getHumidity();

    for (int i = 1; i < DATASET_LENGTH; i++)
    {
      tempDataSeries[i - 1] = tempDataSeries[i];
      humidDataSeries[i - 1] = humidDataSeries[i];
    }
    tempDataSeries[DATASET_LENGTH - 1] = temp;
    humidDataSeries[DATASET_LENGTH - 1] = humid;

    if (mqttClient.connected())
    {
      emitMqtt(temp, humid);
    }
  }

  delay(5);
}

static void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.pushColors(&color_p->full, w * h, true);
  tft.endWrite();

  lv_disp_flush_ready(disp);
}

static void touchpad_read(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
  TouchPoint touchPos = touchScreen.read();
  if (touchPos.touched)
  {
    data->state = LV_INDEV_STATE_PR;
    data->point.x = touchPos.xPos;
    data->point.y = touchPos.yPos;
  }
  else
  {
    data->state = LV_INDEV_STATE_REL;
  }
}

static void lv_tick_task(void *arg)
{
  lv_tick_inc(portTICK_RATE_MS);
}

static void lv_handler_task(void *arg)
{
  lv_task_handler();
}

static void ui_update_task(void *arg)
{
  if (lv_scr_act() == ui_DataScreen)
  {
    double temp = tempDataSeries[DATASET_LENGTH - 1];
    double humid = humidDataSeries[DATASET_LENGTH - 1];

    partialUpdateChartData(currentSelectDataChart);

    lv_label_set_text(ui_DataScreenTempValueLabel, isnan(temp) ? "-" : String(temp, 1).c_str());
    lv_label_set_text(ui_DataScreenHumidValueLabel, isnan(humid) ? "-" : String(humid, 1).c_str());
  }
}

static void initEEPROM()
{
  if (!EEPROM.begin(EEPROM_TOTAL_BYTES))
  {
    Serial.println("EEPROM init error");
    return;
  }

  uint64_t header = EEPROM.readULong64(EEPROM_HEADER_ADDR);

  if (header != EEPROM_HEADER_KEY)
  {
#ifdef EEPROM_WRITE
    EEPROM.writeULong64(EEPROM_HEADER_ADDR, EEPROM_HEADER_KEY);
#endif

    EEPROM.writeString(EEPROM_SSID_ADDR, "wifissid");
    EEPROM.writeString(EEPROM_WIFIPW_ADDR, "wifipw");
    EEPROM.writeDouble(EEPROM_GPSLAT_ADDR, 15.8700);
    EEPROM.writeDouble(EEPROM_GPSLONG_ADDR, 100.9925);
    EEPROM.commit();
  }

  // Read values
  ssid = EEPROM.readString(EEPROM_SSID_ADDR);
  wifiPw = EEPROM.readString(EEPROM_WIFIPW_ADDR);
  gpsLatitude = EEPROM.readDouble(EEPROM_GPSLAT_ADDR);
  gpsLongtitude = EEPROM.readDouble(EEPROM_GPSLONG_ADDR);
}

static void initUI2()
{
  lv_label_set_text(ui_DataScreenConnectLabel, "Connecting...");

  lv_chart_set_range(ui_DatsScreenChart, LV_CHART_AXIS_PRIMARY_Y, -10, 40);
  lv_chart_set_range(ui_DatsScreenChart, LV_CHART_AXIS_SECONDARY_Y, 0, 100);

  seriesHumid = lv_chart_get_series_next(ui_DatsScreenChart, NULL);
  seriesTemp = lv_chart_get_series_next(ui_DatsScreenChart, seriesHumid);

  lv_chart_set_all_value(ui_DatsScreenChart, seriesTemp, LV_CHART_POINT_NONE);
  lv_chart_set_all_value(ui_DatsScreenChart, seriesHumid, LV_CHART_POINT_NONE);

  for (int i = 0; i < DATASET_LENGTH; i++)
  {
    tempDataSeries[i] = NAN;
    humidDataSeries[i] = NAN;
  }

  switchVisibleChartTo(TEMP_CHART);
  updateDataStatus();
}

static void beginWifi()
{
  WiFi.begin(ssid.c_str(), wifiPw.length() > 0 ? wifiPw.c_str() : NULL);
}

static void connectMqtt()
{
  mqttClient.connect(mqttClientName.c_str());
}

static void emitMqtt(double temp, double humid)
{
  String topic = "push_";
  topic.concat(macAddress);

  String sharedPayload = String();
  sharedPayload.concat(macAddress);
  sharedPayload.concat(":");
  sharedPayload.concat(mqttClientName);
  sharedPayload.concat(":");
  sharedPayload.concat(timeClient.getEpochTime());

  // HB:macAddress:gateway:gatewayTs:battLv:chargeState:connectivity
  String hbPayload = "HB:";
  hbPayload.concat(sharedPayload);
  hbPayload.concat(":100:-:-");

  // W:macAddress:gateway:gatewayTs:temp:humid:batt:rssi
  String wPayload = "W:";
  wPayload.concat(sharedPayload);
  wPayload.concat(":");
  if (isnan(temp))
  {
    wPayload.concat("-");
  }
  else
  {
    wPayload.concat(temp);
  }
  wPayload.concat(":");
  if (isnan(humid))
  {
    wPayload.concat("-");
  }
  else
  {
    wPayload.concat(humid);
  }
  wPayload.concat(":100:");
  wPayload.concat(WiFi.RSSI());

  // GEO:macAddress:gateway:gatewayTs:lat:lng
  String geoPayload = "GEO:";
  geoPayload.concat(sharedPayload);
  geoPayload.concat(":");
  geoPayload.concat(gpsLatitude);
  geoPayload.concat(":");
  geoPayload.concat(gpsLongtitude);

  bool hbSentSuccess = mqttClient.publish(topic.c_str(), hbPayload.c_str());
  bool wSentSuccess = mqttClient.publish(topic.c_str(), wPayload.c_str());
  bool geoSentSuccess = mqttClient.publish(topic.c_str(), geoPayload.c_str());

  mqttSentSuccess = hbSentSuccess && wSentSuccess && geoSentSuccess;
  Serial.print("HB:");
  Serial.print(hbSentSuccess ? "T" : "F");
  Serial.print(", W:");
  Serial.print(wSentSuccess ? "T" : "F");
  Serial.print(", GEO:");
  Serial.print(geoSentSuccess ? "T" : "F");
  Serial.println();
}

void switchVisibleChartTo(chart_type type)
{
  currentSelectDataChart = type;

  if (type == TEMP_CHART)
  {
    lv_chart_set_axis_tick(ui_DatsScreenChart, LV_CHART_AXIS_PRIMARY_Y, 10, 5, 6, 5, true, 50);
    lv_label_set_text(ui_DataScreenChartTitle, "Temp");
  }
  else
  {
    lv_chart_set_all_value(ui_DatsScreenChart, seriesTemp, LV_CHART_POINT_NONE);
    lv_chart_set_axis_tick(ui_DatsScreenChart, LV_CHART_AXIS_PRIMARY_Y, 10, 5, 6, 5, false, 50);
  }

  if (type == HUMID_CHART)
  {
    lv_chart_set_axis_tick(ui_DatsScreenChart, LV_CHART_AXIS_SECONDARY_Y, 10, 5, 6, 5, true, 50);
    lv_label_set_text(ui_DataScreenChartTitle, "Humidity");
  }
  else
  {
    lv_chart_set_all_value(ui_DatsScreenChart, seriesHumid, LV_CHART_POINT_NONE);
    lv_chart_set_axis_tick(ui_DatsScreenChart, LV_CHART_AXIS_SECONDARY_Y, 10, 5, 6, 5, false, 50);
  }

  partialUpdateChartData(type);
}

static void partialUpdateChartData(chart_type type)
{
  if (type == TEMP_CHART)
  {
    for (int i = 0; i < DATASET_LENGTH; i++)
    {
      lv_coord_t data = isnan(tempDataSeries[i]) ? LV_CHART_POINT_NONE : (lv_coord_t)tempDataSeries[i];
      lv_chart_set_value_by_id(ui_DatsScreenChart, seriesTemp, i, data);
    }
  }
  else if (type == HUMID_CHART)
  {
    for (int i = 0; i < DATASET_LENGTH; i++)
    {
      lv_coord_t data = isnan(humidDataSeries[i]) ? LV_CHART_POINT_NONE : (lv_coord_t)humidDataSeries[i];
      lv_chart_set_value_by_id(ui_DatsScreenChart, seriesHumid, i, data);
    }
  }
}

static void updateDataStatus()
{
  String status;
  switch (currentWifiStatus)
  {
  case WL_IDLE_STATUS:
    status = String("WiFi Connecting...");
    break;
  case WL_CONNECTED:
    status = String("WiFi Connected");
    break;
  case WL_DISCONNECTED:
    status = String("WiFi Disconnected");
    break;
  case WL_NO_SSID_AVAIL:
  case WL_CONNECT_FAILED:
    status = String("WiFi Connect Failed");
    break;
  default:
    status = String("WiFi Error");
    break;
  }

  lv_label_set_text(ui_DataScreenConnectLabel, status.c_str());
}

void updateSettingPage()
{
  lv_textarea_set_text(ui_SettingScreenSsidTextArea, ssid.c_str());
  lv_textarea_set_text(ui_SettingScreenWifiPwTextArea, wifiPw.c_str());
  lv_textarea_set_text(ui_SettingScreenMacTextArea, macAddress.c_str());
  lv_textarea_set_text(ui_SettingScreenLatTextArea, String(gpsLatitude, 8).c_str());
  lv_textarea_set_text(ui_SettingScreenLongTextArea, String(gpsLongtitude, 8).c_str());
}

void boundEditText(lv_obj_t *target, lv_keyboard_mode_t mode, bool isPassword)
{
  textareaRef = target;
  lv_keyboard_set_textarea(ui_EditTextScreenKeyboard, ui_EditTextScreenTextArea);
  lv_textarea_set_text(ui_EditTextScreenTextArea, isPassword ? "" : lv_textarea_get_text(target));
  lv_keyboard_set_mode(ui_EditTextScreenKeyboard, mode);
}

void validateEditText()
{
  if (textareaRef)
  {
    bool valid = false;

    double actualValue;
    String data = String(lv_textarea_get_text(ui_EditTextScreenTextArea));
    if (textareaRef == ui_SettingScreenSsidTextArea)
    {
      valid = data.length() > 0;
      data = data.substring(0, SSID_MAXLENGTH);
    }
    else if (textareaRef == ui_SettingScreenWifiPwTextArea)
    {
      valid = true;
      data = data.substring(0, WIFIPW_MAXLENGTH);
    }
    else if (textareaRef == ui_SettingScreenLatTextArea)
    {
      actualValue = data.toDouble();
      valid = data.length() > 0 && actualValue >= -90 && actualValue <= 90;
      data = String(actualValue, 8);
    }
    else if (textareaRef == ui_SettingScreenLongTextArea)
    {
      actualValue = data.toDouble();
      valid = data.length() > 0 && actualValue >= -180 && actualValue <= 180;
      data = String(actualValue, 8);
    }

    if (valid)
    {
      lv_textarea_set_text(textareaRef, data.c_str());
    }

    textareaRef = NULL;
  }
}

void confirmEditSetting()
{
  ssid = String(lv_textarea_get_text(ui_SettingScreenSsidTextArea));
  wifiPw = String(lv_textarea_get_text(ui_SettingScreenWifiPwTextArea));
  gpsLatitude = String(lv_textarea_get_text(ui_SettingScreenLatTextArea)).toDouble();
  gpsLongtitude = String(lv_textarea_get_text(ui_SettingScreenLongTextArea)).toDouble();

  updateEEPROM();

  mqttClient.disconnect();
  timeClient.end();
  WiFi.disconnect();
  mqttSentSuccess = true;

  beginWifi();
}

static void updateEEPROM()
{
  // Init data
#ifdef EEPROM_WRITE
  EEPROM.writeULong64(EEPROM_HEADER_ADDR, EEPROM_HEADER_KEY);
#endif

  EEPROM.writeString(EEPROM_SSID_ADDR, ssid);
  EEPROM.writeString(EEPROM_WIFIPW_ADDR, wifiPw);
  EEPROM.writeDouble(EEPROM_GPSLAT_ADDR, gpsLatitude);
  EEPROM.writeDouble(EEPROM_GPSLONG_ADDR, gpsLongtitude);
  EEPROM.commit();
}

#if SENSOR_MOCKUP_DEMO
static double getTemp()
{
  double t1 = millis() * 0.001;
  double temp = 20 + (10 * __dRandomT(t1));
  return temp;
}
static double getHumidity()
{
  double t1 = millis() * 0.001 + 50000;
  double humid = 50 + (50 * __dRandomT(t1));
  return humid;
}
#else
static double getTemp()
{
  ds18b20.requestTemperatures();
  double temp = ds18b20.getTempCByIndex(0);
  return (temp == DEVICE_DISCONNECTED_C) ? NAN : temp;
}
static double getHumidity()
{
  static sensors_event_t humidity, temp;
  if (shtc3.getEvent(&humidity, &temp))
  {
    return humidity.relative_humidity;
  }
  else
  {
    return NAN;
  }
}
#endif