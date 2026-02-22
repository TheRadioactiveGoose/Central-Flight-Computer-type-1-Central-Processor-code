#ifndef intercomLib.h
#define intercomLib.h

#include <Arduino.h>
#include "Adafruit_BMP3XX.h"
#include "RH_RF95.h"
#include "Adafruit_BNO055.h"
#include "Adafruit_GPS.h"

void BMP388_Initialization (Adafruit_BMP3XX bmp, bool systemsGo);
void RFM95_Initialization (RH_RF95 rf95, bool systemsGo);
void BNO055_Initialization (Adafruit_BNO055 bno, bool systemsGo);
void Adafruit_GPS_Initialization (Adafruit_GPS GPS, bool systemsGo);

#endif