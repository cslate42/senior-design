-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\mpu6050\ADXL345_ip_src_i2c_mstr.vhd
-- Created: 2017-12-02 12:28:36
-- 
-- Generated by MATLAB 9.2 and HDL Coder 3.10
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: ADXL345_ip_src_i2c_mstr
-- Source Path: mpu6050/I2C_MPU6050_IP/I2C_MasterController/i2c_mstr
-- Hierarchy Level: 2
-- 
-- I2C Master Controller
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
USE work.ADXL345_ip_src_I2C_MPU6050_IP_pkg.ALL;

ENTITY ADXL345_ip_src_i2c_mstr IS
  PORT( clk                               :   IN    std_logic;
        reset                             :   IN    std_logic;
        enb                               :   IN    std_logic;
        enb_1                             :   IN    std_logic;
        rd_wr                             :   IN    std_logic;
        mode                              :   IN    std_logic;
        slv_addr                          :   IN    std_logic_vector(7 DOWNTO 0);  -- uint8
        reg_addr                          :   IN    std_logic_vector(7 DOWNTO 0);  -- uint8
        reg_addr_burstIn                  :   IN    std_logic;
        reg_data                          :   IN    std_logic_vector(7 DOWNTO 0);  -- uint8
        sda_in                            :   IN    std_logic;
        busy                              :   OUT   std_logic;
        scl                               :   OUT   std_logic;
        sda                               :   OUT   std_logic;
        ack                               :   OUT   std_logic;
        n_ack                             :   OUT   std_logic;
        reg_data_burst                    :   OUT   std_logic;
        reg_addr_burst                    :   OUT   std_logic;
        mstr_ack                          :   OUT   std_logic;
        data_out                          :   OUT   std_logic_vector(7 DOWNTO 0)  -- uint8
        );
END ADXL345_ip_src_i2c_mstr;


ARCHITECTURE rtl OF ADXL345_ip_src_i2c_mstr IS

  -- Functions
  -- HDLCODER_TO_STDLOGIC 
  FUNCTION hdlcoder_to_stdlogic(arg: boolean) RETURN std_logic IS
  BEGIN
    IF arg THEN
      RETURN '1';
    ELSE
      RETURN '0';
    END IF;
  END FUNCTION;


  -- Signals
  SIGNAL slv_addr_unsigned                : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL reg_addr_unsigned                : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL reg_data_unsigned                : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL is_i2c_mstr                      : T_state_type_is_i2c_mstr;  -- uint8
  SIGNAL bit_cnt                          : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL data_out_tmp                     : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL temp_data                        : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL busy_reg                         : std_logic;
  SIGNAL scl_reg                          : std_logic;
  SIGNAL sda_reg                          : std_logic;
  SIGNAL ack_reg                          : std_logic;
  SIGNAL n_ack_reg                        : std_logic;
  SIGNAL reg_data_burst_reg               : std_logic;
  SIGNAL reg_addr_burst_reg               : std_logic;
  SIGNAL mstr_ack_reg                     : std_logic;
  SIGNAL data_out_reg                     : unsigned(7 DOWNTO 0);  -- ufix8
  SIGNAL is_i2c_mstr_next                 : T_state_type_is_i2c_mstr;  -- enum type state_type_is_i2c_mstr (47 enums)
  SIGNAL bit_cnt_next                     : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL temp_data_next                   : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL busy_reg_next                    : std_logic;
  SIGNAL scl_reg_next                     : std_logic;
  SIGNAL sda_reg_next                     : std_logic;
  SIGNAL ack_reg_next                     : std_logic;
  SIGNAL n_ack_reg_next                   : std_logic;
  SIGNAL reg_data_burst_reg_next          : std_logic;
  SIGNAL reg_addr_burst_reg_next          : std_logic;
  SIGNAL mstr_ack_reg_next                : std_logic;
  SIGNAL data_out_reg_next                : unsigned(7 DOWNTO 0);  -- ufix8

BEGIN
  slv_addr_unsigned <= unsigned(slv_addr);

  reg_addr_unsigned <= unsigned(reg_addr);

  reg_data_unsigned <= unsigned(reg_data);

  i2c_mstr_process : PROCESS (clk)
  BEGIN
    IF clk'EVENT AND clk = '1' THEN
      IF reset = '1' THEN
        bit_cnt <= to_unsigned(16#00#, 8);
        ack_reg <= '0';
        n_ack_reg <= '0';
        reg_addr_burst_reg <= '0';
        mstr_ack_reg <= '0';
        data_out_reg <= to_unsigned(16#00#, 8);
        --Entry: I2C_MPU6050_IP/I2C_MasterController/i2c_mstr
        --Entry Internal: I2C_MPU6050_IP/I2C_MasterController/i2c_mstr
        --Transition: '<S8>:2212'
        is_i2c_mstr <= IN_idle;
        --Entry 'idle': '<S8>:2160'
        scl_reg <= '1';
        sda_reg <= '1';
        busy_reg <= '0';
        reg_data_burst_reg <= '0';
        temp_data <= to_unsigned(16#00#, 8);
      ELSIF enb = '1' THEN
        is_i2c_mstr <= is_i2c_mstr_next;
        bit_cnt <= bit_cnt_next;
        temp_data <= temp_data_next;
        busy_reg <= busy_reg_next;
        scl_reg <= scl_reg_next;
        sda_reg <= sda_reg_next;
        ack_reg <= ack_reg_next;
        n_ack_reg <= n_ack_reg_next;
        reg_data_burst_reg <= reg_data_burst_reg_next;
        reg_addr_burst_reg <= reg_addr_burst_reg_next;
        mstr_ack_reg <= mstr_ack_reg_next;
        data_out_reg <= data_out_reg_next;
      END IF;
    END IF;
  END PROCESS i2c_mstr_process;

  i2c_mstr_output : PROCESS (is_i2c_mstr, enb_1, rd_wr, mode, bit_cnt, slv_addr_unsigned, reg_addr_unsigned,
       reg_addr_burstIn, reg_data_unsigned, sda_in, temp_data, busy_reg,
       scl_reg, sda_reg, ack_reg, n_ack_reg, reg_data_burst_reg,
       reg_addr_burst_reg, mstr_ack_reg, data_out_reg)
    VARIABLE bitkm1 : unsigned(7 DOWNTO 0);
    VARIABLE bitkm1_0 : unsigned(7 DOWNTO 0);
    VARIABLE bitkm1_1 : unsigned(7 DOWNTO 0);
    VARIABLE bitkm1_2 : unsigned(7 DOWNTO 0);
    VARIABLE bitkm1_3 : unsigned(7 DOWNTO 0);
    VARIABLE mask : unsigned(7 DOWNTO 0);
    VARIABLE bitkm1_4 : unsigned(7 DOWNTO 0);
    VARIABLE bitkm1_5 : unsigned(7 DOWNTO 0);
    VARIABLE bitkm1_6 : unsigned(7 DOWNTO 0);
    VARIABLE bitkm1_7 : unsigned(7 DOWNTO 0);
    VARIABLE sub_temp : unsigned(8 DOWNTO 0);
    VARIABLE sub_temp_0 : unsigned(8 DOWNTO 0);
    VARIABLE sub_temp_1 : unsigned(8 DOWNTO 0);
    VARIABLE sub_temp_2 : unsigned(8 DOWNTO 0);
    VARIABLE sub_temp_3 : unsigned(8 DOWNTO 0);
    VARIABLE sub_temp_4 : unsigned(8 DOWNTO 0);
    VARIABLE sub_temp_5 : unsigned(8 DOWNTO 0);
    VARIABLE sub_temp_6 : unsigned(8 DOWNTO 0);
    VARIABLE sub_temp_7 : unsigned(8 DOWNTO 0);
    VARIABLE cast : unsigned(7 DOWNTO 0);
    VARIABLE sub_temp_8 : unsigned(8 DOWNTO 0);
    VARIABLE sub_temp_9 : unsigned(8 DOWNTO 0);
    VARIABLE sub_temp_10 : unsigned(8 DOWNTO 0);
    VARIABLE sub_temp_11 : unsigned(8 DOWNTO 0);
    VARIABLE sub_temp_12 : unsigned(8 DOWNTO 0);
    VARIABLE sub_temp_13 : unsigned(8 DOWNTO 0);
  BEGIN
    bit_cnt_next <= bit_cnt;
    busy_reg_next <= busy_reg;
    scl_reg_next <= scl_reg;
    sda_reg_next <= sda_reg;
    ack_reg_next <= ack_reg;
    n_ack_reg_next <= n_ack_reg;
    reg_data_burst_reg_next <= reg_data_burst_reg;
    reg_addr_burst_reg_next <= reg_addr_burst_reg;
    mstr_ack_reg_next <= mstr_ack_reg;
    data_out_reg_next <= data_out_reg;
    is_i2c_mstr_next <= is_i2c_mstr;
    temp_data_next <= temp_data;
    --Gateway: I2C_MPU6050_IP/I2C_MasterController/i2c_mstr
    --During: I2C_MPU6050_IP/I2C_MasterController/i2c_mstr
    CASE is_i2c_mstr IS
      WHEN IN_Increment_Byte_count1 =>
        mstr_ack_reg_next <= '0';
        --During 'Increment_Byte_count1': '<S8>:2187'
        --Transition: '<S8>:2271'
        is_i2c_mstr_next <= IN_cmd_reg_read_data_n;
        --Entry 'cmd_reg_read_data_n': '<S8>:2175'
        scl_reg_next <= '0';
        --mstr_ack(:) = 0
        ack_reg_next <= '1';
      WHEN IN_ack_addr_m =>
        scl_reg_next <= '0';
        --During 'ack_addr_m': '<S8>:2183'
        IF reg_addr_burstIn = '1' THEN 
          --Transition: '<S8>:2247'
          is_i2c_mstr_next <= IN_ack_addrm1;
          --Entry 'ack_addrm1': '<S8>:2244'
          scl_reg_next <= '1';
          ack_reg_next <= '0';
          bit_cnt_next <= to_unsigned(16#08#, 8);
          reg_addr_burst_reg_next <= '1';
        ELSE 
          --Transition: '<S8>:2283'
          is_i2c_mstr_next <= IN_ack_recv_wr1;
          --Entry 'ack_recv_wr1': '<S8>:2278'
          scl_reg_next <= '1';
          sda_reg_next <= '1';
          ack_reg_next <= '1';
        END IF;
      WHEN IN_ack_addr_m_cnf =>
        scl_reg_next <= '0';
        --During 'ack_addr_m_cnf': '<S8>:2176'
        IF ( NOT rd_wr) = '1' THEN 
          --Transition: '<S8>:2198'
          is_i2c_mstr_next <= IN_cmd_reg_data_n;
          --Entry 'cmd_reg_data_n': '<S8>:2188'
          scl_reg_next <= '0';
          ack_reg_next <= '0';
          reg_data_burst_reg_next <= '0';
          sub_temp_12 := resize(bit_cnt, 9) - to_unsigned(16#001#, 9);
          IF sub_temp_12(8) /= '0' THEN 
            bitkm1 := "11111111";
          ELSE 
            bitkm1 := sub_temp_12(7 DOWNTO 0);
          END IF;
          sda_reg_next <= reg_data_unsigned(to_integer(bitkm1));
        ELSIF rd_wr = '1' THEN 
          --Transition: '<S8>:2207'
          is_i2c_mstr_next <= IN_delay;
          --Entry 'delay': '<S8>:2180'
          scl_reg_next <= '0';
          sda_reg_next <= '1';
        END IF;
      WHEN IN_ack_addrm1 =>
        --During 'ack_addrm1': '<S8>:2244'
        --Transition: '<S8>:2203'
        is_i2c_mstr_next <= IN_cmd_reg_addr_n;
        --Entry 'cmd_reg_addr_n': '<S8>:2172'
        scl_reg_next <= '0';
        ack_reg_next <= '0';
        sub_temp_4 := resize(bit_cnt, 9) - to_unsigned(16#001#, 9);
        IF sub_temp_4(8) /= '0' THEN 
          bitkm1_0 := "11111111";
        ELSE 
          bitkm1_0 := sub_temp_4(7 DOWNTO 0);
        END IF;
        sda_reg_next <= reg_addr_unsigned(to_integer(bitkm1_0));
        reg_addr_burst_reg_next <= '0';
      WHEN IN_ack_data =>
        --During 'ack_data': '<S8>:2174'
        --Transition: '<S8>:2267'
        is_i2c_mstr_next <= IN_ack_end1;
        --Entry 'ack_end1': '<S8>:2301'
        scl_reg_next <= '1';
        sda_reg_next <= '1';
        ack_reg_next <= '1';
      WHEN IN_ack_end =>
        scl_reg_next <= '1';
        --During 'ack_end': '<S8>:2266'
        IF ( NOT sda_in) = '1' THEN 
          --Transition: '<S8>:2243'
          IF mode = '1' THEN 
            --Transition: '<S8>:2246'
            bit_cnt_next <= to_unsigned(16#08#, 8);
            is_i2c_mstr_next <= IN_cmd_reg_data_n;
            --Entry 'cmd_reg_data_n': '<S8>:2188'
            scl_reg_next <= '0';
            ack_reg_next <= '0';
            reg_data_burst_reg_next <= '0';
            sda_reg_next <= reg_data_unsigned(7);
          ELSE 
            --Transition: '<S8>:2296'
            is_i2c_mstr_next <= IN_scl_ext_n;
            --Entry 'scl_ext_n': '<S8>:2163'
            scl_reg_next <= '0';
            sda_reg_next <= '0';
            ack_reg_next <= '0';
            mstr_ack_reg_next <= '0';
          END IF;
        ELSE 
          --Transition: '<S8>:2222'
          is_i2c_mstr_next <= IN_error_ack;
          --Entry 'error_ack': '<S8>:2171'
          scl_reg_next <= '0';
          sda_reg_next <= '1';
          n_ack_reg_next <= '1';
        END IF;
      WHEN IN_ack_end1 =>
        --During 'ack_end1': '<S8>:2301'
        --Transition: '<S8>:2302'
        is_i2c_mstr_next <= IN_ack_end;
        --Entry 'ack_end': '<S8>:2266'
        scl_reg_next <= '1';
        sda_reg_next <= '1';
        ack_reg_next <= '1';
      WHEN IN_ack_recv_wr =>
        scl_reg_next <= '1';
        --During 'ack_recv_wr': '<S8>:2260'
        IF ( NOT sda_in) = '1' THEN 
          --Transition: '<S8>:2223'
          is_i2c_mstr_next <= IN_ack_wr_p;
          --Entry 'ack_wr_p': '<S8>:2264'
          scl_reg_next <= '0';
          ack_reg_next <= '0';
          sda_reg_next <= '0';
          bit_cnt_next <= to_unsigned(16#08#, 8);
        ELSE 
          --Transition: '<S8>:2217'
          is_i2c_mstr_next <= IN_error_ack;
          --Entry 'error_ack': '<S8>:2171'
          scl_reg_next <= '0';
          sda_reg_next <= '1';
          n_ack_reg_next <= '1';
        END IF;
      WHEN IN_ack_recv_wr1 =>
        --During 'ack_recv_wr1': '<S8>:2278'
        --Transition: '<S8>:2298'
        is_i2c_mstr_next <= IN_ack_recv_wr2;
        --Entry 'ack_recv_wr2': '<S8>:2297'
        scl_reg_next <= '1';
        sda_reg_next <= '1';
        ack_reg_next <= '1';
      WHEN IN_ack_recv_wr2 =>
        scl_reg_next <= '1';
        --During 'ack_recv_wr2': '<S8>:2297'
        IF ( NOT sda_in) = '1' THEN 
          --Transition: '<S8>:2206'
          is_i2c_mstr_next <= IN_ack_addr_m_cnf;
          --Entry 'ack_addr_m_cnf': '<S8>:2176'
          scl_reg_next <= '0';
          sda_reg_next <= hdlcoder_to_stdlogic(rd_wr = '1');
          bit_cnt_next <= to_unsigned(16#08#, 8);
          ack_reg_next <= '0';
        ELSE 
          --Transition: '<S8>:2230'
          is_i2c_mstr_next <= IN_error_ack;
          --Entry 'error_ack': '<S8>:2171'
          scl_reg_next <= '0';
          sda_reg_next <= '1';
          n_ack_reg_next <= '1';
        END IF;
      WHEN IN_ack_recv_wr3 =>
        --During 'ack_recv_wr3': '<S8>:2303'
        --Transition: '<S8>:2304'
        is_i2c_mstr_next <= IN_ack_recv_wr;
        --Entry 'ack_recv_wr': '<S8>:2260'
        scl_reg_next <= '1';
        sda_reg_next <= '1';
        ack_reg_next <= '1';
        bit_cnt_next <= to_unsigned(16#08#, 8);
      WHEN IN_ack_slv =>
        --During 'ack_slv': '<S8>:2170'
        --Transition: '<S8>:2261'
        is_i2c_mstr_next <= IN_ack_recv_wr3;
        --Entry 'ack_recv_wr3': '<S8>:2303'
        scl_reg_next <= '1';
        sda_reg_next <= '1';
        ack_reg_next <= '1';
      WHEN IN_ack_slv1 =>
        --During 'ack_slv1': '<S8>:2219'
        --Transition: '<S8>:2259'
        is_i2c_mstr_next <= IN_ack_slv_cnf1;
        --Entry 'ack_slv_cnf1': '<S8>:2194'
        scl_reg_next <= '1';
        ack_reg_next <= '1';
        bit_cnt_next <= to_unsigned(16#08#, 8);
      WHEN IN_ack_slv_cnf1 =>
        scl_reg_next <= '1';
        --During 'ack_slv_cnf1': '<S8>:2194'
        IF ( NOT sda_in) = '1' THEN 
          --Transition: '<S8>:2239'
          is_i2c_mstr_next <= IN_ack_wr_p2;
          --Entry 'ack_wr_p2': '<S8>:2274'
          scl_reg_next <= '0';
          ack_reg_next <= '1';
          sda_reg_next <= '1';
        ELSE 
          --Transition: '<S8>:2238'
          is_i2c_mstr_next <= IN_error_ack;
          --Entry 'error_ack': '<S8>:2171'
          scl_reg_next <= '0';
          sda_reg_next <= '1';
          n_ack_reg_next <= '1';
        END IF;
      WHEN IN_ack_wr_p =>
        --During 'ack_wr_p': '<S8>:2264'
        --Transition: '<S8>:2292'
        is_i2c_mstr_next <= IN_cmd_reg_addr_n;
        --Entry 'cmd_reg_addr_n': '<S8>:2172'
        scl_reg_next <= '0';
        ack_reg_next <= '0';
        sub_temp_5 := resize(bit_cnt, 9) - to_unsigned(16#001#, 9);
        IF sub_temp_5(8) /= '0' THEN 
          bitkm1_1 := "11111111";
        ELSE 
          bitkm1_1 := sub_temp_5(7 DOWNTO 0);
        END IF;
        sda_reg_next <= reg_addr_unsigned(to_integer(bitkm1_1));
        reg_addr_burst_reg_next <= '0';
      WHEN IN_ack_wr_p2 =>
        --During 'ack_wr_p2': '<S8>:2274'
        --Transition: '<S8>:2275'
        is_i2c_mstr_next <= IN_cmd_reg_read_data_n;
        --Entry 'cmd_reg_read_data_n': '<S8>:2175'
        scl_reg_next <= '0';
        --mstr_ack(:) = 0
        ack_reg_next <= '1';
      WHEN IN_cmd_reg_addr_n =>
        reg_addr_burst_reg_next <= '0';
        --During 'cmd_reg_addr_n': '<S8>:2172'
        --Transition: '<S8>:2227'
        is_i2c_mstr_next <= IN_cmd_reg_addr_p;
        --Entry 'cmd_reg_addr_p': '<S8>:2178'
        scl_reg_next <= '1';
        sub_temp_6 := resize(bit_cnt, 9) - to_unsigned(16#001#, 9);
        IF sub_temp_6(8) /= '0' THEN 
          bit_cnt_next <= "11111111";
        ELSE 
          bit_cnt_next <= sub_temp_6(7 DOWNTO 0);
        END IF;
      WHEN IN_cmd_reg_addr_p =>
        scl_reg_next <= '1';
        --During 'cmd_reg_addr_p': '<S8>:2178'
        IF bit_cnt > to_unsigned(16#00#, 8) THEN 
          --Transition: '<S8>:2226'
          is_i2c_mstr_next <= IN_cmd_reg_addr_n;
          --Entry 'cmd_reg_addr_n': '<S8>:2172'
          scl_reg_next <= '0';
          ack_reg_next <= '0';
          sub_temp_11 := resize(bit_cnt, 9) - to_unsigned(16#001#, 9);
          IF sub_temp_11(8) /= '0' THEN 
            bitkm1_2 := "11111111";
          ELSE 
            bitkm1_2 := sub_temp_11(7 DOWNTO 0);
          END IF;
          sda_reg_next <= reg_addr_unsigned(to_integer(bitkm1_2));
          reg_addr_burst_reg_next <= '0';
        ELSE 
          --Transition: '<S8>:2232'
          is_i2c_mstr_next <= IN_ack_addr_m;
          --Entry 'ack_addr_m': '<S8>:2183'
          scl_reg_next <= '0';
          ack_reg_next <= '1';
          sda_reg_next <= '1';
        END IF;
      WHEN IN_cmd_reg_data_n =>
        --During 'cmd_reg_data_n': '<S8>:2188'
        --Transition: '<S8>:2197'
        is_i2c_mstr_next <= IN_cmd_reg_data_p;
        --Entry 'cmd_reg_data_p': '<S8>:2169'
        scl_reg_next <= '1';
        sub_temp := resize(bit_cnt, 9) - to_unsigned(16#001#, 9);
        IF sub_temp(8) /= '0' THEN 
          bit_cnt_next <= "11111111";
        ELSE 
          bit_cnt_next <= sub_temp(7 DOWNTO 0);
        END IF;
      WHEN IN_cmd_reg_data_p =>
        scl_reg_next <= '1';
        --During 'cmd_reg_data_p': '<S8>:2169'
        IF bit_cnt > to_unsigned(16#00#, 8) THEN 
          --Transition: '<S8>:2190'
          is_i2c_mstr_next <= IN_cmd_reg_data_n;
          --Entry 'cmd_reg_data_n': '<S8>:2188'
          scl_reg_next <= '0';
          ack_reg_next <= '0';
          reg_data_burst_reg_next <= '0';
          sub_temp_13 := resize(bit_cnt, 9) - to_unsigned(16#001#, 9);
          IF sub_temp_13(8) /= '0' THEN 
            bitkm1_3 := "11111111";
          ELSE 
            bitkm1_3 := sub_temp_13(7 DOWNTO 0);
          END IF;
          sda_reg_next <= reg_data_unsigned(to_integer(bitkm1_3));
        ELSE 
          --Transition: '<S8>:2231'
          is_i2c_mstr_next <= IN_ack_data;
          --Entry 'ack_data': '<S8>:2174'
          scl_reg_next <= '0';
          sda_reg_next <= '1';
          ack_reg_next <= '1';
        END IF;
      WHEN IN_cmd_reg_read_data_n =>
        --During 'cmd_reg_read_data_n': '<S8>:2175'
        --Transition: '<S8>:2237'
        is_i2c_mstr_next <= IN_cmd_reg_read_data_p;
        --Entry 'cmd_reg_read_data_p': '<S8>:2179'
        scl_reg_next <= '1';
        IF sda_in = '1' THEN 
          sub_temp_7 := resize(bit_cnt, 9) - to_unsigned(16#001#, 9);
          IF sub_temp_7(8) /= '0' THEN 
            cast := "11111111";
          ELSE 
            cast := sub_temp_7(7 DOWNTO 0);
          END IF;
          mask := to_unsigned(16#01#, 8) sll to_integer(cast);
          temp_data_next <= temp_data OR mask;
        END IF;
        sub_temp_8 := resize(bit_cnt, 9) - to_unsigned(16#001#, 9);
        IF sub_temp_8(8) /= '0' THEN 
          bit_cnt_next <= "11111111";
        ELSE 
          bit_cnt_next <= sub_temp_8(7 DOWNTO 0);
        END IF;
      WHEN IN_cmd_reg_read_data_p =>
        scl_reg_next <= '1';
        --During 'cmd_reg_read_data_p': '<S8>:2179'
        IF bit_cnt > to_unsigned(16#00#, 8) THEN 
          --Transition: '<S8>:2235'
          is_i2c_mstr_next <= IN_cmd_reg_read_data_n;
          --Entry 'cmd_reg_read_data_n': '<S8>:2175'
          scl_reg_next <= '0';
          --mstr_ack(:) = 0
          ack_reg_next <= '1';
        ELSE 
          --Transition: '<S8>:2236'
          is_i2c_mstr_next <= IN_mastr_ack_data;
          --Entry 'mastr_ack_data': '<S8>:2168'
          scl_reg_next <= '0';
          IF mode = '1' THEN 
            sda_reg_next <= '0';
            --ACK
          ELSE 
            sda_reg_next <= '1';
            --NACK
          END IF;
          mstr_ack_reg_next <= '1';
          ack_reg_next <= '0';
          data_out_reg_next <= temp_data;
          temp_data_next <= to_unsigned(16#00#, 8);
        END IF;
      WHEN IN_cmd_slave_addr_n =>
        --During 'cmd_slave_addr_n': '<S8>:2166'
        --Transition: '<S8>:2252'
        is_i2c_mstr_next <= IN_cmd_slave_addr_p;
        --Entry 'cmd_slave_addr_p': '<S8>:2167'
        scl_reg_next <= '1';
        sub_temp_0 := resize(bit_cnt, 9) - to_unsigned(16#001#, 9);
        IF sub_temp_0(8) /= '0' THEN 
          bit_cnt_next <= "11111111";
        ELSE 
          bit_cnt_next <= sub_temp_0(7 DOWNTO 0);
        END IF;
      WHEN IN_cmd_slave_addr_n1 =>
        --During 'cmd_slave_addr_n1': '<S8>:2214'
        --Transition: '<S8>:2250'
        is_i2c_mstr_next <= IN_cmd_slave_addr_p1;
        --Entry 'cmd_slave_addr_p1': '<S8>:2241'
        scl_reg_next <= '1';
        sub_temp_1 := resize(bit_cnt, 9) - to_unsigned(16#001#, 9);
        IF sub_temp_1(8) /= '0' THEN 
          bit_cnt_next <= "11111111";
        ELSE 
          bit_cnt_next <= sub_temp_1(7 DOWNTO 0);
        END IF;
      WHEN IN_cmd_slave_addr_p =>
        scl_reg_next <= '1';
        --During 'cmd_slave_addr_p': '<S8>:2167'
        IF bit_cnt > to_unsigned(16#00#, 8) THEN 
          --Transition: '<S8>:2220'
          is_i2c_mstr_next <= IN_cmd_slave_addr_n;
          --Entry 'cmd_slave_addr_n': '<S8>:2166'
          scl_reg_next <= '0';
          sub_temp_9 := resize(bit_cnt, 9) - to_unsigned(16#001#, 9);
          IF sub_temp_9(8) /= '0' THEN 
            bitkm1_4 := "11111111";
          ELSE 
            bitkm1_4 := sub_temp_9(7 DOWNTO 0);
          END IF;
          sda_reg_next <= slv_addr_unsigned(to_integer(bitkm1_4));
        ELSE 
          --Transition: '<S8>:2195'
          is_i2c_mstr_next <= IN_write_n;
          --Entry 'write_n': '<S8>:2181'
          scl_reg_next <= '0';
          sda_reg_next <= '0';
        END IF;
      WHEN IN_cmd_slave_addr_p1 =>
        scl_reg_next <= '1';
        --During 'cmd_slave_addr_p1': '<S8>:2241'
        IF bit_cnt > to_unsigned(16#00#, 8) THEN 
          --Transition: '<S8>:2201'
          is_i2c_mstr_next <= IN_cmd_slave_addr_n1;
          --Entry 'cmd_slave_addr_n1': '<S8>:2214'
          scl_reg_next <= '0';
          sub_temp_10 := resize(bit_cnt, 9) - to_unsigned(16#001#, 9);
          IF sub_temp_10(8) /= '0' THEN 
            bitkm1_5 := "11111111";
          ELSE 
            bitkm1_5 := sub_temp_10(7 DOWNTO 0);
          END IF;
          sda_reg_next <= slv_addr_unsigned(to_integer(bitkm1_5));
        ELSE 
          --Transition: '<S8>:2251'
          is_i2c_mstr_next <= IN_read_n;
          --Entry 'read_n': '<S8>:2228'
          scl_reg_next <= '0';
          sda_reg_next <= '1';
        END IF;
      WHEN IN_delay =>
        --During 'delay': '<S8>:2180'
        --Transition: '<S8>:2293'
        is_i2c_mstr_next <= IN_ready_repeated;
        --Entry 'ready_repeated': '<S8>:2189'
        scl_reg_next <= '1';
        sda_reg_next <= '1';
      WHEN IN_error_ack =>
        n_ack_reg_next <= '1';
        --During 'error_ack': '<S8>:2171'
        --Transition: '<S8>:2196'
        is_i2c_mstr_next <= IN_scl_ext_n;
        --Entry 'scl_ext_n': '<S8>:2163'
        scl_reg_next <= '0';
        sda_reg_next <= '0';
        ack_reg_next <= '0';
        mstr_ack_reg_next <= '0';
      WHEN IN_idle =>
        scl_reg_next <= '1';
        busy_reg_next <= '0';
        --During 'idle': '<S8>:2160'
        IF enb_1 = '1' THEN 
          --Transition: '<S8>:2234'
          is_i2c_mstr_next <= IN_ready;
          --Entry 'ready': '<S8>:2156'
          scl_reg_next <= '1';
          sda_reg_next <= '1';
          data_out_reg_next <= to_unsigned(16#00#, 8);
        END IF;
      WHEN IN_mastr_ack_data =>
        mstr_ack_reg_next <= '1';
        scl_reg_next <= '0';
        --During 'mastr_ack_data': '<S8>:2168'
        IF mode = '1' THEN 
          --Transition: '<S8>:2224'
          is_i2c_mstr_next <= IN_mastr_ack_data_cnf;
          --Entry 'mastr_ack_data_cnf': '<S8>:2165'
          scl_reg_next <= '1';
          sda_reg_next <= '0';
          mstr_ack_reg_next <= '1';
        ELSE 
          --Transition: '<S8>:2288'
          is_i2c_mstr_next <= IN_mastr_ack_data_cnf1;
          --Entry 'mastr_ack_data_cnf1': '<S8>:2281'
          scl_reg_next <= '1';
          sda_reg_next <= '1';
          mstr_ack_reg_next <= '1';
        END IF;
      WHEN IN_mastr_ack_data_cnf =>
        --During 'mastr_ack_data_cnf': '<S8>:2165'
        --Transition: '<S8>:2211'
        is_i2c_mstr_next <= IN_Increment_Byte_count1;
        --Entry 'Increment_Byte_count1': '<S8>:2187'
        scl_reg_next <= '0';
        bit_cnt_next <= to_unsigned(16#08#, 8);
        mstr_ack_reg_next <= '0';
        reg_data_burst_reg_next <= '1';
        sda_reg_next <= '1';
      WHEN IN_mastr_ack_data_cnf1 =>
        --During 'mastr_ack_data_cnf1': '<S8>:2281'
        --Transition: '<S8>:2282'
        is_i2c_mstr_next <= IN_scl_ext_n;
        --Entry 'scl_ext_n': '<S8>:2163'
        scl_reg_next <= '0';
        sda_reg_next <= '0';
        ack_reg_next <= '0';
        mstr_ack_reg_next <= '0';
      WHEN IN_read_n =>
        --During 'read_n': '<S8>:2228'
        --Transition: '<S8>:2202'
        is_i2c_mstr_next <= IN_read_p;
        --Entry 'read_p': '<S8>:2191'
        scl_reg_next <= '1';
        sda_reg_next <= '1';
        bit_cnt_next <= to_unsigned(16#08#, 8);
      WHEN IN_read_p =>
        --During 'read_p': '<S8>:2191'
        --Transition: '<S8>:2204'
        is_i2c_mstr_next <= IN_ack_slv1;
        --Entry 'ack_slv1': '<S8>:2219'
        scl_reg_next <= '0';
        ack_reg_next <= '1';
        sda_reg_next <= '1';
      WHEN IN_ready =>
        --During 'ready': '<S8>:2156'
        --Transition: '<S8>:2290'
        is_i2c_mstr_next <= IN_start_n;
        --Entry 'start_n': '<S8>:2159'
        scl_reg_next <= '1';
        sda_reg_next <= '0';
        bit_cnt_next <= to_unsigned(16#07#, 8);
        busy_reg_next <= '1';
        data_out_reg_next <= to_unsigned(16#00#, 8);
      WHEN IN_ready_repeated =>
        --During 'ready_repeated': '<S8>:2189'
        --Transition: '<S8>:2245'
        is_i2c_mstr_next <= IN_ready_repeated_dummy;
        --Entry 'ready_repeated_dummy': '<S8>:2233'
        scl_reg_next <= '1';
        sda_reg_next <= '1';
      WHEN IN_ready_repeated_dummy =>
        --During 'ready_repeated_dummy': '<S8>:2233'
        --Transition: '<S8>:2200'
        is_i2c_mstr_next <= IN_repeat_strt_n;
        --Entry 'repeat_strt_n': '<S8>:2182'
        scl_reg_next <= '1';
        sda_reg_next <= '0';
        bit_cnt_next <= to_unsigned(16#07#, 8);
        busy_reg_next <= '1';
      WHEN IN_repeat_strt_n =>
        scl_reg_next <= '1';
        busy_reg_next <= '1';
        --During 'repeat_strt_n': '<S8>:2182'
        --Transition: '<S8>:2249'
        is_i2c_mstr_next <= IN_repeat_strt_p;
        --Entry 'repeat_strt_p': '<S8>:2184'
        sda_reg_next <= '0';
      WHEN IN_repeat_strt_p =>
        --During 'repeat_strt_p': '<S8>:2184'
        --Transition: '<S8>:2248'
        is_i2c_mstr_next <= IN_cmd_slave_addr_n1;
        --Entry 'cmd_slave_addr_n1': '<S8>:2214'
        scl_reg_next <= '0';
        sub_temp_2 := resize(bit_cnt, 9) - to_unsigned(16#001#, 9);
        IF sub_temp_2(8) /= '0' THEN 
          bitkm1_6 := "11111111";
        ELSE 
          bitkm1_6 := sub_temp_2(7 DOWNTO 0);
        END IF;
        sda_reg_next <= slv_addr_unsigned(to_integer(bitkm1_6));
      WHEN IN_scl_ext_n =>
        mstr_ack_reg_next <= '0';
        --During 'scl_ext_n': '<S8>:2163'
        --Transition: '<S8>:2229'
        is_i2c_mstr_next <= IN_scl_ext_p;
        --Entry 'scl_ext_p': '<S8>:2157'
        scl_reg_next <= '1';
        sda_reg_next <= '0';
        ack_reg_next <= '0';
      WHEN IN_scl_ext_p =>
        scl_reg_next <= '1';
        --During 'scl_ext_p': '<S8>:2157'
        --Transition: '<S8>:2209'
        is_i2c_mstr_next <= IN_stop;
        --Entry 'stop': '<S8>:2158'
        sda_reg_next <= '0';
      WHEN IN_start_n =>
        scl_reg_next <= '1';
        busy_reg_next <= '1';
        --During 'start_n': '<S8>:2159'
        --Transition: '<S8>:2210'
        is_i2c_mstr_next <= IN_start_p;
        --Entry 'start_p': '<S8>:2164'
        sda_reg_next <= '0';
      WHEN IN_start_p =>
        --During 'start_p': '<S8>:2164'
        --Transition: '<S8>:2291'
        is_i2c_mstr_next <= IN_cmd_slave_addr_n;
        --Entry 'cmd_slave_addr_n': '<S8>:2166'
        scl_reg_next <= '0';
        sub_temp_3 := resize(bit_cnt, 9) - to_unsigned(16#001#, 9);
        IF sub_temp_3(8) /= '0' THEN 
          bitkm1_7 := "11111111";
        ELSE 
          bitkm1_7 := sub_temp_3(7 DOWNTO 0);
        END IF;
        sda_reg_next <= slv_addr_unsigned(to_integer(bitkm1_7));
      WHEN IN_stop =>
        --During 'stop': '<S8>:2158'
        --Transition: '<S8>:2289'
        is_i2c_mstr_next <= IN_stop_ext;
        --Entry 'stop_ext': '<S8>:2162'
        scl_reg_next <= '1';
        sda_reg_next <= '1';
        ack_reg_next <= '0';
      WHEN IN_stop_ext =>
        --During 'stop_ext': '<S8>:2162'
        --Transition: '<S8>:2215'
        is_i2c_mstr_next <= IN_idle;
        --Entry 'idle': '<S8>:2160'
        scl_reg_next <= '1';
        sda_reg_next <= '1';
        busy_reg_next <= '0';
        reg_data_burst_reg_next <= '0';
        temp_data_next <= to_unsigned(16#00#, 8);
      WHEN IN_write_n =>
        --During 'write_n': '<S8>:2181'
        --Transition: '<S8>:2225'
        is_i2c_mstr_next <= IN_write_p;
        --Entry 'write_p': '<S8>:2185'
        scl_reg_next <= '1';
        sda_reg_next <= '0';
      WHEN OTHERS => 
        --During 'write_p': '<S8>:2185'
        --Transition: '<S8>:2218'
        is_i2c_mstr_next <= IN_ack_slv;
        --Entry 'ack_slv': '<S8>:2170'
        scl_reg_next <= '0';
        ack_reg_next <= '1';
        sda_reg_next <= '1';
    END CASE;
  END PROCESS i2c_mstr_output;

  busy <= busy_reg_next;
  scl <= scl_reg_next;
  sda <= sda_reg_next;
  ack <= ack_reg_next;
  n_ack <= n_ack_reg_next;
  reg_data_burst <= reg_data_burst_reg_next;
  reg_addr_burst <= reg_addr_burst_reg_next;
  mstr_ack <= mstr_ack_reg_next;
  data_out_tmp <= data_out_reg_next;

  data_out <= std_logic_vector(data_out_tmp);

END rtl;

