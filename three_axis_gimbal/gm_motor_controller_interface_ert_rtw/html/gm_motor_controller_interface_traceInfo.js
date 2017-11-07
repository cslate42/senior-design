function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/motor_controller */
	this.urlHashMap["gm_motor_controller_interface:16"] = "gm_motor_controller_interface.c:23,55";
	/* <Root>/PWM */
	this.urlHashMap["gm_motor_controller_interface:13"] = "gm_motor_controller_interface.c:37&gm_motor_controller_interface.h:42";
	/* <S2>/EXTERNALPORT_PWM_DTC */
	this.urlHashMap["gm_motor_controller_interface:18"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=gm_motor_controller_interface:18";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "gm_motor_controller_interface"};
	this.sidHashMap["gm_motor_controller_interface"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "gm_motor_controller_interface:16"};
	this.sidHashMap["gm_motor_controller_interface:16"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "gm_motor_controller_interface:20"};
	this.sidHashMap["gm_motor_controller_interface:20"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<Root>/motor_controller"] = {sid: "gm_motor_controller_interface:16"};
	this.sidHashMap["gm_motor_controller_interface:16"] = {rtwname: "<Root>/motor_controller"};
	this.rtwnameHashMap["<Root>/PWM"] = {sid: "gm_motor_controller_interface:13"};
	this.sidHashMap["gm_motor_controller_interface:13"] = {rtwname: "<Root>/PWM"};
	this.rtwnameHashMap["<S1>/AXI4LiteRead"] = {sid: "gm_motor_controller_interface:20"};
	this.sidHashMap["gm_motor_controller_interface:20"] = {rtwname: "<S1>/AXI4LiteRead"};
	this.rtwnameHashMap["<S1>/AXI4Reset"] = {sid: "gm_motor_controller_interface:22"};
	this.sidHashMap["gm_motor_controller_interface:22"] = {rtwname: "<S1>/AXI4Reset"};
	this.rtwnameHashMap["<S1>/AXI4ResetModelSource"] = {sid: "gm_motor_controller_interface:23"};
	this.sidHashMap["gm_motor_controller_interface:23"] = {rtwname: "<S1>/AXI4ResetModelSource"};
	this.rtwnameHashMap["<S1>/PWM"] = {sid: "gm_motor_controller_interface:17"};
	this.sidHashMap["gm_motor_controller_interface:17"] = {rtwname: "<S1>/PWM"};
	this.rtwnameHashMap["<S2>/EXTERNALPORT_PWM_DTC"] = {sid: "gm_motor_controller_interface:18"};
	this.sidHashMap["gm_motor_controller_interface:18"] = {rtwname: "<S2>/EXTERNALPORT_PWM_DTC"};
	this.rtwnameHashMap["<S2>/GROUND_PWM"] = {sid: "gm_motor_controller_interface:19"};
	this.sidHashMap["gm_motor_controller_interface:19"] = {rtwname: "<S2>/GROUND_PWM"};
	this.rtwnameHashMap["<S2>/Out1"] = {sid: "gm_motor_controller_interface:21"};
	this.sidHashMap["gm_motor_controller_interface:21"] = {rtwname: "<S2>/Out1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
