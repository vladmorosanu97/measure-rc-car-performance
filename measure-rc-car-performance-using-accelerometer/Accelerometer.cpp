#include <Adafruit_MPU6050.h>
#include <Wire.h>
#include "Accelerometer.h"
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

Accelerometer::Accelerometer(int pin) {
  _pin = pin;
}

void Accelerometer::setup(){
  Serial.println("Initializing MPU6050 accelerometer...");
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("Accelerometer done.");

  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
} 

void Accelerometer::readData(){
  mpu.getEvent(&a, &g, &temp);
}

float Accelerometer::getXAcceleration(){
  return a.acceleration.x;
}

// float Accelerometer::getYAcceleration(){
//   return (a.acceleration.y);
// }

// float Accelerometer::getZAcceleration(){
//   return (a.acceleration.z);
// }