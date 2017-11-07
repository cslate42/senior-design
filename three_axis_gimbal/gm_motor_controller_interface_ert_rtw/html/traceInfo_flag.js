function TraceInfoFlag() {
    this.traceFlag = new Array();
}
top.TraceInfoFlag.instance = new TraceInfoFlag();
function TraceInfoLineFlag() {
    this.lineTraceFlag = new Array();
    this.lineTraceFlag["gm_motor_controller_interface.c:38"]=1;
}
top.TraceInfoLineFlag.instance = new TraceInfoLineFlag();
