#ifndef actionTakerLib_H
#define actionTakerLib_H

#include <Arduino.h>
#include "Adafruit_BMP3XX.h"
#include "Wire.h"
#include "Adafruit_Sensor.h"
#include "SPI.h"

void cameraOn ();
void cameraOff ();
void cameraConnect ();
void calibrateBMP ();
void setPressureBMP (char commandBuffer[16]);
void calibrateBNO ();
void FGCon ();
void testFGC (char commandBuffer[16], bool testResult);
void FGCoff ();
void ABORT ();
void popChute ();

#endif