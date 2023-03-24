#ifndef Gps_h
#define Gps_h

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

class Gps {
public:
	Gps(int pin);
  void setup();
  void readData();
  double getLatitude();
  double getLongitude();
  double getSpeed();
private:
  int _pin;
};
#endif