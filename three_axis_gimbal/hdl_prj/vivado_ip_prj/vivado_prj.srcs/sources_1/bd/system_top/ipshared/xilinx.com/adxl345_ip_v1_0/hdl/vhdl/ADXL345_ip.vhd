-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\gm_mpu6050_interface\ADXL345_ip.vhd
-- Created: 2017-11-29 14:34:00
-- 
-- Generated by MATLAB 9.2 and HDL Coder 3.10
-- 
-- 
-- -------------------------------------------------------------
-- Rate and Clocking Details
-- -------------------------------------------------------------
-- Model base rate: -1
-- Target subsystem base rate: -1
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: ADXL345_ip
-- Source Path: ADXL345_ip
-- Hierarchy Level: 0
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY ADXL345_ip IS
  PORT( IPCORE_CLK                        :   IN    std_logic;  -- ufix1
        IPCORE_RESETN                     :   IN    std_logic;  -- ufix1
        AXI4_Lite_ACLK                    :   IN    std_logic;  -- ufix1
        AXI4_Lite_ARESETN                 :   IN    std_logic;  -- ufix1
        AXI4_Lite_AWADDR                  :   IN    std_logic_vector(15 DOWNTO 0);  -- ufix16
        AXI4_Lite_AWVALID                 :   IN    std_logic;  -- ufix1
        AXI4_Lite_WDATA                   :   IN    std_logic_vector(31 DOWNTO 0);  -- ufix32
        AXI4_Lite_WSTRB                   :   IN    std_logic_vector(3 DOWNTO 0);  -- ufix4
        AXI4_Lite_WVALID                  :   IN    std_logic;  -- ufix1
        AXI4_Lite_BREADY                  :   IN    std_logic;  -- ufix1
        AXI4_Lite_ARADDR                  :   IN    std_logic_vector(15 DOWNTO 0);  -- ufix16
        AXI4_Lite_ARVALID                 :   IN    std_logic;  -- ufix1
        AXI4_Lite_RREADY                  :   IN    std_logic;  -- ufix1
        SDA                               :   OUT   std_logic;  -- ufix1
        CS                                :   OUT   std_logic;  -- ufix1
        ADDRALT                           :   OUT   std_logic;  -- ufix1
        PmodJA1                           :   OUT   std_logic_vector(7 DOWNTO 0);  -- ufix8
        AXI4_Lite_AWREADY                 :   OUT   std_logic;  -- ufix1
        AXI4_Lite_WREADY                  :   OUT   std_logic;  -- ufix1
        AXI4_Lite_BRESP                   :   OUT   std_logic_vector(1 DOWNTO 0);  -- ufix2
        AXI4_Lite_BVALID                  :   OUT   std_logic;  -- ufix1
        AXI4_Lite_ARREADY                 :   OUT   std_logic;  -- ufix1
        AXI4_Lite_RDATA                   :   OUT   std_logic_vector(31 DOWNTO 0);  -- ufix32
        AXI4_Lite_RRESP                   :   OUT   std_logic_vector(1 DOWNTO 0);  -- ufix2
        AXI4_Lite_RVALID                  :   OUT   std_logic  -- ufix1
        );
END ADXL345_ip;


ARCHITECTURE rtl OF ADXL345_ip IS

  -- Component Declarations
  COMPONENT ADXL345_ip_axi_lite
    PORT( reset                           :   IN    std_logic;
          AXI4_Lite_ACLK                  :   IN    std_logic;  -- ufix1
          AXI4_Lite_ARESETN               :   IN    std_logic;  -- ufix1
          AXI4_Lite_AWADDR                :   IN    std_logic_vector(15 DOWNTO 0);  -- ufix16
          AXI4_Lite_AWVALID               :   IN    std_logic;  -- ufix1
          AXI4_Lite_WDATA                 :   IN    std_logic_vector(31 DOWNTO 0);  -- ufix32
          AXI4_Lite_WSTRB                 :   IN    std_logic_vector(3 DOWNTO 0);  -- ufix4
          AXI4_Lite_WVALID                :   IN    std_logic;  -- ufix1
          AXI4_Lite_BREADY                :   IN    std_logic;  -- ufix1
          AXI4_Lite_ARADDR                :   IN    std_logic_vector(15 DOWNTO 0);  -- ufix16
          AXI4_Lite_ARVALID               :   IN    std_logic;  -- ufix1
          AXI4_Lite_RREADY                :   IN    std_logic;  -- ufix1
          read_AccelX                     :   IN    std_logic_vector(15 DOWNTO 0);  -- sfix16
          read_AccelY                     :   IN    std_logic_vector(15 DOWNTO 0);  -- sfix16
          read_AccelZ                     :   IN    std_logic_vector(15 DOWNTO 0);  -- sfix16
          read_validout                   :   IN    std_logic;  -- ufix1
          read_deviceID                   :   IN    std_logic_vector(7 DOWNTO 0);  -- ufix8
          read_RegData                    :   IN    std_logic_vector(7 DOWNTO 0);  -- ufix8
          read_GyroX                      :   IN    std_logic_vector(15 DOWNTO 0);  -- sfix16
          read_GyroY                      :   IN    std_logic_vector(15 DOWNTO 0);  -- sfix16
          read_GyroZ                      :   IN    std_logic_vector(15 DOWNTO 0);  -- sfix16
          AXI4_Lite_AWREADY               :   OUT   std_logic;  -- ufix1
          AXI4_Lite_WREADY                :   OUT   std_logic;  -- ufix1
          AXI4_Lite_BRESP                 :   OUT   std_logic_vector(1 DOWNTO 0);  -- ufix2
          AXI4_Lite_BVALID                :   OUT   std_logic;  -- ufix1
          AXI4_Lite_ARREADY               :   OUT   std_logic;  -- ufix1
          AXI4_Lite_RDATA                 :   OUT   std_logic_vector(31 DOWNTO 0);  -- ufix32
          AXI4_Lite_RRESP                 :   OUT   std_logic_vector(1 DOWNTO 0);  -- ufix2
          AXI4_Lite_RVALID                :   OUT   std_logic;  -- ufix1
          write_axi_enable                :   OUT   std_logic;  -- ufix1
          write_ConfigDevice              :   OUT   std_logic;  -- ufix1
          write_RegAddr                   :   OUT   std_logic_vector(7 DOWNTO 0);  -- ufix8
          reset_internal                  :   OUT   std_logic  -- ufix1
          );
  END COMPONENT;

  COMPONENT ADXL345_ip_dut
    PORT( clk                             :   IN    std_logic;  -- ufix1
          reset                           :   IN    std_logic;
          dut_enable                      :   IN    std_logic;  -- ufix1
          RegAddr                         :   IN    std_logic_vector(7 DOWNTO 0);  -- ufix8
          ConfigDevice                    :   IN    std_logic;  -- ufix1
          ce_out                          :   OUT   std_logic;  -- ufix1
          SCL                             :   OUT   std_logic;  -- ufix1
          SDA                             :   OUT   std_logic;  -- ufix1
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
          GyroZ                           :   OUT   std_logic_vector(15 DOWNTO 0)  -- sfix16
          );
  END COMPONENT;

  -- Component Configuration Statements
  FOR ALL : ADXL345_ip_axi_lite
    USE ENTITY work.ADXL345_ip_axi_lite(rtl);

  FOR ALL : ADXL345_ip_dut
    USE ENTITY work.ADXL345_ip_dut(rtl);

  -- Signals
  SIGNAL reset                            : std_logic;
  SIGNAL reset_cm                         : std_logic;  -- ufix1
  SIGNAL reset_internal                   : std_logic;  -- ufix1
  SIGNAL AccelX_sig                       : std_logic_vector(15 DOWNTO 0);  -- ufix16
  SIGNAL AccelY_sig                       : std_logic_vector(15 DOWNTO 0);  -- ufix16
  SIGNAL AccelZ_sig                       : std_logic_vector(15 DOWNTO 0);  -- ufix16
  SIGNAL validout_sig                     : std_logic;  -- ufix1
  SIGNAL deviceID_sig                     : std_logic_vector(7 DOWNTO 0);  -- ufix8
  SIGNAL RegData_sig                      : std_logic_vector(7 DOWNTO 0);  -- ufix8
  SIGNAL GyroX_sig                        : std_logic_vector(15 DOWNTO 0);  -- ufix16
  SIGNAL GyroY_sig                        : std_logic_vector(15 DOWNTO 0);  -- ufix16
  SIGNAL GyroZ_sig                        : std_logic_vector(15 DOWNTO 0);  -- ufix16
  SIGNAL AXI4_Lite_BRESP_tmp              : std_logic_vector(1 DOWNTO 0);  -- ufix2
  SIGNAL AXI4_Lite_RDATA_tmp              : std_logic_vector(31 DOWNTO 0);  -- ufix32
  SIGNAL AXI4_Lite_RRESP_tmp              : std_logic_vector(1 DOWNTO 0);  -- ufix2
  SIGNAL write_axi_enable                 : std_logic;  -- ufix1
  SIGNAL write_ConfigDevice               : std_logic;  -- ufix1
  SIGNAL write_RegAddr                    : std_logic_vector(7 DOWNTO 0);  -- ufix8
  SIGNAL ce_out_sig                       : std_logic;  -- ufix1
  SIGNAL SCL_sig                          : std_logic;  -- ufix1
  SIGNAL SDA_sig                          : std_logic;  -- ufix1
  SIGNAL CS_sig                           : std_logic;  -- ufix1
  SIGNAL ADDRALT_sig                      : std_logic;  -- ufix1
  SIGNAL const_zero                       : unsigned(6 DOWNTO 0);  -- ufix7
  SIGNAL PmodJA1_tmp                      : unsigned(7 DOWNTO 0);  -- ufix8

BEGIN
  u_ADXL345_ip_axi_lite_inst : ADXL345_ip_axi_lite
    PORT MAP( reset => reset,
              AXI4_Lite_ACLK => AXI4_Lite_ACLK,  -- ufix1
              AXI4_Lite_ARESETN => AXI4_Lite_ARESETN,  -- ufix1
              AXI4_Lite_AWADDR => AXI4_Lite_AWADDR,  -- ufix16
              AXI4_Lite_AWVALID => AXI4_Lite_AWVALID,  -- ufix1
              AXI4_Lite_WDATA => AXI4_Lite_WDATA,  -- ufix32
              AXI4_Lite_WSTRB => AXI4_Lite_WSTRB,  -- ufix4
              AXI4_Lite_WVALID => AXI4_Lite_WVALID,  -- ufix1
              AXI4_Lite_BREADY => AXI4_Lite_BREADY,  -- ufix1
              AXI4_Lite_ARADDR => AXI4_Lite_ARADDR,  -- ufix16
              AXI4_Lite_ARVALID => AXI4_Lite_ARVALID,  -- ufix1
              AXI4_Lite_RREADY => AXI4_Lite_RREADY,  -- ufix1
              read_AccelX => AccelX_sig,  -- sfix16
              read_AccelY => AccelY_sig,  -- sfix16
              read_AccelZ => AccelZ_sig,  -- sfix16
              read_validout => validout_sig,  -- ufix1
              read_deviceID => deviceID_sig,  -- ufix8
              read_RegData => RegData_sig,  -- ufix8
              read_GyroX => GyroX_sig,  -- sfix16
              read_GyroY => GyroY_sig,  -- sfix16
              read_GyroZ => GyroZ_sig,  -- sfix16
              AXI4_Lite_AWREADY => AXI4_Lite_AWREADY,  -- ufix1
              AXI4_Lite_WREADY => AXI4_Lite_WREADY,  -- ufix1
              AXI4_Lite_BRESP => AXI4_Lite_BRESP_tmp,  -- ufix2
              AXI4_Lite_BVALID => AXI4_Lite_BVALID,  -- ufix1
              AXI4_Lite_ARREADY => AXI4_Lite_ARREADY,  -- ufix1
              AXI4_Lite_RDATA => AXI4_Lite_RDATA_tmp,  -- ufix32
              AXI4_Lite_RRESP => AXI4_Lite_RRESP_tmp,  -- ufix2
              AXI4_Lite_RVALID => AXI4_Lite_RVALID,  -- ufix1
              write_axi_enable => write_axi_enable,  -- ufix1
              write_ConfigDevice => write_ConfigDevice,  -- ufix1
              write_RegAddr => write_RegAddr,  -- ufix8
              reset_internal => reset_internal  -- ufix1
              );

  u_ADXL345_ip_dut_inst : ADXL345_ip_dut
    PORT MAP( clk => IPCORE_CLK,  -- ufix1
              reset => reset,
              dut_enable => write_axi_enable,  -- ufix1
              RegAddr => write_RegAddr,  -- ufix8
              ConfigDevice => write_ConfigDevice,  -- ufix1
              ce_out => ce_out_sig,  -- ufix1
              SCL => SCL_sig,  -- ufix1
              SDA => SDA_sig,  -- ufix1
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
              GyroZ => GyroZ_sig  -- sfix16
              );

  reset_cm <=  NOT IPCORE_RESETN;

  reset <= reset_cm OR reset_internal;

  const_zero <= to_unsigned(16#00#, 7);

  PmodJA1_tmp <= const_zero & SCL_sig;

  PmodJA1 <= std_logic_vector(PmodJA1_tmp);

  SDA <= SDA_sig;

  CS <= CS_sig;

  ADDRALT <= ADDRALT_sig;

  AXI4_Lite_BRESP <= AXI4_Lite_BRESP_tmp;

  AXI4_Lite_RDATA <= AXI4_Lite_RDATA_tmp;

  AXI4_Lite_RRESP <= AXI4_Lite_RRESP_tmp;

END rtl;

