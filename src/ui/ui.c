// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
// LVGL VERSION: 8.2.0
// PROJECT: Coldchain_Hotel

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_DataScreen;
void ui_event_DataScreenTempPanel(lv_event_t *e);
lv_obj_t *ui_DataScreenTempPanel;
lv_obj_t *ui_DataScreenTempLabel;
lv_obj_t *ui_DataScreenTempValueLabel;
lv_obj_t *ui_DataScreenTempUnitLabel;
void ui_event_DataScreenHumidPanel(lv_event_t *e);
lv_obj_t *ui_DataScreenHumidPanel;
lv_obj_t *ui_DataScreenHumidLabel;
lv_obj_t *ui_DataScreenHumidValueLabel;
lv_obj_t *ui_DataScreenHumidUnitLabel;
lv_obj_t *ui_DatsScreenChart;
lv_obj_t *ui_DataScreenChartTitle;
lv_obj_t *ui_DataScreenConnectLabel;
void ui_event_DataScreenSettingBtn(lv_event_t *e);
lv_obj_t *ui_DataScreenSettingBtn;
lv_obj_t *ui_DatsScreenSettingLabel;
lv_obj_t *ui_SettingScreen;
lv_obj_t *ui_SettingScreenLabel;
lv_obj_t *ui_SeetingScreenPanel;
lv_obj_t *ui_SettingScreenSsidLabel;
lv_obj_t *ui_SettingScreenSsidTextArea;
void ui_event_SettingScreenSsidEditBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreenSsidEditBtn;
lv_obj_t *ui_SettingScreenSsidEditImg;
lv_obj_t *ui_SettingScreenWifiPwLabel;
lv_obj_t *ui_SettingScreenWifiPwTextArea;
void ui_event_SettingScreenWifiPwEditBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreenWifiPwEditBtn;
lv_obj_t *ui_SettingScreenWifiPwImg;
lv_obj_t *ui_SettingScreenMacLabel;
lv_obj_t *ui_SettingScreenMacTextArea;
lv_obj_t *ui_SettingScreenLatLabel;
lv_obj_t *ui_SettingScreenLatTextArea;
void ui_event_SettingScreenLatEditBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreenLatEditBtn;
lv_obj_t *ui_SettingScreenLatEditImg;
lv_obj_t *ui_SettingScreenLongTextArea;
void ui_event_SettingScreenLongEditBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreenLongEditBtn;
lv_obj_t *ui_SettingScreenLongEditImg;
void ui_event_SettingScreenConfirmBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreenConfirmBtn;
lv_obj_t *ui_SettingScreenConfirmLabel;
void ui_event_SettingScreenCancelBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreenCancelBtn;
lv_obj_t *ui_SettingScreenCancelLabel;
lv_obj_t *ui_EditTextScreen;
lv_obj_t *ui_EditTextScreenPanel;
lv_obj_t *ui_EditTextScreenTextArea;
lv_obj_t *ui_EditTextScreenKeyboard;
void ui_event_EditTextScreenConfirmBtn(lv_event_t *e);
lv_obj_t *ui_EditTextScreenConfirmBtn;
lv_obj_t *ui_EditTextScreenConfirmLabel;
void ui_event_EditTextScreenCancelBtn(lv_event_t *e);
lv_obj_t *ui_EditTextScreenCancelBtn;
lv_obj_t *ui_EditTextScreenCancelLabel;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP != 0
#error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_DataScreenTempPanel(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        visibleTempDataChart(e);
    }
}
void ui_event_DataScreenHumidPanel(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        visibleHumidDataChart(e);
    }
}
void ui_event_DataScreenSettingBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toSettingPage(e);
    }
}
void ui_event_SettingScreenSsidEditBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toEditSsid(e);
    }
}
void ui_event_SettingScreenWifiPwEditBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toEditWifiPw(e);
    }
}
void ui_event_SettingScreenLatEditBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toEditLat(e);
    }
}
void ui_event_SettingScreenLongEditBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toEditLong(e);
    }
}
void ui_event_SettingScreenConfirmBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        settingConfirm(e);
    }
}
void ui_event_SettingScreenCancelBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        settingCancel(e);
    }
}
void ui_event_EditTextScreenConfirmBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        enterTextConfirm(e);
    }
}
void ui_event_EditTextScreenCancelBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        enterTextCancel(e);
    }
}

///////////////////// SCREENS ////////////////////
void ui_DataScreen_screen_init(void)
{
    ui_DataScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_DataScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_DataScreenTempPanel = lv_obj_create(ui_DataScreen);
    lv_obj_set_width(ui_DataScreenTempPanel, 100);
    lv_obj_set_height(ui_DataScreenTempPanel, 110);
    lv_obj_set_x(ui_DataScreenTempPanel, 180);
    lv_obj_set_y(ui_DataScreenTempPanel, -85);
    lv_obj_set_align(ui_DataScreenTempPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_DataScreenTempPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_DataScreenTempPanel, lv_color_hex(0xFFC4C4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DataScreenTempPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DataScreenTempLabel = lv_label_create(ui_DataScreenTempPanel);
    lv_obj_set_width(ui_DataScreenTempLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_DataScreenTempLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_DataScreenTempLabel, 0);
    lv_obj_set_y(ui_DataScreenTempLabel, -35);
    lv_obj_set_align(ui_DataScreenTempLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DataScreenTempLabel, "Temp");

    ui_DataScreenTempValueLabel = lv_label_create(ui_DataScreenTempPanel);
    lv_obj_set_width(ui_DataScreenTempValueLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_DataScreenTempValueLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_DataScreenTempValueLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DataScreenTempValueLabel, "-");
    lv_obj_set_style_text_font(ui_DataScreenTempValueLabel, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DataScreenTempUnitLabel = lv_label_create(ui_DataScreenTempPanel);
    lv_obj_set_width(ui_DataScreenTempUnitLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_DataScreenTempUnitLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_DataScreenTempUnitLabel, 0);
    lv_obj_set_y(ui_DataScreenTempUnitLabel, 35);
    lv_obj_set_align(ui_DataScreenTempUnitLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DataScreenTempUnitLabel, "C");

    ui_DataScreenHumidPanel = lv_obj_create(ui_DataScreen);
    lv_obj_set_width(ui_DataScreenHumidPanel, 100);
    lv_obj_set_height(ui_DataScreenHumidPanel, 110);
    lv_obj_set_x(ui_DataScreenHumidPanel, 180);
    lv_obj_set_y(ui_DataScreenHumidPanel, 35);
    lv_obj_set_align(ui_DataScreenHumidPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_DataScreenHumidPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_DataScreenHumidPanel, lv_color_hex(0xCCE6FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DataScreenHumidPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DataScreenHumidLabel = lv_label_create(ui_DataScreenHumidPanel);
    lv_obj_set_width(ui_DataScreenHumidLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_DataScreenHumidLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_DataScreenHumidLabel, 0);
    lv_obj_set_y(ui_DataScreenHumidLabel, -35);
    lv_obj_set_align(ui_DataScreenHumidLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DataScreenHumidLabel, "Humidity");

    ui_DataScreenHumidValueLabel = lv_label_create(ui_DataScreenHumidPanel);
    lv_obj_set_width(ui_DataScreenHumidValueLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_DataScreenHumidValueLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_DataScreenHumidValueLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DataScreenHumidValueLabel, "-");
    lv_obj_set_style_text_font(ui_DataScreenHumidValueLabel, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DataScreenHumidUnitLabel = lv_label_create(ui_DataScreenHumidPanel);
    lv_obj_set_width(ui_DataScreenHumidUnitLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_DataScreenHumidUnitLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_DataScreenHumidUnitLabel, 0);
    lv_obj_set_y(ui_DataScreenHumidUnitLabel, 35);
    lv_obj_set_align(ui_DataScreenHumidUnitLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DataScreenHumidUnitLabel, "%RH");

    ui_DatsScreenChart = lv_chart_create(ui_DataScreen);
    lv_obj_set_width(ui_DatsScreenChart, 280);
    lv_obj_set_height(ui_DatsScreenChart, 200);
    lv_obj_set_x(ui_DatsScreenChart, -55);
    lv_obj_set_y(ui_DatsScreenChart, -35);
    lv_obj_set_align(ui_DatsScreenChart, LV_ALIGN_CENTER);
    lv_chart_set_type(ui_DatsScreenChart, LV_CHART_TYPE_LINE);
    lv_chart_set_point_count(ui_DatsScreenChart, 25);
    lv_chart_set_range(ui_DatsScreenChart, LV_CHART_AXIS_PRIMARY_Y, -10, 40);
    lv_chart_set_range(ui_DatsScreenChart, LV_CHART_AXIS_SECONDARY_Y, 0, 100);
    lv_chart_set_div_line_count(ui_DatsScreenChart, 6, 5);
    lv_chart_set_axis_tick(ui_DatsScreenChart, LV_CHART_AXIS_PRIMARY_X, 10, 5, 5, 5, false, 50);
    lv_chart_set_axis_tick(ui_DatsScreenChart, LV_CHART_AXIS_PRIMARY_Y, 10, 5, 6, 5, true, 50);
    lv_chart_series_t *ui_DatsScreenChart_series_1 = lv_chart_add_series(ui_DatsScreenChart, lv_color_hex(0xFF5959),
                                                                         LV_CHART_AXIS_PRIMARY_Y);
    static lv_coord_t ui_DatsScreenChart_series_1_array[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    lv_chart_set_ext_y_array(ui_DatsScreenChart, ui_DatsScreenChart_series_1, ui_DatsScreenChart_series_1_array);
    lv_chart_series_t *ui_DatsScreenChart_series_2 = lv_chart_add_series(ui_DatsScreenChart, lv_color_hex(0x3393FF),
                                                                         LV_CHART_AXIS_SECONDARY_Y);
    static lv_coord_t ui_DatsScreenChart_series_2_array[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    lv_chart_set_ext_y_array(ui_DatsScreenChart, ui_DatsScreenChart_series_2, ui_DatsScreenChart_series_2_array);

    ui_DataScreenChartTitle = lv_label_create(ui_DataScreen);
    lv_obj_set_width(ui_DataScreenChartTitle, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_DataScreenChartTitle, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_DataScreenChartTitle, -55);
    lv_obj_set_y(ui_DataScreenChartTitle, 90);
    lv_obj_set_align(ui_DataScreenChartTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DataScreenChartTitle, "Temp");

    ui_DataScreenConnectLabel = lv_label_create(ui_DataScreen);
    lv_obj_set_width(ui_DataScreenConnectLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_DataScreenConnectLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_DataScreenConnectLabel, -55);
    lv_obj_set_y(ui_DataScreenConnectLabel, 125);
    lv_obj_set_align(ui_DataScreenConnectLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DataScreenConnectLabel, "[Status]");

    ui_DataScreenSettingBtn = lv_btn_create(ui_DataScreen);
    lv_obj_set_width(ui_DataScreenSettingBtn, 90);
    lv_obj_set_height(ui_DataScreenSettingBtn, 40);
    lv_obj_set_x(ui_DataScreenSettingBtn, 185);
    lv_obj_set_y(ui_DataScreenSettingBtn, 125);
    lv_obj_set_align(ui_DataScreenSettingBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_DataScreenSettingBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_DataScreenSettingBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_DatsScreenSettingLabel = lv_label_create(ui_DataScreenSettingBtn);
    lv_obj_set_width(ui_DatsScreenSettingLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_DatsScreenSettingLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_DatsScreenSettingLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DatsScreenSettingLabel, "Setting");

    lv_obj_add_event_cb(ui_DataScreenTempPanel, ui_event_DataScreenTempPanel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_DataScreenHumidPanel, ui_event_DataScreenHumidPanel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_DataScreenSettingBtn, ui_event_DataScreenSettingBtn, LV_EVENT_ALL, NULL);
}
void ui_SettingScreen_screen_init(void)
{
    ui_SettingScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SettingScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreenLabel = lv_label_create(ui_SettingScreen);
    lv_obj_set_width(ui_SettingScreenLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreenLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreenLabel, 0);
    lv_obj_set_y(ui_SettingScreenLabel, -125);
    lv_obj_set_align(ui_SettingScreenLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingScreenLabel, "Setting");
    lv_obj_set_style_text_font(ui_SettingScreenLabel, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SeetingScreenPanel = lv_obj_create(ui_SettingScreen);
    lv_obj_set_width(ui_SeetingScreenPanel, 450);
    lv_obj_set_height(ui_SeetingScreenPanel, 195);
    lv_obj_set_x(ui_SeetingScreenPanel, 0);
    lv_obj_set_y(ui_SeetingScreenPanel, -5);
    lv_obj_set_align(ui_SeetingScreenPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_SeetingScreenPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_SeetingScreenPanel, lv_color_hex(0xECECEC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SeetingScreenPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreenSsidLabel = lv_label_create(ui_SeetingScreenPanel);
    lv_obj_set_width(ui_SettingScreenSsidLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreenSsidLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreenSsidLabel, 0);
    lv_obj_set_y(ui_SettingScreenSsidLabel, -60);
    lv_obj_set_align(ui_SettingScreenSsidLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingScreenSsidLabel, "SSID");

    ui_SettingScreenSsidTextArea = lv_textarea_create(ui_SeetingScreenPanel);
    lv_obj_set_width(ui_SettingScreenSsidTextArea, 300);
    lv_obj_set_height(ui_SettingScreenSsidTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreenSsidTextArea, 80);
    lv_obj_set_y(ui_SettingScreenSsidTextArea, -60);
    lv_obj_set_align(ui_SettingScreenSsidTextArea, LV_ALIGN_LEFT_MID);
    lv_textarea_set_placeholder_text(ui_SettingScreenSsidTextArea, "Placeholder...");
    lv_textarea_set_one_line(ui_SettingScreenSsidTextArea, true);
    lv_obj_clear_flag(ui_SettingScreenSsidTextArea, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_obj_set_style_pad_left(ui_SettingScreenSsidTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingScreenSsidTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingScreenSsidTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingScreenSsidTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreenSsidEditBtn = lv_btn_create(ui_SeetingScreenPanel);
    lv_obj_set_width(ui_SettingScreenSsidEditBtn, 32);
    lv_obj_set_height(ui_SettingScreenSsidEditBtn, 32);
    lv_obj_set_x(ui_SettingScreenSsidEditBtn, 200);
    lv_obj_set_y(ui_SettingScreenSsidEditBtn, -60);
    lv_obj_set_align(ui_SettingScreenSsidEditBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreenSsidEditBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreenSsidEditBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreenSsidEditImg = lv_img_create(ui_SettingScreenSsidEditBtn);
    lv_img_set_src(ui_SettingScreenSsidEditImg, &ui_img_pen_square_png);
    lv_obj_set_width(ui_SettingScreenSsidEditImg, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreenSsidEditImg, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreenSsidEditImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreenSsidEditImg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_SettingScreenSsidEditImg, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreenWifiPwLabel = lv_label_create(ui_SeetingScreenPanel);
    lv_obj_set_width(ui_SettingScreenWifiPwLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreenWifiPwLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreenWifiPwLabel, 0);
    lv_obj_set_y(ui_SettingScreenWifiPwLabel, -20);
    lv_obj_set_align(ui_SettingScreenWifiPwLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingScreenWifiPwLabel, "Password");

    ui_SettingScreenWifiPwTextArea = lv_textarea_create(ui_SeetingScreenPanel);
    lv_obj_set_width(ui_SettingScreenWifiPwTextArea, 300);
    lv_obj_set_height(ui_SettingScreenWifiPwTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreenWifiPwTextArea, 80);
    lv_obj_set_y(ui_SettingScreenWifiPwTextArea, -20);
    lv_obj_set_align(ui_SettingScreenWifiPwTextArea, LV_ALIGN_LEFT_MID);
    lv_textarea_set_placeholder_text(ui_SettingScreenWifiPwTextArea, "Placeholder...");
    lv_textarea_set_one_line(ui_SettingScreenWifiPwTextArea, true);
    lv_textarea_set_password_mode(ui_SettingScreenWifiPwTextArea, true);
    lv_obj_clear_flag(ui_SettingScreenWifiPwTextArea, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_obj_set_style_pad_left(ui_SettingScreenWifiPwTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingScreenWifiPwTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingScreenWifiPwTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingScreenWifiPwTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreenWifiPwEditBtn = lv_btn_create(ui_SeetingScreenPanel);
    lv_obj_set_width(ui_SettingScreenWifiPwEditBtn, 32);
    lv_obj_set_height(ui_SettingScreenWifiPwEditBtn, 32);
    lv_obj_set_x(ui_SettingScreenWifiPwEditBtn, 200);
    lv_obj_set_y(ui_SettingScreenWifiPwEditBtn, -20);
    lv_obj_set_align(ui_SettingScreenWifiPwEditBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreenWifiPwEditBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreenWifiPwEditBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreenWifiPwImg = lv_img_create(ui_SettingScreenWifiPwEditBtn);
    lv_img_set_src(ui_SettingScreenWifiPwImg, &ui_img_pen_square_png);
    lv_obj_set_width(ui_SettingScreenWifiPwImg, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreenWifiPwImg, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreenWifiPwImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreenWifiPwImg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_SettingScreenWifiPwImg, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreenMacLabel = lv_label_create(ui_SeetingScreenPanel);
    lv_obj_set_width(ui_SettingScreenMacLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreenMacLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreenMacLabel, 0);
    lv_obj_set_y(ui_SettingScreenMacLabel, 20);
    lv_obj_set_align(ui_SettingScreenMacLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingScreenMacLabel, "MAC");

    ui_SettingScreenMacTextArea = lv_textarea_create(ui_SeetingScreenPanel);
    lv_obj_set_width(ui_SettingScreenMacTextArea, 340);
    lv_obj_set_height(ui_SettingScreenMacTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreenMacTextArea, 80);
    lv_obj_set_y(ui_SettingScreenMacTextArea, 20);
    lv_obj_set_align(ui_SettingScreenMacTextArea, LV_ALIGN_LEFT_MID);
    lv_textarea_set_placeholder_text(ui_SettingScreenMacTextArea, "Placeholder...");
    lv_textarea_set_one_line(ui_SettingScreenMacTextArea, true);
    lv_obj_clear_flag(ui_SettingScreenMacTextArea, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_obj_set_style_pad_left(ui_SettingScreenMacTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingScreenMacTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingScreenMacTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingScreenMacTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreenLatLabel = lv_label_create(ui_SeetingScreenPanel);
    lv_obj_set_width(ui_SettingScreenLatLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreenLatLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreenLatLabel, 0);
    lv_obj_set_y(ui_SettingScreenLatLabel, 60);
    lv_obj_set_align(ui_SettingScreenLatLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingScreenLatLabel, "GPS");

    ui_SettingScreenLatTextArea = lv_textarea_create(ui_SeetingScreenPanel);
    lv_obj_set_width(ui_SettingScreenLatTextArea, 125);
    lv_obj_set_height(ui_SettingScreenLatTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreenLatTextArea, 80);
    lv_obj_set_y(ui_SettingScreenLatTextArea, 60);
    lv_obj_set_align(ui_SettingScreenLatTextArea, LV_ALIGN_LEFT_MID);
    lv_textarea_set_placeholder_text(ui_SettingScreenLatTextArea, "Placeholder...");
    lv_textarea_set_one_line(ui_SettingScreenLatTextArea, true);
    lv_obj_clear_flag(ui_SettingScreenLatTextArea, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_obj_set_style_pad_left(ui_SettingScreenLatTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingScreenLatTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingScreenLatTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingScreenLatTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreenLatEditBtn = lv_btn_create(ui_SeetingScreenPanel);
    lv_obj_set_width(ui_SettingScreenLatEditBtn, 32);
    lv_obj_set_height(ui_SettingScreenLatEditBtn, 32);
    lv_obj_set_x(ui_SettingScreenLatEditBtn, 215);
    lv_obj_set_y(ui_SettingScreenLatEditBtn, 60);
    lv_obj_set_align(ui_SettingScreenLatEditBtn, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_SettingScreenLatEditBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreenLatEditBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreenLatEditImg = lv_img_create(ui_SettingScreenLatEditBtn);
    lv_img_set_src(ui_SettingScreenLatEditImg, &ui_img_pen_square_png);
    lv_obj_set_width(ui_SettingScreenLatEditImg, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreenLatEditImg, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreenLatEditImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreenLatEditImg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_SettingScreenLatEditImg, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreenLongTextArea = lv_textarea_create(ui_SeetingScreenPanel);
    lv_obj_set_width(ui_SettingScreenLongTextArea, 125);
    lv_obj_set_height(ui_SettingScreenLongTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreenLongTextArea, 255);
    lv_obj_set_y(ui_SettingScreenLongTextArea, 60);
    lv_obj_set_align(ui_SettingScreenLongTextArea, LV_ALIGN_LEFT_MID);
    lv_textarea_set_placeholder_text(ui_SettingScreenLongTextArea, "Placeholder...");
    lv_textarea_set_one_line(ui_SettingScreenLongTextArea, true);
    lv_obj_clear_flag(ui_SettingScreenLongTextArea, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_obj_set_style_pad_left(ui_SettingScreenLongTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingScreenLongTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingScreenLongTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingScreenLongTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreenLongEditBtn = lv_btn_create(ui_SeetingScreenPanel);
    lv_obj_set_width(ui_SettingScreenLongEditBtn, 32);
    lv_obj_set_height(ui_SettingScreenLongEditBtn, 32);
    lv_obj_set_x(ui_SettingScreenLongEditBtn, 200);
    lv_obj_set_y(ui_SettingScreenLongEditBtn, 60);
    lv_obj_set_align(ui_SettingScreenLongEditBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreenLongEditBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreenLongEditBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreenLongEditImg = lv_img_create(ui_SettingScreenLongEditBtn);
    lv_img_set_src(ui_SettingScreenLongEditImg, &ui_img_pen_square_png);
    lv_obj_set_width(ui_SettingScreenLongEditImg, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreenLongEditImg, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreenLongEditImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreenLongEditImg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_SettingScreenLongEditImg, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreenConfirmBtn = lv_btn_create(ui_SettingScreen);
    lv_obj_set_width(ui_SettingScreenConfirmBtn, 90);
    lv_obj_set_height(ui_SettingScreenConfirmBtn, 40);
    lv_obj_set_x(ui_SettingScreenConfirmBtn, -60);
    lv_obj_set_y(ui_SettingScreenConfirmBtn, 125);
    lv_obj_set_align(ui_SettingScreenConfirmBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreenConfirmBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreenConfirmBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreenConfirmLabel = lv_label_create(ui_SettingScreenConfirmBtn);
    lv_obj_set_width(ui_SettingScreenConfirmLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreenConfirmLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreenConfirmLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingScreenConfirmLabel, "Confirm");

    ui_SettingScreenCancelBtn = lv_btn_create(ui_SettingScreen);
    lv_obj_set_width(ui_SettingScreenCancelBtn, 90);
    lv_obj_set_height(ui_SettingScreenCancelBtn, 40);
    lv_obj_set_x(ui_SettingScreenCancelBtn, 60);
    lv_obj_set_y(ui_SettingScreenCancelBtn, 125);
    lv_obj_set_align(ui_SettingScreenCancelBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreenCancelBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreenCancelBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_bg_color(ui_SettingScreenCancelBtn, lv_color_hex(0xFF5959), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingScreenCancelBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreenCancelLabel = lv_label_create(ui_SettingScreenCancelBtn);
    lv_obj_set_width(ui_SettingScreenCancelLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreenCancelLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreenCancelLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingScreenCancelLabel, "Cancel");

    lv_obj_add_event_cb(ui_SettingScreenSsidEditBtn, ui_event_SettingScreenSsidEditBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreenWifiPwEditBtn, ui_event_SettingScreenWifiPwEditBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreenLatEditBtn, ui_event_SettingScreenLatEditBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreenLongEditBtn, ui_event_SettingScreenLongEditBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreenConfirmBtn, ui_event_SettingScreenConfirmBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreenCancelBtn, ui_event_SettingScreenCancelBtn, LV_EVENT_ALL, NULL);
}
void ui_EditTextScreen_screen_init(void)
{
    ui_EditTextScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_EditTextScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_EditTextScreenPanel = lv_obj_create(ui_EditTextScreen);
    lv_obj_set_width(ui_EditTextScreenPanel, 450);
    lv_obj_set_height(ui_EditTextScreenPanel, 240);
    lv_obj_set_x(ui_EditTextScreenPanel, 0);
    lv_obj_set_y(ui_EditTextScreenPanel, -25);
    lv_obj_set_align(ui_EditTextScreenPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_EditTextScreenPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_EditTextScreenPanel, lv_color_hex(0xECECEC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_EditTextScreenPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_EditTextScreenTextArea = lv_textarea_create(ui_EditTextScreenPanel);
    lv_obj_set_width(ui_EditTextScreenTextArea, 430);
    lv_obj_set_height(ui_EditTextScreenTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_EditTextScreenTextArea, 0);
    lv_obj_set_y(ui_EditTextScreenTextArea, -10);
    lv_obj_set_align(ui_EditTextScreenTextArea, LV_ALIGN_TOP_MID);
    lv_textarea_set_placeholder_text(ui_EditTextScreenTextArea, "Placeholder...");
    lv_textarea_set_one_line(ui_EditTextScreenTextArea, true);
    lv_obj_set_style_pad_left(ui_EditTextScreenTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_EditTextScreenTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_EditTextScreenTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_EditTextScreenTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_EditTextScreenKeyboard = lv_keyboard_create(ui_EditTextScreenPanel);
    lv_obj_set_width(ui_EditTextScreenKeyboard, 440);
    lv_obj_set_height(ui_EditTextScreenKeyboard, 185);
    lv_obj_set_x(ui_EditTextScreenKeyboard, 0);
    lv_obj_set_y(ui_EditTextScreenKeyboard, 15);
    lv_obj_set_align(ui_EditTextScreenKeyboard, LV_ALIGN_BOTTOM_MID);

    ui_EditTextScreenConfirmBtn = lv_btn_create(ui_EditTextScreen);
    lv_obj_set_width(ui_EditTextScreenConfirmBtn, 90);
    lv_obj_set_height(ui_EditTextScreenConfirmBtn, 40);
    lv_obj_set_x(ui_EditTextScreenConfirmBtn, -60);
    lv_obj_set_y(ui_EditTextScreenConfirmBtn, 125);
    lv_obj_set_align(ui_EditTextScreenConfirmBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_EditTextScreenConfirmBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_EditTextScreenConfirmBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_EditTextScreenConfirmLabel = lv_label_create(ui_EditTextScreenConfirmBtn);
    lv_obj_set_width(ui_EditTextScreenConfirmLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_EditTextScreenConfirmLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_EditTextScreenConfirmLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_EditTextScreenConfirmLabel, "Confirm");

    ui_EditTextScreenCancelBtn = lv_btn_create(ui_EditTextScreen);
    lv_obj_set_width(ui_EditTextScreenCancelBtn, 90);
    lv_obj_set_height(ui_EditTextScreenCancelBtn, 40);
    lv_obj_set_x(ui_EditTextScreenCancelBtn, 60);
    lv_obj_set_y(ui_EditTextScreenCancelBtn, 125);
    lv_obj_set_align(ui_EditTextScreenCancelBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_EditTextScreenCancelBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_EditTextScreenCancelBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_bg_color(ui_EditTextScreenCancelBtn, lv_color_hex(0xFF5959), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_EditTextScreenCancelBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_EditTextScreenCancelLabel = lv_label_create(ui_EditTextScreenCancelBtn);
    lv_obj_set_width(ui_EditTextScreenCancelLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_EditTextScreenCancelLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_EditTextScreenCancelLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_EditTextScreenCancelLabel, "Cancel");

    lv_obj_add_event_cb(ui_EditTextScreenConfirmBtn, ui_event_EditTextScreenConfirmBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_EditTextScreenCancelBtn, ui_event_EditTextScreenCancelBtn, LV_EVENT_ALL, NULL);
}

void ui_init(void)
{
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                              false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_DataScreen_screen_init();
    ui_SettingScreen_screen_init();
    ui_EditTextScreen_screen_init();
}
