/*
 * File Name:         hdl_prj\ipcore\ADXL345_ip_v1_0\include\ADXL345_ip_addr.h
 * Description:       C Header File
 * Created:           2017-12-03 22:48:44
*/

#ifndef ADXL345_IP_H_
#define ADXL345_IP_H_

#define  IPCore_Reset_ADXL345_ip         0x0  //write 0x1 to bit 0 to reset IP core
#define  IPCore_Enable_ADXL345_ip        0x4  //enabled (by default) when bit 0 is 0x1
#define  isDeviceSetup_Data_ADXL345_ip   0x100  //data register for Outport isDeviceSetup
#define  ConfigDevice_Data_ADXL345_ip    0x104  //data register for Inport ConfigDevice
#define  AccelX_Data_ADXL345_ip          0x108  //data register for Outport AccelX
#define  AccelY_Data_ADXL345_ip          0x10C  //data register for Outport AccelY
#define  AccelZ_Data_ADXL345_ip          0x110  //data register for Outport AccelZ
#define  RegAddr_Data_ADXL345_ip         0x114  //data register for Inport RegAddr
#define  validout_Data_ADXL345_ip        0x118  //data register for Outport validout
#define  deviceID_Data_ADXL345_ip        0x11C  //data register for Outport deviceID
#define  RegData_Data_ADXL345_ip         0x120  //data register for Outport RegData
#define  GyroX_Data_ADXL345_ip           0x124  //data register for Outport GyroX
#define  GyroY_Data_ADXL345_ip           0x128  //data register for Outport GyroY
#define  GyroZ_Data_ADXL345_ip           0x12C  //data register for Outport GyroZ

#endif /* ADXL345_IP_H_ */
