/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#include "ina226.h"
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
// static int32_t speed = 39;
// static bool is_increase = true;
// static int32_t power = 3000;
// static float trip = 12.4;
// static int32_t ODO = 288;
/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

void VAP_datashow_timer_cb(lv_timer_t *t)
{
    lv_ui *ui = t->user_data;
    if (Voltage<10.0f)
    {
        lv_label_set_text_fmt(ui->screen_value1_label_voltage, "%.3fV", Voltage);//set Voltage value
    } else if (Voltage>=10.0f && Voltage<100.0f)
    {
        lv_label_set_text_fmt(ui->screen_value1_label_voltage, "%.2fV", Voltage);//set Voltage value
    }

    if (Current<10.0f)
    {
        lv_label_set_text_fmt(ui->screen_value1_label_current, "%.1fmA", Current);
    } else if (Current>=10.0f && Current<100.0f)
    {
        lv_label_set_text_fmt(ui->screen_value1_label_current, "%.1fmA", Current);
    } else if (Current>=100.0f && Current<1000.0f)
    {
        lv_label_set_text_fmt(ui->screen_value1_label_current, "%.0fmA", Current);
    } else if (Current>=1000.0f && Current<10000.0f)
    {
        lv_label_set_text_fmt(ui->screen_value1_label_current, "%.2fA", Current/1000.0f);
    } else if (Current>=10000.0f && Current<100000.0f)
    {
        lv_label_set_text_fmt(ui->screen_value1_label_current, "%.1fA", Current/1000.0f);
    }

    lv_label_set_text_fmt(ui->screen_value1_label_power, "%.3fW", Power/1000.0f);

}

void VAP2_datashow_timer_cb(lv_timer_t *t)
{
    lv_ui *ui = t->user_data;
    if (Voltage<10.0f)
    {
        lv_label_set_text_fmt(ui->screen_value2_label_voltage, "电压:%.3fV", Voltage);//set Voltage value
    } else if (Voltage>=10.0f && Voltage<100.0f)
    {
        lv_label_set_text_fmt(ui->screen_value2_label_voltage, "电压:%.2fV", Voltage);//set Voltage value
    }

    if (Current<10.0f)
    {
        lv_label_set_text_fmt(ui->screen_value2_label_current, "电流:%.1fmA", Current);
    } else if (Current>=10.0f && Current<100.0f)
    {
        lv_label_set_text_fmt(ui->screen_value2_label_current, "电流:%.1fmA", Current);
    } else if (Current>=100.0f && Current<1000.0f)
    {
        lv_label_set_text_fmt(ui->screen_value2_label_current, "电流:%.0fmA", Current);
    } else if (Current>=1000.0f && Current<10000.0f)
    {
        lv_label_set_text_fmt(ui->screen_value2_label_current, "电流:%.2fA", Current/1000.0f);
    } else if (Current>=10000.0f && Current<100000.0f)
    {
        lv_label_set_text_fmt(ui->screen_value2_label_current, "电流:%.1fA", Current/1000.0f);
    }

    lv_label_set_text_fmt(ui->screen_value2_label_power, "功率:%.3fW", Power/1000.0f);

}

int16_t ShowVoltageData,LastVoltageData;
int16_t ShowCurrentData,LastCurrentData;
int16_t VoltageRange=50,CurrentRange=10;
/**
 * @brief 图表数据显示
 *
 * @param t
 */
void VAP_Chartshow_timer_cb(lv_timer_t *t)
{
    lv_ui *ui = t->user_data;

    LastVoltageData = ShowVoltageData;
    ShowVoltageData = (int16_t)((float)Voltage*10.0f);//设计图表显示的最小分辨率为0.1V
    LastCurrentData = ShowCurrentData;
    ShowCurrentData = (int16_t)((float)Current);
    //将数据传到图表
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_0, ShowVoltageData);
    lv_chart_set_next_value(ui->screen_waveVA_chart_1, ui->screen_waveVA_chart_1_1, ShowCurrentData);

    //在图表下方显示电压
    if (Voltage<10.0f)
    {
        lv_label_set_text_fmt(ui->screen_waveVA_label_Voltage, "%.3fV", Voltage);//set Voltage value
    } else if (Voltage>=10.0f && Voltage<100.0f)
    {
        lv_label_set_text_fmt(ui->screen_waveVA_label_Voltage, "%.2fV", Voltage);//set Voltage value
        // lv_chart_set_range(ui->screen_waveVA_chart_1, LV_CHART_AXIS_PRIMARY_Y, 200, 300);
    }

    //设置电压显示量程(这里是放大后的数据)
    if (ShowVoltageData<=100 &&ShowVoltageData>50 && LastVoltageData<=50)
    {
        lv_chart_set_range(ui->screen_waveVA_chart_1, LV_CHART_AXIS_PRIMARY_Y, 0, 100);
        VoltageRange = 100;
    }
    if (ShowVoltageData>100 && LastVoltageData<=100)
    {
        lv_chart_set_range(ui->screen_waveVA_chart_1, LV_CHART_AXIS_PRIMARY_Y, 0, 300);
        VoltageRange = 300;
    }
    if (ShowVoltageData<80 && LastVoltageData>=80)
    {
        lv_chart_set_range(ui->screen_waveVA_chart_1, LV_CHART_AXIS_PRIMARY_Y, 0, 100);
        VoltageRange = 100;
    }
    if (ShowVoltageData<33 && LastVoltageData>=33)
    {
        lv_chart_set_range(ui->screen_waveVA_chart_1, LV_CHART_AXIS_PRIMARY_Y, 0, 50);
        VoltageRange = 50;
    }



    //在图表下方显示电流
    if (Current<10.0f)
    {
        lv_label_set_text_fmt(ui->screen_waveVA_label_Current, "%.1fmA", Current);
    } else if (Current>=10.0f && Current<100.0f)
    {
        lv_label_set_text_fmt(ui->screen_waveVA_label_Current, "%.1fmA", Current);
    } else if (Current>=100.0f && Current<1000.0f)
    {
        lv_label_set_text_fmt(ui->screen_waveVA_label_Current, "%.0fmA", Current);
    } else if (Current>=1000.0f && Current<10000.0f)
    {
        lv_label_set_text_fmt(ui->screen_waveVA_label_Current, "%.2fA", Current/1000.0f);
    } else if (Current>=10000.0f && Current<100000.0f)
    {
        lv_label_set_text_fmt(ui->screen_waveVA_label_Current, "%.1fA", Current/1000.0f);
    }

    //设置电流显示量程
    if (ShowCurrentData>10 && LastCurrentData<=10)
    {
        lv_chart_set_range(ui->screen_waveVA_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 100);
        CurrentRange = 100;
    }
    if (ShowCurrentData>100 && LastCurrentData<=100)
    {
        lv_chart_set_range(ui->screen_waveVA_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 1000);
        CurrentRange = 1000;
    }
    if (ShowCurrentData>1000 && LastCurrentData<=1000)
    {
        lv_chart_set_range(ui->screen_waveVA_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 10000);
        CurrentRange = 10000;
    }
    if (ShowCurrentData>10000 && LastCurrentData<=20000)
    {
        lv_chart_set_range(ui->screen_waveVA_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 20000);
        CurrentRange = 20000;
    }
    if (ShowCurrentData<8000 && LastCurrentData>=8000)
    {
        lv_chart_set_range(ui->screen_waveVA_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 10000);
        CurrentRange = 10000;
    }
    if (ShowCurrentData<800 && LastCurrentData>=800)
    {
        lv_chart_set_range(ui->screen_waveVA_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 1000);
        CurrentRange = 1000;
    }
    if (ShowCurrentData<80 && LastCurrentData>=80)
    {
        lv_chart_set_range(ui->screen_waveVA_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 100);
        CurrentRange = 100;
    }
    if (ShowCurrentData<10 && LastCurrentData>=10)
    {
        lv_chart_set_range(ui->screen_waveVA_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 10);
        CurrentRange = 10;
    }

}

/**
 * @brief 图表数据显示
 *
 * @param t
 */
int16_t ShowPowerData,LastPowerData;
int16_t PowerRange=50;
void VAPW_Chartshow_timer_cb(lv_timer_t *t)
{
    lv_ui *ui = t->user_data;
    LastPowerData = ShowPowerData;
    ShowPowerData = (int16_t)((float)Power/100.0f);

    lv_chart_set_next_value(ui->screen_waveW_chart_1, ui->screen_waveW_chart_1_0, (int16_t)Power/10.0f);
    lv_label_set_text_fmt(ui->screen_waveW_label_power, "%.3fW", Power/1000.0f);

    //设置功率显示量程
    if (ShowPowerData>1 && LastPowerData<=1)
    {
        lv_chart_set_range(ui->screen_waveW_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 10*100);
        PowerRange = 10;
    }
    if (ShowPowerData>10 && LastPowerData<=10)
    {
        lv_chart_set_range(ui->screen_waveW_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 50*100);
        PowerRange = 50;
    }
    if (ShowPowerData>50 && LastPowerData<=50)
    {
        lv_chart_set_range(ui->screen_waveW_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 100*100);
        PowerRange = 100;
    }
    if (ShowPowerData>100 && LastPowerData<=100)
    {
        lv_chart_set_range(ui->screen_waveW_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 300*100);
        PowerRange = 300;
    }
    if (ShowPowerData<80 && LastPowerData>=80)
    {
        lv_chart_set_range(ui->screen_waveW_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 100*100);
        PowerRange = 100;
    }
    if (ShowPowerData<33 && LastPowerData>=33)
    {
        lv_chart_set_range(ui->screen_waveW_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 50*100);
        PowerRange = 50;
    }
    if (ShowPowerData<8 && LastPowerData>=8)
    {
        lv_chart_set_range(ui->screen_waveW_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 10*100);
        PowerRange = 10;
    }
    if (ShowPowerData<0.8 && LastPowerData>=8)
    {
        lv_chart_set_range(ui->screen_waveW_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 8*100);
        PowerRange = 1;
    }
}
