-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\gm_mpu6050_interface\ADXL345_ip_src_AXI4Lite_Read_GyroZ.vhd
-- Created: 2017-11-29 14:33:47
-- 
-- Generated by MATLAB 9.2 and HDL Coder 3.10
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: ADXL345_ip_src_AXI4Lite_Read_GyroZ
-- Source Path: gm_mpu6050_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_GyroZ
-- Hierarchy Level: 2
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY ADXL345_ip_src_AXI4Lite_Read_GyroZ IS
  PORT( Out1                              :   OUT   std_logic_vector(31 DOWNTO 0)  -- uint32
        );
END ADXL345_ip_src_AXI4Lite_Read_GyroZ;


ARCHITECTURE rtl OF ADXL345_ip_src_AXI4Lite_Read_GyroZ IS

  -- Component Declarations
  COMPONENT ADXL345_ip_src_zynq_AXIRead_block4
    PORT( out0                            :   OUT   std_logic_vector(31 DOWNTO 0)  -- uint32
          );
  END COMPONENT;

  -- Component Configuration Statements
  FOR ALL : ADXL345_ip_src_zynq_AXIRead_block4
    USE ENTITY work.ADXL345_ip_src_zynq_AXIRead_block4(rtl);

  -- Signals
  SIGNAL out0                             : std_logic_vector(31 DOWNTO 0);  -- ufix32

BEGIN
  -- <S9>/AXI4-Interface Read
  -- 
  -- <S9>/Signal Specification
  u_AXI4_Interface_Read : ADXL345_ip_src_zynq_AXIRead_block4
    PORT MAP( out0 => out0  -- uint32
              );

  Out1 <= out0;

END rtl;

