#include <SPI.h>
#include <SD.h>
#include "Storage.h"
#include "Gps.h"
#include <stdlib.h>

int storagePin = 4;

Storage storage(storagePin);
Gps gps(storagePin);

char time[20];
char speed[10];
char text[40];

float previousSpeed = 0;
int previousSpeedCount = 50;

float countdown = 0;
bool newTrack = false;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Starting");
  storage.setup();
  gps.setup();
  
  Serial.println(F("Time \t Speed"));
  
  storage.writeToFile(" ");
  storage.writeToFile("Time \t Speed");
}

void loop() {
  gps.readData();
  
  if(gps.getSpeed() - previousSpeed < 0.1) {
    previousSpeedCount = previousSpeedCount + 1;
  } else {
    previousSpeedCount = 0;
  }

  if(previousSpeedCount >= 50) {
    previousSpeed = gps.getSpeed();
    countdown = millis();
    delay(10);
    newTrack = false;
    return;
  }

  if(newTrack == false){
    Serial.println(" ");
    storage.writeToFile(" ");
    newTrack = true;    
  }
  
  
  ltoa(millis()-countdown, time, 10);
  dtostrf(gps.getSpeed(), 4, 2, speed);
  
  strcpy(text, time);
  strcat(text, " ");
  strcat(text, speed);
    
  
  Serial.println(text);
  storage.writeToFile(text);
  
  previousSpeed = gps.getSpeed();

  delay(10);
}

