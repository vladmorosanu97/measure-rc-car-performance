# Measure RC car performance using Arduino

To test the performance of an RC car, I use a combination of quantitative measurements and qualitative observations. Here are some factors that I considered when testing the RC car:
* Speed using M8Q-5883 GPS module
* Acceleration using MPU6050 board
* Storage using Micro SD card module

**NOTE**: I encountered some problems when wanted to connect all the sensores at once, so the only way I figured it out was to connect each sensore at a time.
You will find two folders in this repository: `measure-rc-car-performance-using-gps` and `measure-rc-car-performance-using-accelerometer`, each of them is using a GPS or an accelerometer with a storage sd card module. 

# Micro SD Card Module

To connect the Micro SD Card module to an Arduino Uno, you can follow these steps:

First, make sure that your Micro SD Card module is compatible with the Arduino Uno. Most Micro SD Card modules available in the market are compatible with Arduino Uno.
Identify the pins on your Micro SD Card module. Typically, it will have 6 pins: GND, VCC, MISO, MOSI, SCK, and CS.

Connect the GND pin of the Micro SD Card module to the GND pin of the Arduino Uno.

Connect the VCC pin of the Micro SD Card module to the 5V pin of the Arduino Uno.

Connect the MISO pin of the Micro SD Card module to the digital pin 12 of the Arduino Uno.

Connect the MOSI pin of the Micro SD Card module to the digital pin 11 of the Arduino Uno.

Connect the SCK pin of the Micro SD Card module to the digital pin 13 of the Arduino Uno.

Connect the CS pin of the Micro SD Card module to digital pin 4

You can use a micro SD card that is less or equal to 32 GB of storage.


# M8Q-5883 GPS Module

To connect an M8Q-5883 GPS module to an Arduino, you will need to follow these steps:

Gather the necessary components: an M8Q-5883 GPS module, an Arduino board (such as an Arduino Uno), breadboard or jumper wires, and a USB cable.

Connect the GPS module to the Arduino board using jumper wires or a breadboard. The M8Q-5883 GPS module has 6 pins: VCC, GND, TX, RX, SDA, and SCL. Here's how to connect the GPS module to the Arduino board:

Connect the VCC pin to 5V on the Arduino board.

Connect the GND pin to GND on the Arduino board.

Connect the TX pin to a digital pin (e.g. pin 2) on the Arduino board.

Connect the RX pin to a digital pin (e.g. pin 3) on the Arduino board.

Go to the `measure-rc-car-performance-using-gps` folder, open the `measure-rc-car-performance-using-gps.ino` and upload the files to your arduino.


# MPU6050 Accelerometer

Connecting the MPU6050 accelerometer to an Arduino board requires the following steps:
Connect the VCC pin of the MPU6050 module to the 5V pin of the Arduino board.

Connect the GND pin of the MPU6050 module to the GND pin of the Arduino board.

Connect the SDA pin of the MPU6050 module to the A4 pin (or SDA pin) of the Arduino board.

Connect the SCL pin of the MPU6050 module to the A5 pin (or SCL pin) of the Arduino board.

Once you have connected all the pins, go to the `measure-rc-car-performance-using-accelerometer` folder, open the `measure-rc-car-performance-using-accelerometer.ino` and upload the files to your arduino.
