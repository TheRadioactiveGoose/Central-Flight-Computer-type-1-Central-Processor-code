#include <Arduino.h>
#include "Adafruit_BMP3XX.h"
#include "Adafruit_BNO055.h"
#include "Adafruit_GPS.h"
#include "utility/imumaths.h"

String datastring;

void packNavigationalBufferPreKalman (Adafruit_BMP3XX bmp, Adafruit_BNO055 bno, Adafruit_GPS GPS, char navPacket[82], int seaLevelPressure)
{

    GPS.read();

    datastring = String(GPS.latitudeDegrees*10000);
    datastring.toCharArray(&navPacket[0], 7);
    datastring = String(GPS.longitudeDegrees*-10000);
    datastring.toCharArray(&navPacket[7], 7);
    datastring = String(GPS.altitude);
    datastring.toCharArray(&navPacket[14], 7);

    bmp.performReading(); 

    datastring = String(bmp.readAltitude(seaLevelPressure));
    datastring.toCharArray(&navPacket[21], 7);

    datastring = String(); //gotta figure out the BNO055
    datastring.toCharArray(&navPacket[28], 5);
}