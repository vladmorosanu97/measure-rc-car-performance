#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include "Gps.h"

SoftwareSerial gpsSerial(2, 3);
TinyGPSPlus gpsPlus;

Gps::Gps(int pin) {
  _pin = pin;
}

void Gps::setup(){
  Serial.print(F("Initializing GPS..."));
  gpsSerial.begin(9600);
  Serial.println(F("GPS initialization done."));
} 

void Gps::readData(){
  /*if(gpsSerial.available() > 0)
  {
    if (gpsPlus.encode(gpsSerial.read()))
    {
      Serial.print("Speed (kph): ");
      Serial.println(gpsPlus.speed.kmph());
      
      Serial.print("Latitude: ");
      Serial.println(gpsPlus.location.lat(), 6);
      Serial.print("Longitude: ");
      Serial.println(gpsPlus.location.lng(), 6);
      Serial.print("Altitude: ");
      Serial.println(gpsPlus.altitude.meters());
    
    }
  } else {
    Serial.println("GPS not available");    
  }
  
  if (millis() > 5000 && gpsPlus.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }
  */
  
  while (gpsSerial.available() > 0)
    gpsPlus.encode(gpsSerial.read());
}


double Gps::getLatitude(){
  if (gpsPlus.location.isValid())
  {
    return gpsPlus.location.lat();
  }
  else
  {
    return 0;
  }
}

double Gps::getLongitude(){
  if (gpsPlus.location.isValid())
  {
    return gpsPlus.location.lng();
  }
  else
  {
    return 0;
  }
}

double Gps::getSpeed(){
  return gpsPlus.speed.kmph();
}