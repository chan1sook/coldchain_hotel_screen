// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
// LVGL VERSION: 8.2.0
// PROJECT: Coldchain_Hotel

#include "Arduino.h"
#include "ui.h"
#include "common.h"

extern lv_obj_t *textareaRef;

extern void switchVisibleChartTo(chart_type type);
extern void updateSettingPage();
extern void boundEditText(lv_obj_t *target, lv_keyboard_mode_t mode, bool isPassword);
extern void validateEditText();
extern void confirmEditSetting();

void visibleTempDataChart(lv_event_t *e)
{
  switchVisibleChartTo(TEMP_CHART);
}

void visibleHumidDataChart(lv_event_t *e)
{
  switchVisibleChartTo(HUMID_CHART);
}

void toSettingPage(lv_event_t *e)
{
  updateSettingPage();
  lv_scr_load_anim(ui_SettingScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, true);
}

void toEditSsid(lv_event_t *e)
{
  boundEditText(ui_SettingScreenSsidTextArea, LV_KEYBOARD_MODE_TEXT_LOWER, false);
  lv_scr_load_anim(ui_EditTextScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void toEditWifiPw(lv_event_t *e)
{
  boundEditText(ui_SettingScreenWifiPwTextArea, LV_KEYBOARD_MODE_TEXT_LOWER, true);
  lv_scr_load_anim(ui_EditTextScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void toEditLat(lv_event_t *e)
{
  boundEditText(ui_SettingScreenLatTextArea, LV_KEYBOARD_MODE_NUMBER, false);
  lv_scr_load_anim(ui_EditTextScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void toEditLong(lv_event_t *e)
{
  boundEditText(ui_SettingScreenLongTextArea, LV_KEYBOARD_MODE_NUMBER, false);
  lv_scr_load_anim(ui_EditTextScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void settingConfirm(lv_event_t *e)
{
  confirmEditSetting();
  lv_scr_load_anim(ui_DataScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void settingCancel(lv_event_t *e)
{
  lv_scr_load_anim(ui_DataScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void enterTextConfirm(lv_event_t *e)
{
  validateEditText();
  lv_scr_load_anim(ui_SettingScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void enterTextCancel(lv_event_t *e)
{
  textareaRef = NULL;
  lv_scr_load_anim(ui_SettingScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}
