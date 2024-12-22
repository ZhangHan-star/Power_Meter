#include "Key.h"
#include "driver/gpio.h"

#define Key_Right 9

void Key_Init(void)
{
   //初始化GPIO配置结构 为 零
    gpio_config_t io_conf = {};
    //失能中断
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //设置输入引脚
    io_conf.pin_bit_mask = (1ULL<<Key_Right);
    //设置输入模式
    io_conf.mode = GPIO_MODE_INPUT;
    //使能上拉电阻
    io_conf.pull_up_en = 1;
    //失能下拉电阻
    io_conf.pull_down_en = 0;
    ////用给定的设置配置GPIO
    gpio_config(&io_conf);
}

bool GetKeyValue(uint8_t Key_num)
{
    return gpio_get_level(Key_num);
}
