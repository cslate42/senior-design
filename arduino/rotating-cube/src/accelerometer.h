#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

#ifndef ADXL345_h
    #define ADXL345_h
    // using namespace std;
    class ADXL345 {
        private:
            Adafruit_ADXL345_Unified sensorInst;
            int sensorId;
        public:
            ADXL345(int);
            void setup();
            void displaySensorDetails();
            void displayDataRate();
            void displayRange();
            void displayData();
            void serialEncode();
    };
    extern ADXL345 adxl345;
#endif
