#include "Storage.h"
#include <SPI.h>
#include <SD.h>
#include "Arduino.h"

Storage::Storage(int pin) {
	_pin = pin;
}

void Storage::setup(){
  Serial.print("Initializing SD card...");
  if (!SD.begin(_pin)) {
    Serial.println("Initialization failed!");
   
    while(!SD.begin(_pin)){
        Serial.println("Initialization failed!!");
    };
  }
  Serial.println("SD Card initialization done.");

  Serial.print("Open storage file ");
  Serial.println(_fileName);
  _file = SD.open(_fileName, FILE_WRITE);
  if (!_file) {
    while(!_file){
      _file = SD.open(_fileName, FILE_WRITE);
      Serial.println("Storage file not available");
      _file.println("Storage file not available");
      _file.flush();
      delay(100);
    }
  }
  Serial.println("Storage file ready");
}

void Storage::writeToFile(char* content){
  _file.println(content);
  _file.flush();
}