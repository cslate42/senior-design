#include <Wire.h>
#include "I2Cdev.h"
#include "MPU6050.h"

#ifndef GY_521_h
    #define GY_521_h
    // using namespace std;
    class GY_521 {
        private:
            MPU6050 sensorInst;
            int16_t accl[3];
            int16_t gyro[3];
            uint8_t deviceAddr;
        public:
            GY_521(uint8_t);
            void setup(); 
            void serialEncode();
    };
#endif
