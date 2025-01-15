/*
 * @Author: 星痕迷鹿 1959171224@qq.com
 * @Date: 2024-08-09 20:16:07
 * @LastEditors: 星痕迷鹿 1959171224@qq.com
 * @LastEditTime: 2024-09-18 22:28:51
 * @FilePath: \Power_Meter\main\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_chip_info.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "driver/gpio.h"
#include <stdio.h>
#include "esp_system.h"
#include "lvgl.h"
#include "lv_demos.h"
#include "lvgl_helpers.h"
#include "nvs_flash.h"

#include "led_strip/include/led_strip.h"

#include "IIC.h"
#include "ina226.h"
#include "Key.h"
#include "Beep.h"
#include "TCP.h"
#include "WS2812b.h"
#include "porting/lv_port_indev.h"

#include "gui_guider.h"
#include "custom.h"

#include <unistd.h>

#define TAG "main"


void lv_tick_task(void *arg)
{
    lv_tick_inc(1);
}


lv_ui guider_ui;

static void ChackKey(void *arg);
static void Get_Ina226_Data(void *arg);
static void Beep_Task(void *arg);


static QueueHandle_t alarm_evt_queue ;
static QueueHandle_t beep_evt_queue ;

void app_main(void)
{
    vTaskDelay(pdMS_TO_TICKS(500));
    //初始化FLASH
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    Key_Init();
    wifi_init_softap();
    ESP_LOGI("UserPrintf:", "Ina226");
    ina226_init();
    ESP_LOGI("UserPrintf:", "Ina226_Init");
    /* Initialize SPI or I2C bus used by the drivers */
    lvgl_driver_init();
    lv_port_indev_init();
    ESP_LOGI("UserPrintf:", "LVGL_Init!");
    lv_init();
    lv_color_t *buf1 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf1 != NULL);
    static lv_color_t *buf2 = NULL;

    static lv_disp_draw_buf_t disp_buf;

    uint32_t size_in_px = DISP_BUF_SIZE;
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, size_in_px);
    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = LV_HOR_RES_MAX;
    disp_drv.ver_res = LV_VER_RES_MAX;
    disp_drv.flush_cb = disp_driver_flush;
    disp_drv.draw_buf = &disp_buf;
    lv_disp_drv_register(&disp_drv);

    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &lv_tick_task,
        .name = "periodic_gui"};
    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, 1 * 1000));

    //创建一个队列来处理告警事件
    alarm_evt_queue = xQueueCreate(5, sizeof(uint32_t));
    beep_evt_queue = xQueueCreate(5, sizeof(uint32_t));

    //创建一个按键检测任务
    xTaskCreate(ChackKey,        //任务函数
                "ChackKey_task",      //任务名字
                1024,                           //任务堆栈
                NULL,                           //传递给任务函数的参数
                6,                             //任务优先级
                NULL                            //任务句柄
     );
    //创建一个ina226读取任务
    xTaskCreate(Get_Ina226_Data,        //任务函数
                "Get_INA226_task",      //任务名字
                2048,                           //任务堆栈
                NULL,                           //传递给任务函数的参数
                5,                             //任务优先级
                NULL                            //任务句柄
     );
     //创建一个蜂鸣器任务
     xTaskCreate(Beep_Task,        //任务函数
                "Beep_Task",      //任务名字
                1024,                           //任务堆栈
                NULL,                           //传递给任务函数的参数
                6,                             //任务优先级
                NULL                            //任务句柄
     );
     //创建一个WS2812b显示任务
    //  xTaskCreate(LED_Task,        //任务函数
    //             "WS2812b_Task",      //任务名字
    //             512,                           //任务堆栈
    //             NULL,                           //传递给任务函数的参数
    //             6,                             //任务优先级
    //             NULL                            //任务句柄
    //  );

    // lvgl demo演示
    // lv_demo_widgets();
    // lv_demo_benchmark();

    setup_ui(&guider_ui);


    while (1)
    {
        /* Delay 1 tick assumes FreeRTOS tick is 10ms */
        vTaskDelay(pdMS_TO_TICKS(10));
        lv_task_handler();
    }
}




static void ChackKey(void *arg)
{
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = pdMS_TO_TICKS(10);  // 10毫秒
    xLastWakeTime = xTaskGetTickCount();

    uint8_t RightKeyValue = 0;
    uint8_t LeftKeyValue = 0;
    static KeyState RightKey_state = {false, 0, false};
    static KeyState LeftKey_state = {false, 0, false};

    ESP_LOGI("UserPrintf:", "ChackKey Start!");
    for (;;){
        // 获取键对应的值
        // lastvalue = nowvalue;
        // nowvalue = GetKeyValue(9);

        // if ((nowvalue != lastvalue)&& nowvalue != 1)
        // {
        //     lv_obj_t *nowScr=lv_scr_act();
        //     lv_event_send(nowScr, LV_EVENT_PRESSING, NULL);//手动发送LV_EVENT_CANCEL事件
        //     xQueueSend(beep_evt_queue, &nowvalue, portMAX_DELAY);
        //     vTaskDelay(pdMS_TO_TICKS(200));
        // }
        RightKeyValue = Key_Pressed_handle(&RightKey_state,GetKeyValue(9));
        if (RightKeyValue!=0)
        {
            ESP_LOGI("UserPrintf:", "lastvalue:%d", RightKeyValue);
        }
        LeftKeyValue = Key_Pressed_handle(&LeftKey_state,GetKeyValue(8));
        if (LeftKeyValue!=0)
        {
            ESP_LOGI("UserPrintf:", "lastvalue:%d", LeftKeyValue);
        }

        xTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}

static void Get_Ina226_Data(void *arg)
{
    ESP_LOGI("UserPrintf:", "Get_Ina226_Data Start!");
    for(;;){
        ina226_read_data(&Voltage, &Current, &Power);
        // ESP_LOGI("UserPrintf:", "Voltage:%f,Current:%f,Power:%f", Voltage, Current, Power);
        if (Voltage > 28.0f)
        {
            // xQueueSend(alarm_evt_queue, &Voltage, portMAX_DELAY);
        }

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}


static void Beep_Task(void *arg)
{
    BeepInitConfig();
    ESP_LOGI("UserPrintf:", "Beep_Task Start!");
    Beep_ON();
    vTaskDelay(pdMS_TO_TICKS(250));
    Beep_OFF();

    float temp;
    for(;;)
    {
        if (xQueueReceive(beep_evt_queue, &temp, 20 / portTICK_PERIOD_MS)){
            Beep_ON();
        }else{
            Beep_OFF();
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
