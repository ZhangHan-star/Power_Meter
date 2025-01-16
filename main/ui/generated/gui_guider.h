/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen_value1;
	bool screen_value1_del;
	lv_obj_t *screen_value1_cont_3;
	lv_obj_t *screen_value1_line_1;
	lv_obj_t *screen_value1_line_2;
	lv_obj_t *screen_value1_line_3;
	lv_obj_t *screen_value1_label_voltage;
	lv_obj_t *screen_value1_label_current;
	lv_obj_t *screen_value1_label_power;
	lv_obj_t *screen_value2;
	bool screen_value2_del;
	lv_obj_t *screen_value2_line_2;
	lv_obj_t *screen_value2_line_1;
	lv_obj_t *screen_value2_label_voltage;
	lv_obj_t *screen_value2_label_current;
	lv_obj_t *screen_value2_label_power;
	lv_obj_t *screen_waveVA;
	bool screen_waveVA_del;
	lv_obj_t *screen_waveVA_line_1;
	lv_obj_t *screen_waveVA_chart_1;
	lv_chart_series_t *screen_waveVA_chart_1_0;
	lv_chart_series_t *screen_waveVA_chart_1_1;
	lv_obj_t *screen_waveVA_label_Current;
	lv_obj_t *screen_waveVA_label_Voltage;
	lv_obj_t *screen_waveW;
	bool screen_waveW_del;
	lv_obj_t *screen_waveW_chart_1;
	lv_chart_series_t *screen_waveW_chart_1_0;
	lv_obj_t *screen_waveW_label_power;
	lv_obj_t *screen_threshold;
	bool screen_threshold_del;
	lv_obj_t *screen_threshold_line_1;
	lv_obj_t *screen_threshold_label_low;
	lv_obj_t *screen_threshold_label_over;
	lv_obj_t *screen_threshold_spinbox_low;
	lv_obj_t *screen_threshold_spinbox_low_btn;
	lv_obj_t *screen_threshold_spinbox_low_btn_minus;
	lv_obj_t *screen_threshold_spinbox_over;
	lv_obj_t *screen_threshold_spinbox_over_btn;
	lv_obj_t *screen_threshold_spinbox_over_btn_minus;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_screen_value1(lv_ui *ui);
void setup_scr_screen_value2(lv_ui *ui);
void setup_scr_screen_waveVA(lv_ui *ui);
void setup_scr_screen_waveW(lv_ui *ui);
void setup_scr_screen_threshold(lv_ui *ui);

LV_FONT_DECLARE(lv_font_Abel_regular_25)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_16)
LV_FONT_DECLARE(lv_font_Abel_regular_30)
LV_FONT_DECLARE(lv_font_simkai_16)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_12)
LV_FONT_DECLARE(lv_font_Abel_regular_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)


#ifdef __cplusplus
}
#endif
#endif
