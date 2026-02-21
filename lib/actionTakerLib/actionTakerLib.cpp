#include <Arduino.h>
#include <string.h>
#include "Adafruit_BMP3XX.h"
#include "Wire.h"
#include "Adafruit_Sensor.h"
#include "SPI.h"
#include "Adafruit_BNO055.h"

void cameraOn ()
{
//to be implemented later
//DOESNT NEED TO BE IMPLEMENTED FOR FIRST FLIGHT // CAMERA MANUALLY ACTIVATED
return;
}

void cameraOff ()
{
//to be implemented later
//DOESNT NEED TO BE IMPLEMENTED FOR FIRST FLIGHT // CAMERA MANUALLY ACTIVATED
return;
}

void cameraConnect ()
{
//to be implemented later
//DOESNT NEED TO BE IMPLEMENTED FOR FIRST FLIGHT // CAMERA MANUALLY ACTIVATED
return;
}

void calibrateBMP (Adafruit_BMP3XX bmp, int seaLevelPressure, bool testResult)
{
    int currentPress = bmp.pressure / 100.0;
    int calculatedAltitude = 44330 * (1.0 - pow(currentPress / seaLevelPressure, 0.190295));
    if (calculatedAltitude != bmp.readAltitude(seaLevelPressure))
    {
        testResult = false;
        return;
    }
    else
    {
        testResult = true;
        return;
    }
}

void setPressureBMP (Adafruit_BMP3XX bmp, char commandBuffer[16], int seaLevelPressure)
{
    #define pressureDataLength 8
    #define dataStartLocation 5
    char pressData[9] = {0}; // preps an empty character array to hold just the data, to make atoi easy
    strncpy(pressData, commandBuffer + dataStartLocation, pressureDataLength); // places the selected locations from commandBuffer into pressData
    pressData[9] = '\0'; // adds a null pointer at the end of pressData to make it a c string for atoi
    seaLevelPressure = atoi(pressData); // places the characters of pressData into seaLevelPressure as the new seaLevelPressure
}

void calibrateBNO (Adafruit_BNO055 bno, bool testResult)
{
  // Get the four calibration values (0..3)
  // Any sensor data reporting 0 should be ignored, 3 means 'fully calibrated"
  uint8_t system, gyro, accel, mag;
  system = gyro = accel = mag = 0;
  bno.getCalibration(&system, &gyro, &accel, &mag);

  /* The data should be ignored until the system calibration is > 0 */
  if (!system)
  {
    testResult = false;
    return;
  }
  else
  {
    testResult = true;
    return;
  }
}

void FGCon ()
{
//to be implemented when IntercomLib is done
//DOESNT NEED TO BE IMPLEMENTED FOR FIRST FLIGHT // FGC NOT FLYING
return;
}

void testFGC (char commandBuffer[16], bool testResult)
{
//to be implemented when IntercomLib is done
//DOESNT NEED TO BE IMPLEMENTED FOR FIRST FLIGHT // FGC NOT FLYING
return;
}

void FGCoff ()
{
//to be implemented when IntercomLib is done
//DOESNT NEED TO BE IMPLEMENTED FOR FIRST FLIGHT // FGC NOT FLYING
return;
}

void ABORT (bool isChutePopped, int parachuteChargePin1)
{
    popChute(isChutePopped, parachuteChargePin1);
    FGCoff();
}

void popChute (bool isChutePopped, int parachuteChargePin1)
{
    analogWrite(parachuteChargePin1, HIGH); // puts the pin on high, pumping all 3.3V of power through it to ignite the charge
    isChutePopped = true;
}