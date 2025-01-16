#include "Key.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "freertos/queue.h"


void Key_Init(void)
{
    //初始化GPIO配置结构 为 零
    gpio_config_t io_conf = {};
    //失能中断
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //设置输入模式
    io_conf.mode = GPIO_MODE_INPUT;
    //使能上拉电阻
    io_conf.pull_up_en = 1;
    //失能下拉电阻
    io_conf.pull_down_en = 0;
    //设置输入引脚
    io_conf.pin_bit_mask = (1ULL << Key_Right);
    ////用给定的设置配置GPIO
    gpio_config(&io_conf);
    //设置输入引脚
    io_conf.pin_bit_mask = (1ULL << Key_Left);
    ////用给定的设置配置GPIO
    gpio_config(&io_conf);

}

bool GetKeyValue(uint8_t Key_num)
{
    return !gpio_get_level(Key_num);
}



// static KeyState key_state = {false, 0, false};

uint8_t Key_Pressed_handle(KeyState* key_state, bool isKeyPressed) {
    uint8_t keyStatus = KEY_NONE;
    // 检查按键状态变化
    if (key_state->last_value != isKeyPressed) {
        if (isKeyPressed) {  // 按下
            key_state->flag = true;
        }
        else {  // 松开
            if (key_state->flag) {
                if (key_state->count < 50) {
                    keyStatus = KEY_Short;
                }
                else if (key_state->count >= 50) {
                    keyStatus = KEY_Long;
                }
                key_state->flag = false;
                key_state->count = 0;
            }
        }
    }
    else if (isKeyPressed && key_state->flag && key_state->count >= 100) {
        keyStatus = KEY_Continue;
    }

    // 更新按键状态
    if (key_state->flag) {
        if (key_state->count < UINT16_MAX - 1) {  // 防止计数器溢出
            key_state->count++;
        }
    }
    key_state->last_value = isKeyPressed;
    return keyStatus;
}

uint8_t RightKeyValue = 0;
uint8_t LeftKeyValue = 0;
void ChackKey(void* arg)
{
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = pdMS_TO_TICKS(10);  // 10毫秒
    xLastWakeTime = xTaskGetTickCount();

    extern QueueHandle_t beep_evt_queue;


    static KeyState RightKey_state = { false, 0, false };
    static KeyState LeftKey_state = { false, 0, false };

    ESP_LOGI("UserPrintf:", "ChackKey Start!");
    for (;;) {
        // RightKeyValue = Key_Pressed_handle(&RightKey_state,GetKeyValue(9));
        // if (RightKeyValue!=0)
        // {
        //     ESP_LOGI("UserPrintf:", "lastvalue:%d", RightKeyValue);
        // }
        // LeftKeyValue = Key_Pressed_handle(&LeftKey_state,GetKeyValue(8));
        // if (LeftKeyValue!=0)
        // {
        //     ESP_LOGI("UserPrintf:", "lastvalue:%d", LeftKeyValue);
        // }

        RightKeyValue = Key_Pressed_handle(&RightKey_state, GetKeyValue(9));
        LeftKeyValue = Key_Pressed_handle(&LeftKey_state, GetKeyValue(8));
        lv_obj_t* nowScr = lv_scr_act();
        extern lv_ui guider_ui;
        if (nowScr == guider_ui.screen_value1)
        {
            if (RightKeyValue == KEY_Short)
            {
                lv_event_send(nowScr, LV_EVENT_PRESSED, NULL);
            }
            else if (LeftKeyValue == KEY_Short)
            {
                lv_event_send(nowScr, LV_EVENT_CLICKED, NULL);
            }
        }
        else if (nowScr == guider_ui.screen_value2)
        {
            if (RightKeyValue == KEY_Short)
            {
                lv_event_send(nowScr, LV_EVENT_PRESSED, NULL);
            }
            else if (LeftKeyValue == KEY_Short)
            {
                lv_event_send(nowScr, LV_EVENT_CLICKED, NULL);
            }
        }
        else if (nowScr == guider_ui.screen_waveVA)
        {
            if (RightKeyValue == KEY_Short)
            {
                lv_event_send(nowScr, LV_EVENT_PRESSED, NULL);
            }
            else if (LeftKeyValue == KEY_Short)
            {
                lv_event_send(nowScr, LV_EVENT_CLICKED, NULL);
            }
        }
        else if (nowScr == guider_ui.screen_waveW)
        {
            if (RightKeyValue == KEY_Short)
            {
                lv_event_send(nowScr, LV_EVENT_PRESSED, NULL);
            }
            else if (LeftKeyValue == KEY_Short)
            {
                lv_event_send(nowScr, LV_EVENT_CLICKED, NULL);
            }

        }
        else if (nowScr == guider_ui.screen_threshold)
        {
            if (RightKeyValue == KEY_Short)
            {
                lv_event_send(nowScr, LV_EVENT_PRESSED, NULL);
            }
        }
        float nowvalue = 1;

        if (RightKeyValue != 0 || LeftKeyValue != 0)xQueueSend(beep_evt_queue, &nowvalue, portMAX_DELAY);
        xTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}
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
