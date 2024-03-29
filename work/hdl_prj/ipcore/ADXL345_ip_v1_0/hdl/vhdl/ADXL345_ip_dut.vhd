-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\mpu6050_working\ADXL345_ip_dut.vhd
-- Created: 2017-12-03 22:48:44
-- 
-- Generated by MATLAB 9.2 and HDL Coder 3.10
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: ADXL345_ip_dut
-- Source Path: ADXL345_ip/ADXL345_ip_dut
-- Hierarchy Level: 1
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY ADXL345_ip_dut IS
  PORT( clk                               :   IN    std_logic;
        reset                             :   IN    std_logic;
        dut_enable                        :   IN    std_logic;  -- ufix1
        RegAddr                           :   IN    std_logic_vector(7 DOWNTO 0);  -- ufix8
        ConfigDevice                      :   IN    std_logic;  -- ufix1
        ce_out                            :   OUT   std_logic;  -- ufix1
        SCL                               :   OUT   std_logic;  -- ufix1
        SDA                               :   INOUT std_logic;  -- ufix1
        AccelX                            :   OUT   std_logic_vector(15 DOWNTO 0);  -- sfix16
        AccelY                            :   OUT   std_logic_vector(15 DOWNTO 0);  -- sfix16
        AccelZ                            :   OUT   std_logic_vector(15 DOWNTO 0);  -- sfix16
        validout                          :   OUT   std_logic;  -- ufix1
        deviceID                          :   OUT   std_logic_vector(7 DOWNTO 0);  -- ufix8
        CS                                :   OUT   std_logic;  -- ufix1
        ADDRALT                           :   OUT   std_logic;  -- ufix1
        RegData                           :   OUT   std_logic_vector(7 DOWNTO 0);  -- ufix8
        GyroX                             :   OUT   std_logic_vector(15 DOWNTO 0);  -- sfix16
        GyroY                             :   OUT   std_logic_vector(15 DOWNTO 0);  -- sfix16
        GyroZ                             :   OUT   std_logic_vector(15 DOWNTO 0);  -- sfix16
        isDeviceSetup                     :   OUT   std_logic  -- ufix1
        );
END ADXL345_ip_dut;


ARCHITECTURE rtl OF ADXL345_ip_dut IS

  -- Component Declarations
  COMPONENT ADXL345_ip_src_I2C_MPU6050_IP
    PORT( clk                             :   IN    std_logic;
          clk_enable                      :   IN    std_logic;
          reset                           :   IN    std_logic;
          RegAddr                         :   IN    std_logic_vector(7 DOWNTO 0);  -- ufix8
          ConfigDevice                    :   IN    std_logic;  -- ufix1
          ce_out                          :   OUT   std_logic;  -- ufix1
          SCL                             :   OUT   std_logic;  -- ufix1
          SDA                             :   INOUT std_logic;  -- ufix1
          AccelX                          :   OUT   std_logic_vector(15 DOWNTO 0);  -- sfix16
          AccelY                          :   OUT   std_logic_vector(15 DOWNTO 0);  -- sfix16
          AccelZ                          :   OUT   std_logic_vector(15 DOWNTO 0);  -- sfix16
          validout                        :   OUT   std_logic;  -- ufix1
          deviceID                        :   OUT   std_logic_vector(7 DOWNTO 0);  -- ufix8
          CS                              :   OUT   std_logic;  -- ufix1
          ADDRALT                         :   OUT   std_logic;  -- ufix1
          RegData                         :   OUT   std_logic_vector(7 DOWNTO 0);  -- ufix8
          GyroX                           :   OUT   std_logic_vector(15 DOWNTO 0);  -- sfix16
          GyroY                           :   OUT   std_logic_vector(15 DOWNTO 0);  -- sfix16
          GyroZ                           :   OUT   std_logic_vector(15 DOWNTO 0);  -- sfix16
          isDeviceSetup                   :   OUT   std_logic  -- ufix1
          );
  END COMPONENT;

  -- Component Configuration Statements
  FOR ALL : ADXL345_ip_src_I2C_MPU6050_IP
    USE ENTITY work.ADXL345_ip_src_I2C_MPU6050_IP(rtl);

  -- Signals
  SIGNAL enb                              : std_logic;
  SIGNAL ConfigDevice_sig                 : std_logic;  -- ufix1
  SIGNAL ce_out_sig                       : std_logic;  -- ufix1
  SIGNAL SCL_sig                          : std_logic;  -- ufix1
  SIGNAL AccelX_sig                       : std_logic_vector(15 DOWNTO 0);  -- ufix16
  SIGNAL AccelY_sig                       : std_logic_vector(15 DOWNTO 0);  -- ufix16
  SIGNAL AccelZ_sig                       : std_logic_vector(15 DOWNTO 0);  -- ufix16
  SIGNAL validout_sig                     : std_logic;  -- ufix1
  SIGNAL deviceID_sig                     : std_logic_vector(7 DOWNTO 0);  -- ufix8
  SIGNAL CS_sig                           : std_logic;  -- ufix1
  SIGNAL ADDRALT_sig                      : std_logic;  -- ufix1
  SIGNAL RegData_sig                      : std_logic_vector(7 DOWNTO 0);  -- ufix8
  SIGNAL GyroX_sig                        : std_logic_vector(15 DOWNTO 0);  -- ufix16
  SIGNAL GyroY_sig                        : std_logic_vector(15 DOWNTO 0);  -- ufix16
  SIGNAL GyroZ_sig                        : std_logic_vector(15 DOWNTO 0);  -- ufix16
  SIGNAL isDeviceSetup_sig                : std_logic;  -- ufix1

BEGIN
  u_ADXL345_ip_src_I2C_MPU6050_IP : ADXL345_ip_src_I2C_MPU6050_IP
    PORT MAP( clk => clk,
              clk_enable => enb,
              reset => reset,
              RegAddr => RegAddr,  -- ufix8
              ConfigDevice => ConfigDevice_sig,  -- ufix1
              ce_out => ce_out_sig,  -- ufix1
              SCL => SCL_sig,  -- ufix1
              SDA => SDA,  -- ufix1
              AccelX => AccelX_sig,  -- sfix16
              AccelY => AccelY_sig,  -- sfix16
              AccelZ => AccelZ_sig,  -- sfix16
              validout => validout_sig,  -- ufix1
              deviceID => deviceID_sig,  -- ufix8
              CS => CS_sig,  -- ufix1
              ADDRALT => ADDRALT_sig,  -- ufix1
              RegData => RegData_sig,  -- ufix8
              GyroX => GyroX_sig,  -- sfix16
              GyroY => GyroY_sig,  -- sfix16
              GyroZ => GyroZ_sig,  -- sfix16
              isDeviceSetup => isDeviceSetup_sig  -- ufix1
              );

  ConfigDevice_sig <= ConfigDevice;

  enb <= dut_enable;

  ce_out <= ce_out_sig;

  SCL <= SCL_sig;

  AccelX <= AccelX_sig;

  AccelY <= AccelY_sig;

  AccelZ <= AccelZ_sig;

  validout <= validout_sig;

  deviceID <= deviceID_sig;

  CS <= CS_sig;

  ADDRALT <= ADDRALT_sig;

  RegData <= RegData_sig;

  GyroX <= GyroX_sig;

  GyroY <= GyroY_sig;

  GyroZ <= GyroZ_sig;

  isDeviceSetup <= isDeviceSetup_sig;

END rtl;

