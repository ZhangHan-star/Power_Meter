#include "Key.h"
#include "driver/gpio.h"



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
