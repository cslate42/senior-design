/*
 * File Name:         hdl_prj\ipcore\I2C_MPU60_ip_v1_0\include\I2C_MPU60_ip_addr.h
 * Description:       C Header File
 * Created:           2017-11-18 14:33:48
*/

#ifndef I2C_MPU60_IP_H_
#define I2C_MPU60_IP_H_

#define  IPCore_Reset_I2C_MPU60_ip        0x0  //write 0x1 to bit 0 to reset IP core
#define  IPCore_Enable_I2C_MPU60_ip       0x4  //enabled (by default) when bit 0 is 0x1
#define  ConfigDevice_Data_I2C_MPU60_ip   0x100  //data register for Inport ConfigDevice
#define  AccelX_Data_I2C_MPU60_ip         0x104  //data register for Outport AccelX
#define  AccelY_Data_I2C_MPU60_ip         0x108  //data register for Outport AccelY
#define  AccelZ_Data_I2C_MPU60_ip         0x10C  //data register for Outport AccelZ
#define  validout_Data_I2C_MPU60_ip       0x110  //data register for Outport validout
#define  RegAddr_Data_I2C_MPU60_ip        0x114  //data register for Inport RegAddr
#define  deviceID_Data_I2C_MPU60_ip       0x118  //data register for Outport deviceID
#define  RegData_Data_I2C_MPU60_ip        0x11C  //data register for Outport RegData
#define  GyroX_Data_I2C_MPU60_ip          0x120  //data register for Outport GyroX
#define  GyroY_Data_I2C_MPU60_ip          0x124  //data register for Outport GyroY
#define  GyroZ_Data_I2C_MPU60_ip          0x128  //data register for Outport GyroZ

#endif /* I2C_MPU60_IP_H_ */
