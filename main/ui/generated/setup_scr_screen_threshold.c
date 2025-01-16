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



void setup_scr_screen_threshold(lv_ui *ui)
{
    //Write codes screen_threshold
    ui->screen_threshold = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_threshold, 160, 100);
    lv_obj_set_scrollbar_mode(ui->screen_threshold, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_threshold, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_threshold, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_threshold, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_threshold, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_threshold_line_1
    ui->screen_threshold_line_1 = lv_line_create(ui->screen_threshold);
    static lv_point_t screen_threshold_line_1[] = {{0, 81},{160, 81},};
    lv_line_set_points(ui->screen_threshold_line_1, screen_threshold_line_1, 2);
    lv_obj_set_pos(ui->screen_threshold_line_1, 0, 0);
    lv_obj_set_size(ui->screen_threshold_line_1, 160, 100);

    //Write style for screen_threshold_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_threshold_line_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_threshold_line_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_threshold_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_threshold_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_threshold_label_low
    ui->screen_threshold_label_low = lv_label_create(ui->screen_threshold);
    lv_label_set_text(ui->screen_threshold_label_low, "低压阈值");
    lv_label_set_long_mode(ui->screen_threshold_label_low, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_threshold_label_low, 5, 40);
    lv_obj_set_size(ui->screen_threshold_label_low, 65, 20);

    //Write style for screen_threshold_label_low, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_threshold_label_low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_threshold_label_low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_threshold_label_low, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_threshold_label_low, &lv_font_simkai_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_threshold_label_low, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_threshold_label_low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_threshold_label_low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_threshold_label_low, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_threshold_label_low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_threshold_label_low, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_threshold_label_low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_threshold_label_low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_threshold_label_low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_threshold_label_low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_threshold_label_over
    ui->screen_threshold_label_over = lv_label_create(ui->screen_threshold);
    lv_label_set_text(ui->screen_threshold_label_over, "过压阈值");
    lv_label_set_long_mode(ui->screen_threshold_label_over, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_threshold_label_over, 5, 10);
    lv_obj_set_size(ui->screen_threshold_label_over, 65, 20);

    //Write style for screen_threshold_label_over, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_threshold_label_over, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_threshold_label_over, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_threshold_label_over, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_threshold_label_over, &lv_font_simkai_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_threshold_label_over, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_threshold_label_over, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_threshold_label_over, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_threshold_label_over, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_threshold_label_over, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_threshold_label_over, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_threshold_label_over, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_threshold_label_over, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_threshold_label_over, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_threshold_label_over, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_threshold_spinbox_low
    ui->screen_threshold_spinbox_low = lv_spinbox_create(ui->screen_threshold);
    lv_obj_set_pos(ui->screen_threshold_spinbox_low, 100, 40);
    lv_obj_set_width(ui->screen_threshold_spinbox_low, 30);
    lv_obj_set_height(ui->screen_threshold_spinbox_low, 20);
    lv_spinbox_set_digit_format(ui->screen_threshold_spinbox_low, 3, 2);
    lv_spinbox_set_range(ui->screen_threshold_spinbox_low, -999, 999);
    lv_coord_t screen_threshold_spinbox_low_h = lv_obj_get_height(ui->screen_threshold_spinbox_low);
    ui->screen_threshold_spinbox_low_btn = lv_btn_create(ui->screen_threshold);
    lv_obj_set_size(ui->screen_threshold_spinbox_low_btn, screen_threshold_spinbox_low_h, screen_threshold_spinbox_low_h);
    lv_obj_align_to(ui->screen_threshold_spinbox_low_btn, ui->screen_threshold_spinbox_low, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_img_src(ui->screen_threshold_spinbox_low_btn, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->screen_threshold_spinbox_low_btn, lv_screen_threshold_spinbox_low_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->screen_threshold_spinbox_low_btn_minus = lv_btn_create(ui->screen_threshold);
    lv_obj_set_size(ui->screen_threshold_spinbox_low_btn_minus, screen_threshold_spinbox_low_h, screen_threshold_spinbox_low_h);
    lv_obj_align_to(ui->screen_threshold_spinbox_low_btn_minus, ui->screen_threshold_spinbox_low, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_img_src(ui->screen_threshold_spinbox_low_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->screen_threshold_spinbox_low_btn_minus, lv_screen_threshold_spinbox_low_decrement_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_set_pos(ui->screen_threshold_spinbox_low, 100, 40);

    //Write style for screen_threshold_spinbox_low, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_threshold_spinbox_low, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_threshold_spinbox_low, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_threshold_spinbox_low, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_threshold_spinbox_low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_threshold_spinbox_low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_threshold_spinbox_low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_threshold_spinbox_low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_threshold_spinbox_low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_threshold_spinbox_low, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_threshold_spinbox_low, &lv_font_Abel_regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_threshold_spinbox_low, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_threshold_spinbox_low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_threshold_spinbox_low, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_threshold_spinbox_low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_threshold_spinbox_low, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_threshold_spinbox_low, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_threshold_spinbox_low, &lv_font_Abel_regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_threshold_spinbox_low, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_threshold_spinbox_low, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_threshold_spinbox_low, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_threshold_spinbox_low, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_threshold_spinbox_low_extra_btns_main_default
    static lv_style_t style_screen_threshold_spinbox_low_extra_btns_main_default;
    ui_init_style(&style_screen_threshold_spinbox_low_extra_btns_main_default);

    lv_style_set_text_color(&style_screen_threshold_spinbox_low_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_threshold_spinbox_low_extra_btns_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_threshold_spinbox_low_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_screen_threshold_spinbox_low_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_threshold_spinbox_low_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_threshold_spinbox_low_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_threshold_spinbox_low_extra_btns_main_default, 0);
    lv_style_set_radius(&style_screen_threshold_spinbox_low_extra_btns_main_default, 4);
    lv_style_set_shadow_width(&style_screen_threshold_spinbox_low_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_threshold_spinbox_low_btn, &style_screen_threshold_spinbox_low_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_threshold_spinbox_low_btn_minus, &style_screen_threshold_spinbox_low_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_threshold_spinbox_over
    ui->screen_threshold_spinbox_over = lv_spinbox_create(ui->screen_threshold);
    lv_obj_set_pos(ui->screen_threshold_spinbox_over, 100, 10);
    lv_obj_set_width(ui->screen_threshold_spinbox_over, 30);
    lv_obj_set_height(ui->screen_threshold_spinbox_over, 20);
    lv_spinbox_set_digit_format(ui->screen_threshold_spinbox_over, 3, 2);
    lv_spinbox_set_range(ui->screen_threshold_spinbox_over, -999, 999);
    lv_coord_t screen_threshold_spinbox_over_h = lv_obj_get_height(ui->screen_threshold_spinbox_over);
    ui->screen_threshold_spinbox_over_btn = lv_btn_create(ui->screen_threshold);
    lv_obj_set_size(ui->screen_threshold_spinbox_over_btn, screen_threshold_spinbox_over_h, screen_threshold_spinbox_over_h);
    lv_obj_align_to(ui->screen_threshold_spinbox_over_btn, ui->screen_threshold_spinbox_over, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_img_src(ui->screen_threshold_spinbox_over_btn, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->screen_threshold_spinbox_over_btn, lv_screen_threshold_spinbox_over_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->screen_threshold_spinbox_over_btn_minus = lv_btn_create(ui->screen_threshold);
    lv_obj_set_size(ui->screen_threshold_spinbox_over_btn_minus, screen_threshold_spinbox_over_h, screen_threshold_spinbox_over_h);
    lv_obj_align_to(ui->screen_threshold_spinbox_over_btn_minus, ui->screen_threshold_spinbox_over, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_img_src(ui->screen_threshold_spinbox_over_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->screen_threshold_spinbox_over_btn_minus, lv_screen_threshold_spinbox_over_decrement_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_set_pos(ui->screen_threshold_spinbox_over, 100, 10);

    //Write style for screen_threshold_spinbox_over, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_threshold_spinbox_over, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_threshold_spinbox_over, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_threshold_spinbox_over, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_threshold_spinbox_over, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_threshold_spinbox_over, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_threshold_spinbox_over, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_threshold_spinbox_over, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_threshold_spinbox_over, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_threshold_spinbox_over, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_threshold_spinbox_over, &lv_font_Abel_regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_threshold_spinbox_over, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_threshold_spinbox_over, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_threshold_spinbox_over, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_threshold_spinbox_over, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_threshold_spinbox_over, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_threshold_spinbox_over, lv_color_hex(0x000000), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_threshold_spinbox_over, &lv_font_Abel_regular_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_threshold_spinbox_over, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_threshold_spinbox_over, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_threshold_spinbox_over, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_threshold_spinbox_over, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_threshold_spinbox_over_extra_btns_main_default
    static lv_style_t style_screen_threshold_spinbox_over_extra_btns_main_default;
    ui_init_style(&style_screen_threshold_spinbox_over_extra_btns_main_default);

    lv_style_set_text_color(&style_screen_threshold_spinbox_over_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_threshold_spinbox_over_extra_btns_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_threshold_spinbox_over_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_screen_threshold_spinbox_over_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_threshold_spinbox_over_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_threshold_spinbox_over_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_threshold_spinbox_over_extra_btns_main_default, 0);
    lv_style_set_radius(&style_screen_threshold_spinbox_over_extra_btns_main_default, 4);
    lv_style_set_shadow_width(&style_screen_threshold_spinbox_over_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_threshold_spinbox_over_btn, &style_screen_threshold_spinbox_over_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_threshold_spinbox_over_btn_minus, &style_screen_threshold_spinbox_over_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_threshold.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_threshold);

    //Init events for screen.
    events_init_screen_threshold(ui);
}
