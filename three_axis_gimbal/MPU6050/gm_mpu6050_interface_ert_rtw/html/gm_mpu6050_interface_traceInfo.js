function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Constant */
	this.urlHashMap["gm_mpu6050_interface:1"] = "gm_mpu6050_interface.c:64&gm_mpu6050_interface.h:91&gm_mpu6050_interface_data.c:31";
	/* <Root>/Constant1 */
	this.urlHashMap["gm_mpu6050_interface:2"] = "gm_mpu6050_interface.c:65&gm_mpu6050_interface.h:94&gm_mpu6050_interface_data.c:34";
	/* <Root>/Constant2 */
	this.urlHashMap["gm_mpu6050_interface:3"] = "gm_mpu6050_interface.c:78&gm_mpu6050_interface.h:85&gm_mpu6050_interface_data.c:25";
	/* <Root>/I2C_MPU6050_IP */
	this.urlHashMap["gm_mpu6050_interface:4"] = "gm_mpu6050_interface.c:34,75,197,239,242,387,397,520";
	/* <Root>/Manual Switch */
	this.urlHashMap["gm_mpu6050_interface:62"] = "gm_mpu6050_interface.c:63,73&gm_mpu6050_interface.h:88&gm_mpu6050_interface_data.c:28";
	/* <Root>/Scope */
	this.urlHashMap["gm_mpu6050_interface:65"] = "gm_mpu6050_interface.h:55";
	/* <Root>/Scope1 */
	this.urlHashMap["gm_mpu6050_interface:66"] = "gm_mpu6050_interface.h:59";
	/* <Root>/UserRegValue */
	this.urlHashMap["gm_mpu6050_interface:67"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:67";
	/* <Root>/deviceID */
	this.urlHashMap["gm_mpu6050_interface:68"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:68";
	/* <Root>/SCL */
	this.urlHashMap["gm_mpu6050_interface:69"] = "gm_mpu6050_interface.c:199&gm_mpu6050_interface.h:76";
	/* <Root>/SDA */
	this.urlHashMap["gm_mpu6050_interface:70"] = "gm_mpu6050_interface.c:202&gm_mpu6050_interface.h:77";
	/* <Root>/CS */
	this.urlHashMap["gm_mpu6050_interface:71"] = "gm_mpu6050_interface.c:205&gm_mpu6050_interface.h:78";
	/* <Root>/AddrAlt */
	this.urlHashMap["gm_mpu6050_interface:72"] = "gm_mpu6050_interface.c:208&gm_mpu6050_interface.h:79";
	/* <S2>/AXI4Lite_Read_AccelX_DTC */
	this.urlHashMap["gm_mpu6050_interface:81"] = "gm_mpu6050_interface.c:106";
	/* <S2>/AXI4Lite_Read_AccelY_DTC */
	this.urlHashMap["gm_mpu6050_interface:83"] = "gm_mpu6050_interface.c:118";
	/* <S2>/AXI4Lite_Read_AccelZ_DTC */
	this.urlHashMap["gm_mpu6050_interface:85"] = "gm_mpu6050_interface.c:130";
	/* <S2>/AXI4Lite_Read_GyroX_DTC */
	this.urlHashMap["gm_mpu6050_interface:97"] = "gm_mpu6050_interface.c:168";
	/* <S2>/AXI4Lite_Read_GyroY_DTC */
	this.urlHashMap["gm_mpu6050_interface:99"] = "gm_mpu6050_interface.c:180";
	/* <S2>/AXI4Lite_Read_GyroZ_DTC */
	this.urlHashMap["gm_mpu6050_interface:101"] = "gm_mpu6050_interface.c:192";
	/* <S2>/AXI4Lite_Read_RegData_DTC */
	this.urlHashMap["gm_mpu6050_interface:95"] = "msg=&block=gm_mpu6050_interface:95";
	/* <S2>/AXI4Lite_Read_deviceID_DTC */
	this.urlHashMap["gm_mpu6050_interface:89"] = "msg=&block=gm_mpu6050_interface:89";
	/* <S2>/AXI4Lite_Read_validout_DTC */
	this.urlHashMap["gm_mpu6050_interface:87"] = "gm_mpu6050_interface.c:142";
	/* <S2>/EXTERNALPORT_ADDRALT_DTC */
	this.urlHashMap["gm_mpu6050_interface:93"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:93";
	/* <S2>/EXTERNALPORT_CS_DTC */
	this.urlHashMap["gm_mpu6050_interface:91"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:91";
	/* <S2>/EXTERNALPORT_SCL_DTC */
	this.urlHashMap["gm_mpu6050_interface:77"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:77";
	/* <S2>/EXTERNALPORT_SDA_DTC */
	this.urlHashMap["gm_mpu6050_interface:79"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:79";
	/* <S3>/AXI4Lite_Write_ConfigDevice_DTC */
	this.urlHashMap["gm_mpu6050_interface:75"] = "gm_mpu6050_interface.c:89";
	/* <S3>/AXI4Lite_Write_RegAddr_DTC */
	this.urlHashMap["gm_mpu6050_interface:73"] = "gm_mpu6050_interface.c:77";
	/* <S4>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:82:16"] = "gm_mpu6050_interface.c:99,100,107,270,281,421,422,430&gm_mpu6050_interface.h:50,71";
	/* <S5>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:84:16"] = "gm_mpu6050_interface.c:111,112,119,283,294,432,433,441&gm_mpu6050_interface.h:49,70";
	/* <S6>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:86:16"] = "gm_mpu6050_interface.c:123,124,131,296,307,443,444,452&gm_mpu6050_interface.h:48,69";
	/* <S7>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:98:16"] = "gm_mpu6050_interface.c:161,162,169,348,359,487,488,496&gm_mpu6050_interface.h:47,68";
	/* <S8>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:100:16"] = "gm_mpu6050_interface.c:173,174,181,361,372,498,499,507&gm_mpu6050_interface.h:46,67";
	/* <S9>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:102:16"] = "gm_mpu6050_interface.c:185,186,193,374,385,509,510,518&gm_mpu6050_interface.h:45,66";
	/* <S10>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:96:16"] = "gm_mpu6050_interface.c:154,155,335,346,476,477,485&gm_mpu6050_interface.h:44,65";
	/* <S11>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:90:16"] = "gm_mpu6050_interface.c:147,148,322,333,465,466,474&gm_mpu6050_interface.h:43,64";
	/* <S12>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:88:16"] = "gm_mpu6050_interface.c:135,136,143,309,320,454,455,463&gm_mpu6050_interface.h:42,63";
	/* <S13>/AXI4-Interface Write */
	this.urlHashMap["gm_mpu6050_interface:76:17"] = "gm_mpu6050_interface.c:92,93,257,268,410,411,419&gm_mpu6050_interface.h:52,62";
	/* <S14>/AXI4-Interface Write */
	this.urlHashMap["gm_mpu6050_interface:74:17"] = "gm_mpu6050_interface.c:82,83,244,255,399,400,408&gm_mpu6050_interface.h:51,61";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "gm_mpu6050_interface"};
	this.sidHashMap["gm_mpu6050_interface"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "gm_mpu6050_interface:4"};
	this.sidHashMap["gm_mpu6050_interface:4"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "gm_mpu6050_interface:106"};
	this.sidHashMap["gm_mpu6050_interface:106"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "gm_mpu6050_interface:103"};
	this.sidHashMap["gm_mpu6050_interface:103"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "gm_mpu6050_interface:82"};
	this.sidHashMap["gm_mpu6050_interface:82"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<S5>"] = {sid: "gm_mpu6050_interface:84"};
	this.sidHashMap["gm_mpu6050_interface:84"] = {rtwname: "<S5>"};
	this.rtwnameHashMap["<S6>"] = {sid: "gm_mpu6050_interface:86"};
	this.sidHashMap["gm_mpu6050_interface:86"] = {rtwname: "<S6>"};
	this.rtwnameHashMap["<S7>"] = {sid: "gm_mpu6050_interface:98"};
	this.sidHashMap["gm_mpu6050_interface:98"] = {rtwname: "<S7>"};
	this.rtwnameHashMap["<S8>"] = {sid: "gm_mpu6050_interface:100"};
	this.sidHashMap["gm_mpu6050_interface:100"] = {rtwname: "<S8>"};
	this.rtwnameHashMap["<S9>"] = {sid: "gm_mpu6050_interface:102"};
	this.sidHashMap["gm_mpu6050_interface:102"] = {rtwname: "<S9>"};
	this.rtwnameHashMap["<S10>"] = {sid: "gm_mpu6050_interface:96"};
	this.sidHashMap["gm_mpu6050_interface:96"] = {rtwname: "<S10>"};
	this.rtwnameHashMap["<S11>"] = {sid: "gm_mpu6050_interface:90"};
	this.sidHashMap["gm_mpu6050_interface:90"] = {rtwname: "<S11>"};
	this.rtwnameHashMap["<S12>"] = {sid: "gm_mpu6050_interface:88"};
	this.sidHashMap["gm_mpu6050_interface:88"] = {rtwname: "<S12>"};
	this.rtwnameHashMap["<S13>"] = {sid: "gm_mpu6050_interface:76"};
	this.sidHashMap["gm_mpu6050_interface:76"] = {rtwname: "<S13>"};
	this.rtwnameHashMap["<S14>"] = {sid: "gm_mpu6050_interface:74"};
	this.sidHashMap["gm_mpu6050_interface:74"] = {rtwname: "<S14>"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "gm_mpu6050_interface:1"};
	this.sidHashMap["gm_mpu6050_interface:1"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "gm_mpu6050_interface:2"};
	this.sidHashMap["gm_mpu6050_interface:2"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/Constant2"] = {sid: "gm_mpu6050_interface:3"};
	this.sidHashMap["gm_mpu6050_interface:3"] = {rtwname: "<Root>/Constant2"};
	this.rtwnameHashMap["<Root>/I2C_MPU6050_IP"] = {sid: "gm_mpu6050_interface:4"};
	this.sidHashMap["gm_mpu6050_interface:4"] = {rtwname: "<Root>/I2C_MPU6050_IP"};
	this.rtwnameHashMap["<Root>/Manual Switch"] = {sid: "gm_mpu6050_interface:62"};
	this.sidHashMap["gm_mpu6050_interface:62"] = {rtwname: "<Root>/Manual Switch"};
	this.rtwnameHashMap["<Root>/Mux"] = {sid: "gm_mpu6050_interface:63"};
	this.sidHashMap["gm_mpu6050_interface:63"] = {rtwname: "<Root>/Mux"};
	this.rtwnameHashMap["<Root>/Mux1"] = {sid: "gm_mpu6050_interface:64"};
	this.sidHashMap["gm_mpu6050_interface:64"] = {rtwname: "<Root>/Mux1"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "gm_mpu6050_interface:65"};
	this.sidHashMap["gm_mpu6050_interface:65"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<Root>/Scope1"] = {sid: "gm_mpu6050_interface:66"};
	this.sidHashMap["gm_mpu6050_interface:66"] = {rtwname: "<Root>/Scope1"};
	this.rtwnameHashMap["<Root>/UserRegValue"] = {sid: "gm_mpu6050_interface:67"};
	this.sidHashMap["gm_mpu6050_interface:67"] = {rtwname: "<Root>/UserRegValue"};
	this.rtwnameHashMap["<Root>/deviceID"] = {sid: "gm_mpu6050_interface:68"};
	this.sidHashMap["gm_mpu6050_interface:68"] = {rtwname: "<Root>/deviceID"};
	this.rtwnameHashMap["<Root>/SCL"] = {sid: "gm_mpu6050_interface:69"};
	this.sidHashMap["gm_mpu6050_interface:69"] = {rtwname: "<Root>/SCL"};
	this.rtwnameHashMap["<Root>/SDA"] = {sid: "gm_mpu6050_interface:70"};
	this.sidHashMap["gm_mpu6050_interface:70"] = {rtwname: "<Root>/SDA"};
	this.rtwnameHashMap["<Root>/CS"] = {sid: "gm_mpu6050_interface:71"};
	this.sidHashMap["gm_mpu6050_interface:71"] = {rtwname: "<Root>/CS"};
	this.rtwnameHashMap["<Root>/AddrAlt"] = {sid: "gm_mpu6050_interface:72"};
	this.sidHashMap["gm_mpu6050_interface:72"] = {rtwname: "<Root>/AddrAlt"};
	this.rtwnameHashMap["<S1>/RegAddr"] = {sid: "gm_mpu6050_interface:5"};
	this.sidHashMap["gm_mpu6050_interface:5"] = {rtwname: "<S1>/RegAddr"};
	this.rtwnameHashMap["<S1>/ConfigDevice"] = {sid: "gm_mpu6050_interface:6"};
	this.sidHashMap["gm_mpu6050_interface:6"] = {rtwname: "<S1>/ConfigDevice"};
	this.rtwnameHashMap["<S1>/AXI4LiteRead"] = {sid: "gm_mpu6050_interface:106"};
	this.sidHashMap["gm_mpu6050_interface:106"] = {rtwname: "<S1>/AXI4LiteRead"};
	this.rtwnameHashMap["<S1>/AXI4LiteWrite"] = {sid: "gm_mpu6050_interface:103"};
	this.sidHashMap["gm_mpu6050_interface:103"] = {rtwname: "<S1>/AXI4LiteWrite"};
	this.rtwnameHashMap["<S1>/AXI4Reset"] = {sid: "gm_mpu6050_interface:120"};
	this.sidHashMap["gm_mpu6050_interface:120"] = {rtwname: "<S1>/AXI4Reset"};
	this.rtwnameHashMap["<S1>/AXI4ResetModelSource"] = {sid: "gm_mpu6050_interface:121"};
	this.sidHashMap["gm_mpu6050_interface:121"] = {rtwname: "<S1>/AXI4ResetModelSource"};
	this.rtwnameHashMap["<S1>/SCL"] = {sid: "gm_mpu6050_interface:48"};
	this.sidHashMap["gm_mpu6050_interface:48"] = {rtwname: "<S1>/SCL"};
	this.rtwnameHashMap["<S1>/SDA"] = {sid: "gm_mpu6050_interface:49"};
	this.sidHashMap["gm_mpu6050_interface:49"] = {rtwname: "<S1>/SDA"};
	this.rtwnameHashMap["<S1>/AccelX"] = {sid: "gm_mpu6050_interface:50"};
	this.sidHashMap["gm_mpu6050_interface:50"] = {rtwname: "<S1>/AccelX"};
	this.rtwnameHashMap["<S1>/AccelY"] = {sid: "gm_mpu6050_interface:51"};
	this.sidHashMap["gm_mpu6050_interface:51"] = {rtwname: "<S1>/AccelY"};
	this.rtwnameHashMap["<S1>/AccelZ"] = {sid: "gm_mpu6050_interface:52"};
	this.sidHashMap["gm_mpu6050_interface:52"] = {rtwname: "<S1>/AccelZ"};
	this.rtwnameHashMap["<S1>/validout"] = {sid: "gm_mpu6050_interface:53"};
	this.sidHashMap["gm_mpu6050_interface:53"] = {rtwname: "<S1>/validout"};
	this.rtwnameHashMap["<S1>/deviceID"] = {sid: "gm_mpu6050_interface:54"};
	this.sidHashMap["gm_mpu6050_interface:54"] = {rtwname: "<S1>/deviceID"};
	this.rtwnameHashMap["<S1>/CS"] = {sid: "gm_mpu6050_interface:55"};
	this.sidHashMap["gm_mpu6050_interface:55"] = {rtwname: "<S1>/CS"};
	this.rtwnameHashMap["<S1>/ADDRALT"] = {sid: "gm_mpu6050_interface:56"};
	this.sidHashMap["gm_mpu6050_interface:56"] = {rtwname: "<S1>/ADDRALT"};
	this.rtwnameHashMap["<S1>/RegData"] = {sid: "gm_mpu6050_interface:57"};
	this.sidHashMap["gm_mpu6050_interface:57"] = {rtwname: "<S1>/RegData"};
	this.rtwnameHashMap["<S1>/GyroX"] = {sid: "gm_mpu6050_interface:58"};
	this.sidHashMap["gm_mpu6050_interface:58"] = {rtwname: "<S1>/GyroX"};
	this.rtwnameHashMap["<S1>/GyroY"] = {sid: "gm_mpu6050_interface:59"};
	this.sidHashMap["gm_mpu6050_interface:59"] = {rtwname: "<S1>/GyroY"};
	this.rtwnameHashMap["<S1>/GyroZ"] = {sid: "gm_mpu6050_interface:60"};
	this.sidHashMap["gm_mpu6050_interface:60"] = {rtwname: "<S1>/GyroZ"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_AccelX"] = {sid: "gm_mpu6050_interface:82"};
	this.sidHashMap["gm_mpu6050_interface:82"] = {rtwname: "<S2>/AXI4Lite_Read_AccelX"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_AccelX_DTC"] = {sid: "gm_mpu6050_interface:81"};
	this.sidHashMap["gm_mpu6050_interface:81"] = {rtwname: "<S2>/AXI4Lite_Read_AccelX_DTC"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_AccelY"] = {sid: "gm_mpu6050_interface:84"};
	this.sidHashMap["gm_mpu6050_interface:84"] = {rtwname: "<S2>/AXI4Lite_Read_AccelY"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_AccelY_DTC"] = {sid: "gm_mpu6050_interface:83"};
	this.sidHashMap["gm_mpu6050_interface:83"] = {rtwname: "<S2>/AXI4Lite_Read_AccelY_DTC"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_AccelZ"] = {sid: "gm_mpu6050_interface:86"};
	this.sidHashMap["gm_mpu6050_interface:86"] = {rtwname: "<S2>/AXI4Lite_Read_AccelZ"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_AccelZ_DTC"] = {sid: "gm_mpu6050_interface:85"};
	this.sidHashMap["gm_mpu6050_interface:85"] = {rtwname: "<S2>/AXI4Lite_Read_AccelZ_DTC"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_GyroX"] = {sid: "gm_mpu6050_interface:98"};
	this.sidHashMap["gm_mpu6050_interface:98"] = {rtwname: "<S2>/AXI4Lite_Read_GyroX"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_GyroX_DTC"] = {sid: "gm_mpu6050_interface:97"};
	this.sidHashMap["gm_mpu6050_interface:97"] = {rtwname: "<S2>/AXI4Lite_Read_GyroX_DTC"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_GyroY"] = {sid: "gm_mpu6050_interface:100"};
	this.sidHashMap["gm_mpu6050_interface:100"] = {rtwname: "<S2>/AXI4Lite_Read_GyroY"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_GyroY_DTC"] = {sid: "gm_mpu6050_interface:99"};
	this.sidHashMap["gm_mpu6050_interface:99"] = {rtwname: "<S2>/AXI4Lite_Read_GyroY_DTC"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_GyroZ"] = {sid: "gm_mpu6050_interface:102"};
	this.sidHashMap["gm_mpu6050_interface:102"] = {rtwname: "<S2>/AXI4Lite_Read_GyroZ"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_GyroZ_DTC"] = {sid: "gm_mpu6050_interface:101"};
	this.sidHashMap["gm_mpu6050_interface:101"] = {rtwname: "<S2>/AXI4Lite_Read_GyroZ_DTC"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_RegData"] = {sid: "gm_mpu6050_interface:96"};
	this.sidHashMap["gm_mpu6050_interface:96"] = {rtwname: "<S2>/AXI4Lite_Read_RegData"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_RegData_DTC"] = {sid: "gm_mpu6050_interface:95"};
	this.sidHashMap["gm_mpu6050_interface:95"] = {rtwname: "<S2>/AXI4Lite_Read_RegData_DTC"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_deviceID"] = {sid: "gm_mpu6050_interface:90"};
	this.sidHashMap["gm_mpu6050_interface:90"] = {rtwname: "<S2>/AXI4Lite_Read_deviceID"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_deviceID_DTC"] = {sid: "gm_mpu6050_interface:89"};
	this.sidHashMap["gm_mpu6050_interface:89"] = {rtwname: "<S2>/AXI4Lite_Read_deviceID_DTC"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_validout"] = {sid: "gm_mpu6050_interface:88"};
	this.sidHashMap["gm_mpu6050_interface:88"] = {rtwname: "<S2>/AXI4Lite_Read_validout"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_validout_DTC"] = {sid: "gm_mpu6050_interface:87"};
	this.sidHashMap["gm_mpu6050_interface:87"] = {rtwname: "<S2>/AXI4Lite_Read_validout_DTC"};
	this.rtwnameHashMap["<S2>/EXTERNALPORT_ADDRALT_DTC"] = {sid: "gm_mpu6050_interface:93"};
	this.sidHashMap["gm_mpu6050_interface:93"] = {rtwname: "<S2>/EXTERNALPORT_ADDRALT_DTC"};
	this.rtwnameHashMap["<S2>/EXTERNALPORT_CS_DTC"] = {sid: "gm_mpu6050_interface:91"};
	this.sidHashMap["gm_mpu6050_interface:91"] = {rtwname: "<S2>/EXTERNALPORT_CS_DTC"};
	this.rtwnameHashMap["<S2>/EXTERNALPORT_SCL_DTC"] = {sid: "gm_mpu6050_interface:77"};
	this.sidHashMap["gm_mpu6050_interface:77"] = {rtwname: "<S2>/EXTERNALPORT_SCL_DTC"};
	this.rtwnameHashMap["<S2>/EXTERNALPORT_SDA_DTC"] = {sid: "gm_mpu6050_interface:79"};
	this.sidHashMap["gm_mpu6050_interface:79"] = {rtwname: "<S2>/EXTERNALPORT_SDA_DTC"};
	this.rtwnameHashMap["<S2>/GROUND_ADDRALT"] = {sid: "gm_mpu6050_interface:94"};
	this.sidHashMap["gm_mpu6050_interface:94"] = {rtwname: "<S2>/GROUND_ADDRALT"};
	this.rtwnameHashMap["<S2>/GROUND_CS"] = {sid: "gm_mpu6050_interface:92"};
	this.sidHashMap["gm_mpu6050_interface:92"] = {rtwname: "<S2>/GROUND_CS"};
	this.rtwnameHashMap["<S2>/GROUND_SCL"] = {sid: "gm_mpu6050_interface:78"};
	this.sidHashMap["gm_mpu6050_interface:78"] = {rtwname: "<S2>/GROUND_SCL"};
	this.rtwnameHashMap["<S2>/GROUND_SDA"] = {sid: "gm_mpu6050_interface:80"};
	this.sidHashMap["gm_mpu6050_interface:80"] = {rtwname: "<S2>/GROUND_SDA"};
	this.rtwnameHashMap["<S2>/Out1"] = {sid: "gm_mpu6050_interface:107"};
	this.sidHashMap["gm_mpu6050_interface:107"] = {rtwname: "<S2>/Out1"};
	this.rtwnameHashMap["<S2>/Out2"] = {sid: "gm_mpu6050_interface:108"};
	this.sidHashMap["gm_mpu6050_interface:108"] = {rtwname: "<S2>/Out2"};
	this.rtwnameHashMap["<S2>/Out3"] = {sid: "gm_mpu6050_interface:109"};
	this.sidHashMap["gm_mpu6050_interface:109"] = {rtwname: "<S2>/Out3"};
	this.rtwnameHashMap["<S2>/Out4"] = {sid: "gm_mpu6050_interface:110"};
	this.sidHashMap["gm_mpu6050_interface:110"] = {rtwname: "<S2>/Out4"};
	this.rtwnameHashMap["<S2>/Out5"] = {sid: "gm_mpu6050_interface:111"};
	this.sidHashMap["gm_mpu6050_interface:111"] = {rtwname: "<S2>/Out5"};
	this.rtwnameHashMap["<S2>/Out6"] = {sid: "gm_mpu6050_interface:112"};
	this.sidHashMap["gm_mpu6050_interface:112"] = {rtwname: "<S2>/Out6"};
	this.rtwnameHashMap["<S2>/Out7"] = {sid: "gm_mpu6050_interface:113"};
	this.sidHashMap["gm_mpu6050_interface:113"] = {rtwname: "<S2>/Out7"};
	this.rtwnameHashMap["<S2>/Out8"] = {sid: "gm_mpu6050_interface:114"};
	this.sidHashMap["gm_mpu6050_interface:114"] = {rtwname: "<S2>/Out8"};
	this.rtwnameHashMap["<S2>/Out9"] = {sid: "gm_mpu6050_interface:115"};
	this.sidHashMap["gm_mpu6050_interface:115"] = {rtwname: "<S2>/Out9"};
	this.rtwnameHashMap["<S2>/Out10"] = {sid: "gm_mpu6050_interface:116"};
	this.sidHashMap["gm_mpu6050_interface:116"] = {rtwname: "<S2>/Out10"};
	this.rtwnameHashMap["<S2>/Out11"] = {sid: "gm_mpu6050_interface:117"};
	this.sidHashMap["gm_mpu6050_interface:117"] = {rtwname: "<S2>/Out11"};
	this.rtwnameHashMap["<S2>/Out12"] = {sid: "gm_mpu6050_interface:118"};
	this.sidHashMap["gm_mpu6050_interface:118"] = {rtwname: "<S2>/Out12"};
	this.rtwnameHashMap["<S2>/Out13"] = {sid: "gm_mpu6050_interface:119"};
	this.sidHashMap["gm_mpu6050_interface:119"] = {rtwname: "<S2>/Out13"};
	this.rtwnameHashMap["<S3>/In1"] = {sid: "gm_mpu6050_interface:104"};
	this.sidHashMap["gm_mpu6050_interface:104"] = {rtwname: "<S3>/In1"};
	this.rtwnameHashMap["<S3>/In2"] = {sid: "gm_mpu6050_interface:105"};
	this.sidHashMap["gm_mpu6050_interface:105"] = {rtwname: "<S3>/In2"};
	this.rtwnameHashMap["<S3>/AXI4Lite_Write_ConfigDevice"] = {sid: "gm_mpu6050_interface:76"};
	this.sidHashMap["gm_mpu6050_interface:76"] = {rtwname: "<S3>/AXI4Lite_Write_ConfigDevice"};
	this.rtwnameHashMap["<S3>/AXI4Lite_Write_ConfigDevice_DTC"] = {sid: "gm_mpu6050_interface:75"};
	this.sidHashMap["gm_mpu6050_interface:75"] = {rtwname: "<S3>/AXI4Lite_Write_ConfigDevice_DTC"};
	this.rtwnameHashMap["<S3>/AXI4Lite_Write_RegAddr"] = {sid: "gm_mpu6050_interface:74"};
	this.sidHashMap["gm_mpu6050_interface:74"] = {rtwname: "<S3>/AXI4Lite_Write_RegAddr"};
	this.rtwnameHashMap["<S3>/AXI4Lite_Write_RegAddr_DTC"] = {sid: "gm_mpu6050_interface:73"};
	this.sidHashMap["gm_mpu6050_interface:73"] = {rtwname: "<S3>/AXI4Lite_Write_RegAddr_DTC"};
	this.rtwnameHashMap["<S4>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:82:16"};
	this.sidHashMap["gm_mpu6050_interface:82:16"] = {rtwname: "<S4>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S4>/Signal Specification"] = {sid: "gm_mpu6050_interface:82:24"};
	this.sidHashMap["gm_mpu6050_interface:82:24"] = {rtwname: "<S4>/Signal Specification"};
	this.rtwnameHashMap["<S4>/Out1"] = {sid: "gm_mpu6050_interface:82:19"};
	this.sidHashMap["gm_mpu6050_interface:82:19"] = {rtwname: "<S4>/Out1"};
	this.rtwnameHashMap["<S5>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:84:16"};
	this.sidHashMap["gm_mpu6050_interface:84:16"] = {rtwname: "<S5>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S5>/Signal Specification"] = {sid: "gm_mpu6050_interface:84:24"};
	this.sidHashMap["gm_mpu6050_interface:84:24"] = {rtwname: "<S5>/Signal Specification"};
	this.rtwnameHashMap["<S5>/Out1"] = {sid: "gm_mpu6050_interface:84:19"};
	this.sidHashMap["gm_mpu6050_interface:84:19"] = {rtwname: "<S5>/Out1"};
	this.rtwnameHashMap["<S6>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:86:16"};
	this.sidHashMap["gm_mpu6050_interface:86:16"] = {rtwname: "<S6>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S6>/Signal Specification"] = {sid: "gm_mpu6050_interface:86:24"};
	this.sidHashMap["gm_mpu6050_interface:86:24"] = {rtwname: "<S6>/Signal Specification"};
	this.rtwnameHashMap["<S6>/Out1"] = {sid: "gm_mpu6050_interface:86:19"};
	this.sidHashMap["gm_mpu6050_interface:86:19"] = {rtwname: "<S6>/Out1"};
	this.rtwnameHashMap["<S7>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:98:16"};
	this.sidHashMap["gm_mpu6050_interface:98:16"] = {rtwname: "<S7>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S7>/Signal Specification"] = {sid: "gm_mpu6050_interface:98:24"};
	this.sidHashMap["gm_mpu6050_interface:98:24"] = {rtwname: "<S7>/Signal Specification"};
	this.rtwnameHashMap["<S7>/Out1"] = {sid: "gm_mpu6050_interface:98:19"};
	this.sidHashMap["gm_mpu6050_interface:98:19"] = {rtwname: "<S7>/Out1"};
	this.rtwnameHashMap["<S8>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:100:16"};
	this.sidHashMap["gm_mpu6050_interface:100:16"] = {rtwname: "<S8>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S8>/Signal Specification"] = {sid: "gm_mpu6050_interface:100:24"};
	this.sidHashMap["gm_mpu6050_interface:100:24"] = {rtwname: "<S8>/Signal Specification"};
	this.rtwnameHashMap["<S8>/Out1"] = {sid: "gm_mpu6050_interface:100:19"};
	this.sidHashMap["gm_mpu6050_interface:100:19"] = {rtwname: "<S8>/Out1"};
	this.rtwnameHashMap["<S9>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:102:16"};
	this.sidHashMap["gm_mpu6050_interface:102:16"] = {rtwname: "<S9>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S9>/Signal Specification"] = {sid: "gm_mpu6050_interface:102:24"};
	this.sidHashMap["gm_mpu6050_interface:102:24"] = {rtwname: "<S9>/Signal Specification"};
	this.rtwnameHashMap["<S9>/Out1"] = {sid: "gm_mpu6050_interface:102:19"};
	this.sidHashMap["gm_mpu6050_interface:102:19"] = {rtwname: "<S9>/Out1"};
	this.rtwnameHashMap["<S10>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:96:16"};
	this.sidHashMap["gm_mpu6050_interface:96:16"] = {rtwname: "<S10>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S10>/Signal Specification"] = {sid: "gm_mpu6050_interface:96:24"};
	this.sidHashMap["gm_mpu6050_interface:96:24"] = {rtwname: "<S10>/Signal Specification"};
	this.rtwnameHashMap["<S10>/Out1"] = {sid: "gm_mpu6050_interface:96:19"};
	this.sidHashMap["gm_mpu6050_interface:96:19"] = {rtwname: "<S10>/Out1"};
	this.rtwnameHashMap["<S11>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:90:16"};
	this.sidHashMap["gm_mpu6050_interface:90:16"] = {rtwname: "<S11>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S11>/Signal Specification"] = {sid: "gm_mpu6050_interface:90:24"};
	this.sidHashMap["gm_mpu6050_interface:90:24"] = {rtwname: "<S11>/Signal Specification"};
	this.rtwnameHashMap["<S11>/Out1"] = {sid: "gm_mpu6050_interface:90:19"};
	this.sidHashMap["gm_mpu6050_interface:90:19"] = {rtwname: "<S11>/Out1"};
	this.rtwnameHashMap["<S12>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:88:16"};
	this.sidHashMap["gm_mpu6050_interface:88:16"] = {rtwname: "<S12>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S12>/Signal Specification"] = {sid: "gm_mpu6050_interface:88:24"};
	this.sidHashMap["gm_mpu6050_interface:88:24"] = {rtwname: "<S12>/Signal Specification"};
	this.rtwnameHashMap["<S12>/Out1"] = {sid: "gm_mpu6050_interface:88:19"};
	this.sidHashMap["gm_mpu6050_interface:88:19"] = {rtwname: "<S12>/Out1"};
	this.rtwnameHashMap["<S13>/In1"] = {sid: "gm_mpu6050_interface:76:21"};
	this.sidHashMap["gm_mpu6050_interface:76:21"] = {rtwname: "<S13>/In1"};
	this.rtwnameHashMap["<S13>/AXI4-Interface Write"] = {sid: "gm_mpu6050_interface:76:17"};
	this.sidHashMap["gm_mpu6050_interface:76:17"] = {rtwname: "<S13>/AXI4-Interface Write"};
	this.rtwnameHashMap["<S13>/Signal Specification"] = {sid: "gm_mpu6050_interface:76:24"};
	this.sidHashMap["gm_mpu6050_interface:76:24"] = {rtwname: "<S13>/Signal Specification"};
	this.rtwnameHashMap["<S14>/In1"] = {sid: "gm_mpu6050_interface:74:21"};
	this.sidHashMap["gm_mpu6050_interface:74:21"] = {rtwname: "<S14>/In1"};
	this.rtwnameHashMap["<S14>/AXI4-Interface Write"] = {sid: "gm_mpu6050_interface:74:17"};
	this.sidHashMap["gm_mpu6050_interface:74:17"] = {rtwname: "<S14>/AXI4-Interface Write"};
	this.rtwnameHashMap["<S14>/Signal Specification"] = {sid: "gm_mpu6050_interface:74:24"};
	this.sidHashMap["gm_mpu6050_interface:74:24"] = {rtwname: "<S14>/Signal Specification"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
