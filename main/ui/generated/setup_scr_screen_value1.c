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



void setup_scr_screen_value1(lv_ui *ui)
{
    //Write codes screen_value1
    ui->screen_value1 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_value1, 160, 100);
    lv_obj_set_scrollbar_mode(ui->screen_value1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_value1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_value1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_value1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_value1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_value1_cont_3
    ui->screen_value1_cont_3 = lv_obj_create(ui->screen_value1);
    lv_obj_set_pos(ui->screen_value1_cont_3, 0, 0);
    lv_obj_set_size(ui->screen_value1_cont_3, 160, 80);
    lv_obj_set_scrollbar_mode(ui->screen_value1_cont_3, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_value1_cont_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_value1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_value1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_value1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_value1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_value1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_value1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_value1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_value1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_value1_line_1
    ui->screen_value1_line_1 = lv_line_create(ui->screen_value1_cont_3);
    static lv_point_t screen_value1_line_1[] = {{0, 40},{160, 40},};
    lv_line_set_points(ui->screen_value1_line_1, screen_value1_line_1, 2);
    lv_obj_set_pos(ui->screen_value1_line_1, 0, 0);
    lv_obj_set_size(ui->screen_value1_line_1, 160, 80);

    //Write style for screen_value1_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_value1_line_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_value1_line_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_value1_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_value1_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_value1_line_2
    ui->screen_value1_line_2 = lv_line_create(ui->screen_value1_cont_3);
    static lv_point_t screen_value1_line_2[] = {{80, 0},{80, 40},};
    lv_line_set_points(ui->screen_value1_line_2, screen_value1_line_2, 2);
    lv_obj_set_pos(ui->screen_value1_line_2, 0, 0);
    lv_obj_set_size(ui->screen_value1_line_2, 160, 80);

    //Write style for screen_value1_line_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_value1_line_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_value1_line_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_value1_line_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_value1_line_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_value1_line_3
    ui->screen_value1_line_3 = lv_line_create(ui->screen_value1_cont_3);
    static lv_point_t screen_value1_line_3[] = {{0, 81},{160, 81},};
    lv_line_set_points(ui->screen_value1_line_3, screen_value1_line_3, 2);
    lv_obj_set_pos(ui->screen_value1_line_3, 0, 0);
    lv_obj_set_size(ui->screen_value1_line_3, 160, 100);

    //Write style for screen_value1_line_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_value1_line_3, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_value1_line_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_value1_line_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_value1_line_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_value1_label_voltage
    ui->screen_value1_label_voltage = lv_label_create(ui->screen_value1_cont_3);
    lv_label_set_text(ui->screen_value1_label_voltage, "0.123V");
    lv_label_set_long_mode(ui->screen_value1_label_voltage, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_value1_label_voltage, 0, 0);
    lv_obj_set_size(ui->screen_value1_label_voltage, 80, 40);

    //Write style for screen_value1_label_voltage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_value1_label_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_value1_label_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_value1_label_voltage, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_value1_label_voltage, &lv_font_Abel_regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_value1_label_voltage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_value1_label_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_value1_label_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_value1_label_voltage, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_value1_label_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_value1_label_voltage, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_value1_label_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_value1_label_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_value1_label_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_value1_label_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_value1_label_current
    ui->screen_value1_label_current = lv_label_create(ui->screen_value1_cont_3);
    lv_label_set_text(ui->screen_value1_label_current, "0.0mA");
    lv_label_set_long_mode(ui->screen_value1_label_current, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_value1_label_current, 80, 0);
    lv_obj_set_size(ui->screen_value1_label_current, 80, 40);

    //Write style for screen_value1_label_current, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_value1_label_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_value1_label_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_value1_label_current, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_value1_label_current, &lv_font_Abel_regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_value1_label_current, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_value1_label_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_value1_label_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_value1_label_current, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_value1_label_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_value1_label_current, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_value1_label_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_value1_label_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_value1_label_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_value1_label_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_value1_label_power
    ui->screen_value1_label_power = lv_label_create(ui->screen_value1_cont_3);
    lv_label_set_text(ui->screen_value1_label_power, "0.000W");
    lv_label_set_long_mode(ui->screen_value1_label_power, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_value1_label_power, 0, 40);
    lv_obj_set_size(ui->screen_value1_label_power, 160, 40);

    //Write style for screen_value1_label_power, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_value1_label_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_value1_label_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_value1_label_power, lv_color_hex(0x00ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_value1_label_power, &lv_font_Abel_regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_value1_label_power, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_value1_label_power, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_value1_label_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_value1_label_power, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_value1_label_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_value1_label_power, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_value1_label_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_value1_label_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_value1_label_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_value1_label_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_value1.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_value1);

    //Init events for screen.
    events_init_screen_value1(ui);
}
