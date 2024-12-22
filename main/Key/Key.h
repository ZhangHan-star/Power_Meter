#ifndef _KEY_H_
#define _KEY_H_

#include "driver/gpio.h"
#include "hal/gpio_types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void Key_Init(void);
bool GetKeyValue(uint8_t Key_num);

#endif
