-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\gm_mpu6050_interface\ADXL345_ip_src_I2C_MPU6050_IP_tc.vhd
-- Created: 2017-11-29 14:33:47
-- 
-- Generated by MATLAB 9.2 and HDL Coder 3.10
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: ADXL345_ip_src_I2C_MPU6050_IP_tc
-- Source Path: I2C_MPU6050_IP_tc
-- Hierarchy Level: 1
-- 
-- Master clock enable input: clk_enable
-- 
-- enb_1_1_1   : 125x slower than clk_enable with phase 1
-- enb_125_1_0 : identical to clk_enable
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY ADXL345_ip_src_I2C_MPU6050_IP_tc IS
  PORT( clk                               :   IN    std_logic;
        reset                             :   IN    std_logic;
        clk_enable                        :   IN    std_logic;
        enb_1_1_1                         :   OUT   std_logic;
        enb_125_1_0                       :   OUT   std_logic
        );
END ADXL345_ip_src_I2C_MPU6050_IP_tc;


ARCHITECTURE rtl OF ADXL345_ip_src_I2C_MPU6050_IP_tc IS

  -- Signals
  SIGNAL count125                         : unsigned(6 DOWNTO 0);  -- ufix7
  SIGNAL phase_1                          : std_logic;
  SIGNAL phase_1_tmp                      : std_logic;
  SIGNAL phase_all                        : std_logic;

BEGIN
  Counter125 : PROCESS (clk)
  BEGIN
    IF clk'event AND clk = '1' THEN
      IF reset = '1' THEN
        count125 <= to_unsigned(1, 7);
      ELSIF clk_enable = '1' THEN
        IF count125 = to_unsigned(124, 7) THEN
          count125 <= to_unsigned(0, 7);
        ELSE
          count125 <= count125 + to_unsigned(1, 7);
        END IF;
      END IF;
    END IF; 
  END PROCESS Counter125;

  temp_process1 : PROCESS (clk)
  BEGIN
    IF clk'event AND clk = '1' THEN
      IF reset = '1' THEN
        phase_1 <= '1';
      ELSIF clk_enable = '1' THEN
        phase_1 <= phase_1_tmp;
      END IF;
    END IF; 
  END PROCESS temp_process1;

  phase_1_tmp <= '1' WHEN count125 = to_unsigned(0, 7) AND clk_enable = '1' ELSE '0';

  phase_all <= '1' WHEN clk_enable = '1' ELSE '0';

  enb_1_1_1 <=  phase_1 AND clk_enable;

  enb_125_1_0 <=  phase_all AND clk_enable;


END rtl;

