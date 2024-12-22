#ifndef _INA226_H_
#define _INA226_H_

#define INA226_ADDR 0x40
#define INA226_REG_CONFIG 0x00
#define INA226_REG_CALIB 0x05

#define INA226_REG_SHUNT_VOLTAGE 0x01
#define INA226_REG_BUS_VOLTAGE 0x02
#define INA226_REG_POWER 0x03
#define INA226_REG_CURRENT 0x04

extern float Voltage;
extern float Current;
extern float Power;

void ina226_init(void );
void ina226_read_data(float *voltage, float *current, float *power);

#endif // !_INA226_H_
