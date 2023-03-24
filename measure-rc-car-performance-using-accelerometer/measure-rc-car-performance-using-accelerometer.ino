#include <SPI.h>
#include <SD.h>
#include "Storage.h"
#include "Accelerometer.h"
#include <stdlib.h>

int storagePin = 4;

Storage storage(storagePin);
Accelerometer accelerometer(storagePin);

char time[20];
char accelerationX[10];
char text[40];

float previousAccelerationX = 0;
int previousAccelerationCount = 50;

float countdown = 0;
bool newTrack = false;


void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Starting");
  storage.setup();
  accelerometer.setup();
  
  Serial.println(F("Time \t AccX \t AccY \t AccZ"));
  
  storage.writeToFile(" ");
  storage.writeToFile("Time \t AccX \t AccY \t AccZ");
}

void loop() {
  accelerometer.readData();
  
  if(accelerometer.getXAcceleration() - previousAccelerationX < 0.1) {
    previousAccelerationCount = previousAccelerationCount+1;
  } else {
    previousAccelerationCount = 0;
  }

  if(previousAccelerationCount >= 50) {
    previousAccelerationX = accelerometer.getXAcceleration();
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
  dtostrf(accelerometer.getXAcceleration(), 4, 2, accelerationX);
  
  strcpy(text, time);
  strcat(text, " ");
  strcat(text, accelerationX);
    
  
  Serial.println(text);
  storage.writeToFile(text);
  
  previousAccelerationX = accelerometer.getXAcceleration();

  delay(10);
}

