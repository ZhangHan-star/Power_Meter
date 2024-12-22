/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"
#include "ina226.h"
#include "esp_log.h"


const char * V5[] = {"0V", "1V", "2V", "3V", "4V", "5V"};
const char * V10[] = {"0V", "2V", "4V", "6V", "8V", "10"};
const char * V30[] = {"0V", "6", "12", "18", "24", "30"};

const char * mA10[] = {"0mA", "2", "4", "6", "8", "10"};
const char * mA100[] = {"0mA", "20", "40", "60", "80", "100"};
const char * mA1000[] = {"0mA", "200", "400", "600", "800", "1A"};
const char * A10[] = {"0A", "2A", "4A", "6A", "8A", "10"};
const char * A20[] = {"0A", "4A", "8A", "12", "16", "20"};
static void draw_event_cb(lv_event_t * e)
{
    lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);
    if(!lv_obj_draw_part_check_type(dsc, &lv_chart_class, LV_CHART_DRAW_PART_TICK_LABEL)) return;
		// ESP_LOGI("draw_event_cb", "VoltageRange=%d",VoltageRange);
    if(dsc->id == LV_CHART_AXIS_PRIMARY_Y && dsc->text ) {
			if (VoltageRange==50)
			{
				// ESP_LOGI("draw_event_cb", "SetRange = 5V");
				lv_snprintf(dsc->text, dsc->text_length, "%s", V5[dsc->value/10]);
			}else if (VoltageRange==100)
			{
				// ESP_LOGI("draw_event_cb", "SetRange = 10V");
				lv_snprintf(dsc->text, dsc->text_length, "%s", V10[dsc->value/20]);
			}else if (VoltageRange==300)
			{
				// ESP_LOGI("draw_event_cb", "SetRange = 30V");
				lv_snprintf(dsc->text, dsc->text_length, "%s", V30[dsc->value/60]);
			}
    }
		if(dsc->id == LV_CHART_AXIS_SECONDARY_Y && dsc->text ) {
			if (CurrentRange==10)
			{
				// ESP_LOGI("draw_event_cb", "SetRange = 10mA");
				lv_snprintf(dsc->text, dsc->text_length, "%s", mA10[dsc->value/2]);
			}else if (CurrentRange==100)
			{
				// ESP_LOGI("draw_event_cb", "SetRange = 100mA");
				lv_snprintf(dsc->text, dsc->text_length, "%s", mA100[dsc->value/20]);
			}else if (CurrentRange==1000)
			{
				// ESP_LOGI("draw_event_cb", "SetRange = 1A");
				lv_snprintf(dsc->text, dsc->text_length, "%s", mA1000[dsc->value/200]);
			}else if (CurrentRange==10000)
			{
				// ESP_LOGI("draw_event_cb", "SetRange = 10A");
				lv_snprintf(dsc->text, dsc->text_length, "%s", A10[dsc->value/2000]);
			}else if (CurrentRange==20000)
			{
				// ESP_LOGI("draw_event_cb", "SetRange = 20A");
				lv_snprintf(dsc->text, dsc->text_length, "%s", A20[dsc->value/4000]);
			}
    }
}

void setup_scr_screen_2(lv_ui *ui)
{
	//Write codes screen_2
	ui->screen_2 = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_2, 160, 100);
	lv_obj_set_scrollbar_mode(ui->screen_2, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_2_chart_1
	ui->screen_2_chart_1 = lv_chart_create(ui->screen_2);
	lv_chart_set_type(ui->screen_2_chart_1, LV_CHART_TYPE_LINE);
	lv_chart_set_div_line_count(ui->screen_2_chart_1, 6, 11);
	lv_chart_set_point_count(ui->screen_2_chart_1, 32);
	lv_chart_set_range(ui->screen_2_chart_1, LV_CHART_AXIS_PRIMARY_Y, 0, 50);
	lv_chart_set_axis_tick(ui->screen_2_chart_1, LV_CHART_AXIS_PRIMARY_Y, 1, 1, 6, 1, true, 40);
	lv_chart_set_range(ui->screen_2_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 10);
	lv_chart_set_axis_tick(ui->screen_2_chart_1, LV_CHART_AXIS_SECONDARY_Y, 1, 1, 6, 1, true, 40);
	lv_chart_set_zoom_x(ui->screen_2_chart_1, 256);
	lv_chart_set_zoom_y(ui->screen_2_chart_1, 256);
	lv_obj_set_style_size(ui->screen_2_chart_1, 0, LV_PART_INDICATOR);
	ui->screen_2_chart_1_0 = lv_chart_add_series(ui->screen_2_chart_1, lv_color_hex(0xffff00), LV_CHART_AXIS_PRIMARY_Y);
#if LV_USE_FREEMASTER == 0
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_0, 0);
#endif
	ui->screen_2_chart_1_1 = lv_chart_add_series(ui->screen_2_chart_1, lv_color_hex(0xff0000), LV_CHART_AXIS_SECONDARY_Y);
#if LV_USE_FREEMASTER == 0
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_1, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_1, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_1, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_1, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_1, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_1, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_1, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_1, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_1, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_1, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_1, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_1, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_1, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_1, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_1, 0);
	lv_chart_set_next_value(ui->screen_2_chart_1, ui->screen_2_chart_1_1, 0);
#endif
	lv_obj_set_pos(ui->screen_2_chart_1, 20, 0);
	lv_obj_set_size(ui->screen_2_chart_1, 120, 70);
	lv_obj_set_scrollbar_mode(ui->screen_2_chart_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_2_chart_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_2_chart_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_2_chart_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_2_chart_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_2_chart_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_2_chart_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_width(ui->screen_2_chart_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->screen_2_chart_1, lv_color_hex(0x7d8490), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->screen_2_chart_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_2_chart_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_2_chart_1, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_2_chart_1, lv_color_hex(0x151212), LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_2_chart_1, &lv_font_Alatsi_Regular_12, LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_2_chart_1, 255, LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_line_width(ui->screen_2_chart_1, 2, LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->screen_2_chart_1, lv_color_hex(0xe8e8e8), LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->screen_2_chart_1, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

	//Write codes screen_2_label_Voltage
	ui->screen_2_label_Voltage = lv_label_create(ui->screen_2);
	lv_label_set_text(ui->screen_2_label_Voltage, "0.000V");
	lv_label_set_long_mode(ui->screen_2_label_Voltage, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_2_label_Voltage, 20, 70);
	lv_obj_set_size(ui->screen_2_label_Voltage, 60, 10);

	//Write style for screen_2_label_Voltage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_2_label_Voltage, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_2_label_Voltage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_2_label_Voltage, lv_color_hex(0x606060), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_2_label_Voltage, LV_BORDER_SIDE_TOP, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_2_label_Voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_2_label_Voltage, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_2_label_Voltage, &lv_font_Acme_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_2_label_Voltage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_2_label_Voltage, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_2_label_Voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_2_label_Voltage, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_2_label_Voltage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_2_label_Voltage, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_2_label_Voltage, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_2_label_Voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_2_label_Voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_2_label_Voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_2_label_Voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_2_label_Voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_2_label_Current
	ui->screen_2_label_Current = lv_label_create(ui->screen_2);
	lv_label_set_text(ui->screen_2_label_Current, "0.0mA");
	lv_label_set_long_mode(ui->screen_2_label_Current, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_2_label_Current, 80, 70);
	lv_obj_set_size(ui->screen_2_label_Current, 60, 10);

	//Write style for screen_2_label_Current, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_2_label_Current, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_2_label_Current, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_2_label_Current, lv_color_hex(0x606060), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_2_label_Current, LV_BORDER_SIDE_TOP, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_2_label_Current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_2_label_Current, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_2_label_Current, &lv_font_Acme_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_2_label_Current, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_2_label_Current, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_2_label_Current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_2_label_Current, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_2_label_Current, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_2_label_Current, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_2_label_Current, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_2_label_Current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_2_label_Current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_2_label_Current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_2_label_Current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_2_label_Current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of screen_2.
	lv_obj_add_event_cb(ui->screen_2_chart_1,draw_event_cb ,LV_EVENT_DRAW_PART_BEGIN,NULL);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_2);

	//Init events for screen.
	events_init_screen_2(ui);
}
