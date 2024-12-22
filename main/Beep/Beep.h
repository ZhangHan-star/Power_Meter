/*
 * @Author: 星痕迷鹿 1959171224@qq.com
 * @Date: 2024-09-17 10:58:07
 * @LastEditors: 星痕迷鹿 1959171224@qq.com
 * @LastEditTime: 2024-09-17 14:53:30
 * @FilePath: \Power_Meter\main\Beep\Beep.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _BEEP_H_
#define _BEEP_H_

#include "driver/ledc.h"

#define LEDC_TIMER              LEDC_TIMER_0        //定时器0
#define LEDC_MODE               LEDC_LOW_SPEED_MODE //低速模式
#define LEDC_OUTPUT_IO          (5)                // 定义输出GPIO为GPIO5
#define LEDC_CHANNEL            LEDC_CHANNEL_0      // 使用LEDC的通道0
#define LEDC_DUTY_RES           LEDC_TIMER_13_BIT   // LEDC分辨率设置为13位
#define LEDC_DUTY               (4095)              // 设置占空比为50%。 ((2的13次方) - 1) * 50% = 4095
#define LEDC_FREQUENCY          (4000)              // 频率单位是Hz。设置频率为4000 Hz

/**
 * @函数说明        LEDC功能初始化
 * @传入参数        无
 * @函数返回        无
 * @备    注        PWM频率越高，可用的占空比分辨率越低
 */
void BeepInitConfig(void);

void Beep_ON(void);
void Beep_OFF(void);

#endif // !_BEEP_H_
