/*
 * @Author: 星痕迷鹿 1959171224@qq.com
 * @Date: 2024-09-12 19:30:18
 * @LastEditors: 星痕迷鹿 1959171224@qq.com
 * @LastEditTime: 2024-09-14 19:46:53
 * @FilePath: \Power_Meter\main\Ina226\ina226.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <ina226.h>
#include <IIC.h>
#include "driver/i2c.h"
#include "esp_log.h"


float Voltage = 0;
float Current = 0;
float Power = 0;


esp_err_t ina226_write_reg(unsigned char reg, unsigned short data)
{
  esp_err_t err;
  i2c_cmd_handle_t cmd = i2c_cmd_link_create();
  err = i2c_master_start(cmd);
  if (err != ESP_OK)
  {
    ESP_DRAM_LOGE("ina226_write_reg", "i2c_master_start error:%x", err);
    return err;
  }
  err = i2c_master_write_byte(cmd, ( INA226_ADDR << 1 ) | I2C_MASTER_WRITE, 1 );
  if (err != ESP_OK)
  {
    ESP_DRAM_LOGE("ina226_write_reg", "i2c_master_write_byte ina_addr error:%x", err);
    return err;
  }
  err = i2c_master_write_byte(cmd, reg, 1 );
  if (err != ESP_OK)
  {
    ESP_DRAM_LOGE("ina226_write_reg", "i2c_master_write_byte cmd error:%x", err);
    return err;
  }
  err = i2c_master_write(cmd, (unsigned char*)&data, 2, 1 );
  if (err != ESP_OK)
  {
    ESP_DRAM_LOGE("ina226_write_reg", "i2c_master_write error:%x", err);
    return err;
  }
  err = i2c_master_stop(cmd);
  if (err != ESP_OK)
  {
    ESP_DRAM_LOGE("ina226_write_reg", "i2c_master_stop error:%x", err);
    return err;
  }
  err = i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_RATE_MS);
  if (err != ESP_OK)
  {
    ESP_DRAM_LOGE("ina226_write_reg", "i2c_master_cmd_begin error:%x", err);
    return err;
  }
  i2c_cmd_link_delete(cmd);
  return 0;
}

esp_err_t ina226_write_reg_16(unsigned char reg, unsigned short datain)
{
  unsigned char data[3];
  data[0] = reg;
  data[1] = datain >> 8;
  data[2] = datain & 0xff;
  esp_err_t err;

  err = i2c_master_write_to_device(I2C_NUM_0, INA226_ADDR, data, 3, 1000 / portTICK_RATE_MS);
  if (err != ESP_OK)
  {
    ESP_DRAM_LOGE("ina226_write_reg_16", "i2c_master_write_to_device error:%x", err);
    return err;
  }
  return ESP_OK;
}

esp_err_t ina226_read_reg_16(unsigned char reg, unsigned short *data)
{
  unsigned char buf[2];
  esp_err_t err;

  err = i2c_master_write_read_device(I2C_NUM_0, INA226_ADDR, &reg, 1, buf, 2, 1000 / portTICK_RATE_MS);
  if (err != ESP_OK)
  {
    ESP_DRAM_LOGE("ina226_read_reg_16", "i2c_master_read_device error:%x", err);
    return err;
  }
  *data = (buf[0] << 8) | buf[1];
  return ESP_OK;
}

esp_err_t ina226_read_reg(unsigned char reg)
{
  esp_err_t err;
	uint8_t data1,data2;
  unsigned short ret_data;
  i2c_cmd_handle_t cmd = i2c_cmd_link_create();
  err = i2c_master_start(cmd);
  if (err != ESP_OK)
  {
    ESP_DRAM_LOGE("ina226_read_reg", "i2c_master_start error:%x", err);
    return err;
  }
  err = i2c_master_write_byte(cmd, ( INA226_ADDR << 1 ) | I2C_MASTER_WRITE, 1 );
  if (err != ESP_OK)
  {
    ESP_DRAM_LOGE("ina226_read_reg", "i2c_master_write_byte ina_addr error:%x", err);
    return err;
  }
  err = i2c_master_write_byte(cmd, reg, 1 );
  if (err != ESP_OK)
  {
    ESP_DRAM_LOGE("ina226_read_reg", "i2c_master_write_byte cmd error:%x", err);
    return err;
  }
  err = i2c_master_start(cmd);
  if (err != ESP_OK)
  {
    ESP_DRAM_LOGE("ina226_read_reg", "i2c_master_start error:%x", err);
    return err;
  }
  err = i2c_master_write_byte(cmd, ( INA226_ADDR << 1 ) | I2C_MASTER_READ, 1 );
  if (err != ESP_OK)
  {
    ESP_DRAM_LOGE("ina226_read_reg", "i2c_master_write_byte cmd error:%x", err);
    return err;
  }
  err = i2c_master_read_byte(cmd, &data1, 1 );
  if (err != ESP_OK)
  {
    ESP_DRAM_LOGE("ina226_read_reg", "i2c_master_read_byte data1 error:%x", err);
    return err;
  }
  err = i2c_master_read_byte(cmd, &data2, 1 );
  if (err != ESP_OK)
  {
    ESP_DRAM_LOGE("ina226_read_reg", "i2c_master_read_byte data2 error:%x", err);
    return err;
  }
  err = i2c_master_stop(cmd);
  if (err != ESP_OK)
  {
    ESP_DRAM_LOGE("ina226_read_reg", "i2c_master_stop error:%x", err);
    return err;
  }
  err = i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_RATE_MS);
  if (err != ESP_OK)
  {
    ESP_DRAM_LOGE("ina226_read_reg", "i2c_master_cmd_begin error:%x", err);
    return err;
  }
  i2c_cmd_link_delete(cmd);
	return ret_data=(unsigned short)data1<<8|data2;
}

void ina226_init(void )
{
  IIC_GPIO_Init();
  ESP_LOGI("UserPrintf:", "IIC_Init!");
  // //写配置寄存器
  // ina226_write_reg(0x00, 0x4527);//
  // ESP_LOGI("UserPrintf:", "0x00 Write!");
  // ina226_write_reg(0x00, 0x4527);//
  // ESP_LOGI("UserPrintf:", "0x00 Write!");
  // //写校准寄存器【预估电流10A，分压电阻0.005mΩ】
  // ina226_write_reg(0x05, 0x0800);
  // ESP_LOGI("UserPrintf:", "0x05 Write!");
  esp_err_t err;
  err = ina226_write_reg_16(0x00, 0x4527);
  err = ina226_write_reg_16(0x05, 0x0800);
}

/**
 * @brief Ina226读取电压和电流
 *
 * @param voltage
 * @param current
 */
void ina226_read_data(float *voltage, float *current, float *power)
{
  unsigned short data;
  ina226_read_reg_16(INA226_REG_BUS_VOLTAGE,&data);
  *voltage = (float)data *1.25*0.001;
  ina226_read_reg_16(INA226_REG_CURRENT,&data);
  if (((float)data *0.5)>=20000)
  {
    data=0;
  }

  *current = (float)data *0.5;
  ina226_read_reg_16(INA226_REG_POWER,&data);
  *power = (float)data *0.5*25;
}
