/*
 * @Author: 星痕迷鹿 1959171224@qq.com
 * @Date: 2024-09-17 10:57:57
 * @LastEditors: 星痕迷鹿 1959171224@qq.com
 * @LastEditTime: 2024-09-17 16:56:45
 * @FilePath: \Power_Meter\main\Beep\Beep.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


#include "Beep.h"
#include "driver/gpio.h"

/**
 * @函数说明        LEDC功能初始化
 * @传入参数        无
 * @函数返回        无
 * @备    注        PWM频率越高，可用的占空比分辨率越低
 */
void BeepInitConfig(void)
{
    // 准备并应用led PWM定时器配置
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_MODE,          //LED模式 低速模式
        .timer_num        = LEDC_TIMER,         //通道的定时器源    定时器0
        .duty_resolution  = LEDC_DUTY_RES,      //将占空比分辨率设置为13位
        .freq_hz          = LEDC_FREQUENCY,     // 设置输出频率为4 kHz
        .clk_cfg          = LEDC_AUTO_CLK       //设置LEDPWM的时钟来源 为自动
        //LEDC_AUTO_CLK = 启动定时器时，将根据给定的分辨率和占空率参数自动选择led源时钟
    };
    ledc_timer_config(&ledc_timer);

    // 准备并应用LEDC PWM通道配置
    ledc_channel_config_t ledc_channel = {
        .speed_mode     = LEDC_MODE,            //LED模式 低速模式
        .channel        = LEDC_CHANNEL,         //通道0
        .timer_sel      = LEDC_TIMER,           //定时器源 定时器0
        .intr_type      = LEDC_INTR_DISABLE,    //关闭中断
        .gpio_num       = LEDC_OUTPUT_IO,       //输出引脚  GPIO5
        .duty           = 0,                    // 设置占空比为0
        .hpoint         = 0
    };
    ledc_channel_config(&ledc_channel);
}


void Beep_ON(void)
{
  // ledc_fade_func_install(ESP_INTR_FLAG_LEVEL1);
  // ledc_set_duty_and_update(LEDC_MODE, LEDC_CHANNEL, LEDC_DUTY, 0);
  // 设置占空比为50
  ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, LEDC_DUTY);
  // 更新通道占空比
  ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);
}

void Beep_OFF(void)
{
  // ledc_fade_func_install(ESP_INTR_FLAG_LEVEL1);
  // ledc_set_duty_and_update(LEDC_MODE, LEDC_CHANNEL, 0, 0);
  // 设置占空比为0
  ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, 0);
  // 更新通道占空比
  ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);
}
