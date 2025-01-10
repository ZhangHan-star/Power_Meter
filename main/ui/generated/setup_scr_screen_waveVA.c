/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
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



void setup_scr_screen_waveVA(lv_ui *ui)
{
    //Write codes screen_waveVA
    ui->screen_waveVA = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_waveVA, 160, 100);
    lv_obj_set_scrollbar_mode(ui->screen_waveVA, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_waveVA, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_waveVA, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_waveVA, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_waveVA, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_waveVA_line_1
    ui->screen_waveVA_line_1 = lv_line_create(ui->screen_waveVA);
    static lv_point_t screen_waveVA_line_1[] = {{0, 81},{160, 81},};
    lv_line_set_points(ui->screen_waveVA_line_1, screen_waveVA_line_1, 2);
    lv_obj_set_pos(ui->screen_waveVA_line_1, 0, 0);
    lv_obj_set_size(ui->screen_waveVA_line_1, 160, 100);

    //Write style for screen_waveVA_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_waveVA_line_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_waveVA_line_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_waveVA_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_waveVA_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_waveVA_chart_1
    ui->screen_waveVA_chart_1 = lv_chart_create(ui->screen_waveVA);
    lv_chart_set_type(ui->screen_waveVA_chart_1, LV_CHART_TYPE_LINE);
    lv_chart_set_div_line_count(ui->screen_waveVA_chart_1, 6, 11);
    lv_chart_set_point_count(ui->screen_waveVA_chart_1, 32);
    lv_chart_set_range(ui->screen_waveVA_chart_1, LV_CHART_AXIS_PRIMARY_Y, 0, 30);
    lv_chart_set_axis_tick(ui->screen_waveVA_chart_1, LV_CHART_AXIS_PRIMARY_Y, 1, 1, 6, 1, true, 40);
    lv_chart_set_range(ui->screen_waveVA_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 100);
    lv_chart_set_axis_tick(ui->screen_waveVA_chart_1, LV_CHART_AXIS_SECONDARY_Y, 1, 1, 6, 1, true, 40);
    lv_chart_set_zoom_x(ui->screen_waveVA_chart_1, 256);
    lv_chart_set_zoom_y(ui->screen_waveVA_chart_1, 256);
    lv_obj_set_style_size(ui->screen_waveVA_chart_1, 0, LV_PART_INDICATOR);
    ui->screen_waveVA_chart_1_0 = lv_chart_add_series(ui->screen_waveVA_chart_1, lv_color_hex(0xffff00), LV_CHART_AXIS_PRIMARY_Y);
#if LV_USE_FREEMASTER == 0
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, 0);
#endif
    ui->screen_waveVA_chart_1_1 = lv_chart_add_series(ui->screen_waveVA_chart_1, lv_color_hex(0xff0000), LV_CHART_AXIS_SECONDARY_Y);
#if LV_USE_FREEMASTER == 0
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_1, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_1, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_1, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_1, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_1, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_1, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_1, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_1, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_1, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_1, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_1, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_1, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_1, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_1, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_1, 0);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_1, 0);
#endif
    lv_obj_set_pos(ui->screen_waveVA_chart_1, 20, 0);
    lv_obj_set_size(ui->screen_waveVA_chart_1, 120, 70);
    lv_obj_set_scrollbar_mode(ui->screen_waveVA_chart_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_waveVA_chart_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_waveVA_chart_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_waveVA_chart_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_waveVA_chart_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_waveVA_chart_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_waveVA_chart_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->screen_waveVA_chart_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_waveVA_chart_1, lv_color_hex(0x7d8490), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_waveVA_chart_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_waveVA_chart_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_waveVA_chart_1, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_waveVA_chart_1, lv_color_hex(0xffffff), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_waveVA_chart_1, &lv_font_Alatsi_Regular_12, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_waveVA_chart_1, 255, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->screen_waveVA_chart_1, 2, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_waveVA_chart_1, lv_color_hex(0x7D8490), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_waveVA_chart_1, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write codes screen_waveVA_label_Current
    ui->screen_waveVA_label_Current = lv_label_create(ui->screen_waveVA);
    lv_label_set_text(ui->screen_waveVA_label_Current, "0.0mA");
    lv_label_set_long_mode(ui->screen_waveVA_label_Current, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_waveVA_label_Current, 80, 61);
    lv_obj_set_size(ui->screen_waveVA_label_Current, 60, 19);

    //Write style for screen_waveVA_label_Current, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_waveVA_label_Current, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_waveVA_label_Current, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_waveVA_label_Current, lv_color_hex(0x606060), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_waveVA_label_Current, LV_BORDER_SIDE_TOP, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_waveVA_label_Current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_waveVA_label_Current, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_waveVA_label_Current, &lv_font_Abel_regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_waveVA_label_Current, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_waveVA_label_Current, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_waveVA_label_Current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_waveVA_label_Current, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_waveVA_label_Current, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_waveVA_label_Current, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_waveVA_label_Current, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_waveVA_label_Current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_waveVA_label_Current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_waveVA_label_Current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_waveVA_label_Current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_waveVA_label_Current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_waveVA_label_Voltage
    ui->screen_waveVA_label_Voltage = lv_label_create(ui->screen_waveVA);
    lv_label_set_text(ui->screen_waveVA_label_Voltage, "0.000V");
    lv_label_set_long_mode(ui->screen_waveVA_label_Voltage, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_waveVA_label_Voltage, 20, 61);
    lv_obj_set_size(ui->screen_waveVA_label_Voltage, 60, 19);

    //Write style for screen_waveVA_label_Voltage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_waveVA_label_Voltage, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_waveVA_label_Voltage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_waveVA_label_Voltage, lv_color_hex(0x606060), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_waveVA_label_Voltage, LV_BORDER_SIDE_TOP, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_waveVA_label_Voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_waveVA_label_Voltage, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_waveVA_label_Voltage, &lv_font_Abel_regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_waveVA_label_Voltage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_waveVA_label_Voltage, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_waveVA_label_Voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_waveVA_label_Voltage, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_waveVA_label_Voltage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_waveVA_label_Voltage, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_waveVA_label_Voltage, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_waveVA_label_Voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_waveVA_label_Voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_waveVA_label_Voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_waveVA_label_Voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_waveVA_label_Voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_waveVA.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_waveVA);

    //Init events for screen.
    events_init_screen_waveVA(ui);
}
