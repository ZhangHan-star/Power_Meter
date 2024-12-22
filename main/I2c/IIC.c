/*
 * @Author: 星痕迷鹿 1959171224@qq.com
 * @Date: 2024-09-12 18:37:36
 * @LastEditors: 星痕迷鹿 1959171224@qq.com
 * @LastEditTime: 2024-09-14 15:58:51
 * @FilePath: \Power_Meter\main\I2c\IIC.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "IIC.h"
#include <stdio.h>
#include "sys/unistd.h"
#include "driver/i2c.h"
#include "esp_log.h"

#define GPIO_SCL          0              // IIC 时钟引脚
#define GPIO_SDA          1              // IIC 数据引脚
#define IIC_NUM           I2C_NUM_0      // IIC 硬件0

#define ACK_CHECK_EN      0x1            /*!< I2C 主机将【理会】  应答*/
#define ACK_CHECK_DIS     0x0            /*!< I2C 主机将【不理会】应答 */

#define I2C_MASTER_TX_BUF_DISABLE   0   /*!< I2C 主机不需要发送缓存区 */
#define I2C_MASTER_RX_BUF_DISABLE   0   /*!< I2C 主机不需要接收缓存区 */

/******************************************************************
 * 函 数 名 称：IIC_GPIO_Init
 * 函 数 说 明：对IIC初始化
 * 函 数 形 参：无
 * 函 数 返 回：无
 * 作       者：LC
 * 备       注：无
******************************************************************/
void IIC_GPIO_Init()
{
    int i2c_master_port = IIC_NUM;
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,              // 设定为主机
        .sda_io_num = GPIO_SDA,               // SDA引脚设定
        .sda_pullup_en = GPIO_PULLUP_ENABLE,  // 启动SDA引脚上拉电阻
        .scl_io_num = GPIO_SCL,               // SCL引脚设定
        .scl_pullup_en = GPIO_PULLUP_ENABLE,  // 启动SCL引脚上拉电阻
        .master.clk_speed = 100000,           // 使用 100KHz 时钟频率
        // .clk_flags = 0,          /* 可选项，这个选项是用来选择时钟源 */
    };
    i2c_param_config(i2c_master_port, &conf);  // 将conf结构体的设定配置到 IIC_NUM
    i2c_driver_install(IIC_NUM, conf.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
}
