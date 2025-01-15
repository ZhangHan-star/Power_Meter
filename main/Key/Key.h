#ifndef _KEY_H_
#define _KEY_H_

#include "driver/gpio.h"
#include "hal/gpio_types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//按键引脚定义
#define Key_Right 9
#define Key_Left  8
//按键状态定义
#define KEY_NONE 0
#define KEY_Short 1
#define KEY_Long 2
#define KEY_Continue 3

// 定义一个结构体来封装按键状态
typedef struct {
  bool last_value;
  uint16_t count;
  bool flag;
} KeyState;

void Key_Init(void);
bool GetKeyValue(uint8_t Key_num);
uint8_t Key_Pressed_handle(KeyState* key_state, bool isKeyPressed);

#endif
