function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Constant */
	this.urlHashMap["gm_mpu6050_working_interface:49"] = "gm_mpu6050_working_interface.c:82&gm_mpu6050_working_interface.h:157&gm_mpu6050_working_interface_data.c:49";
	/* <Root>/Constant1 */
	this.urlHashMap["gm_mpu6050_working_interface:50"] = "gm_mpu6050_working_interface.c:83&gm_mpu6050_working_interface.h:160&gm_mpu6050_working_interface_data.c:52";
	/* <Root>/Constant2 */
	this.urlHashMap["gm_mpu6050_working_interface:51"] = "gm_mpu6050_working_interface.c:96&gm_mpu6050_working_interface.h:151&gm_mpu6050_working_interface_data.c:43";
	/* <Root>/Constant3 */
	this.urlHashMap["gm_mpu6050_working_interface:52"] = "gm_mpu6050_working_interface.c:226&gm_mpu6050_working_interface.h:142&gm_mpu6050_working_interface_data.c:34";
	/* <Root>/Constant4 */
	this.urlHashMap["gm_mpu6050_working_interface:53"] = "gm_mpu6050_working_interface.c:243&gm_mpu6050_working_interface.h:145&gm_mpu6050_working_interface_data.c:37";
	/* <Root>/Constant5 */
	this.urlHashMap["gm_mpu6050_working_interface:54"] = "gm_mpu6050_working_interface.c:260&gm_mpu6050_working_interface.h:148&gm_mpu6050_working_interface_data.c:40";
	/* <Root>/I2C_MPU6050_IP */
	this.urlHashMap["gm_mpu6050_working_interface:55"] = "gm_mpu6050_working_interface.c:36,93,223,408,411,569,591,725";
	/* <Root>/Manual Switch */
	this.urlHashMap["gm_mpu6050_working_interface:114"] = "gm_mpu6050_working_interface.c:81,91&gm_mpu6050_working_interface.h:154&gm_mpu6050_working_interface_data.c:46";
	/* <Root>/Scope */
	this.urlHashMap["gm_mpu6050_working_interface:115"] = "gm_mpu6050_working_interface.h:107";
	/* <Root>/UserRegValue */
	this.urlHashMap["gm_mpu6050_working_interface:147"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_working_interface:147";
	/* <Root>/deviceID */
	this.urlHashMap["gm_mpu6050_working_interface:148"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_working_interface:148";
	/* <Root>/gyroX */
	this.urlHashMap["gm_mpu6050_working_interface:149"] = "gm_mpu6050_working_interface.c:239&gm_mpu6050_working_interface.h:125";
	/* <Root>/gyroY */
	this.urlHashMap["gm_mpu6050_working_interface:150"] = "gm_mpu6050_working_interface.c:256&gm_mpu6050_working_interface.h:126";
	/* <Root>/gyroZ */
	this.urlHashMap["gm_mpu6050_working_interface:151"] = "gm_mpu6050_working_interface.c:273&gm_mpu6050_working_interface.h:127";
	/* <S1>/MATLAB Function1 */
	this.urlHashMap["gm_mpu6050_working_interface:12"] = "gm_mpu6050_working_interface.c:55,225&gm_mpu6050_working_interface.h:80";
	/* <S1>/Subtract */
	this.urlHashMap["gm_mpu6050_working_interface:13"] = "gm_mpu6050_working_interface.c:229";
	/* <S1>/Sum1 */
	this.urlHashMap["gm_mpu6050_working_interface:14"] = "gm_mpu6050_working_interface.c:230";
	/* <S1>/Unit Delay3 */
	this.urlHashMap["gm_mpu6050_working_interface:15"] = "gm_mpu6050_working_interface.c:231,276,572&gm_mpu6050_working_interface.h:90,133&gm_mpu6050_working_interface_data.c:25";
	/* <S2>/MATLAB Function1 */
	this.urlHashMap["gm_mpu6050_working_interface:28"] = "gm_mpu6050_working_interface.c:56,242&gm_mpu6050_working_interface.h:79";
	/* <S2>/Subtract */
	this.urlHashMap["gm_mpu6050_working_interface:29"] = "gm_mpu6050_working_interface.c:246";
	/* <S2>/Sum1 */
	this.urlHashMap["gm_mpu6050_working_interface:30"] = "gm_mpu6050_working_interface.c:247";
	/* <S2>/Unit Delay3 */
	this.urlHashMap["gm_mpu6050_working_interface:31"] = "gm_mpu6050_working_interface.c:248,280,576&gm_mpu6050_working_interface.h:91,136&gm_mpu6050_working_interface_data.c:28";
	/* <S3>/MATLAB Function1 */
	this.urlHashMap["gm_mpu6050_working_interface:44"] = "gm_mpu6050_working_interface.c:57,259&gm_mpu6050_working_interface.h:78";
	/* <S3>/Subtract */
	this.urlHashMap["gm_mpu6050_working_interface:45"] = "gm_mpu6050_working_interface.c:263";
	/* <S3>/Sum1 */
	this.urlHashMap["gm_mpu6050_working_interface:46"] = "gm_mpu6050_working_interface.c:264";
	/* <S3>/Unit Delay3 */
	this.urlHashMap["gm_mpu6050_working_interface:47"] = "gm_mpu6050_working_interface.c:265,284,580&gm_mpu6050_working_interface.h:92,139&gm_mpu6050_working_interface_data.c:31";
	/* <S5>/Chart */
	this.urlHashMap["gm_mpu6050_working_interface:119"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:119";
	/* <S5>/Display1 */
	this.urlHashMap["gm_mpu6050_working_interface:120"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:120";
	/* <S5>/ESCPeriod */
	this.urlHashMap["gm_mpu6050_working_interface:121"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:121";
	/* <S5>/Gain */
	this.urlHashMap["gm_mpu6050_working_interface:122"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:122";
	/* <S6>/Data Type Conversion */
	this.urlHashMap["gm_mpu6050_working_interface:7"] = "gm_mpu6050_working_interface.c:227";
	/* <S6>/Fcn */
	this.urlHashMap["gm_mpu6050_working_interface:8"] = "gm_mpu6050_working_interface.c:228";
	/* <S6>/Fcn1 */
	this.urlHashMap["gm_mpu6050_working_interface:9"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:9";
	/* <S7>:1 */
	this.urlHashMap["gm_mpu6050_working_interface:12:1"] = "gm_mpu6050_working_interface.c:62";
	/* <S7>:1:2 */
	this.urlHashMap["gm_mpu6050_working_interface:12:1:2"] = "gm_mpu6050_working_interface.c:63";
	/* <S7>:1:3 */
	this.urlHashMap["gm_mpu6050_working_interface:12:1:3"] = "gm_mpu6050_working_interface.c:65";
	/* <S7>:1:4 */
	this.urlHashMap["gm_mpu6050_working_interface:12:1:4"] = "gm_mpu6050_working_interface.c:68";
	/* <S7>:1:5 */
	this.urlHashMap["gm_mpu6050_working_interface:12:1:5"] = "gm_mpu6050_working_interface.c:69";
	/* <S8>/Data Type Conversion */
	this.urlHashMap["gm_mpu6050_working_interface:23"] = "gm_mpu6050_working_interface.c:244";
	/* <S8>/Fcn */
	this.urlHashMap["gm_mpu6050_working_interface:24"] = "gm_mpu6050_working_interface.c:245";
	/* <S8>/Fcn1 */
	this.urlHashMap["gm_mpu6050_working_interface:25"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:25";
	/* <S9>:1 */
	this.urlHashMap["gm_mpu6050_working_interface:28:1"] = "msg=rtwMsg_reusableFunction&block=gm_mpu6050_working_interface:28:1";
	/* <S10>/Data Type Conversion */
	this.urlHashMap["gm_mpu6050_working_interface:39"] = "gm_mpu6050_working_interface.c:261";
	/* <S10>/Fcn */
	this.urlHashMap["gm_mpu6050_working_interface:40"] = "gm_mpu6050_working_interface.c:262";
	/* <S10>/Fcn1 */
	this.urlHashMap["gm_mpu6050_working_interface:41"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:41";
	/* <S11>:1 */
	this.urlHashMap["gm_mpu6050_working_interface:44:1"] = "msg=rtwMsg_reusableFunction&block=gm_mpu6050_working_interface:44:1";
	/* <S12>/AXI4Lite_Read_AccelX_DTC */
	this.urlHashMap["gm_mpu6050_working_interface:162"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:162";
	/* <S12>/AXI4Lite_Read_AccelY_DTC */
	this.urlHashMap["gm_mpu6050_working_interface:164"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:164";
	/* <S12>/AXI4Lite_Read_AccelZ_DTC */
	this.urlHashMap["gm_mpu6050_working_interface:166"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:166";
	/* <S12>/AXI4Lite_Read_GyroX_DTC */
	this.urlHashMap["gm_mpu6050_working_interface:178"] = "gm_mpu6050_working_interface.c:179&gm_mpu6050_working_interface.h:81";
	/* <S12>/AXI4Lite_Read_GyroY_DTC */
	this.urlHashMap["gm_mpu6050_working_interface:180"] = "gm_mpu6050_working_interface.c:192&gm_mpu6050_working_interface.h:82";
	/* <S12>/AXI4Lite_Read_GyroZ_DTC */
	this.urlHashMap["gm_mpu6050_working_interface:182"] = "gm_mpu6050_working_interface.c:205&gm_mpu6050_working_interface.h:83";
	/* <S12>/AXI4Lite_Read_RegData_DTC */
	this.urlHashMap["gm_mpu6050_working_interface:176"] = "gm_mpu6050_working_interface.c:166&gm_mpu6050_working_interface.h:85";
	/* <S12>/AXI4Lite_Read_deviceID_DTC */
	this.urlHashMap["gm_mpu6050_working_interface:170"] = "gm_mpu6050_working_interface.c:153&gm_mpu6050_working_interface.h:84";
	/* <S12>/AXI4Lite_Read_isDeviceSetup_DTC */
	this.urlHashMap["gm_mpu6050_working_interface:184"] = "gm_mpu6050_working_interface.c:218";
	/* <S12>/AXI4Lite_Read_validout_DTC */
	this.urlHashMap["gm_mpu6050_working_interface:168"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:168";
	/* <S12>/EXTERNALPORT_ADDRALT_DTC */
	this.urlHashMap["gm_mpu6050_working_interface:174"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:174";
	/* <S12>/EXTERNALPORT_CS_DTC */
	this.urlHashMap["gm_mpu6050_working_interface:172"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:172";
	/* <S12>/EXTERNALPORT_SCL_DTC */
	this.urlHashMap["gm_mpu6050_working_interface:158"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:158";
	/* <S12>/EXTERNALPORT_SDA_DTC */
	this.urlHashMap["gm_mpu6050_working_interface:160"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:160";
	/* <S13>/AXI4Lite_Write_ConfigDevice_DTC */
	this.urlHashMap["gm_mpu6050_working_interface:156"] = "gm_mpu6050_working_interface.c:108";
	/* <S13>/AXI4Lite_Write_RegAddr_DTC */
	this.urlHashMap["gm_mpu6050_working_interface:154"] = "gm_mpu6050_working_interface.c:95";
	/* <S14>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_working_interface:163:16"] = "gm_mpu6050_working_interface.c:118,119,439,450,615,616,624&gm_mpu6050_working_interface.h:102,120";
	/* <S15>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_working_interface:165:16"] = "gm_mpu6050_working_interface.c:125,126,452,463,626,627,635&gm_mpu6050_working_interface.h:101,119";
	/* <S16>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_working_interface:167:16"] = "gm_mpu6050_working_interface.c:132,133,465,476,637,638,646&gm_mpu6050_working_interface.h:100,118";
	/* <S17>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_working_interface:179:16"] = "gm_mpu6050_working_interface.c:172,173,180,517,528,681,682,690&gm_mpu6050_working_interface.h:99,117";
	/* <S18>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_working_interface:181:16"] = "gm_mpu6050_working_interface.c:185,186,193,530,541,692,693,701&gm_mpu6050_working_interface.h:98,116";
	/* <S19>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_working_interface:183:16"] = "gm_mpu6050_working_interface.c:198,199,206,543,554,703,704,712&gm_mpu6050_working_interface.h:97,115";
	/* <S20>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_working_interface:177:16"] = "gm_mpu6050_working_interface.c:159,160,167,504,515,670,671,679&gm_mpu6050_working_interface.h:96,114";
	/* <S21>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_working_interface:171:16"] = "gm_mpu6050_working_interface.c:146,147,154,491,502,659,660,668&gm_mpu6050_working_interface.h:95,113";
	/* <S22>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_working_interface:185:16"] = "gm_mpu6050_working_interface.c:211,212,219,556,567,714,715,723&gm_mpu6050_working_interface.h:94,112";
	/* <S23>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_working_interface:169:16"] = "gm_mpu6050_working_interface.c:139,140,478,489,648,649,657&gm_mpu6050_working_interface.h:93,111";
	/* <S24>/AXI4-Interface Write */
	this.urlHashMap["gm_mpu6050_working_interface:157:17"] = "gm_mpu6050_working_interface.c:111,112,426,437,604,605,613&gm_mpu6050_working_interface.h:104,110";
	/* <S25>/AXI4-Interface Write */
	this.urlHashMap["gm_mpu6050_working_interface:155:17"] = "gm_mpu6050_working_interface.c:101,102,413,424,593,594,602&gm_mpu6050_working_interface.h:103,109";
	/* <S26>:3 */
	this.urlHashMap["gm_mpu6050_working_interface:119:3"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:119:3";
	/* <S26>:1 */
	this.urlHashMap["gm_mpu6050_working_interface:119:1"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:119:1";
	/* <S26>:16 */
	this.urlHashMap["gm_mpu6050_working_interface:119:16"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:119:16";
	/* <S26>:4 */
	this.urlHashMap["gm_mpu6050_working_interface:119:4"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:119:4";
	/* <S26>:5 */
	this.urlHashMap["gm_mpu6050_working_interface:119:5"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:119:5";
	/* <S27>/Base Frequency */
	this.urlHashMap["gm_mpu6050_working_interface:126"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:126";
	/* <S27>/Data Type Conversion */
	this.urlHashMap["gm_mpu6050_working_interface:127"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:127";
	/* <S27>/MATLAB Function */
	this.urlHashMap["gm_mpu6050_working_interface:128"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:128";
	/* <S27>/MATLAB Function1 */
	this.urlHashMap["gm_mpu6050_working_interface:129"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:129";
	/* <S27>/Max Frequency */
	this.urlHashMap["gm_mpu6050_working_interface:130"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:130";
	/* <S27>/Min Frequency */
	this.urlHashMap["gm_mpu6050_working_interface:131"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:131";
	/* <S27>/Sum */
	this.urlHashMap["gm_mpu6050_working_interface:134"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:134";
	/* <S27>/Sum1 */
	this.urlHashMap["gm_mpu6050_working_interface:135"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:135";
	/* <S28>:1 */
	this.urlHashMap["gm_mpu6050_working_interface:128:1"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:128:1";
	/* <S29>:1 */
	this.urlHashMap["gm_mpu6050_working_interface:129:1"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_working_interface:129:1";
	/* <S30>/u */
	this.urlHashMap["gm_mpu6050_working_interface:132:1"] = "msg=&block=gm_mpu6050_working_interface:132:1";
	/* <S30>/Derivative Gain */
	this.urlHashMap["gm_mpu6050_working_interface:132:1666"] = "msg=&block=gm_mpu6050_working_interface:132:1666";
	/* <S30>/Filter */
	this.urlHashMap["gm_mpu6050_working_interface:132:1668"] = "msg=&block=gm_mpu6050_working_interface:132:1668";
	/* <S30>/Filter Coefficient */
	this.urlHashMap["gm_mpu6050_working_interface:132:1669"] = "msg=&block=gm_mpu6050_working_interface:132:1669";
	/* <S30>/Integral Gain */
	this.urlHashMap["gm_mpu6050_working_interface:132:1665"] = "msg=&block=gm_mpu6050_working_interface:132:1665";
	/* <S30>/Integrator */
	this.urlHashMap["gm_mpu6050_working_interface:132:1667"] = "msg=&block=gm_mpu6050_working_interface:132:1667";
	/* <S30>/Proportional Gain */
	this.urlHashMap["gm_mpu6050_working_interface:132:1664"] = "msg=&block=gm_mpu6050_working_interface:132:1664";
	/* <S30>/Sum */
	this.urlHashMap["gm_mpu6050_working_interface:132:1663"] = "msg=&block=gm_mpu6050_working_interface:132:1663";
	/* <S30>/SumD */
	this.urlHashMap["gm_mpu6050_working_interface:132:1670"] = "msg=&block=gm_mpu6050_working_interface:132:1670";
	/* <S30>/y */
	this.urlHashMap["gm_mpu6050_working_interface:132:10"] = "msg=&block=gm_mpu6050_working_interface:132:10";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "gm_mpu6050_working_interface"};
	this.sidHashMap["gm_mpu6050_working_interface"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "gm_mpu6050_working_interface:1"};
	this.sidHashMap["gm_mpu6050_working_interface:1"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "gm_mpu6050_working_interface:17"};
	this.sidHashMap["gm_mpu6050_working_interface:17"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "gm_mpu6050_working_interface:33"};
	this.sidHashMap["gm_mpu6050_working_interface:33"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "gm_mpu6050_working_interface:55"};
	this.sidHashMap["gm_mpu6050_working_interface:55"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<S5>"] = {sid: "gm_mpu6050_working_interface:116"};
	this.sidHashMap["gm_mpu6050_working_interface:116"] = {rtwname: "<S5>"};
	this.rtwnameHashMap["<S6>"] = {sid: "gm_mpu6050_working_interface:5"};
	this.sidHashMap["gm_mpu6050_working_interface:5"] = {rtwname: "<S6>"};
	this.rtwnameHashMap["<S7>"] = {sid: "gm_mpu6050_working_interface:12"};
	this.sidHashMap["gm_mpu6050_working_interface:12"] = {rtwname: "<S7>"};
	this.rtwnameHashMap["<S8>"] = {sid: "gm_mpu6050_working_interface:21"};
	this.sidHashMap["gm_mpu6050_working_interface:21"] = {rtwname: "<S8>"};
	this.rtwnameHashMap["<S9>"] = {sid: "gm_mpu6050_working_interface:28"};
	this.sidHashMap["gm_mpu6050_working_interface:28"] = {rtwname: "<S9>"};
	this.rtwnameHashMap["<S10>"] = {sid: "gm_mpu6050_working_interface:37"};
	this.sidHashMap["gm_mpu6050_working_interface:37"] = {rtwname: "<S10>"};
	this.rtwnameHashMap["<S11>"] = {sid: "gm_mpu6050_working_interface:44"};
	this.sidHashMap["gm_mpu6050_working_interface:44"] = {rtwname: "<S11>"};
	this.rtwnameHashMap["<S12>"] = {sid: "gm_mpu6050_working_interface:189"};
	this.sidHashMap["gm_mpu6050_working_interface:189"] = {rtwname: "<S12>"};
	this.rtwnameHashMap["<S13>"] = {sid: "gm_mpu6050_working_interface:186"};
	this.sidHashMap["gm_mpu6050_working_interface:186"] = {rtwname: "<S13>"};
	this.rtwnameHashMap["<S14>"] = {sid: "gm_mpu6050_working_interface:163"};
	this.sidHashMap["gm_mpu6050_working_interface:163"] = {rtwname: "<S14>"};
	this.rtwnameHashMap["<S15>"] = {sid: "gm_mpu6050_working_interface:165"};
	this.sidHashMap["gm_mpu6050_working_interface:165"] = {rtwname: "<S15>"};
	this.rtwnameHashMap["<S16>"] = {sid: "gm_mpu6050_working_interface:167"};
	this.sidHashMap["gm_mpu6050_working_interface:167"] = {rtwname: "<S16>"};
	this.rtwnameHashMap["<S17>"] = {sid: "gm_mpu6050_working_interface:179"};
	this.sidHashMap["gm_mpu6050_working_interface:179"] = {rtwname: "<S17>"};
	this.rtwnameHashMap["<S18>"] = {sid: "gm_mpu6050_working_interface:181"};
	this.sidHashMap["gm_mpu6050_working_interface:181"] = {rtwname: "<S18>"};
	this.rtwnameHashMap["<S19>"] = {sid: "gm_mpu6050_working_interface:183"};
	this.sidHashMap["gm_mpu6050_working_interface:183"] = {rtwname: "<S19>"};
	this.rtwnameHashMap["<S20>"] = {sid: "gm_mpu6050_working_interface:177"};
	this.sidHashMap["gm_mpu6050_working_interface:177"] = {rtwname: "<S20>"};
	this.rtwnameHashMap["<S21>"] = {sid: "gm_mpu6050_working_interface:171"};
	this.sidHashMap["gm_mpu6050_working_interface:171"] = {rtwname: "<S21>"};
	this.rtwnameHashMap["<S22>"] = {sid: "gm_mpu6050_working_interface:185"};
	this.sidHashMap["gm_mpu6050_working_interface:185"] = {rtwname: "<S22>"};
	this.rtwnameHashMap["<S23>"] = {sid: "gm_mpu6050_working_interface:169"};
	this.sidHashMap["gm_mpu6050_working_interface:169"] = {rtwname: "<S23>"};
	this.rtwnameHashMap["<S24>"] = {sid: "gm_mpu6050_working_interface:157"};
	this.sidHashMap["gm_mpu6050_working_interface:157"] = {rtwname: "<S24>"};
	this.rtwnameHashMap["<S25>"] = {sid: "gm_mpu6050_working_interface:155"};
	this.sidHashMap["gm_mpu6050_working_interface:155"] = {rtwname: "<S25>"};
	this.rtwnameHashMap["<S26>"] = {sid: "gm_mpu6050_working_interface:119"};
	this.sidHashMap["gm_mpu6050_working_interface:119"] = {rtwname: "<S26>"};
	this.rtwnameHashMap["<S27>"] = {sid: "gm_mpu6050_working_interface:123"};
	this.sidHashMap["gm_mpu6050_working_interface:123"] = {rtwname: "<S27>"};
	this.rtwnameHashMap["<S28>"] = {sid: "gm_mpu6050_working_interface:128"};
	this.sidHashMap["gm_mpu6050_working_interface:128"] = {rtwname: "<S28>"};
	this.rtwnameHashMap["<S29>"] = {sid: "gm_mpu6050_working_interface:129"};
	this.sidHashMap["gm_mpu6050_working_interface:129"] = {rtwname: "<S29>"};
	this.rtwnameHashMap["<S30>"] = {sid: "gm_mpu6050_working_interface:132"};
	this.sidHashMap["gm_mpu6050_working_interface:132"] = {rtwname: "<S30>"};
	this.rtwnameHashMap["<Root>/AngleConverterX"] = {sid: "gm_mpu6050_working_interface:1"};
	this.sidHashMap["gm_mpu6050_working_interface:1"] = {rtwname: "<Root>/AngleConverterX"};
	this.rtwnameHashMap["<Root>/AngleConverterY"] = {sid: "gm_mpu6050_working_interface:17"};
	this.sidHashMap["gm_mpu6050_working_interface:17"] = {rtwname: "<Root>/AngleConverterY"};
	this.rtwnameHashMap["<Root>/AngleConverterZ"] = {sid: "gm_mpu6050_working_interface:33"};
	this.sidHashMap["gm_mpu6050_working_interface:33"] = {rtwname: "<Root>/AngleConverterZ"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "gm_mpu6050_working_interface:49"};
	this.sidHashMap["gm_mpu6050_working_interface:49"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "gm_mpu6050_working_interface:50"};
	this.sidHashMap["gm_mpu6050_working_interface:50"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/Constant2"] = {sid: "gm_mpu6050_working_interface:51"};
	this.sidHashMap["gm_mpu6050_working_interface:51"] = {rtwname: "<Root>/Constant2"};
	this.rtwnameHashMap["<Root>/Constant3"] = {sid: "gm_mpu6050_working_interface:52"};
	this.sidHashMap["gm_mpu6050_working_interface:52"] = {rtwname: "<Root>/Constant3"};
	this.rtwnameHashMap["<Root>/Constant4"] = {sid: "gm_mpu6050_working_interface:53"};
	this.sidHashMap["gm_mpu6050_working_interface:53"] = {rtwname: "<Root>/Constant4"};
	this.rtwnameHashMap["<Root>/Constant5"] = {sid: "gm_mpu6050_working_interface:54"};
	this.sidHashMap["gm_mpu6050_working_interface:54"] = {rtwname: "<Root>/Constant5"};
	this.rtwnameHashMap["<Root>/I2C_MPU6050_IP"] = {sid: "gm_mpu6050_working_interface:55"};
	this.sidHashMap["gm_mpu6050_working_interface:55"] = {rtwname: "<Root>/I2C_MPU6050_IP"};
	this.rtwnameHashMap["<Root>/Manual Switch"] = {sid: "gm_mpu6050_working_interface:114"};
	this.sidHashMap["gm_mpu6050_working_interface:114"] = {rtwname: "<Root>/Manual Switch"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "gm_mpu6050_working_interface:115"};
	this.sidHashMap["gm_mpu6050_working_interface:115"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<Root>/Subsystem"] = {sid: "gm_mpu6050_working_interface:116"};
	this.sidHashMap["gm_mpu6050_working_interface:116"] = {rtwname: "<Root>/Subsystem"};
	this.rtwnameHashMap["<Root>/Terminator"] = {sid: "gm_mpu6050_working_interface:139"};
	this.sidHashMap["gm_mpu6050_working_interface:139"] = {rtwname: "<Root>/Terminator"};
	this.rtwnameHashMap["<Root>/Terminator1"] = {sid: "gm_mpu6050_working_interface:140"};
	this.sidHashMap["gm_mpu6050_working_interface:140"] = {rtwname: "<Root>/Terminator1"};
	this.rtwnameHashMap["<Root>/Terminator2"] = {sid: "gm_mpu6050_working_interface:141"};
	this.sidHashMap["gm_mpu6050_working_interface:141"] = {rtwname: "<Root>/Terminator2"};
	this.rtwnameHashMap["<Root>/Terminator3"] = {sid: "gm_mpu6050_working_interface:142"};
	this.sidHashMap["gm_mpu6050_working_interface:142"] = {rtwname: "<Root>/Terminator3"};
	this.rtwnameHashMap["<Root>/Terminator4"] = {sid: "gm_mpu6050_working_interface:143"};
	this.sidHashMap["gm_mpu6050_working_interface:143"] = {rtwname: "<Root>/Terminator4"};
	this.rtwnameHashMap["<Root>/Terminator5"] = {sid: "gm_mpu6050_working_interface:144"};
	this.sidHashMap["gm_mpu6050_working_interface:144"] = {rtwname: "<Root>/Terminator5"};
	this.rtwnameHashMap["<Root>/Terminator6"] = {sid: "gm_mpu6050_working_interface:145"};
	this.sidHashMap["gm_mpu6050_working_interface:145"] = {rtwname: "<Root>/Terminator6"};
	this.rtwnameHashMap["<Root>/Terminator7"] = {sid: "gm_mpu6050_working_interface:146"};
	this.sidHashMap["gm_mpu6050_working_interface:146"] = {rtwname: "<Root>/Terminator7"};
	this.rtwnameHashMap["<Root>/UserRegValue"] = {sid: "gm_mpu6050_working_interface:147"};
	this.sidHashMap["gm_mpu6050_working_interface:147"] = {rtwname: "<Root>/UserRegValue"};
	this.rtwnameHashMap["<Root>/deviceID"] = {sid: "gm_mpu6050_working_interface:148"};
	this.sidHashMap["gm_mpu6050_working_interface:148"] = {rtwname: "<Root>/deviceID"};
	this.rtwnameHashMap["<Root>/gyroX"] = {sid: "gm_mpu6050_working_interface:149"};
	this.sidHashMap["gm_mpu6050_working_interface:149"] = {rtwname: "<Root>/gyroX"};
	this.rtwnameHashMap["<Root>/gyroY"] = {sid: "gm_mpu6050_working_interface:150"};
	this.sidHashMap["gm_mpu6050_working_interface:150"] = {rtwname: "<Root>/gyroY"};
	this.rtwnameHashMap["<Root>/gyroZ"] = {sid: "gm_mpu6050_working_interface:151"};
	this.sidHashMap["gm_mpu6050_working_interface:151"] = {rtwname: "<Root>/gyroZ"};
	this.rtwnameHashMap["<S1>/angleRaw"] = {sid: "gm_mpu6050_working_interface:2"};
	this.sidHashMap["gm_mpu6050_working_interface:2"] = {rtwname: "<S1>/angleRaw"};
	this.rtwnameHashMap["<S1>/isDeviceSetup"] = {sid: "gm_mpu6050_working_interface:3"};
	this.sidHashMap["gm_mpu6050_working_interface:3"] = {rtwname: "<S1>/isDeviceSetup"};
	this.rtwnameHashMap["<S1>/bias"] = {sid: "gm_mpu6050_working_interface:4"};
	this.sidHashMap["gm_mpu6050_working_interface:4"] = {rtwname: "<S1>/bias"};
	this.rtwnameHashMap["<S1>/GyroConverter"] = {sid: "gm_mpu6050_working_interface:5"};
	this.sidHashMap["gm_mpu6050_working_interface:5"] = {rtwname: "<S1>/GyroConverter"};
	this.rtwnameHashMap["<S1>/MATLAB Function1"] = {sid: "gm_mpu6050_working_interface:12"};
	this.sidHashMap["gm_mpu6050_working_interface:12"] = {rtwname: "<S1>/MATLAB Function1"};
	this.rtwnameHashMap["<S1>/Subtract"] = {sid: "gm_mpu6050_working_interface:13"};
	this.sidHashMap["gm_mpu6050_working_interface:13"] = {rtwname: "<S1>/Subtract"};
	this.rtwnameHashMap["<S1>/Sum1"] = {sid: "gm_mpu6050_working_interface:14"};
	this.sidHashMap["gm_mpu6050_working_interface:14"] = {rtwname: "<S1>/Sum1"};
	this.rtwnameHashMap["<S1>/Unit Delay3"] = {sid: "gm_mpu6050_working_interface:15"};
	this.sidHashMap["gm_mpu6050_working_interface:15"] = {rtwname: "<S1>/Unit Delay3"};
	this.rtwnameHashMap["<S1>/angle"] = {sid: "gm_mpu6050_working_interface:16"};
	this.sidHashMap["gm_mpu6050_working_interface:16"] = {rtwname: "<S1>/angle"};
	this.rtwnameHashMap["<S2>/angleRaw"] = {sid: "gm_mpu6050_working_interface:18"};
	this.sidHashMap["gm_mpu6050_working_interface:18"] = {rtwname: "<S2>/angleRaw"};
	this.rtwnameHashMap["<S2>/isDeviceSetup"] = {sid: "gm_mpu6050_working_interface:19"};
	this.sidHashMap["gm_mpu6050_working_interface:19"] = {rtwname: "<S2>/isDeviceSetup"};
	this.rtwnameHashMap["<S2>/bias"] = {sid: "gm_mpu6050_working_interface:20"};
	this.sidHashMap["gm_mpu6050_working_interface:20"] = {rtwname: "<S2>/bias"};
	this.rtwnameHashMap["<S2>/GyroConverter"] = {sid: "gm_mpu6050_working_interface:21"};
	this.sidHashMap["gm_mpu6050_working_interface:21"] = {rtwname: "<S2>/GyroConverter"};
	this.rtwnameHashMap["<S2>/MATLAB Function1"] = {sid: "gm_mpu6050_working_interface:28"};
	this.sidHashMap["gm_mpu6050_working_interface:28"] = {rtwname: "<S2>/MATLAB Function1"};
	this.rtwnameHashMap["<S2>/Subtract"] = {sid: "gm_mpu6050_working_interface:29"};
	this.sidHashMap["gm_mpu6050_working_interface:29"] = {rtwname: "<S2>/Subtract"};
	this.rtwnameHashMap["<S2>/Sum1"] = {sid: "gm_mpu6050_working_interface:30"};
	this.sidHashMap["gm_mpu6050_working_interface:30"] = {rtwname: "<S2>/Sum1"};
	this.rtwnameHashMap["<S2>/Unit Delay3"] = {sid: "gm_mpu6050_working_interface:31"};
	this.sidHashMap["gm_mpu6050_working_interface:31"] = {rtwname: "<S2>/Unit Delay3"};
	this.rtwnameHashMap["<S2>/angle"] = {sid: "gm_mpu6050_working_interface:32"};
	this.sidHashMap["gm_mpu6050_working_interface:32"] = {rtwname: "<S2>/angle"};
	this.rtwnameHashMap["<S3>/angleRaw"] = {sid: "gm_mpu6050_working_interface:34"};
	this.sidHashMap["gm_mpu6050_working_interface:34"] = {rtwname: "<S3>/angleRaw"};
	this.rtwnameHashMap["<S3>/isDeviceSetup"] = {sid: "gm_mpu6050_working_interface:35"};
	this.sidHashMap["gm_mpu6050_working_interface:35"] = {rtwname: "<S3>/isDeviceSetup"};
	this.rtwnameHashMap["<S3>/bias"] = {sid: "gm_mpu6050_working_interface:36"};
	this.sidHashMap["gm_mpu6050_working_interface:36"] = {rtwname: "<S3>/bias"};
	this.rtwnameHashMap["<S3>/GyroConverter"] = {sid: "gm_mpu6050_working_interface:37"};
	this.sidHashMap["gm_mpu6050_working_interface:37"] = {rtwname: "<S3>/GyroConverter"};
	this.rtwnameHashMap["<S3>/MATLAB Function1"] = {sid: "gm_mpu6050_working_interface:44"};
	this.sidHashMap["gm_mpu6050_working_interface:44"] = {rtwname: "<S3>/MATLAB Function1"};
	this.rtwnameHashMap["<S3>/Subtract"] = {sid: "gm_mpu6050_working_interface:45"};
	this.sidHashMap["gm_mpu6050_working_interface:45"] = {rtwname: "<S3>/Subtract"};
	this.rtwnameHashMap["<S3>/Sum1"] = {sid: "gm_mpu6050_working_interface:46"};
	this.sidHashMap["gm_mpu6050_working_interface:46"] = {rtwname: "<S3>/Sum1"};
	this.rtwnameHashMap["<S3>/Unit Delay3"] = {sid: "gm_mpu6050_working_interface:47"};
	this.sidHashMap["gm_mpu6050_working_interface:47"] = {rtwname: "<S3>/Unit Delay3"};
	this.rtwnameHashMap["<S3>/angle"] = {sid: "gm_mpu6050_working_interface:48"};
	this.sidHashMap["gm_mpu6050_working_interface:48"] = {rtwname: "<S3>/angle"};
	this.rtwnameHashMap["<S4>/RegAddr"] = {sid: "gm_mpu6050_working_interface:56"};
	this.sidHashMap["gm_mpu6050_working_interface:56"] = {rtwname: "<S4>/RegAddr"};
	this.rtwnameHashMap["<S4>/ConfigDevice"] = {sid: "gm_mpu6050_working_interface:57"};
	this.sidHashMap["gm_mpu6050_working_interface:57"] = {rtwname: "<S4>/ConfigDevice"};
	this.rtwnameHashMap["<S4>/AXI4LiteRead"] = {sid: "gm_mpu6050_working_interface:189"};
	this.sidHashMap["gm_mpu6050_working_interface:189"] = {rtwname: "<S4>/AXI4LiteRead"};
	this.rtwnameHashMap["<S4>/AXI4LiteWrite"] = {sid: "gm_mpu6050_working_interface:186"};
	this.sidHashMap["gm_mpu6050_working_interface:186"] = {rtwname: "<S4>/AXI4LiteWrite"};
	this.rtwnameHashMap["<S4>/AXI4Reset"] = {sid: "gm_mpu6050_working_interface:204"};
	this.sidHashMap["gm_mpu6050_working_interface:204"] = {rtwname: "<S4>/AXI4Reset"};
	this.rtwnameHashMap["<S4>/AXI4ResetModelSource"] = {sid: "gm_mpu6050_working_interface:205"};
	this.sidHashMap["gm_mpu6050_working_interface:205"] = {rtwname: "<S4>/AXI4ResetModelSource"};
	this.rtwnameHashMap["<S4>/SCL"] = {sid: "gm_mpu6050_working_interface:99"};
	this.sidHashMap["gm_mpu6050_working_interface:99"] = {rtwname: "<S4>/SCL"};
	this.rtwnameHashMap["<S4>/SDA"] = {sid: "gm_mpu6050_working_interface:100"};
	this.sidHashMap["gm_mpu6050_working_interface:100"] = {rtwname: "<S4>/SDA"};
	this.rtwnameHashMap["<S4>/AccelX"] = {sid: "gm_mpu6050_working_interface:101"};
	this.sidHashMap["gm_mpu6050_working_interface:101"] = {rtwname: "<S4>/AccelX"};
	this.rtwnameHashMap["<S4>/AccelY"] = {sid: "gm_mpu6050_working_interface:102"};
	this.sidHashMap["gm_mpu6050_working_interface:102"] = {rtwname: "<S4>/AccelY"};
	this.rtwnameHashMap["<S4>/AccelZ"] = {sid: "gm_mpu6050_working_interface:103"};
	this.sidHashMap["gm_mpu6050_working_interface:103"] = {rtwname: "<S4>/AccelZ"};
	this.rtwnameHashMap["<S4>/validout"] = {sid: "gm_mpu6050_working_interface:104"};
	this.sidHashMap["gm_mpu6050_working_interface:104"] = {rtwname: "<S4>/validout"};
	this.rtwnameHashMap["<S4>/deviceID"] = {sid: "gm_mpu6050_working_interface:105"};
	this.sidHashMap["gm_mpu6050_working_interface:105"] = {rtwname: "<S4>/deviceID"};
	this.rtwnameHashMap["<S4>/CS"] = {sid: "gm_mpu6050_working_interface:106"};
	this.sidHashMap["gm_mpu6050_working_interface:106"] = {rtwname: "<S4>/CS"};
	this.rtwnameHashMap["<S4>/ADDRALT"] = {sid: "gm_mpu6050_working_interface:107"};
	this.sidHashMap["gm_mpu6050_working_interface:107"] = {rtwname: "<S4>/ADDRALT"};
	this.rtwnameHashMap["<S4>/RegData"] = {sid: "gm_mpu6050_working_interface:108"};
	this.sidHashMap["gm_mpu6050_working_interface:108"] = {rtwname: "<S4>/RegData"};
	this.rtwnameHashMap["<S4>/GyroX"] = {sid: "gm_mpu6050_working_interface:109"};
	this.sidHashMap["gm_mpu6050_working_interface:109"] = {rtwname: "<S4>/GyroX"};
	this.rtwnameHashMap["<S4>/GyroY"] = {sid: "gm_mpu6050_working_interface:110"};
	this.sidHashMap["gm_mpu6050_working_interface:110"] = {rtwname: "<S4>/GyroY"};
	this.rtwnameHashMap["<S4>/GyroZ"] = {sid: "gm_mpu6050_working_interface:111"};
	this.sidHashMap["gm_mpu6050_working_interface:111"] = {rtwname: "<S4>/GyroZ"};
	this.rtwnameHashMap["<S4>/isDeviceSetup"] = {sid: "gm_mpu6050_working_interface:112"};
	this.sidHashMap["gm_mpu6050_working_interface:112"] = {rtwname: "<S4>/isDeviceSetup"};
	this.rtwnameHashMap["<S5>/desiredAngle"] = {sid: "gm_mpu6050_working_interface:117"};
	this.sidHashMap["gm_mpu6050_working_interface:117"] = {rtwname: "<S5>/desiredAngle"};
	this.rtwnameHashMap["<S5>/currAngle"] = {sid: "gm_mpu6050_working_interface:118"};
	this.sidHashMap["gm_mpu6050_working_interface:118"] = {rtwname: "<S5>/currAngle"};
	this.rtwnameHashMap["<S5>/Chart"] = {sid: "gm_mpu6050_working_interface:119"};
	this.sidHashMap["gm_mpu6050_working_interface:119"] = {rtwname: "<S5>/Chart"};
	this.rtwnameHashMap["<S5>/Display1"] = {sid: "gm_mpu6050_working_interface:120"};
	this.sidHashMap["gm_mpu6050_working_interface:120"] = {rtwname: "<S5>/Display1"};
	this.rtwnameHashMap["<S5>/ESCPeriod"] = {sid: "gm_mpu6050_working_interface:121"};
	this.sidHashMap["gm_mpu6050_working_interface:121"] = {rtwname: "<S5>/ESCPeriod"};
	this.rtwnameHashMap["<S5>/Gain"] = {sid: "gm_mpu6050_working_interface:122"};
	this.sidHashMap["gm_mpu6050_working_interface:122"] = {rtwname: "<S5>/Gain"};
	this.rtwnameHashMap["<S5>/Subsystem"] = {sid: "gm_mpu6050_working_interface:123"};
	this.sidHashMap["gm_mpu6050_working_interface:123"] = {rtwname: "<S5>/Subsystem"};
	this.rtwnameHashMap["<S5>/pwm"] = {sid: "gm_mpu6050_working_interface:137"};
	this.sidHashMap["gm_mpu6050_working_interface:137"] = {rtwname: "<S5>/pwm"};
	this.rtwnameHashMap["<S6>/in"] = {sid: "gm_mpu6050_working_interface:6"};
	this.sidHashMap["gm_mpu6050_working_interface:6"] = {rtwname: "<S6>/in"};
	this.rtwnameHashMap["<S6>/Data Type Conversion"] = {sid: "gm_mpu6050_working_interface:7"};
	this.sidHashMap["gm_mpu6050_working_interface:7"] = {rtwname: "<S6>/Data Type Conversion"};
	this.rtwnameHashMap["<S6>/Fcn"] = {sid: "gm_mpu6050_working_interface:8"};
	this.sidHashMap["gm_mpu6050_working_interface:8"] = {rtwname: "<S6>/Fcn"};
	this.rtwnameHashMap["<S6>/Fcn1"] = {sid: "gm_mpu6050_working_interface:9"};
	this.sidHashMap["gm_mpu6050_working_interface:9"] = {rtwname: "<S6>/Fcn1"};
	this.rtwnameHashMap["<S6>/degPerSec"] = {sid: "gm_mpu6050_working_interface:10"};
	this.sidHashMap["gm_mpu6050_working_interface:10"] = {rtwname: "<S6>/degPerSec"};
	this.rtwnameHashMap["<S7>:1"] = {sid: "gm_mpu6050_working_interface:12:1"};
	this.sidHashMap["gm_mpu6050_working_interface:12:1"] = {rtwname: "<S7>:1"};
	this.rtwnameHashMap["<S7>:1:2"] = {sid: "gm_mpu6050_working_interface:12:1:2"};
	this.sidHashMap["gm_mpu6050_working_interface:12:1:2"] = {rtwname: "<S7>:1:2"};
	this.rtwnameHashMap["<S7>:1:3"] = {sid: "gm_mpu6050_working_interface:12:1:3"};
	this.sidHashMap["gm_mpu6050_working_interface:12:1:3"] = {rtwname: "<S7>:1:3"};
	this.rtwnameHashMap["<S7>:1:4"] = {sid: "gm_mpu6050_working_interface:12:1:4"};
	this.sidHashMap["gm_mpu6050_working_interface:12:1:4"] = {rtwname: "<S7>:1:4"};
	this.rtwnameHashMap["<S7>:1:5"] = {sid: "gm_mpu6050_working_interface:12:1:5"};
	this.sidHashMap["gm_mpu6050_working_interface:12:1:5"] = {rtwname: "<S7>:1:5"};
	this.rtwnameHashMap["<S8>/in"] = {sid: "gm_mpu6050_working_interface:22"};
	this.sidHashMap["gm_mpu6050_working_interface:22"] = {rtwname: "<S8>/in"};
	this.rtwnameHashMap["<S8>/Data Type Conversion"] = {sid: "gm_mpu6050_working_interface:23"};
	this.sidHashMap["gm_mpu6050_working_interface:23"] = {rtwname: "<S8>/Data Type Conversion"};
	this.rtwnameHashMap["<S8>/Fcn"] = {sid: "gm_mpu6050_working_interface:24"};
	this.sidHashMap["gm_mpu6050_working_interface:24"] = {rtwname: "<S8>/Fcn"};
	this.rtwnameHashMap["<S8>/Fcn1"] = {sid: "gm_mpu6050_working_interface:25"};
	this.sidHashMap["gm_mpu6050_working_interface:25"] = {rtwname: "<S8>/Fcn1"};
	this.rtwnameHashMap["<S8>/degPerSec"] = {sid: "gm_mpu6050_working_interface:26"};
	this.sidHashMap["gm_mpu6050_working_interface:26"] = {rtwname: "<S8>/degPerSec"};
	this.rtwnameHashMap["<S9>:1"] = {sid: "gm_mpu6050_working_interface:28:1"};
	this.sidHashMap["gm_mpu6050_working_interface:28:1"] = {rtwname: "<S9>:1"};
	this.rtwnameHashMap["<S10>/in"] = {sid: "gm_mpu6050_working_interface:38"};
	this.sidHashMap["gm_mpu6050_working_interface:38"] = {rtwname: "<S10>/in"};
	this.rtwnameHashMap["<S10>/Data Type Conversion"] = {sid: "gm_mpu6050_working_interface:39"};
	this.sidHashMap["gm_mpu6050_working_interface:39"] = {rtwname: "<S10>/Data Type Conversion"};
	this.rtwnameHashMap["<S10>/Fcn"] = {sid: "gm_mpu6050_working_interface:40"};
	this.sidHashMap["gm_mpu6050_working_interface:40"] = {rtwname: "<S10>/Fcn"};
	this.rtwnameHashMap["<S10>/Fcn1"] = {sid: "gm_mpu6050_working_interface:41"};
	this.sidHashMap["gm_mpu6050_working_interface:41"] = {rtwname: "<S10>/Fcn1"};
	this.rtwnameHashMap["<S10>/degPerSec"] = {sid: "gm_mpu6050_working_interface:42"};
	this.sidHashMap["gm_mpu6050_working_interface:42"] = {rtwname: "<S10>/degPerSec"};
	this.rtwnameHashMap["<S11>:1"] = {sid: "gm_mpu6050_working_interface:44:1"};
	this.sidHashMap["gm_mpu6050_working_interface:44:1"] = {rtwname: "<S11>:1"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_AccelX"] = {sid: "gm_mpu6050_working_interface:163"};
	this.sidHashMap["gm_mpu6050_working_interface:163"] = {rtwname: "<S12>/AXI4Lite_Read_AccelX"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_AccelX_DTC"] = {sid: "gm_mpu6050_working_interface:162"};
	this.sidHashMap["gm_mpu6050_working_interface:162"] = {rtwname: "<S12>/AXI4Lite_Read_AccelX_DTC"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_AccelY"] = {sid: "gm_mpu6050_working_interface:165"};
	this.sidHashMap["gm_mpu6050_working_interface:165"] = {rtwname: "<S12>/AXI4Lite_Read_AccelY"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_AccelY_DTC"] = {sid: "gm_mpu6050_working_interface:164"};
	this.sidHashMap["gm_mpu6050_working_interface:164"] = {rtwname: "<S12>/AXI4Lite_Read_AccelY_DTC"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_AccelZ"] = {sid: "gm_mpu6050_working_interface:167"};
	this.sidHashMap["gm_mpu6050_working_interface:167"] = {rtwname: "<S12>/AXI4Lite_Read_AccelZ"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_AccelZ_DTC"] = {sid: "gm_mpu6050_working_interface:166"};
	this.sidHashMap["gm_mpu6050_working_interface:166"] = {rtwname: "<S12>/AXI4Lite_Read_AccelZ_DTC"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_GyroX"] = {sid: "gm_mpu6050_working_interface:179"};
	this.sidHashMap["gm_mpu6050_working_interface:179"] = {rtwname: "<S12>/AXI4Lite_Read_GyroX"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_GyroX_DTC"] = {sid: "gm_mpu6050_working_interface:178"};
	this.sidHashMap["gm_mpu6050_working_interface:178"] = {rtwname: "<S12>/AXI4Lite_Read_GyroX_DTC"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_GyroY"] = {sid: "gm_mpu6050_working_interface:181"};
	this.sidHashMap["gm_mpu6050_working_interface:181"] = {rtwname: "<S12>/AXI4Lite_Read_GyroY"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_GyroY_DTC"] = {sid: "gm_mpu6050_working_interface:180"};
	this.sidHashMap["gm_mpu6050_working_interface:180"] = {rtwname: "<S12>/AXI4Lite_Read_GyroY_DTC"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_GyroZ"] = {sid: "gm_mpu6050_working_interface:183"};
	this.sidHashMap["gm_mpu6050_working_interface:183"] = {rtwname: "<S12>/AXI4Lite_Read_GyroZ"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_GyroZ_DTC"] = {sid: "gm_mpu6050_working_interface:182"};
	this.sidHashMap["gm_mpu6050_working_interface:182"] = {rtwname: "<S12>/AXI4Lite_Read_GyroZ_DTC"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_RegData"] = {sid: "gm_mpu6050_working_interface:177"};
	this.sidHashMap["gm_mpu6050_working_interface:177"] = {rtwname: "<S12>/AXI4Lite_Read_RegData"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_RegData_DTC"] = {sid: "gm_mpu6050_working_interface:176"};
	this.sidHashMap["gm_mpu6050_working_interface:176"] = {rtwname: "<S12>/AXI4Lite_Read_RegData_DTC"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_deviceID"] = {sid: "gm_mpu6050_working_interface:171"};
	this.sidHashMap["gm_mpu6050_working_interface:171"] = {rtwname: "<S12>/AXI4Lite_Read_deviceID"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_deviceID_DTC"] = {sid: "gm_mpu6050_working_interface:170"};
	this.sidHashMap["gm_mpu6050_working_interface:170"] = {rtwname: "<S12>/AXI4Lite_Read_deviceID_DTC"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_isDeviceSetup"] = {sid: "gm_mpu6050_working_interface:185"};
	this.sidHashMap["gm_mpu6050_working_interface:185"] = {rtwname: "<S12>/AXI4Lite_Read_isDeviceSetup"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_isDeviceSetup_DTC"] = {sid: "gm_mpu6050_working_interface:184"};
	this.sidHashMap["gm_mpu6050_working_interface:184"] = {rtwname: "<S12>/AXI4Lite_Read_isDeviceSetup_DTC"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_validout"] = {sid: "gm_mpu6050_working_interface:169"};
	this.sidHashMap["gm_mpu6050_working_interface:169"] = {rtwname: "<S12>/AXI4Lite_Read_validout"};
	this.rtwnameHashMap["<S12>/AXI4Lite_Read_validout_DTC"] = {sid: "gm_mpu6050_working_interface:168"};
	this.sidHashMap["gm_mpu6050_working_interface:168"] = {rtwname: "<S12>/AXI4Lite_Read_validout_DTC"};
	this.rtwnameHashMap["<S12>/EXTERNALPORT_ADDRALT_DTC"] = {sid: "gm_mpu6050_working_interface:174"};
	this.sidHashMap["gm_mpu6050_working_interface:174"] = {rtwname: "<S12>/EXTERNALPORT_ADDRALT_DTC"};
	this.rtwnameHashMap["<S12>/EXTERNALPORT_CS_DTC"] = {sid: "gm_mpu6050_working_interface:172"};
	this.sidHashMap["gm_mpu6050_working_interface:172"] = {rtwname: "<S12>/EXTERNALPORT_CS_DTC"};
	this.rtwnameHashMap["<S12>/EXTERNALPORT_SCL_DTC"] = {sid: "gm_mpu6050_working_interface:158"};
	this.sidHashMap["gm_mpu6050_working_interface:158"] = {rtwname: "<S12>/EXTERNALPORT_SCL_DTC"};
	this.rtwnameHashMap["<S12>/EXTERNALPORT_SDA_DTC"] = {sid: "gm_mpu6050_working_interface:160"};
	this.sidHashMap["gm_mpu6050_working_interface:160"] = {rtwname: "<S12>/EXTERNALPORT_SDA_DTC"};
	this.rtwnameHashMap["<S12>/GROUND_ADDRALT"] = {sid: "gm_mpu6050_working_interface:175"};
	this.sidHashMap["gm_mpu6050_working_interface:175"] = {rtwname: "<S12>/GROUND_ADDRALT"};
	this.rtwnameHashMap["<S12>/GROUND_CS"] = {sid: "gm_mpu6050_working_interface:173"};
	this.sidHashMap["gm_mpu6050_working_interface:173"] = {rtwname: "<S12>/GROUND_CS"};
	this.rtwnameHashMap["<S12>/GROUND_SCL"] = {sid: "gm_mpu6050_working_interface:159"};
	this.sidHashMap["gm_mpu6050_working_interface:159"] = {rtwname: "<S12>/GROUND_SCL"};
	this.rtwnameHashMap["<S12>/GROUND_SDA"] = {sid: "gm_mpu6050_working_interface:161"};
	this.sidHashMap["gm_mpu6050_working_interface:161"] = {rtwname: "<S12>/GROUND_SDA"};
	this.rtwnameHashMap["<S12>/Out1"] = {sid: "gm_mpu6050_working_interface:190"};
	this.sidHashMap["gm_mpu6050_working_interface:190"] = {rtwname: "<S12>/Out1"};
	this.rtwnameHashMap["<S12>/Out2"] = {sid: "gm_mpu6050_working_interface:191"};
	this.sidHashMap["gm_mpu6050_working_interface:191"] = {rtwname: "<S12>/Out2"};
	this.rtwnameHashMap["<S12>/Out3"] = {sid: "gm_mpu6050_working_interface:192"};
	this.sidHashMap["gm_mpu6050_working_interface:192"] = {rtwname: "<S12>/Out3"};
	this.rtwnameHashMap["<S12>/Out4"] = {sid: "gm_mpu6050_working_interface:193"};
	this.sidHashMap["gm_mpu6050_working_interface:193"] = {rtwname: "<S12>/Out4"};
	this.rtwnameHashMap["<S12>/Out5"] = {sid: "gm_mpu6050_working_interface:194"};
	this.sidHashMap["gm_mpu6050_working_interface:194"] = {rtwname: "<S12>/Out5"};
	this.rtwnameHashMap["<S12>/Out6"] = {sid: "gm_mpu6050_working_interface:195"};
	this.sidHashMap["gm_mpu6050_working_interface:195"] = {rtwname: "<S12>/Out6"};
	this.rtwnameHashMap["<S12>/Out7"] = {sid: "gm_mpu6050_working_interface:196"};
	this.sidHashMap["gm_mpu6050_working_interface:196"] = {rtwname: "<S12>/Out7"};
	this.rtwnameHashMap["<S12>/Out8"] = {sid: "gm_mpu6050_working_interface:197"};
	this.sidHashMap["gm_mpu6050_working_interface:197"] = {rtwname: "<S12>/Out8"};
	this.rtwnameHashMap["<S12>/Out9"] = {sid: "gm_mpu6050_working_interface:198"};
	this.sidHashMap["gm_mpu6050_working_interface:198"] = {rtwname: "<S12>/Out9"};
	this.rtwnameHashMap["<S12>/Out10"] = {sid: "gm_mpu6050_working_interface:199"};
	this.sidHashMap["gm_mpu6050_working_interface:199"] = {rtwname: "<S12>/Out10"};
	this.rtwnameHashMap["<S12>/Out11"] = {sid: "gm_mpu6050_working_interface:200"};
	this.sidHashMap["gm_mpu6050_working_interface:200"] = {rtwname: "<S12>/Out11"};
	this.rtwnameHashMap["<S12>/Out12"] = {sid: "gm_mpu6050_working_interface:201"};
	this.sidHashMap["gm_mpu6050_working_interface:201"] = {rtwname: "<S12>/Out12"};
	this.rtwnameHashMap["<S12>/Out13"] = {sid: "gm_mpu6050_working_interface:202"};
	this.sidHashMap["gm_mpu6050_working_interface:202"] = {rtwname: "<S12>/Out13"};
	this.rtwnameHashMap["<S12>/Out14"] = {sid: "gm_mpu6050_working_interface:203"};
	this.sidHashMap["gm_mpu6050_working_interface:203"] = {rtwname: "<S12>/Out14"};
	this.rtwnameHashMap["<S13>/In1"] = {sid: "gm_mpu6050_working_interface:187"};
	this.sidHashMap["gm_mpu6050_working_interface:187"] = {rtwname: "<S13>/In1"};
	this.rtwnameHashMap["<S13>/In2"] = {sid: "gm_mpu6050_working_interface:188"};
	this.sidHashMap["gm_mpu6050_working_interface:188"] = {rtwname: "<S13>/In2"};
	this.rtwnameHashMap["<S13>/AXI4Lite_Write_ConfigDevice"] = {sid: "gm_mpu6050_working_interface:157"};
	this.sidHashMap["gm_mpu6050_working_interface:157"] = {rtwname: "<S13>/AXI4Lite_Write_ConfigDevice"};
	this.rtwnameHashMap["<S13>/AXI4Lite_Write_ConfigDevice_DTC"] = {sid: "gm_mpu6050_working_interface:156"};
	this.sidHashMap["gm_mpu6050_working_interface:156"] = {rtwname: "<S13>/AXI4Lite_Write_ConfigDevice_DTC"};
	this.rtwnameHashMap["<S13>/AXI4Lite_Write_RegAddr"] = {sid: "gm_mpu6050_working_interface:155"};
	this.sidHashMap["gm_mpu6050_working_interface:155"] = {rtwname: "<S13>/AXI4Lite_Write_RegAddr"};
	this.rtwnameHashMap["<S13>/AXI4Lite_Write_RegAddr_DTC"] = {sid: "gm_mpu6050_working_interface:154"};
	this.sidHashMap["gm_mpu6050_working_interface:154"] = {rtwname: "<S13>/AXI4Lite_Write_RegAddr_DTC"};
	this.rtwnameHashMap["<S14>/AXI4-Interface Read"] = {sid: "gm_mpu6050_working_interface:163:16"};
	this.sidHashMap["gm_mpu6050_working_interface:163:16"] = {rtwname: "<S14>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S14>/Signal Specification"] = {sid: "gm_mpu6050_working_interface:163:24"};
	this.sidHashMap["gm_mpu6050_working_interface:163:24"] = {rtwname: "<S14>/Signal Specification"};
	this.rtwnameHashMap["<S14>/Out1"] = {sid: "gm_mpu6050_working_interface:163:19"};
	this.sidHashMap["gm_mpu6050_working_interface:163:19"] = {rtwname: "<S14>/Out1"};
	this.rtwnameHashMap["<S15>/AXI4-Interface Read"] = {sid: "gm_mpu6050_working_interface:165:16"};
	this.sidHashMap["gm_mpu6050_working_interface:165:16"] = {rtwname: "<S15>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S15>/Signal Specification"] = {sid: "gm_mpu6050_working_interface:165:24"};
	this.sidHashMap["gm_mpu6050_working_interface:165:24"] = {rtwname: "<S15>/Signal Specification"};
	this.rtwnameHashMap["<S15>/Out1"] = {sid: "gm_mpu6050_working_interface:165:19"};
	this.sidHashMap["gm_mpu6050_working_interface:165:19"] = {rtwname: "<S15>/Out1"};
	this.rtwnameHashMap["<S16>/AXI4-Interface Read"] = {sid: "gm_mpu6050_working_interface:167:16"};
	this.sidHashMap["gm_mpu6050_working_interface:167:16"] = {rtwname: "<S16>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S16>/Signal Specification"] = {sid: "gm_mpu6050_working_interface:167:24"};
	this.sidHashMap["gm_mpu6050_working_interface:167:24"] = {rtwname: "<S16>/Signal Specification"};
	this.rtwnameHashMap["<S16>/Out1"] = {sid: "gm_mpu6050_working_interface:167:19"};
	this.sidHashMap["gm_mpu6050_working_interface:167:19"] = {rtwname: "<S16>/Out1"};
	this.rtwnameHashMap["<S17>/AXI4-Interface Read"] = {sid: "gm_mpu6050_working_interface:179:16"};
	this.sidHashMap["gm_mpu6050_working_interface:179:16"] = {rtwname: "<S17>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S17>/Signal Specification"] = {sid: "gm_mpu6050_working_interface:179:24"};
	this.sidHashMap["gm_mpu6050_working_interface:179:24"] = {rtwname: "<S17>/Signal Specification"};
	this.rtwnameHashMap["<S17>/Out1"] = {sid: "gm_mpu6050_working_interface:179:19"};
	this.sidHashMap["gm_mpu6050_working_interface:179:19"] = {rtwname: "<S17>/Out1"};
	this.rtwnameHashMap["<S18>/AXI4-Interface Read"] = {sid: "gm_mpu6050_working_interface:181:16"};
	this.sidHashMap["gm_mpu6050_working_interface:181:16"] = {rtwname: "<S18>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S18>/Signal Specification"] = {sid: "gm_mpu6050_working_interface:181:24"};
	this.sidHashMap["gm_mpu6050_working_interface:181:24"] = {rtwname: "<S18>/Signal Specification"};
	this.rtwnameHashMap["<S18>/Out1"] = {sid: "gm_mpu6050_working_interface:181:19"};
	this.sidHashMap["gm_mpu6050_working_interface:181:19"] = {rtwname: "<S18>/Out1"};
	this.rtwnameHashMap["<S19>/AXI4-Interface Read"] = {sid: "gm_mpu6050_working_interface:183:16"};
	this.sidHashMap["gm_mpu6050_working_interface:183:16"] = {rtwname: "<S19>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S19>/Signal Specification"] = {sid: "gm_mpu6050_working_interface:183:24"};
	this.sidHashMap["gm_mpu6050_working_interface:183:24"] = {rtwname: "<S19>/Signal Specification"};
	this.rtwnameHashMap["<S19>/Out1"] = {sid: "gm_mpu6050_working_interface:183:19"};
	this.sidHashMap["gm_mpu6050_working_interface:183:19"] = {rtwname: "<S19>/Out1"};
	this.rtwnameHashMap["<S20>/AXI4-Interface Read"] = {sid: "gm_mpu6050_working_interface:177:16"};
	this.sidHashMap["gm_mpu6050_working_interface:177:16"] = {rtwname: "<S20>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S20>/Signal Specification"] = {sid: "gm_mpu6050_working_interface:177:24"};
	this.sidHashMap["gm_mpu6050_working_interface:177:24"] = {rtwname: "<S20>/Signal Specification"};
	this.rtwnameHashMap["<S20>/Out1"] = {sid: "gm_mpu6050_working_interface:177:19"};
	this.sidHashMap["gm_mpu6050_working_interface:177:19"] = {rtwname: "<S20>/Out1"};
	this.rtwnameHashMap["<S21>/AXI4-Interface Read"] = {sid: "gm_mpu6050_working_interface:171:16"};
	this.sidHashMap["gm_mpu6050_working_interface:171:16"] = {rtwname: "<S21>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S21>/Signal Specification"] = {sid: "gm_mpu6050_working_interface:171:24"};
	this.sidHashMap["gm_mpu6050_working_interface:171:24"] = {rtwname: "<S21>/Signal Specification"};
	this.rtwnameHashMap["<S21>/Out1"] = {sid: "gm_mpu6050_working_interface:171:19"};
	this.sidHashMap["gm_mpu6050_working_interface:171:19"] = {rtwname: "<S21>/Out1"};
	this.rtwnameHashMap["<S22>/AXI4-Interface Read"] = {sid: "gm_mpu6050_working_interface:185:16"};
	this.sidHashMap["gm_mpu6050_working_interface:185:16"] = {rtwname: "<S22>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S22>/Signal Specification"] = {sid: "gm_mpu6050_working_interface:185:24"};
	this.sidHashMap["gm_mpu6050_working_interface:185:24"] = {rtwname: "<S22>/Signal Specification"};
	this.rtwnameHashMap["<S22>/Out1"] = {sid: "gm_mpu6050_working_interface:185:19"};
	this.sidHashMap["gm_mpu6050_working_interface:185:19"] = {rtwname: "<S22>/Out1"};
	this.rtwnameHashMap["<S23>/AXI4-Interface Read"] = {sid: "gm_mpu6050_working_interface:169:16"};
	this.sidHashMap["gm_mpu6050_working_interface:169:16"] = {rtwname: "<S23>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S23>/Signal Specification"] = {sid: "gm_mpu6050_working_interface:169:24"};
	this.sidHashMap["gm_mpu6050_working_interface:169:24"] = {rtwname: "<S23>/Signal Specification"};
	this.rtwnameHashMap["<S23>/Out1"] = {sid: "gm_mpu6050_working_interface:169:19"};
	this.sidHashMap["gm_mpu6050_working_interface:169:19"] = {rtwname: "<S23>/Out1"};
	this.rtwnameHashMap["<S24>/In1"] = {sid: "gm_mpu6050_working_interface:157:21"};
	this.sidHashMap["gm_mpu6050_working_interface:157:21"] = {rtwname: "<S24>/In1"};
	this.rtwnameHashMap["<S24>/AXI4-Interface Write"] = {sid: "gm_mpu6050_working_interface:157:17"};
	this.sidHashMap["gm_mpu6050_working_interface:157:17"] = {rtwname: "<S24>/AXI4-Interface Write"};
	this.rtwnameHashMap["<S24>/Signal Specification"] = {sid: "gm_mpu6050_working_interface:157:24"};
	this.sidHashMap["gm_mpu6050_working_interface:157:24"] = {rtwname: "<S24>/Signal Specification"};
	this.rtwnameHashMap["<S25>/In1"] = {sid: "gm_mpu6050_working_interface:155:21"};
	this.sidHashMap["gm_mpu6050_working_interface:155:21"] = {rtwname: "<S25>/In1"};
	this.rtwnameHashMap["<S25>/AXI4-Interface Write"] = {sid: "gm_mpu6050_working_interface:155:17"};
	this.sidHashMap["gm_mpu6050_working_interface:155:17"] = {rtwname: "<S25>/AXI4-Interface Write"};
	this.rtwnameHashMap["<S25>/Signal Specification"] = {sid: "gm_mpu6050_working_interface:155:24"};
	this.sidHashMap["gm_mpu6050_working_interface:155:24"] = {rtwname: "<S25>/Signal Specification"};
	this.rtwnameHashMap["<S26>:3"] = {sid: "gm_mpu6050_working_interface:119:3"};
	this.sidHashMap["gm_mpu6050_working_interface:119:3"] = {rtwname: "<S26>:3"};
	this.rtwnameHashMap["<S26>:1"] = {sid: "gm_mpu6050_working_interface:119:1"};
	this.sidHashMap["gm_mpu6050_working_interface:119:1"] = {rtwname: "<S26>:1"};
	this.rtwnameHashMap["<S26>:16"] = {sid: "gm_mpu6050_working_interface:119:16"};
	this.sidHashMap["gm_mpu6050_working_interface:119:16"] = {rtwname: "<S26>:16"};
	this.rtwnameHashMap["<S26>:4"] = {sid: "gm_mpu6050_working_interface:119:4"};
	this.sidHashMap["gm_mpu6050_working_interface:119:4"] = {rtwname: "<S26>:4"};
	this.rtwnameHashMap["<S26>:5"] = {sid: "gm_mpu6050_working_interface:119:5"};
	this.sidHashMap["gm_mpu6050_working_interface:119:5"] = {rtwname: "<S26>:5"};
	this.rtwnameHashMap["<S27>/desiredAngle"] = {sid: "gm_mpu6050_working_interface:124"};
	this.sidHashMap["gm_mpu6050_working_interface:124"] = {rtwname: "<S27>/desiredAngle"};
	this.rtwnameHashMap["<S27>/currAngle"] = {sid: "gm_mpu6050_working_interface:125"};
	this.sidHashMap["gm_mpu6050_working_interface:125"] = {rtwname: "<S27>/currAngle"};
	this.rtwnameHashMap["<S27>/Base Frequency"] = {sid: "gm_mpu6050_working_interface:126"};
	this.sidHashMap["gm_mpu6050_working_interface:126"] = {rtwname: "<S27>/Base Frequency"};
	this.rtwnameHashMap["<S27>/Data Type Conversion"] = {sid: "gm_mpu6050_working_interface:127"};
	this.sidHashMap["gm_mpu6050_working_interface:127"] = {rtwname: "<S27>/Data Type Conversion"};
	this.rtwnameHashMap["<S27>/MATLAB Function"] = {sid: "gm_mpu6050_working_interface:128"};
	this.sidHashMap["gm_mpu6050_working_interface:128"] = {rtwname: "<S27>/MATLAB Function"};
	this.rtwnameHashMap["<S27>/MATLAB Function1"] = {sid: "gm_mpu6050_working_interface:129"};
	this.sidHashMap["gm_mpu6050_working_interface:129"] = {rtwname: "<S27>/MATLAB Function1"};
	this.rtwnameHashMap["<S27>/Max Frequency"] = {sid: "gm_mpu6050_working_interface:130"};
	this.sidHashMap["gm_mpu6050_working_interface:130"] = {rtwname: "<S27>/Max Frequency"};
	this.rtwnameHashMap["<S27>/Min Frequency"] = {sid: "gm_mpu6050_working_interface:131"};
	this.sidHashMap["gm_mpu6050_working_interface:131"] = {rtwname: "<S27>/Min Frequency"};
	this.rtwnameHashMap["<S27>/PID Controller"] = {sid: "gm_mpu6050_working_interface:132"};
	this.sidHashMap["gm_mpu6050_working_interface:132"] = {rtwname: "<S27>/PID Controller"};
	this.rtwnameHashMap["<S27>/Signal Specification"] = {sid: "gm_mpu6050_working_interface:133"};
	this.sidHashMap["gm_mpu6050_working_interface:133"] = {rtwname: "<S27>/Signal Specification"};
	this.rtwnameHashMap["<S27>/Sum"] = {sid: "gm_mpu6050_working_interface:134"};
	this.sidHashMap["gm_mpu6050_working_interface:134"] = {rtwname: "<S27>/Sum"};
	this.rtwnameHashMap["<S27>/Sum1"] = {sid: "gm_mpu6050_working_interface:135"};
	this.sidHashMap["gm_mpu6050_working_interface:135"] = {rtwname: "<S27>/Sum1"};
	this.rtwnameHashMap["<S27>/Frequency"] = {sid: "gm_mpu6050_working_interface:136"};
	this.sidHashMap["gm_mpu6050_working_interface:136"] = {rtwname: "<S27>/Frequency"};
	this.rtwnameHashMap["<S28>:1"] = {sid: "gm_mpu6050_working_interface:128:1"};
	this.sidHashMap["gm_mpu6050_working_interface:128:1"] = {rtwname: "<S28>:1"};
	this.rtwnameHashMap["<S29>:1"] = {sid: "gm_mpu6050_working_interface:129:1"};
	this.sidHashMap["gm_mpu6050_working_interface:129:1"] = {rtwname: "<S29>:1"};
	this.rtwnameHashMap["<S30>/u"] = {sid: "gm_mpu6050_working_interface:132:1"};
	this.sidHashMap["gm_mpu6050_working_interface:132:1"] = {rtwname: "<S30>/u"};
	this.rtwnameHashMap["<S30>/Derivative Gain"] = {sid: "gm_mpu6050_working_interface:132:1666"};
	this.sidHashMap["gm_mpu6050_working_interface:132:1666"] = {rtwname: "<S30>/Derivative Gain"};
	this.rtwnameHashMap["<S30>/Filter"] = {sid: "gm_mpu6050_working_interface:132:1668"};
	this.sidHashMap["gm_mpu6050_working_interface:132:1668"] = {rtwname: "<S30>/Filter"};
	this.rtwnameHashMap["<S30>/Filter Coefficient"] = {sid: "gm_mpu6050_working_interface:132:1669"};
	this.sidHashMap["gm_mpu6050_working_interface:132:1669"] = {rtwname: "<S30>/Filter Coefficient"};
	this.rtwnameHashMap["<S30>/Integral Gain"] = {sid: "gm_mpu6050_working_interface:132:1665"};
	this.sidHashMap["gm_mpu6050_working_interface:132:1665"] = {rtwname: "<S30>/Integral Gain"};
	this.rtwnameHashMap["<S30>/Integrator"] = {sid: "gm_mpu6050_working_interface:132:1667"};
	this.sidHashMap["gm_mpu6050_working_interface:132:1667"] = {rtwname: "<S30>/Integrator"};
	this.rtwnameHashMap["<S30>/Proportional Gain"] = {sid: "gm_mpu6050_working_interface:132:1664"};
	this.sidHashMap["gm_mpu6050_working_interface:132:1664"] = {rtwname: "<S30>/Proportional Gain"};
	this.rtwnameHashMap["<S30>/Sum"] = {sid: "gm_mpu6050_working_interface:132:1663"};
	this.sidHashMap["gm_mpu6050_working_interface:132:1663"] = {rtwname: "<S30>/Sum"};
	this.rtwnameHashMap["<S30>/SumD"] = {sid: "gm_mpu6050_working_interface:132:1670"};
	this.sidHashMap["gm_mpu6050_working_interface:132:1670"] = {rtwname: "<S30>/SumD"};
	this.rtwnameHashMap["<S30>/y"] = {sid: "gm_mpu6050_working_interface:132:10"};
	this.sidHashMap["gm_mpu6050_working_interface:132:10"] = {rtwname: "<S30>/y"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
