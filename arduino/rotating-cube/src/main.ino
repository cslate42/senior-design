#include <Wire.h>
/***************************INCLUDES***************************************/
#include "accelerometer.h"
// #include "gyroscope.h"

ADXL345 adxl345 = new ADXL345(12345);

void setup() {
    Serial.begin(9600);  // Used to type in characters
    while (!Serial) {}
    Serial.println("Serial ready");
    adxl345.setup();
}

void loop() {
    // Serial.println("Serial INLOOP");
    adxl345.serialEncode();
}
