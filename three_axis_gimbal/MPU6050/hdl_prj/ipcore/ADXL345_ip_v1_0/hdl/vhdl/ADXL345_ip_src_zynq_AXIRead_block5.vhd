-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\gm_mpu6050_interface\ADXL345_ip_src_zynq_AXIRead_block5.vhd
-- Created: 2017-11-30 11:08:49
-- 
-- Generated by MATLAB 9.2 and HDL Coder 3.10
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: ADXL345_ip_src_zynq_AXIRead_block5
-- Source Path: gm_mpu6050_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_RegData/AXI4-Interface Read
-- Hierarchy Level: 3
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY ADXL345_ip_src_zynq_AXIRead_block5 IS
  PORT( out0                              :   OUT   std_logic_vector(31 DOWNTO 0)  -- uint32
        );
END ADXL345_ip_src_zynq_AXIRead_block5;


ARCHITECTURE rtl OF ADXL345_ip_src_zynq_AXIRead_block5 IS

  -- Signals
  SIGNAL out0_1                           : unsigned(31 DOWNTO 0);  -- uint32

BEGIN
  out0_1 <= to_unsigned(16#00000000#, 32);

  out0 <= std_logic_vector(out0_1);

END rtl;

