-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\hdlcoder_led_blinking\led_count_ip_addr_decoder.vhd
-- Created: 2017-06-14 19:57:20
-- 
-- Generated by MATLAB 9.2 and HDL Coder 3.10
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: led_count_ip_addr_decoder
-- Source Path: led_count_ip/led_count_ip_axi_lite/led_count_ip_addr_decoder
-- Hierarchy Level: 2
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY led_count_ip_addr_decoder IS
  PORT( clk                               :   IN    std_logic;
        reset                             :   IN    std_logic;
        data_write                        :   IN    std_logic_vector(31 DOWNTO 0);  -- ufix32
        addr_sel                          :   IN    std_logic_vector(13 DOWNTO 0);  -- ufix14
        wr_enb                            :   IN    std_logic;  -- ufix1
        rd_enb                            :   IN    std_logic;  -- ufix1
        read_Read_back                    :   IN    std_logic_vector(7 DOWNTO 0);  -- ufix8
        data_read                         :   OUT   std_logic_vector(31 DOWNTO 0);  -- ufix32
        write_axi_enable                  :   OUT   std_logic;  -- ufix1
        write_Blink_frequency             :   OUT   std_logic_vector(3 DOWNTO 0);  -- ufix4
        write_Blink_direction             :   OUT   std_logic  -- ufix1
        );
END led_count_ip_addr_decoder;


ARCHITECTURE rtl OF led_count_ip_addr_decoder IS

  -- Signals
  SIGNAL enb                              : std_logic;
  SIGNAL addr_sel_unsigned                : unsigned(13 DOWNTO 0);  -- ufix14
  SIGNAL decode_sel_Read_back             : std_logic;  -- ufix1
  SIGNAL read_Read_back_unsigned          : unsigned(7 DOWNTO 0);  -- ufix8
  SIGNAL const_1                          : std_logic;  -- ufix1
  SIGNAL const_0                          : unsigned(31 DOWNTO 0);  -- ufix32
  SIGNAL read_reg_Read_back               : unsigned(7 DOWNTO 0);  -- ufix8
  SIGNAL data_in_Read_back                : unsigned(31 DOWNTO 0);  -- ufix32
  SIGNAL decode_rd_Read_back              : unsigned(31 DOWNTO 0);  -- ufix32
  SIGNAL decode_sel_axi_enable            : std_logic;  -- ufix1
  SIGNAL reg_enb_axi_enable               : std_logic;  -- ufix1
  SIGNAL data_write_unsigned              : unsigned(31 DOWNTO 0);  -- ufix32
  SIGNAL data_in_axi_enable               : std_logic;  -- ufix1
  SIGNAL write_reg_axi_enable             : std_logic;  -- ufix1
  SIGNAL decode_sel_Blink_frequency       : std_logic;  -- ufix1
  SIGNAL reg_enb_Blink_frequency          : std_logic;  -- ufix1
  SIGNAL data_in_Blink_frequency          : unsigned(3 DOWNTO 0);  -- ufix4
  SIGNAL write_reg_Blink_frequency        : unsigned(3 DOWNTO 0);  -- ufix4
  SIGNAL decode_sel_Blink_direction       : std_logic;  -- ufix1
  SIGNAL reg_enb_Blink_direction          : std_logic;  -- ufix1
  SIGNAL data_in_Blink_direction          : std_logic;  -- ufix1
  SIGNAL write_reg_Blink_direction        : std_logic;  -- ufix1

BEGIN
  addr_sel_unsigned <= unsigned(addr_sel);

  
  decode_sel_Read_back <= '1' WHEN addr_sel_unsigned = to_unsigned(16#0042#, 14) ELSE
      '0';

  read_Read_back_unsigned <= unsigned(read_Read_back);

  const_1 <= '1';

  enb <= const_1;

  const_0 <= to_unsigned(0, 32);

  reg_Read_back_process : PROCESS (clk)
  BEGIN
    IF clk'EVENT AND clk = '1' THEN
      IF reset = '1' THEN
        read_reg_Read_back <= to_unsigned(16#00#, 8);
      ELSIF enb = '1' THEN
        read_reg_Read_back <= read_Read_back_unsigned;
      END IF;
    END IF;
  END PROCESS reg_Read_back_process;


  data_in_Read_back <= resize(read_reg_Read_back, 32);

  
  decode_rd_Read_back <= const_0 WHEN decode_sel_Read_back = '0' ELSE
      data_in_Read_back;

  data_read <= std_logic_vector(decode_rd_Read_back);

  
  decode_sel_axi_enable <= '1' WHEN addr_sel_unsigned = to_unsigned(16#0001#, 14) ELSE
      '0';

  reg_enb_axi_enable <= decode_sel_axi_enable AND wr_enb;

  data_write_unsigned <= unsigned(data_write);

  data_in_axi_enable <= data_write_unsigned(0);

  reg_axi_enable_process : PROCESS (clk)
  BEGIN
    IF clk'EVENT AND clk = '1' THEN
      IF reset = '1' THEN
        write_reg_axi_enable <= '1';
      ELSIF enb = '1' AND reg_enb_axi_enable = '1' THEN
        write_reg_axi_enable <= data_in_axi_enable;
      END IF;
    END IF;
  END PROCESS reg_axi_enable_process;


  write_axi_enable <= write_reg_axi_enable;

  
  decode_sel_Blink_frequency <= '1' WHEN addr_sel_unsigned = to_unsigned(16#0040#, 14) ELSE
      '0';

  reg_enb_Blink_frequency <= decode_sel_Blink_frequency AND wr_enb;

  data_in_Blink_frequency <= data_write_unsigned(3 DOWNTO 0);

  reg_Blink_frequency_process : PROCESS (clk)
  BEGIN
    IF clk'EVENT AND clk = '1' THEN
      IF reset = '1' THEN
        write_reg_Blink_frequency <= to_unsigned(16#0#, 4);
      ELSIF enb = '1' AND reg_enb_Blink_frequency = '1' THEN
        write_reg_Blink_frequency <= data_in_Blink_frequency;
      END IF;
    END IF;
  END PROCESS reg_Blink_frequency_process;


  write_Blink_frequency <= std_logic_vector(write_reg_Blink_frequency);

  
  decode_sel_Blink_direction <= '1' WHEN addr_sel_unsigned = to_unsigned(16#0041#, 14) ELSE
      '0';

  reg_enb_Blink_direction <= decode_sel_Blink_direction AND wr_enb;

  data_in_Blink_direction <= data_write_unsigned(0);

  reg_Blink_direction_process : PROCESS (clk)
  BEGIN
    IF clk'EVENT AND clk = '1' THEN
      IF reset = '1' THEN
        write_reg_Blink_direction <= '0';
      ELSIF enb = '1' AND reg_enb_Blink_direction = '1' THEN
        write_reg_Blink_direction <= data_in_Blink_direction;
      END IF;
    END IF;
  END PROCESS reg_Blink_direction_process;


  write_Blink_direction <= write_reg_Blink_direction;

END rtl;

