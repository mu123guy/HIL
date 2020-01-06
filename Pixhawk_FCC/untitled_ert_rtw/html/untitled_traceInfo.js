function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "untitled"};
	this.sidHashMap["untitled"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "untitled:22"};
	this.sidHashMap["untitled:22"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "untitled:28"};
	this.sidHashMap["untitled:28"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "untitled:24"};
	this.sidHashMap["untitled:24"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<Root>/Scope1"] = {sid: "untitled:27"};
	this.sidHashMap["untitled:27"] = {rtwname: "<Root>/Scope1"};
	this.rtwnameHashMap["<Root>/Serial Receive"] = {sid: "untitled:23"};
	this.sidHashMap["untitled:23"] = {rtwname: "<Root>/Serial Receive"};
	this.rtwnameHashMap["<Root>/Serial Receive1"] = {sid: "untitled:26"};
	this.sidHashMap["untitled:26"] = {rtwname: "<Root>/Serial Receive1"};
	this.rtwnameHashMap["<Root>/Serial Transmit"] = {sid: "untitled:21"};
	this.sidHashMap["untitled:21"] = {rtwname: "<Root>/Serial Transmit"};
	this.rtwnameHashMap["<Root>/Serial Transmit1"] = {sid: "untitled:25"};
	this.sidHashMap["untitled:25"] = {rtwname: "<Root>/Serial Transmit1"};
	this.rtwnameHashMap["<Root>/Subsystem1"] = {sid: "untitled:20"};
	this.sidHashMap["untitled:20"] = {rtwname: "<Root>/Subsystem1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
