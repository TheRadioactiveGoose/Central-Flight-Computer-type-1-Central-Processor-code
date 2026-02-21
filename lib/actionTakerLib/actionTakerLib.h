#ifndef actionTakerLib_H
#define actionTakerLib_H

#include <Arduino.h>
#include <string.h>
#include "Adafruit_BMP3XX.h"
#include "Wire.h"
#include "Adafruit_Sensor.h"
#include "SPI.h"
#include "Adafruit_BNO055.h"

void cameraOn ();
void cameraOff ();
void cameraConnect ();
void calibrateBMP (Adafruit_BMP3XX bmp, int seaLevelPressure, bool testResult);
void setPressureBMP (Adafruit_BMP3XX bmp, char commandBuffer[16], int seaLevelPressure);
void calibrateBNO (Adafruit_BNO055 bno, bool testResult);
void FGCon ();
void testFGC (char commandBuffer[16], bool testResult);
void FGCoff ();
void ABORT (bool isChutePopped, int parachuteChargePin1);
void popChute (bool isChutePopped, int parachuteChargePin1);
void popMainChute(bool isChutePopped, int parachuteChargePin2);

#endif