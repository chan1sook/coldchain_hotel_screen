// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
// LVGL VERSION: 8.2.0
// PROJECT: Coldchain_Hotel

#ifndef _COLDCHAIN_HOTEL_UI_H
#define _COLDCHAIN_HOTEL_UI_H

#ifdef __cplusplus
extern "C"
{
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

    extern lv_obj_t *ui_DataScreen;
    void ui_event_DataScreenTempPanel(lv_event_t *e);
    extern lv_obj_t *ui_DataScreenTempPanel;
    extern lv_obj_t *ui_DataScreenTempLabel;
    extern lv_obj_t *ui_DataScreenTempValueLabel;
    extern lv_obj_t *ui_DataScreenTempUnitLabel;
    void ui_event_DataScreenHumidPanel(lv_event_t *e);
    extern lv_obj_t *ui_DataScreenHumidPanel;
    extern lv_obj_t *ui_DataScreenHumidLabel;
    extern lv_obj_t *ui_DataScreenHumidValueLabel;
    extern lv_obj_t *ui_DataScreenHumidUnitLabel;
    extern lv_obj_t *ui_DatsScreenChart;
    extern lv_obj_t *ui_DataScreenChartTitle;
    extern lv_obj_t *ui_DataScreenConnectLabel;
    void ui_event_DataScreenSettingBtn(lv_event_t *e);
    extern lv_obj_t *ui_DataScreenSettingBtn;
    extern lv_obj_t *ui_DatsScreenSettingLabel;
    extern lv_obj_t *ui_SettingScreen;
    extern lv_obj_t *ui_SettingScreenLabel;
    extern lv_obj_t *ui_SeetingScreenPanel;
    extern lv_obj_t *ui_SettingScreenSsidLabel;
    extern lv_obj_t *ui_SettingScreenSsidTextArea;
    void ui_event_SettingScreenSsidEditBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreenSsidEditBtn;
    extern lv_obj_t *ui_SettingScreenSsidEditImg;
    extern lv_obj_t *ui_SettingScreenWifiPwLabel;
    extern lv_obj_t *ui_SettingScreenWifiPwTextArea;
    void ui_event_SettingScreenWifiPwEditBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreenWifiPwEditBtn;
    extern lv_obj_t *ui_SettingScreenWifiPwImg;
    extern lv_obj_t *ui_SettingScreenMacLabel;
    extern lv_obj_t *ui_SettingScreenMacTextArea;
    extern lv_obj_t *ui_SettingScreenLatLabel;
    extern lv_obj_t *ui_SettingScreenLatTextArea;
    void ui_event_SettingScreenLatEditBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreenLatEditBtn;
    extern lv_obj_t *ui_SettingScreenLatEditImg;
    extern lv_obj_t *ui_SettingScreenLongTextArea;
    void ui_event_SettingScreenLongEditBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreenLongEditBtn;
    extern lv_obj_t *ui_SettingScreenLongEditImg;
    void ui_event_SettingScreenConfirmBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreenConfirmBtn;
    extern lv_obj_t *ui_SettingScreenConfirmLabel;
    void ui_event_SettingScreenCancelBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreenCancelBtn;
    extern lv_obj_t *ui_SettingScreenCancelLabel;
    extern lv_obj_t *ui_EditTextScreen;
    extern lv_obj_t *ui_EditTextScreenPanel;
    extern lv_obj_t *ui_EditTextScreenTextArea;
    extern lv_obj_t *ui_EditTextScreenKeyboard;
    void ui_event_EditTextScreenConfirmBtn(lv_event_t *e);
    extern lv_obj_t *ui_EditTextScreenConfirmBtn;
    extern lv_obj_t *ui_EditTextScreenConfirmLabel;
    void ui_event_EditTextScreenCancelBtn(lv_event_t *e);
    extern lv_obj_t *ui_EditTextScreenCancelBtn;
    extern lv_obj_t *ui_EditTextScreenCancelLabel;

    void visibleTempDataChart(lv_event_t *e);
    void visibleHumidDataChart(lv_event_t *e);
    void toSettingPage(lv_event_t *e);
    void toEditSsid(lv_event_t *e);
    void toEditWifiPw(lv_event_t *e);
    void toEditLat(lv_event_t *e);
    void toEditLong(lv_event_t *e);
    void settingConfirm(lv_event_t *e);
    void settingCancel(lv_event_t *e);
    void enterTextConfirm(lv_event_t *e);
    void enterTextCancel(lv_event_t *e);

    LV_IMG_DECLARE(ui_img_pen_square_png); // assets\pen_square.png

    void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
