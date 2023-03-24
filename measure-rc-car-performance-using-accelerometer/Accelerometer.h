#ifndef Accelerometer_h
#define Accelerometer_h
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

class Accelerometer {
public:
	Accelerometer(int pin);
  void setup();
  void readData();
  float getXAcceleration();
  //float getYAcceleration();
  //float getZAcceleration();   
private:
  int _pin;
  sensors_event_t a, g, temp;
};
#endif