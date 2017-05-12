// GY-521 => MPU-6050
// http://playground.arduino.cc/Main/MPU-6050#info
// http://www.instructables.com/id/How-to-Measure-Angle-With-MPU-6050GY-521/
// https://courses.cs.washington.edu/courses/cse466/14au/labs/l4/l4.html
// https://www.youtube.com/watch?v=P1OEoA70YJo
// https://www.instructables.com/id/Accelerometer-Gyro-Tutorial/
// https://www.i2cdevlib.com/forums/topic/4-understanding-raw-values-of-accelerometer-and-gyrometer/

#include "gy-521.h"

GY_521::GY_521(uint8_t deviceAddr) {
    this->deviceAddr = deviceAddr;
}

void GY_521::setup() {
    // this->sensorInst = new MPU6050(this->deviceAddr);
    this->sensorInst.initialize();

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(
        this->sensorInst.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed"
    );

    // use the code below to change accel/gyro offset values
    /*
    Serial.println("Updating internal sensor offsets...");
    // -76	-2359	1688	0	0	0
    Serial.print(accelgyro.getXAccelOffset()); Serial.print("\t"); // -76
    Serial.print(accelgyro.getYAccelOffset()); Serial.print("\t"); // -2359
    Serial.print(accelgyro.getZAccelOffset()); Serial.print("\t"); // 1688
    Serial.print(accelgyro.getXGyroOffset()); Serial.print("\t"); // 0
    Serial.print(accelgyro.getYGyroOffset()); Serial.print("\t"); // 0
    Serial.print(accelgyro.getZGyroOffset()); Serial.print("\t"); // 0
    Serial.print("\n");
    accelgyro.setXGyroOffset(220);
    accelgyro.setYGyroOffset(76);
    accelgyro.setZGyroOffset(-85);
    Serial.print(accelgyro.getXAccelOffset()); Serial.print("\t"); // -76
    Serial.print(accelgyro.getYAccelOffset()); Serial.print("\t"); // -2359
    Serial.print(accelgyro.getZAccelOffset()); Serial.print("\t"); // 1688
    Serial.print(accelgyro.getXGyroOffset()); Serial.print("\t"); // 0
    Serial.print(accelgyro.getYGyroOffset()); Serial.print("\t"); // 0
    Serial.print(accelgyro.getZGyroOffset()); Serial.print("\t"); // 0
    Serial.print("\n");
    */
}

void GY_521::serialEncode(void){
    // read raw accel/gyro measurements from device
    // this->sensorInst.getMotion6(
    //     &this->accl[0],
    //     &this->accl[1],
    //     &this->accl[2],
    //     &this->gyro[0],
    //     &this->gyro[1],
    //     &this->gyro[2]
    // );

    // these methods (and a few others) are also available
    this->sensorInst.getAcceleration(&this->accl[0], &this->accl[1], &this->accl[2]);
    this->sensorInst.getRotation(&this->gyro[0], &this->gyro[1], &this->gyro[2]);

    // display tab-separated accel/gyro x/y/z values
    Serial.print("{");

    Serial.print("\"accl\": {");
    Serial.print("\"x\": "); Serial.print(this->accl[0]); Serial.print(",");
    Serial.print("\"y\": "); Serial.print(this->accl[1]); Serial.print(",");
    Serial.print("\"z\": "); Serial.print(this->accl[2]);
    Serial.print("},");

    Serial.print("\t\t\"gyro\": {");
    Serial.print("\"x\": "); Serial.print(this->gyro[0]); Serial.print(",");
    Serial.print("\"y\": "); Serial.print(this->gyro[1]); Serial.print(",");
    Serial.print("\"z\": "); Serial.print(this->gyro[2]);
    Serial.print("}");

    Serial.println("}");
}
