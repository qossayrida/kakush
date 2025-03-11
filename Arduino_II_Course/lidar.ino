#include <Wire.h>
#include <Adafruit_VL53L0X.h>

// Define the shutdown pin
#define SHUTDOWN_PIN 15

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

// Function to enable the sensor
void enableSensor() {
  digitalWrite(SHUTDOWN_PIN, HIGH);
  delay(10); // Delay to allow sensor to initialize
}

// Function to disable the sensor
void disableSensor() {
  digitalWrite(SHUTDOWN_PIN, LOW);
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  // Initialize the shutdown pin
  pinMode(SHUTDOWN_PIN, OUTPUT);
  
  // Enable the sensor
  enableSensor();
  
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1);
  }
  Serial.println(F("VL53L0X API Simple Ranging example\n\n"));
}

void loop() {
  VL53L0X_RangingMeasurementData_t measure;
  
  // Ensure the sensor is enabled
  enableSensor();
  
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
  
  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print(F("Distance (mm): "));
    Serial.println(measure.RangeMilliMeter);
  } else {
    Serial.println(F(" out of range "));
  }
  
  delay(100);
  
  // Optionally, disable the sensor to save power
  // disableSensor();
}
