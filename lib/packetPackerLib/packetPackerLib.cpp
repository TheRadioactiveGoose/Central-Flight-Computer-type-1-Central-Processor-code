#include <Arduino.h>
#include "Adafruit_BMP3XX.h"
#include "Adafruit_BNO055.h"
#include "Adafruit_GPS.h"
#include "utility/imumaths.h"

String datastring;

void packNavigationalBufferPreKalman (Adafruit_BMP3XX bmp, Adafruit_BNO055 bno, Adafruit_GPS GPS, char navPacket[82], int seaLevelPressure, int prev_euler_x, int prev_euler_y, int prev_euler_z)
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

    imu::Vector<3> linearaccel = bno.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);

    datastring = String(linearaccel.z()); //gotta figure out the BNO055
    datastring.toCharArray(&navPacket[28], 5);

    imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);

    datastring = String(euler.x());
    datastring.toCharArray(&navPacket[33], 6);

    datastring = String(euler.y());
    datastring.toCharArray(&navPacket[39], 6);

    datastring = String(euler.z());
    datastring.toCharArray(&navPacket[45], 6);

}