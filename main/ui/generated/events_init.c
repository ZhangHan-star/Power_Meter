/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#include "custom.h"
static lv_timer_t  * value1task_meter;
#include "custom.h"
static lv_timer_t  * value2task_meter;
#include "custom.h"
static lv_timer_t  * ChartShow;
#include "custom.h"
static lv_timer_t  * ChartWShow;

static void screen_value1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_waveVA, guider_ui.screen_waveVA_del, &guider_ui.screen_value1_del, setup_scr_screen_waveVA, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    case LV_EVENT_SCREEN_LOADED:
    {
        value1task_meter = lv_timer_create(VAP_datashow_timer_cb, 100, &guider_ui);

        break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        lv_timer_del(value1task_meter);
        break;
    }
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_value2, guider_ui.screen_value2_del, &guider_ui.screen_value1_del, setup_scr_screen_value2, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_value1 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_value1, screen_value1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_value2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_waveVA, guider_ui.screen_waveVA_del, &guider_ui.screen_value2_del, setup_scr_screen_waveVA, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_value1, guider_ui.screen_value1_del, &guider_ui.screen_value2_del, setup_scr_screen_value1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    case LV_EVENT_SCREEN_LOADED:
    {
        value2task_meter = lv_timer_create(VAP2_datashow_timer_cb, 100, &guider_ui);

        break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        lv_timer_del(value2task_meter);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_value2 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_value2, screen_value2_event_handler, LV_EVENT_ALL, ui);
}

static void screen_waveVA_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_threshold, guider_ui.screen_threshold_del, &guider_ui.screen_waveVA_del, setup_scr_screen_threshold, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    case LV_EVENT_SCREEN_LOADED:
    {
        ChartShow = lv_timer_create(VAP_Chartshow_timer_cb, 100, &guider_ui);
        break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        lv_timer_del(ChartShow);
        break;
    }
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_waveW, guider_ui.screen_waveW_del, &guider_ui.screen_waveVA_del, setup_scr_screen_waveW, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_waveVA (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_waveVA, screen_waveVA_event_handler, LV_EVENT_ALL, ui);
}

static void screen_waveW_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_threshold, guider_ui.screen_threshold_del, &guider_ui.screen_waveW_del, setup_scr_screen_threshold, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_waveVA, guider_ui.screen_waveVA_del, &guider_ui.screen_waveW_del, setup_scr_screen_waveVA, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    case LV_EVENT_SCREEN_LOADED:
    {
        ChartWShow = lv_timer_create(VAPW_Chartshow_timer_cb, 100, &guider_ui);
        break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        lv_timer_del(ChartWShow);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_waveW (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_waveW, screen_waveW_event_handler, LV_EVENT_ALL, ui);
}

static void screen_threshold_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_value1, guider_ui.screen_value1_del, &guider_ui.screen_threshold_del, setup_scr_screen_value1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_threshold (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_threshold, screen_threshold_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
