library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

Library UNISIM;
use UNISIM.vcomponents.all;

entity i2c_bidir 
is Port ( 
		I2C_CLK     : in STD_LOGIC := 'Z'; 
		I2C_DATA	: in STD_LOGIC := 'Z';
		ack			: in STD_LOGIC;
		I2C_SCL		: out STD_LOGIC;
		I2C_SDA		: inout STD_LOGIC;
		sda_local	: out STD_LOGIC :='Z'
	);
end i2c_bidir;

architecture Behavioral of i2c_bidir is

begin

 -- sda_local <= '0'; --Acknowlegement
	
 IOBUF_inst : IOBUF
  port map (
     O => sda_local, 	-- Buffer output
     IO=> I2C_SDA,   	-- Buffer inout port (connect directly to top-level port)
     I => '0',			-- Buffer input
     T => I2C_DATA  	-- 3-state enable input, high=input, low=output 
  );
  
  
 OBUF_inst : OBUF
  port map (
     O => I2C_SCL,     	-- Buffer output (connect directly to top-level port)
     I => I2C_CLK  		-- Buffer input 
  );
   
end Behavioral;