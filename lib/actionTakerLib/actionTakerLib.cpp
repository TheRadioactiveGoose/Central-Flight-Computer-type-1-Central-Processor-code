#include <Arduino.h>
#include "Adafruit_BMP3XX.h"
#include "Wire.h"
#include "Adafruit_Sensor.h"
#include "SPI.h"

void cameraOn ()
{
//to be implemented later
}

void cameraOff ()
{
//to be implemented later
}

void cameraConnect ()
{
//to be implemented later
}

void calibrateBMP (Adafruit_BMP3XX bmp, int seaLevelPressure, bool testResult)
{
    int currentPress = bmp.pressure / 100.0;
    int calculatedAltitude = 44330 * (1.0 - pow(currentPress / seaLevelPressure, 0.190295));
    if (calculatedAltitude != bmp.readAltitude(seaLevelPressure))
    {
        testResult = false;
    }
    else
    {
        testResult = true;
    }
}

void setPressureBMP (char commandBuffer[16], int seaLevelPressure)
{
    memcpy(&seaLevelPressure, &commandBuffer[4], 4);


}

void calibrateBNO ()
{

}

void FGCon ()
{
//to be implemented when IntercomLib is done
}

void testFGC (char commandBuffer[16], bool testResult)
{
//to be implemented when IntercomLib is done
}

void FGCoff ()
{
//to be implemented when IntercomLib is done
}

void ABORT ()
{

}