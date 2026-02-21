#ifndef commandLib_H
#define commandLib_H

#include <Arduino.h>
#include "Adafruit_BMP3XX.h"
#include "Wire.h"
#include "Adafruit_Sensor.h"
#include "SPI.h"
#include "Adafruit_BNO055.h"
#include "actionTakerLib.h"

void commandParse(String command, bool isCommand, int commandKey);
void commandAction(bool isChutePopped, int parachuteChargePin1, int commandKey, char commandBuffer[16], bool testResult, Adafruit_BMP3XX bmp, Adafruit_BNO055 bno);

#endif