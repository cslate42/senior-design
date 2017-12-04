function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
<<<<<<< HEAD
	/* <Root>/Constant */
	this.urlHashMap["gm_mpu6050_interface:1"] = "gm_mpu6050_interface.c:60&gm_mpu6050_interface.h:140&gm_mpu6050_interface_data.c:31";
	/* <Root>/Constant1 */
	this.urlHashMap["gm_mpu6050_interface:2"] = "gm_mpu6050_interface.c:61&gm_mpu6050_interface.h:143&gm_mpu6050_interface_data.c:34";
	/* <Root>/Constant2 */
	this.urlHashMap["gm_mpu6050_interface:3"] = "gm_mpu6050_interface.c:74&gm_mpu6050_interface.h:134&gm_mpu6050_interface_data.c:25";
	/* <Root>/I2C_MPU6050_IP */
	this.urlHashMap["gm_mpu6050_interface:4"] = "gm_mpu6050_interface.c:35,71,212,342,345,490,500,623";
	/* <Root>/Manual Switch */
	this.urlHashMap["gm_mpu6050_interface:62"] = "gm_mpu6050_interface.c:59,69&gm_mpu6050_interface.h:137&gm_mpu6050_interface_data.c:28";
	/* <Root>/Scope */
	this.urlHashMap["gm_mpu6050_interface:65"] = "gm_mpu6050_interface.h:104";
	/* <Root>/Scope1 */
	this.urlHashMap["gm_mpu6050_interface:66"] = "gm_mpu6050_interface.h:108";
	/* <Root>/UserRegValue */
	this.urlHashMap["gm_mpu6050_interface:67"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:67";
	/* <Root>/deviceID */
	this.urlHashMap["gm_mpu6050_interface:68"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:68";
	/* <Root>/SCL */
	this.urlHashMap["gm_mpu6050_interface:69"] = "gm_mpu6050_interface.c:214&gm_mpu6050_interface.h:125";
	/* <Root>/SDA */
	this.urlHashMap["gm_mpu6050_interface:70"] = "gm_mpu6050_interface.c:217&gm_mpu6050_interface.h:126";
	/* <Root>/CS */
	this.urlHashMap["gm_mpu6050_interface:71"] = "gm_mpu6050_interface.c:220&gm_mpu6050_interface.h:127";
	/* <Root>/AddrAlt */
	this.urlHashMap["gm_mpu6050_interface:72"] = "gm_mpu6050_interface.c:223&gm_mpu6050_interface.h:128";
	/* <S2>/AXI4Lite_Read_AccelX_DTC */
	this.urlHashMap["gm_mpu6050_interface:81"] = "gm_mpu6050_interface.c:102&gm_mpu6050_interface.h:78";
	/* <S2>/AXI4Lite_Read_AccelY_DTC */
	this.urlHashMap["gm_mpu6050_interface:83"] = "gm_mpu6050_interface.c:115&gm_mpu6050_interface.h:79";
	/* <S2>/AXI4Lite_Read_AccelZ_DTC */
	this.urlHashMap["gm_mpu6050_interface:85"] = "gm_mpu6050_interface.c:128&gm_mpu6050_interface.h:80";
	/* <S2>/AXI4Lite_Read_GyroX_DTC */
	this.urlHashMap["gm_mpu6050_interface:97"] = "gm_mpu6050_interface.c:180&gm_mpu6050_interface.h:81";
	/* <S2>/AXI4Lite_Read_GyroY_DTC */
	this.urlHashMap["gm_mpu6050_interface:99"] = "gm_mpu6050_interface.c:193&gm_mpu6050_interface.h:82";
	/* <S2>/AXI4Lite_Read_GyroZ_DTC */
	this.urlHashMap["gm_mpu6050_interface:101"] = "gm_mpu6050_interface.c:206&gm_mpu6050_interface.h:83";
	/* <S2>/AXI4Lite_Read_RegData_DTC */
	this.urlHashMap["gm_mpu6050_interface:95"] = "gm_mpu6050_interface.c:167&gm_mpu6050_interface.h:85";
	/* <S2>/AXI4Lite_Read_deviceID_DTC */
	this.urlHashMap["gm_mpu6050_interface:89"] = "gm_mpu6050_interface.c:154&gm_mpu6050_interface.h:84";
	/* <S2>/AXI4Lite_Read_validout_DTC */
	this.urlHashMap["gm_mpu6050_interface:87"] = "gm_mpu6050_interface.c:141&gm_mpu6050_interface.h:86";
	/* <S2>/EXTERNALPORT_ADDRALT_DTC */
	this.urlHashMap["gm_mpu6050_interface:93"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:93";
	/* <S2>/EXTERNALPORT_CS_DTC */
	this.urlHashMap["gm_mpu6050_interface:91"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:91";
	/* <S2>/EXTERNALPORT_SCL_DTC */
	this.urlHashMap["gm_mpu6050_interface:77"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:77";
	/* <S2>/EXTERNALPORT_SDA_DTC */
	this.urlHashMap["gm_mpu6050_interface:79"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:79";
	/* <S3>/AXI4Lite_Write_ConfigDevice_DTC */
	this.urlHashMap["gm_mpu6050_interface:75"] = "gm_mpu6050_interface.c:85";
	/* <S3>/AXI4Lite_Write_RegAddr_DTC */
	this.urlHashMap["gm_mpu6050_interface:73"] = "gm_mpu6050_interface.c:73";
	/* <S4>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:82:16"] = "gm_mpu6050_interface.c:95,96,103,373,384,524,525,533&gm_mpu6050_interface.h:99,120";
	/* <S5>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:84:16"] = "gm_mpu6050_interface.c:108,109,116,386,397,535,536,544&gm_mpu6050_interface.h:98,119";
	/* <S6>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:86:16"] = "gm_mpu6050_interface.c:121,122,129,399,410,546,547,555&gm_mpu6050_interface.h:97,118";
	/* <S7>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:98:16"] = "gm_mpu6050_interface.c:173,174,181,451,462,590,591,599&gm_mpu6050_interface.h:96,117";
	/* <S8>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:100:16"] = "gm_mpu6050_interface.c:186,187,194,464,475,601,602,610&gm_mpu6050_interface.h:95,116";
	/* <S9>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:102:16"] = "gm_mpu6050_interface.c:199,200,207,477,488,612,613,621&gm_mpu6050_interface.h:94,115";
	/* <S10>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:96:16"] = "gm_mpu6050_interface.c:160,161,168,438,449,579,580,588&gm_mpu6050_interface.h:93,114";
	/* <S11>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:90:16"] = "gm_mpu6050_interface.c:147,148,155,425,436,568,569,577&gm_mpu6050_interface.h:92,113";
	/* <S12>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:88:16"] = "gm_mpu6050_interface.c:134,135,142,412,423,557,558,566&gm_mpu6050_interface.h:91,112";
	/* <S13>/AXI4-Interface Write */
	this.urlHashMap["gm_mpu6050_interface:76:17"] = "gm_mpu6050_interface.c:88,89,360,371,513,514,522&gm_mpu6050_interface.h:101,111";
	/* <S14>/AXI4-Interface Write */
	this.urlHashMap["gm_mpu6050_interface:74:17"] = "gm_mpu6050_interface.c:78,79,347,358,502,503,511&gm_mpu6050_interface.h:100,110";
=======
	/* <Root>/TmpCnfDevice */
	this.urlHashMap["gm_mpu6050_interface:1"] = "gm_mpu6050_interface.h:123";
	/* <Root>/tmp */
	this.urlHashMap["gm_mpu6050_interface:2"] = "gm_mpu6050_interface.h:124";
	/* <Root>/tmp1 */
	this.urlHashMap["gm_mpu6050_interface:3"] = "gm_mpu6050_interface.h:125";
	/* <Root>/Constant */
	this.urlHashMap["gm_mpu6050_interface:4"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_interface:4";
	/* <Root>/Constant1 */
	this.urlHashMap["gm_mpu6050_interface:5"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_interface:5";
	/* <Root>/Constant2 */
	this.urlHashMap["gm_mpu6050_interface:6"] = "gm_mpu6050_interface.c:63&gm_mpu6050_interface.h:139&gm_mpu6050_interface_data.c:25";
	/* <Root>/I2C_MPU6050_IP */
	this.urlHashMap["gm_mpu6050_interface:7"] = "gm_mpu6050_interface.c:34,60,191,324,327,459,469,581";
	/* <Root>/Manual Switch */
	this.urlHashMap["gm_mpu6050_interface:83"] = "msg=rtwMsg_notTraceable&block=gm_mpu6050_interface:83";
	/* <Root>/Scope */
	this.urlHashMap["gm_mpu6050_interface:86"] = "gm_mpu6050_interface.h:103";
	/* <Root>/Scope1 */
	this.urlHashMap["gm_mpu6050_interface:87"] = "gm_mpu6050_interface.h:107";
	/* <Root>/UserRegValue */
	this.urlHashMap["gm_mpu6050_interface:96"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:96";
	/* <Root>/deviceID */
	this.urlHashMap["gm_mpu6050_interface:97"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:97";
	/* <Root>/SCL */
	this.urlHashMap["gm_mpu6050_interface:98"] = "gm_mpu6050_interface.c:193&gm_mpu6050_interface.h:130";
	/* <Root>/SDA */
	this.urlHashMap["gm_mpu6050_interface:99"] = "gm_mpu6050_interface.c:196&gm_mpu6050_interface.h:131";
	/* <Root>/CS */
	this.urlHashMap["gm_mpu6050_interface:100"] = "gm_mpu6050_interface.c:199&gm_mpu6050_interface.h:132";
	/* <Root>/AddrAlt */
	this.urlHashMap["gm_mpu6050_interface:101"] = "gm_mpu6050_interface.c:202&gm_mpu6050_interface.h:133";
	/* <S2>/AXI4Lite_Read_AccelX_DTC */
	this.urlHashMap["gm_mpu6050_interface:116"] = "gm_mpu6050_interface.c:81&gm_mpu6050_interface.h:78";
	/* <S2>/AXI4Lite_Read_AccelY_DTC */
	this.urlHashMap["gm_mpu6050_interface:118"] = "gm_mpu6050_interface.c:94&gm_mpu6050_interface.h:79";
	/* <S2>/AXI4Lite_Read_AccelZ_DTC */
	this.urlHashMap["gm_mpu6050_interface:120"] = "gm_mpu6050_interface.c:107&gm_mpu6050_interface.h:80";
	/* <S2>/AXI4Lite_Read_GyroX_DTC */
	this.urlHashMap["gm_mpu6050_interface:132"] = "gm_mpu6050_interface.c:159&gm_mpu6050_interface.h:81";
	/* <S2>/AXI4Lite_Read_GyroY_DTC */
	this.urlHashMap["gm_mpu6050_interface:134"] = "gm_mpu6050_interface.c:172&gm_mpu6050_interface.h:82";
	/* <S2>/AXI4Lite_Read_GyroZ_DTC */
	this.urlHashMap["gm_mpu6050_interface:136"] = "gm_mpu6050_interface.c:185&gm_mpu6050_interface.h:83";
	/* <S2>/AXI4Lite_Read_RegData_DTC */
	this.urlHashMap["gm_mpu6050_interface:130"] = "gm_mpu6050_interface.c:146&gm_mpu6050_interface.h:85";
	/* <S2>/AXI4Lite_Read_deviceID_DTC */
	this.urlHashMap["gm_mpu6050_interface:124"] = "gm_mpu6050_interface.c:133&gm_mpu6050_interface.h:84";
	/* <S2>/AXI4Lite_Read_validout_DTC */
	this.urlHashMap["gm_mpu6050_interface:122"] = "gm_mpu6050_interface.c:120&gm_mpu6050_interface.h:86";
	/* <S2>/EXTERNALPORT_ADDRALT_DTC */
	this.urlHashMap["gm_mpu6050_interface:128"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:128";
	/* <S2>/EXTERNALPORT_CS_DTC */
	this.urlHashMap["gm_mpu6050_interface:126"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:126";
	/* <S2>/EXTERNALPORT_SCL_DTC */
	this.urlHashMap["gm_mpu6050_interface:112"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:112";
	/* <S2>/EXTERNALPORT_SDA_DTC */
	this.urlHashMap["gm_mpu6050_interface:114"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:114";
	/* <S2>/EXTERNALPORT_led0_DTC */
	this.urlHashMap["gm_mpu6050_interface:138"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:138";
	/* <S2>/EXTERNALPORT_led1_DTC */
	this.urlHashMap["gm_mpu6050_interface:140"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:140";
	/* <S2>/EXTERNALPORT_led2_DTC */
	this.urlHashMap["gm_mpu6050_interface:142"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:142";
	/* <S2>/EXTERNALPORT_led3_DTC */
	this.urlHashMap["gm_mpu6050_interface:144"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:144";
	/* <S2>/EXTERNALPORT_led4_DTC */
	this.urlHashMap["gm_mpu6050_interface:146"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:146";
	/* <S2>/EXTERNALPORT_led5_DTC */
	this.urlHashMap["gm_mpu6050_interface:148"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:148";
	/* <S2>/EXTERNALPORT_led6_DTC */
	this.urlHashMap["gm_mpu6050_interface:150"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:150";
	/* <S2>/EXTERNALPORT_led7_DTC */
	this.urlHashMap["gm_mpu6050_interface:152"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:152";
	/* <S3>/AXI4Lite_Write_RegAddr_DTC */
	this.urlHashMap["gm_mpu6050_interface:104"] = "gm_mpu6050_interface.c:62";
	/* <S3>/EXTERNALPORT_ConfigDevice_DTC */
	this.urlHashMap["gm_mpu6050_interface:106"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:106";
	/* <S3>/EXTERNALPORT_modeSw1_DTC */
	this.urlHashMap["gm_mpu6050_interface:110"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:110";
	/* <S3>/EXTERNALPORT_updateSw0_DTC */
	this.urlHashMap["gm_mpu6050_interface:108"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_mpu6050_interface:108";
	/* <S4>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:117:16"] = "gm_mpu6050_interface.c:74,75,82,342,353,482,483,491&gm_mpu6050_interface.h:99,118";
	/* <S5>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:119:16"] = "gm_mpu6050_interface.c:87,88,95,355,366,493,494,502&gm_mpu6050_interface.h:98,117";
	/* <S6>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:121:16"] = "gm_mpu6050_interface.c:100,101,108,368,379,504,505,513&gm_mpu6050_interface.h:97,116";
	/* <S7>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:133:16"] = "gm_mpu6050_interface.c:152,153,160,420,431,548,549,557&gm_mpu6050_interface.h:96,115";
	/* <S8>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:135:16"] = "gm_mpu6050_interface.c:165,166,173,433,444,559,560,568&gm_mpu6050_interface.h:95,114";
	/* <S9>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:137:16"] = "gm_mpu6050_interface.c:178,179,186,446,457,570,571,579&gm_mpu6050_interface.h:94,113";
	/* <S10>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:131:16"] = "gm_mpu6050_interface.c:139,140,147,407,418,537,538,546&gm_mpu6050_interface.h:93,112";
	/* <S11>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:125:16"] = "gm_mpu6050_interface.c:126,127,134,394,405,526,527,535&gm_mpu6050_interface.h:92,111";
	/* <S12>/AXI4-Interface Read */
	this.urlHashMap["gm_mpu6050_interface:123:16"] = "gm_mpu6050_interface.c:113,114,121,381,392,515,516,524&gm_mpu6050_interface.h:91,110";
	/* <S13>/AXI4-Interface Write */
	this.urlHashMap["gm_mpu6050_interface:105:17"] = "gm_mpu6050_interface.c:67,68,329,340,471,472,480&gm_mpu6050_interface.h:100,109";
>>>>>>> 4c498d00033ba8e3c1028dad581483e8536e1362
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "gm_mpu6050_interface"};
	this.sidHashMap["gm_mpu6050_interface"] = {rtwname: "<Root>"};
<<<<<<< HEAD
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
=======
	this.rtwnameHashMap["<S1>"] = {sid: "gm_mpu6050_interface:7"};
	this.sidHashMap["gm_mpu6050_interface:7"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "gm_mpu6050_interface:159"};
	this.sidHashMap["gm_mpu6050_interface:159"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "gm_mpu6050_interface:154"};
	this.sidHashMap["gm_mpu6050_interface:154"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "gm_mpu6050_interface:117"};
	this.sidHashMap["gm_mpu6050_interface:117"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<S5>"] = {sid: "gm_mpu6050_interface:119"};
	this.sidHashMap["gm_mpu6050_interface:119"] = {rtwname: "<S5>"};
	this.rtwnameHashMap["<S6>"] = {sid: "gm_mpu6050_interface:121"};
	this.sidHashMap["gm_mpu6050_interface:121"] = {rtwname: "<S6>"};
	this.rtwnameHashMap["<S7>"] = {sid: "gm_mpu6050_interface:133"};
	this.sidHashMap["gm_mpu6050_interface:133"] = {rtwname: "<S7>"};
	this.rtwnameHashMap["<S8>"] = {sid: "gm_mpu6050_interface:135"};
	this.sidHashMap["gm_mpu6050_interface:135"] = {rtwname: "<S8>"};
	this.rtwnameHashMap["<S9>"] = {sid: "gm_mpu6050_interface:137"};
	this.sidHashMap["gm_mpu6050_interface:137"] = {rtwname: "<S9>"};
	this.rtwnameHashMap["<S10>"] = {sid: "gm_mpu6050_interface:131"};
	this.sidHashMap["gm_mpu6050_interface:131"] = {rtwname: "<S10>"};
	this.rtwnameHashMap["<S11>"] = {sid: "gm_mpu6050_interface:125"};
	this.sidHashMap["gm_mpu6050_interface:125"] = {rtwname: "<S11>"};
	this.rtwnameHashMap["<S12>"] = {sid: "gm_mpu6050_interface:123"};
	this.sidHashMap["gm_mpu6050_interface:123"] = {rtwname: "<S12>"};
	this.rtwnameHashMap["<S13>"] = {sid: "gm_mpu6050_interface:105"};
	this.sidHashMap["gm_mpu6050_interface:105"] = {rtwname: "<S13>"};
	this.rtwnameHashMap["<Root>/TmpCnfDevice"] = {sid: "gm_mpu6050_interface:1"};
	this.sidHashMap["gm_mpu6050_interface:1"] = {rtwname: "<Root>/TmpCnfDevice"};
	this.rtwnameHashMap["<Root>/tmp"] = {sid: "gm_mpu6050_interface:2"};
	this.sidHashMap["gm_mpu6050_interface:2"] = {rtwname: "<Root>/tmp"};
	this.rtwnameHashMap["<Root>/tmp1"] = {sid: "gm_mpu6050_interface:3"};
	this.sidHashMap["gm_mpu6050_interface:3"] = {rtwname: "<Root>/tmp1"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "gm_mpu6050_interface:4"};
	this.sidHashMap["gm_mpu6050_interface:4"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "gm_mpu6050_interface:5"};
	this.sidHashMap["gm_mpu6050_interface:5"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/Constant2"] = {sid: "gm_mpu6050_interface:6"};
	this.sidHashMap["gm_mpu6050_interface:6"] = {rtwname: "<Root>/Constant2"};
	this.rtwnameHashMap["<Root>/I2C_MPU6050_IP"] = {sid: "gm_mpu6050_interface:7"};
	this.sidHashMap["gm_mpu6050_interface:7"] = {rtwname: "<Root>/I2C_MPU6050_IP"};
	this.rtwnameHashMap["<Root>/Manual Switch"] = {sid: "gm_mpu6050_interface:83"};
	this.sidHashMap["gm_mpu6050_interface:83"] = {rtwname: "<Root>/Manual Switch"};
	this.rtwnameHashMap["<Root>/Mux"] = {sid: "gm_mpu6050_interface:84"};
	this.sidHashMap["gm_mpu6050_interface:84"] = {rtwname: "<Root>/Mux"};
	this.rtwnameHashMap["<Root>/Mux1"] = {sid: "gm_mpu6050_interface:85"};
	this.sidHashMap["gm_mpu6050_interface:85"] = {rtwname: "<Root>/Mux1"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "gm_mpu6050_interface:86"};
	this.sidHashMap["gm_mpu6050_interface:86"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<Root>/Scope1"] = {sid: "gm_mpu6050_interface:87"};
	this.sidHashMap["gm_mpu6050_interface:87"] = {rtwname: "<Root>/Scope1"};
	this.rtwnameHashMap["<Root>/Terminator"] = {sid: "gm_mpu6050_interface:88"};
	this.sidHashMap["gm_mpu6050_interface:88"] = {rtwname: "<Root>/Terminator"};
	this.rtwnameHashMap["<Root>/Terminator1"] = {sid: "gm_mpu6050_interface:89"};
	this.sidHashMap["gm_mpu6050_interface:89"] = {rtwname: "<Root>/Terminator1"};
	this.rtwnameHashMap["<Root>/Terminator2"] = {sid: "gm_mpu6050_interface:90"};
	this.sidHashMap["gm_mpu6050_interface:90"] = {rtwname: "<Root>/Terminator2"};
	this.rtwnameHashMap["<Root>/Terminator3"] = {sid: "gm_mpu6050_interface:91"};
	this.sidHashMap["gm_mpu6050_interface:91"] = {rtwname: "<Root>/Terminator3"};
	this.rtwnameHashMap["<Root>/Terminator4"] = {sid: "gm_mpu6050_interface:92"};
	this.sidHashMap["gm_mpu6050_interface:92"] = {rtwname: "<Root>/Terminator4"};
	this.rtwnameHashMap["<Root>/Terminator5"] = {sid: "gm_mpu6050_interface:93"};
	this.sidHashMap["gm_mpu6050_interface:93"] = {rtwname: "<Root>/Terminator5"};
	this.rtwnameHashMap["<Root>/Terminator6"] = {sid: "gm_mpu6050_interface:94"};
	this.sidHashMap["gm_mpu6050_interface:94"] = {rtwname: "<Root>/Terminator6"};
	this.rtwnameHashMap["<Root>/Terminator7"] = {sid: "gm_mpu6050_interface:95"};
	this.sidHashMap["gm_mpu6050_interface:95"] = {rtwname: "<Root>/Terminator7"};
	this.rtwnameHashMap["<Root>/UserRegValue"] = {sid: "gm_mpu6050_interface:96"};
	this.sidHashMap["gm_mpu6050_interface:96"] = {rtwname: "<Root>/UserRegValue"};
	this.rtwnameHashMap["<Root>/deviceID"] = {sid: "gm_mpu6050_interface:97"};
	this.sidHashMap["gm_mpu6050_interface:97"] = {rtwname: "<Root>/deviceID"};
	this.rtwnameHashMap["<Root>/SCL"] = {sid: "gm_mpu6050_interface:98"};
	this.sidHashMap["gm_mpu6050_interface:98"] = {rtwname: "<Root>/SCL"};
	this.rtwnameHashMap["<Root>/SDA"] = {sid: "gm_mpu6050_interface:99"};
	this.sidHashMap["gm_mpu6050_interface:99"] = {rtwname: "<Root>/SDA"};
	this.rtwnameHashMap["<Root>/CS"] = {sid: "gm_mpu6050_interface:100"};
	this.sidHashMap["gm_mpu6050_interface:100"] = {rtwname: "<Root>/CS"};
	this.rtwnameHashMap["<Root>/AddrAlt"] = {sid: "gm_mpu6050_interface:101"};
	this.sidHashMap["gm_mpu6050_interface:101"] = {rtwname: "<Root>/AddrAlt"};
	this.rtwnameHashMap["<S1>/RegAddr"] = {sid: "gm_mpu6050_interface:8"};
	this.sidHashMap["gm_mpu6050_interface:8"] = {rtwname: "<S1>/RegAddr"};
	this.rtwnameHashMap["<S1>/ConfigDevice"] = {sid: "gm_mpu6050_interface:9"};
	this.sidHashMap["gm_mpu6050_interface:9"] = {rtwname: "<S1>/ConfigDevice"};
	this.rtwnameHashMap["<S1>/updateSw0"] = {sid: "gm_mpu6050_interface:10"};
	this.sidHashMap["gm_mpu6050_interface:10"] = {rtwname: "<S1>/updateSw0"};
	this.rtwnameHashMap["<S1>/modeSw1"] = {sid: "gm_mpu6050_interface:11"};
	this.sidHashMap["gm_mpu6050_interface:11"] = {rtwname: "<S1>/modeSw1"};
	this.rtwnameHashMap["<S1>/AXI4LiteRead"] = {sid: "gm_mpu6050_interface:159"};
	this.sidHashMap["gm_mpu6050_interface:159"] = {rtwname: "<S1>/AXI4LiteRead"};
	this.rtwnameHashMap["<S1>/AXI4LiteWrite"] = {sid: "gm_mpu6050_interface:154"};
	this.sidHashMap["gm_mpu6050_interface:154"] = {rtwname: "<S1>/AXI4LiteWrite"};
	this.rtwnameHashMap["<S1>/AXI4Reset"] = {sid: "gm_mpu6050_interface:181"};
	this.sidHashMap["gm_mpu6050_interface:181"] = {rtwname: "<S1>/AXI4Reset"};
	this.rtwnameHashMap["<S1>/AXI4ResetModelSource"] = {sid: "gm_mpu6050_interface:182"};
	this.sidHashMap["gm_mpu6050_interface:182"] = {rtwname: "<S1>/AXI4ResetModelSource"};
	this.rtwnameHashMap["<S1>/SCL"] = {sid: "gm_mpu6050_interface:61"};
	this.sidHashMap["gm_mpu6050_interface:61"] = {rtwname: "<S1>/SCL"};
	this.rtwnameHashMap["<S1>/SDA"] = {sid: "gm_mpu6050_interface:62"};
	this.sidHashMap["gm_mpu6050_interface:62"] = {rtwname: "<S1>/SDA"};
	this.rtwnameHashMap["<S1>/AccelX"] = {sid: "gm_mpu6050_interface:63"};
	this.sidHashMap["gm_mpu6050_interface:63"] = {rtwname: "<S1>/AccelX"};
	this.rtwnameHashMap["<S1>/AccelY"] = {sid: "gm_mpu6050_interface:64"};
	this.sidHashMap["gm_mpu6050_interface:64"] = {rtwname: "<S1>/AccelY"};
	this.rtwnameHashMap["<S1>/AccelZ"] = {sid: "gm_mpu6050_interface:65"};
	this.sidHashMap["gm_mpu6050_interface:65"] = {rtwname: "<S1>/AccelZ"};
	this.rtwnameHashMap["<S1>/validout"] = {sid: "gm_mpu6050_interface:66"};
	this.sidHashMap["gm_mpu6050_interface:66"] = {rtwname: "<S1>/validout"};
	this.rtwnameHashMap["<S1>/deviceID"] = {sid: "gm_mpu6050_interface:67"};
	this.sidHashMap["gm_mpu6050_interface:67"] = {rtwname: "<S1>/deviceID"};
	this.rtwnameHashMap["<S1>/CS"] = {sid: "gm_mpu6050_interface:68"};
	this.sidHashMap["gm_mpu6050_interface:68"] = {rtwname: "<S1>/CS"};
	this.rtwnameHashMap["<S1>/ADDRALT"] = {sid: "gm_mpu6050_interface:69"};
	this.sidHashMap["gm_mpu6050_interface:69"] = {rtwname: "<S1>/ADDRALT"};
	this.rtwnameHashMap["<S1>/RegData"] = {sid: "gm_mpu6050_interface:70"};
	this.sidHashMap["gm_mpu6050_interface:70"] = {rtwname: "<S1>/RegData"};
	this.rtwnameHashMap["<S1>/GyroX"] = {sid: "gm_mpu6050_interface:71"};
	this.sidHashMap["gm_mpu6050_interface:71"] = {rtwname: "<S1>/GyroX"};
	this.rtwnameHashMap["<S1>/GyroY"] = {sid: "gm_mpu6050_interface:72"};
	this.sidHashMap["gm_mpu6050_interface:72"] = {rtwname: "<S1>/GyroY"};
	this.rtwnameHashMap["<S1>/GyroZ"] = {sid: "gm_mpu6050_interface:73"};
	this.sidHashMap["gm_mpu6050_interface:73"] = {rtwname: "<S1>/GyroZ"};
	this.rtwnameHashMap["<S1>/led0"] = {sid: "gm_mpu6050_interface:74"};
	this.sidHashMap["gm_mpu6050_interface:74"] = {rtwname: "<S1>/led0"};
	this.rtwnameHashMap["<S1>/led1"] = {sid: "gm_mpu6050_interface:75"};
	this.sidHashMap["gm_mpu6050_interface:75"] = {rtwname: "<S1>/led1"};
	this.rtwnameHashMap["<S1>/led2"] = {sid: "gm_mpu6050_interface:76"};
	this.sidHashMap["gm_mpu6050_interface:76"] = {rtwname: "<S1>/led2"};
	this.rtwnameHashMap["<S1>/led3"] = {sid: "gm_mpu6050_interface:77"};
	this.sidHashMap["gm_mpu6050_interface:77"] = {rtwname: "<S1>/led3"};
	this.rtwnameHashMap["<S1>/led4"] = {sid: "gm_mpu6050_interface:78"};
	this.sidHashMap["gm_mpu6050_interface:78"] = {rtwname: "<S1>/led4"};
	this.rtwnameHashMap["<S1>/led5"] = {sid: "gm_mpu6050_interface:79"};
	this.sidHashMap["gm_mpu6050_interface:79"] = {rtwname: "<S1>/led5"};
	this.rtwnameHashMap["<S1>/led6"] = {sid: "gm_mpu6050_interface:80"};
	this.sidHashMap["gm_mpu6050_interface:80"] = {rtwname: "<S1>/led6"};
	this.rtwnameHashMap["<S1>/led7"] = {sid: "gm_mpu6050_interface:81"};
	this.sidHashMap["gm_mpu6050_interface:81"] = {rtwname: "<S1>/led7"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_AccelX"] = {sid: "gm_mpu6050_interface:117"};
	this.sidHashMap["gm_mpu6050_interface:117"] = {rtwname: "<S2>/AXI4Lite_Read_AccelX"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_AccelX_DTC"] = {sid: "gm_mpu6050_interface:116"};
	this.sidHashMap["gm_mpu6050_interface:116"] = {rtwname: "<S2>/AXI4Lite_Read_AccelX_DTC"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_AccelY"] = {sid: "gm_mpu6050_interface:119"};
	this.sidHashMap["gm_mpu6050_interface:119"] = {rtwname: "<S2>/AXI4Lite_Read_AccelY"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_AccelY_DTC"] = {sid: "gm_mpu6050_interface:118"};
	this.sidHashMap["gm_mpu6050_interface:118"] = {rtwname: "<S2>/AXI4Lite_Read_AccelY_DTC"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_AccelZ"] = {sid: "gm_mpu6050_interface:121"};
	this.sidHashMap["gm_mpu6050_interface:121"] = {rtwname: "<S2>/AXI4Lite_Read_AccelZ"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_AccelZ_DTC"] = {sid: "gm_mpu6050_interface:120"};
	this.sidHashMap["gm_mpu6050_interface:120"] = {rtwname: "<S2>/AXI4Lite_Read_AccelZ_DTC"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_GyroX"] = {sid: "gm_mpu6050_interface:133"};
	this.sidHashMap["gm_mpu6050_interface:133"] = {rtwname: "<S2>/AXI4Lite_Read_GyroX"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_GyroX_DTC"] = {sid: "gm_mpu6050_interface:132"};
	this.sidHashMap["gm_mpu6050_interface:132"] = {rtwname: "<S2>/AXI4Lite_Read_GyroX_DTC"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_GyroY"] = {sid: "gm_mpu6050_interface:135"};
	this.sidHashMap["gm_mpu6050_interface:135"] = {rtwname: "<S2>/AXI4Lite_Read_GyroY"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_GyroY_DTC"] = {sid: "gm_mpu6050_interface:134"};
	this.sidHashMap["gm_mpu6050_interface:134"] = {rtwname: "<S2>/AXI4Lite_Read_GyroY_DTC"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_GyroZ"] = {sid: "gm_mpu6050_interface:137"};
	this.sidHashMap["gm_mpu6050_interface:137"] = {rtwname: "<S2>/AXI4Lite_Read_GyroZ"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_GyroZ_DTC"] = {sid: "gm_mpu6050_interface:136"};
	this.sidHashMap["gm_mpu6050_interface:136"] = {rtwname: "<S2>/AXI4Lite_Read_GyroZ_DTC"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_RegData"] = {sid: "gm_mpu6050_interface:131"};
	this.sidHashMap["gm_mpu6050_interface:131"] = {rtwname: "<S2>/AXI4Lite_Read_RegData"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_RegData_DTC"] = {sid: "gm_mpu6050_interface:130"};
	this.sidHashMap["gm_mpu6050_interface:130"] = {rtwname: "<S2>/AXI4Lite_Read_RegData_DTC"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_deviceID"] = {sid: "gm_mpu6050_interface:125"};
	this.sidHashMap["gm_mpu6050_interface:125"] = {rtwname: "<S2>/AXI4Lite_Read_deviceID"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_deviceID_DTC"] = {sid: "gm_mpu6050_interface:124"};
	this.sidHashMap["gm_mpu6050_interface:124"] = {rtwname: "<S2>/AXI4Lite_Read_deviceID_DTC"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_validout"] = {sid: "gm_mpu6050_interface:123"};
	this.sidHashMap["gm_mpu6050_interface:123"] = {rtwname: "<S2>/AXI4Lite_Read_validout"};
	this.rtwnameHashMap["<S2>/AXI4Lite_Read_validout_DTC"] = {sid: "gm_mpu6050_interface:122"};
	this.sidHashMap["gm_mpu6050_interface:122"] = {rtwname: "<S2>/AXI4Lite_Read_validout_DTC"};
	this.rtwnameHashMap["<S2>/EXTERNALPORT_ADDRALT_DTC"] = {sid: "gm_mpu6050_interface:128"};
	this.sidHashMap["gm_mpu6050_interface:128"] = {rtwname: "<S2>/EXTERNALPORT_ADDRALT_DTC"};
	this.rtwnameHashMap["<S2>/EXTERNALPORT_CS_DTC"] = {sid: "gm_mpu6050_interface:126"};
	this.sidHashMap["gm_mpu6050_interface:126"] = {rtwname: "<S2>/EXTERNALPORT_CS_DTC"};
	this.rtwnameHashMap["<S2>/EXTERNALPORT_SCL_DTC"] = {sid: "gm_mpu6050_interface:112"};
	this.sidHashMap["gm_mpu6050_interface:112"] = {rtwname: "<S2>/EXTERNALPORT_SCL_DTC"};
	this.rtwnameHashMap["<S2>/EXTERNALPORT_SDA_DTC"] = {sid: "gm_mpu6050_interface:114"};
	this.sidHashMap["gm_mpu6050_interface:114"] = {rtwname: "<S2>/EXTERNALPORT_SDA_DTC"};
	this.rtwnameHashMap["<S2>/EXTERNALPORT_led0_DTC"] = {sid: "gm_mpu6050_interface:138"};
	this.sidHashMap["gm_mpu6050_interface:138"] = {rtwname: "<S2>/EXTERNALPORT_led0_DTC"};
	this.rtwnameHashMap["<S2>/EXTERNALPORT_led1_DTC"] = {sid: "gm_mpu6050_interface:140"};
	this.sidHashMap["gm_mpu6050_interface:140"] = {rtwname: "<S2>/EXTERNALPORT_led1_DTC"};
	this.rtwnameHashMap["<S2>/EXTERNALPORT_led2_DTC"] = {sid: "gm_mpu6050_interface:142"};
	this.sidHashMap["gm_mpu6050_interface:142"] = {rtwname: "<S2>/EXTERNALPORT_led2_DTC"};
	this.rtwnameHashMap["<S2>/EXTERNALPORT_led3_DTC"] = {sid: "gm_mpu6050_interface:144"};
	this.sidHashMap["gm_mpu6050_interface:144"] = {rtwname: "<S2>/EXTERNALPORT_led3_DTC"};
	this.rtwnameHashMap["<S2>/EXTERNALPORT_led4_DTC"] = {sid: "gm_mpu6050_interface:146"};
	this.sidHashMap["gm_mpu6050_interface:146"] = {rtwname: "<S2>/EXTERNALPORT_led4_DTC"};
	this.rtwnameHashMap["<S2>/EXTERNALPORT_led5_DTC"] = {sid: "gm_mpu6050_interface:148"};
	this.sidHashMap["gm_mpu6050_interface:148"] = {rtwname: "<S2>/EXTERNALPORT_led5_DTC"};
	this.rtwnameHashMap["<S2>/EXTERNALPORT_led6_DTC"] = {sid: "gm_mpu6050_interface:150"};
	this.sidHashMap["gm_mpu6050_interface:150"] = {rtwname: "<S2>/EXTERNALPORT_led6_DTC"};
	this.rtwnameHashMap["<S2>/EXTERNALPORT_led7_DTC"] = {sid: "gm_mpu6050_interface:152"};
	this.sidHashMap["gm_mpu6050_interface:152"] = {rtwname: "<S2>/EXTERNALPORT_led7_DTC"};
	this.rtwnameHashMap["<S2>/GROUND_ADDRALT"] = {sid: "gm_mpu6050_interface:129"};
	this.sidHashMap["gm_mpu6050_interface:129"] = {rtwname: "<S2>/GROUND_ADDRALT"};
	this.rtwnameHashMap["<S2>/GROUND_CS"] = {sid: "gm_mpu6050_interface:127"};
	this.sidHashMap["gm_mpu6050_interface:127"] = {rtwname: "<S2>/GROUND_CS"};
	this.rtwnameHashMap["<S2>/GROUND_SCL"] = {sid: "gm_mpu6050_interface:113"};
	this.sidHashMap["gm_mpu6050_interface:113"] = {rtwname: "<S2>/GROUND_SCL"};
	this.rtwnameHashMap["<S2>/GROUND_SDA"] = {sid: "gm_mpu6050_interface:115"};
	this.sidHashMap["gm_mpu6050_interface:115"] = {rtwname: "<S2>/GROUND_SDA"};
	this.rtwnameHashMap["<S2>/GROUND_led0"] = {sid: "gm_mpu6050_interface:139"};
	this.sidHashMap["gm_mpu6050_interface:139"] = {rtwname: "<S2>/GROUND_led0"};
	this.rtwnameHashMap["<S2>/GROUND_led1"] = {sid: "gm_mpu6050_interface:141"};
	this.sidHashMap["gm_mpu6050_interface:141"] = {rtwname: "<S2>/GROUND_led1"};
	this.rtwnameHashMap["<S2>/GROUND_led2"] = {sid: "gm_mpu6050_interface:143"};
	this.sidHashMap["gm_mpu6050_interface:143"] = {rtwname: "<S2>/GROUND_led2"};
	this.rtwnameHashMap["<S2>/GROUND_led3"] = {sid: "gm_mpu6050_interface:145"};
	this.sidHashMap["gm_mpu6050_interface:145"] = {rtwname: "<S2>/GROUND_led3"};
	this.rtwnameHashMap["<S2>/GROUND_led4"] = {sid: "gm_mpu6050_interface:147"};
	this.sidHashMap["gm_mpu6050_interface:147"] = {rtwname: "<S2>/GROUND_led4"};
	this.rtwnameHashMap["<S2>/GROUND_led5"] = {sid: "gm_mpu6050_interface:149"};
	this.sidHashMap["gm_mpu6050_interface:149"] = {rtwname: "<S2>/GROUND_led5"};
	this.rtwnameHashMap["<S2>/GROUND_led6"] = {sid: "gm_mpu6050_interface:151"};
	this.sidHashMap["gm_mpu6050_interface:151"] = {rtwname: "<S2>/GROUND_led6"};
	this.rtwnameHashMap["<S2>/GROUND_led7"] = {sid: "gm_mpu6050_interface:153"};
	this.sidHashMap["gm_mpu6050_interface:153"] = {rtwname: "<S2>/GROUND_led7"};
	this.rtwnameHashMap["<S2>/Out1"] = {sid: "gm_mpu6050_interface:160"};
	this.sidHashMap["gm_mpu6050_interface:160"] = {rtwname: "<S2>/Out1"};
	this.rtwnameHashMap["<S2>/Out2"] = {sid: "gm_mpu6050_interface:161"};
	this.sidHashMap["gm_mpu6050_interface:161"] = {rtwname: "<S2>/Out2"};
	this.rtwnameHashMap["<S2>/Out3"] = {sid: "gm_mpu6050_interface:162"};
	this.sidHashMap["gm_mpu6050_interface:162"] = {rtwname: "<S2>/Out3"};
	this.rtwnameHashMap["<S2>/Out4"] = {sid: "gm_mpu6050_interface:163"};
	this.sidHashMap["gm_mpu6050_interface:163"] = {rtwname: "<S2>/Out4"};
	this.rtwnameHashMap["<S2>/Out5"] = {sid: "gm_mpu6050_interface:164"};
	this.sidHashMap["gm_mpu6050_interface:164"] = {rtwname: "<S2>/Out5"};
	this.rtwnameHashMap["<S2>/Out6"] = {sid: "gm_mpu6050_interface:165"};
	this.sidHashMap["gm_mpu6050_interface:165"] = {rtwname: "<S2>/Out6"};
	this.rtwnameHashMap["<S2>/Out7"] = {sid: "gm_mpu6050_interface:166"};
	this.sidHashMap["gm_mpu6050_interface:166"] = {rtwname: "<S2>/Out7"};
	this.rtwnameHashMap["<S2>/Out8"] = {sid: "gm_mpu6050_interface:167"};
	this.sidHashMap["gm_mpu6050_interface:167"] = {rtwname: "<S2>/Out8"};
	this.rtwnameHashMap["<S2>/Out9"] = {sid: "gm_mpu6050_interface:168"};
	this.sidHashMap["gm_mpu6050_interface:168"] = {rtwname: "<S2>/Out9"};
	this.rtwnameHashMap["<S2>/Out10"] = {sid: "gm_mpu6050_interface:169"};
	this.sidHashMap["gm_mpu6050_interface:169"] = {rtwname: "<S2>/Out10"};
	this.rtwnameHashMap["<S2>/Out11"] = {sid: "gm_mpu6050_interface:170"};
	this.sidHashMap["gm_mpu6050_interface:170"] = {rtwname: "<S2>/Out11"};
	this.rtwnameHashMap["<S2>/Out12"] = {sid: "gm_mpu6050_interface:171"};
	this.sidHashMap["gm_mpu6050_interface:171"] = {rtwname: "<S2>/Out12"};
	this.rtwnameHashMap["<S2>/Out13"] = {sid: "gm_mpu6050_interface:172"};
	this.sidHashMap["gm_mpu6050_interface:172"] = {rtwname: "<S2>/Out13"};
	this.rtwnameHashMap["<S2>/Out14"] = {sid: "gm_mpu6050_interface:173"};
	this.sidHashMap["gm_mpu6050_interface:173"] = {rtwname: "<S2>/Out14"};
	this.rtwnameHashMap["<S2>/Out15"] = {sid: "gm_mpu6050_interface:174"};
	this.sidHashMap["gm_mpu6050_interface:174"] = {rtwname: "<S2>/Out15"};
	this.rtwnameHashMap["<S2>/Out16"] = {sid: "gm_mpu6050_interface:175"};
	this.sidHashMap["gm_mpu6050_interface:175"] = {rtwname: "<S2>/Out16"};
	this.rtwnameHashMap["<S2>/Out17"] = {sid: "gm_mpu6050_interface:176"};
	this.sidHashMap["gm_mpu6050_interface:176"] = {rtwname: "<S2>/Out17"};
	this.rtwnameHashMap["<S2>/Out18"] = {sid: "gm_mpu6050_interface:177"};
	this.sidHashMap["gm_mpu6050_interface:177"] = {rtwname: "<S2>/Out18"};
	this.rtwnameHashMap["<S2>/Out19"] = {sid: "gm_mpu6050_interface:178"};
	this.sidHashMap["gm_mpu6050_interface:178"] = {rtwname: "<S2>/Out19"};
	this.rtwnameHashMap["<S2>/Out20"] = {sid: "gm_mpu6050_interface:179"};
	this.sidHashMap["gm_mpu6050_interface:179"] = {rtwname: "<S2>/Out20"};
	this.rtwnameHashMap["<S2>/Out21"] = {sid: "gm_mpu6050_interface:180"};
	this.sidHashMap["gm_mpu6050_interface:180"] = {rtwname: "<S2>/Out21"};
	this.rtwnameHashMap["<S3>/In1"] = {sid: "gm_mpu6050_interface:155"};
	this.sidHashMap["gm_mpu6050_interface:155"] = {rtwname: "<S3>/In1"};
	this.rtwnameHashMap["<S3>/In2"] = {sid: "gm_mpu6050_interface:156"};
	this.sidHashMap["gm_mpu6050_interface:156"] = {rtwname: "<S3>/In2"};
	this.rtwnameHashMap["<S3>/In3"] = {sid: "gm_mpu6050_interface:157"};
	this.sidHashMap["gm_mpu6050_interface:157"] = {rtwname: "<S3>/In3"};
	this.rtwnameHashMap["<S3>/In4"] = {sid: "gm_mpu6050_interface:158"};
	this.sidHashMap["gm_mpu6050_interface:158"] = {rtwname: "<S3>/In4"};
	this.rtwnameHashMap["<S3>/AXI4Lite_Write_RegAddr"] = {sid: "gm_mpu6050_interface:105"};
	this.sidHashMap["gm_mpu6050_interface:105"] = {rtwname: "<S3>/AXI4Lite_Write_RegAddr"};
	this.rtwnameHashMap["<S3>/AXI4Lite_Write_RegAddr_DTC"] = {sid: "gm_mpu6050_interface:104"};
	this.sidHashMap["gm_mpu6050_interface:104"] = {rtwname: "<S3>/AXI4Lite_Write_RegAddr_DTC"};
	this.rtwnameHashMap["<S3>/EXTERNALPORT_ConfigDevice"] = {sid: "gm_mpu6050_interface:107"};
	this.sidHashMap["gm_mpu6050_interface:107"] = {rtwname: "<S3>/EXTERNALPORT_ConfigDevice"};
	this.rtwnameHashMap["<S3>/EXTERNALPORT_ConfigDevice_DTC"] = {sid: "gm_mpu6050_interface:106"};
	this.sidHashMap["gm_mpu6050_interface:106"] = {rtwname: "<S3>/EXTERNALPORT_ConfigDevice_DTC"};
	this.rtwnameHashMap["<S3>/EXTERNALPORT_modeSw1"] = {sid: "gm_mpu6050_interface:111"};
	this.sidHashMap["gm_mpu6050_interface:111"] = {rtwname: "<S3>/EXTERNALPORT_modeSw1"};
	this.rtwnameHashMap["<S3>/EXTERNALPORT_modeSw1_DTC"] = {sid: "gm_mpu6050_interface:110"};
	this.sidHashMap["gm_mpu6050_interface:110"] = {rtwname: "<S3>/EXTERNALPORT_modeSw1_DTC"};
	this.rtwnameHashMap["<S3>/EXTERNALPORT_updateSw0"] = {sid: "gm_mpu6050_interface:109"};
	this.sidHashMap["gm_mpu6050_interface:109"] = {rtwname: "<S3>/EXTERNALPORT_updateSw0"};
	this.rtwnameHashMap["<S3>/EXTERNALPORT_updateSw0_DTC"] = {sid: "gm_mpu6050_interface:108"};
	this.sidHashMap["gm_mpu6050_interface:108"] = {rtwname: "<S3>/EXTERNALPORT_updateSw0_DTC"};
	this.rtwnameHashMap["<S4>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:117:16"};
	this.sidHashMap["gm_mpu6050_interface:117:16"] = {rtwname: "<S4>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S4>/Signal Specification"] = {sid: "gm_mpu6050_interface:117:24"};
	this.sidHashMap["gm_mpu6050_interface:117:24"] = {rtwname: "<S4>/Signal Specification"};
	this.rtwnameHashMap["<S4>/Out1"] = {sid: "gm_mpu6050_interface:117:19"};
	this.sidHashMap["gm_mpu6050_interface:117:19"] = {rtwname: "<S4>/Out1"};
	this.rtwnameHashMap["<S5>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:119:16"};
	this.sidHashMap["gm_mpu6050_interface:119:16"] = {rtwname: "<S5>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S5>/Signal Specification"] = {sid: "gm_mpu6050_interface:119:24"};
	this.sidHashMap["gm_mpu6050_interface:119:24"] = {rtwname: "<S5>/Signal Specification"};
	this.rtwnameHashMap["<S5>/Out1"] = {sid: "gm_mpu6050_interface:119:19"};
	this.sidHashMap["gm_mpu6050_interface:119:19"] = {rtwname: "<S5>/Out1"};
	this.rtwnameHashMap["<S6>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:121:16"};
	this.sidHashMap["gm_mpu6050_interface:121:16"] = {rtwname: "<S6>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S6>/Signal Specification"] = {sid: "gm_mpu6050_interface:121:24"};
	this.sidHashMap["gm_mpu6050_interface:121:24"] = {rtwname: "<S6>/Signal Specification"};
	this.rtwnameHashMap["<S6>/Out1"] = {sid: "gm_mpu6050_interface:121:19"};
	this.sidHashMap["gm_mpu6050_interface:121:19"] = {rtwname: "<S6>/Out1"};
	this.rtwnameHashMap["<S7>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:133:16"};
	this.sidHashMap["gm_mpu6050_interface:133:16"] = {rtwname: "<S7>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S7>/Signal Specification"] = {sid: "gm_mpu6050_interface:133:24"};
	this.sidHashMap["gm_mpu6050_interface:133:24"] = {rtwname: "<S7>/Signal Specification"};
	this.rtwnameHashMap["<S7>/Out1"] = {sid: "gm_mpu6050_interface:133:19"};
	this.sidHashMap["gm_mpu6050_interface:133:19"] = {rtwname: "<S7>/Out1"};
	this.rtwnameHashMap["<S8>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:135:16"};
	this.sidHashMap["gm_mpu6050_interface:135:16"] = {rtwname: "<S8>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S8>/Signal Specification"] = {sid: "gm_mpu6050_interface:135:24"};
	this.sidHashMap["gm_mpu6050_interface:135:24"] = {rtwname: "<S8>/Signal Specification"};
	this.rtwnameHashMap["<S8>/Out1"] = {sid: "gm_mpu6050_interface:135:19"};
	this.sidHashMap["gm_mpu6050_interface:135:19"] = {rtwname: "<S8>/Out1"};
	this.rtwnameHashMap["<S9>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:137:16"};
	this.sidHashMap["gm_mpu6050_interface:137:16"] = {rtwname: "<S9>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S9>/Signal Specification"] = {sid: "gm_mpu6050_interface:137:24"};
	this.sidHashMap["gm_mpu6050_interface:137:24"] = {rtwname: "<S9>/Signal Specification"};
	this.rtwnameHashMap["<S9>/Out1"] = {sid: "gm_mpu6050_interface:137:19"};
	this.sidHashMap["gm_mpu6050_interface:137:19"] = {rtwname: "<S9>/Out1"};
	this.rtwnameHashMap["<S10>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:131:16"};
	this.sidHashMap["gm_mpu6050_interface:131:16"] = {rtwname: "<S10>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S10>/Signal Specification"] = {sid: "gm_mpu6050_interface:131:24"};
	this.sidHashMap["gm_mpu6050_interface:131:24"] = {rtwname: "<S10>/Signal Specification"};
	this.rtwnameHashMap["<S10>/Out1"] = {sid: "gm_mpu6050_interface:131:19"};
	this.sidHashMap["gm_mpu6050_interface:131:19"] = {rtwname: "<S10>/Out1"};
	this.rtwnameHashMap["<S11>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:125:16"};
	this.sidHashMap["gm_mpu6050_interface:125:16"] = {rtwname: "<S11>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S11>/Signal Specification"] = {sid: "gm_mpu6050_interface:125:24"};
	this.sidHashMap["gm_mpu6050_interface:125:24"] = {rtwname: "<S11>/Signal Specification"};
	this.rtwnameHashMap["<S11>/Out1"] = {sid: "gm_mpu6050_interface:125:19"};
	this.sidHashMap["gm_mpu6050_interface:125:19"] = {rtwname: "<S11>/Out1"};
	this.rtwnameHashMap["<S12>/AXI4-Interface Read"] = {sid: "gm_mpu6050_interface:123:16"};
	this.sidHashMap["gm_mpu6050_interface:123:16"] = {rtwname: "<S12>/AXI4-Interface Read"};
	this.rtwnameHashMap["<S12>/Signal Specification"] = {sid: "gm_mpu6050_interface:123:24"};
	this.sidHashMap["gm_mpu6050_interface:123:24"] = {rtwname: "<S12>/Signal Specification"};
	this.rtwnameHashMap["<S12>/Out1"] = {sid: "gm_mpu6050_interface:123:19"};
	this.sidHashMap["gm_mpu6050_interface:123:19"] = {rtwname: "<S12>/Out1"};
	this.rtwnameHashMap["<S13>/In1"] = {sid: "gm_mpu6050_interface:105:21"};
	this.sidHashMap["gm_mpu6050_interface:105:21"] = {rtwname: "<S13>/In1"};
	this.rtwnameHashMap["<S13>/AXI4-Interface Write"] = {sid: "gm_mpu6050_interface:105:17"};
	this.sidHashMap["gm_mpu6050_interface:105:17"] = {rtwname: "<S13>/AXI4-Interface Write"};
	this.rtwnameHashMap["<S13>/Signal Specification"] = {sid: "gm_mpu6050_interface:105:24"};
	this.sidHashMap["gm_mpu6050_interface:105:24"] = {rtwname: "<S13>/Signal Specification"};
>>>>>>> 4c498d00033ba8e3c1028dad581483e8536e1362
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
