// https://learn.adafruit.com/adxl345-digital-accelerometer/programming
// ADXL345
#include "accelerometer.h"

ADXL345::ADXL345(int sensorId) {
    this->sensorId = sensorId;
}

void ADXL345::setup() {
    // Assign a unique ID to this sensor at the same time
    sensorInst = Adafruit_ADXL345_Unified(this->sensorId);
    #ifndef ESP8266
    while (!Serial); // for Leonardo/Micro/Zero
    #endif
    Serial.begin(9600);
    Serial.println("Accelerometer Test"); Serial.println("");

    /* Initialise the sensor */
    if(!sensorInst.begin())  {
        /* There was a problem detecting the ADXL345 ... check your connections */
        Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
        while(1);
    }

    // Set the range to whatever is appropriate for your project +-
    sensorInst.setRange(ADXL345_RANGE_16_G);
    // displaySetRange(ADXL345_RANGE_8_G);
    // displaySetRange(ADXL345_RANGE_4_G);
    // displaySetRange(ADXL345_RANGE_2_G);

    // Display some basic information on this sensor
    displaySensorDetails();

    // Display additional settings (outside the scope of sensor_t)
    displayDataRate();
    displayRange();
    Serial.println("");
}

void ADXL345::displaySensorDetails(void) {
    sensor_t sensor;
    sensorInst.getSensor(&sensor);
    Serial.println("------------------------------------");
    Serial.print  ("Sensor:       "); Serial.println(sensor.name);
    Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
    Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
    Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" m/s^2");
    Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" m/s^2");
    Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" m/s^2");
    Serial.println("------------------------------------");
    Serial.println("");
    delay(500);
}

void ADXL345::displayDataRate(void){
    Serial.print  ("Data Rate:    ");
    switch(sensorInst.getDataRate())  {
        case ADXL345_DATARATE_3200_HZ:
        Serial.print  ("3200 ");
        break;
        case ADXL345_DATARATE_1600_HZ:
        Serial.print  ("1600 ");
        break;
        case ADXL345_DATARATE_800_HZ:
        Serial.print  ("800 ");
        break;
        case ADXL345_DATARATE_400_HZ:
        Serial.print  ("400 ");
        break;
        case ADXL345_DATARATE_200_HZ:
        Serial.print  ("200 ");
        break;
        case ADXL345_DATARATE_100_HZ:
        Serial.print  ("100 ");
        break;
        case ADXL345_DATARATE_50_HZ:
        Serial.print  ("50 ");
        break;
        case ADXL345_DATARATE_25_HZ:
        Serial.print  ("25 ");
        break;
        case ADXL345_DATARATE_12_5_HZ:
        Serial.print  ("12.5 ");
        break;
        case ADXL345_DATARATE_6_25HZ:
        Serial.print  ("6.25 ");
        break;
        case ADXL345_DATARATE_3_13_HZ:
        Serial.print  ("3.13 ");
        break;
        case ADXL345_DATARATE_1_56_HZ:
        Serial.print  ("1.56 ");
        break;
        case ADXL345_DATARATE_0_78_HZ:
        Serial.print  ("0.78 ");
        break;
        case ADXL345_DATARATE_0_39_HZ:
        Serial.print  ("0.39 ");
        break;
        case ADXL345_DATARATE_0_20_HZ:
        Serial.print  ("0.20 ");
        break;
        case ADXL345_DATARATE_0_10_HZ:
        Serial.print  ("0.10 ");
        break;
        default:
        Serial.print  ("???? ");
        break;
    }
    Serial.println(" Hz");
}

void ADXL345::displayRange(void){
    Serial.print  ("Range:         +/- ");
    switch(this->sensorInst.getRange())  {
        case ADXL345_RANGE_16_G:
        Serial.print  ("16 ");
        break;
        case ADXL345_RANGE_8_G:
        Serial.print  ("8 ");
        break;
        case ADXL345_RANGE_4_G:
        Serial.print  ("4 ");
        break;
        case ADXL345_RANGE_2_G:
        Serial.print  ("2 ");
        break;
        default:
        Serial.print  ("?? ");
        break;
    }
    Serial.println(" g");
}

void ADXL345::displayData(void){
    // Get a new sensor event
    sensors_event_t event;
    this->sensorInst.getEvent(&event);

    // Display the results (acceleration is measured in m/s^2)
    Serial.print("X: ");
    Serial.print(event.acceleration.x);
    Serial.print("  ");

    Serial.print("Y: ");
    Serial.print(event.acceleration.y);
    Serial.print("  ");

    Serial.print("Z: ");
    Serial.print(event.acceleration.z);
    Serial.print("  ");

    Serial.println("m/s^2 ");
    delay(500);
}

void ADXL345::serialEncode(void){
    // Get a new sensor event
    sensors_event_t event;
    this->sensorInst.getEvent(&event);
    char x[11], y[11], z[11];
    dtostrf(event.acceleration.x, 4, 7, x);
    dtostrf(event.acceleration.y, 4, 7, y);
    dtostrf(event.acceleration.z, 4, 7, z);
    Serial.print("<{");
    Serial.print(x);
    Serial.print("|");
    Serial.print(y);
    Serial.print("|");
    Serial.print(z);
    Serial.println("}>");
}
