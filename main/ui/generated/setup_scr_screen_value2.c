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



void setup_scr_screen_value2(lv_ui *ui)
{
    //Write codes screen_value2
    ui->screen_value2 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_value2, 160, 100);
    lv_obj_set_scrollbar_mode(ui->screen_value2, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_value2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_value2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_value2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_value2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_value2_line_2
    ui->screen_value2_line_2 = lv_line_create(ui->screen_value2);
    static lv_point_t screen_value2_line_2[] = {{130, 0},{130, 81},};
    lv_line_set_points(ui->screen_value2_line_2, screen_value2_line_2, 2);
    lv_obj_set_pos(ui->screen_value2_line_2, 0, 0);
    lv_obj_set_size(ui->screen_value2_line_2, 160, 100);

    //Write style for screen_value2_line_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_value2_line_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_value2_line_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_value2_line_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_value2_line_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_value2_line_1
    ui->screen_value2_line_1 = lv_line_create(ui->screen_value2);
    static lv_point_t screen_value2_line_1[] = {{0, 81},{160, 81},};
    lv_line_set_points(ui->screen_value2_line_1, screen_value2_line_1, 2);
    lv_obj_set_pos(ui->screen_value2_line_1, 0, 0);
    lv_obj_set_size(ui->screen_value2_line_1, 160, 100);

    //Write style for screen_value2_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_value2_line_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_value2_line_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_value2_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_value2_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_value2_label_1
    ui->screen_value2_label_1 = lv_label_create(ui->screen_value2);
    lv_label_set_text(ui->screen_value2_label_1, "电压：0.00V");
    lv_label_set_long_mode(ui->screen_value2_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_value2_label_1, 10, 10);
    lv_obj_set_size(ui->screen_value2_label_1, 110, 20);

    //Write style for screen_value2_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_value2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_value2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_value2_label_1, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_value2_label_1, &lv_font_simkai_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_value2_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_value2_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_value2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_value2_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_value2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_value2_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_value2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_value2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_value2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_value2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_value2_label_2
    ui->screen_value2_label_2 = lv_label_create(ui->screen_value2);
    lv_label_set_text(ui->screen_value2_label_2, "电流：0.0mA");
    lv_label_set_long_mode(ui->screen_value2_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_value2_label_2, 10, 30);
    lv_obj_set_size(ui->screen_value2_label_2, 110, 20);

    //Write style for screen_value2_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_value2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_value2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_value2_label_2, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_value2_label_2, &lv_font_simkai_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_value2_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_value2_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_value2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_value2_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_value2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_value2_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_value2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_value2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_value2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_value2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_value2_label_3
    ui->screen_value2_label_3 = lv_label_create(ui->screen_value2);
    lv_label_set_text(ui->screen_value2_label_3, "功率：0.00W");
    lv_label_set_long_mode(ui->screen_value2_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_value2_label_3, 10, 50);
    lv_obj_set_size(ui->screen_value2_label_3, 110, 20);

    //Write style for screen_value2_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_value2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_value2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_value2_label_3, lv_color_hex(0x00ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_value2_label_3, &lv_font_simkai_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_value2_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_value2_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_value2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_value2_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_value2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_value2_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_value2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_value2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_value2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_value2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_value2.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_value2);

}
