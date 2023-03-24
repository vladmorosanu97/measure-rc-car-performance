#ifndef Storage_h
#define Storage_h

#include <SPI.h>
#include <SD.h>
#include "Arduino.h"

class Storage {
public:
	Storage(int pin);
  void setup();
  void writeToFile(char* content);
private:
  int _pin;
  char* _fileName = "acc.txt";
  File _file;
};
#endif