#include <Arduino.h>
#include "Adafruit_BMP3XX.h"
#include "RH_RF95.h"
#include "Adafruit_BNO055.h"

void BMP388_Initialization (Adafruit_BMP3XX bmp, bool systemsGo)
{
    bmp.begin_I2C(); // find out if necessary, ask dad
    if (!bmp.begin_I2C())
    {
        Serial.println("CRITICAL ERROR DETECTED; BMP388 NOT FOUND / UNRESPONSIVE; EXITING SYSTEM");
        systemsGo = false;
        return;
    }
    bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
    bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
    bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
    bmp.setOutputDataRate(BMP3_ODR_50_HZ);
    Serial.println("BMP388 Initialization complete");
}

void RFM95_Initialization (RH_RF95 rf95, bool systemsGo)
{
    #define RF95_FREQ 915.0
    #define RFM95_RST_Pin 4

    pinMode(RFM95_RST_Pin, OUTPUT);
    digitalWrite(RFM95_RST_Pin, HIGH);
    delay(100);

    // manual reset
    digitalWrite(RFM95_RST_Pin, LOW);
    delay(10);
    digitalWrite(RFM95_RST_Pin, HIGH);
    delay(10);

    rf95.init();
    if (!rf95.init())
    {
        Serial.println("CRITICAL ERROR DETECTED; RFM95 NOT FOUND / UNRESPONSIVE; EXITING SYSTEM");
        systemsGo = false;
        return;
    }
    rf95.setFrequency(RF95_FREQ);
    rf95.setTxPower(23, false);
    Serial.println("RFM95 Initialization complete");
}

void BNO055_Initialization (Adafruit_BNO055 bno, bool systemsGo)
{
    if(!bno.begin())
    {
        Serial.print("CRITICAL ERROR DETECTED; BNO055 NOT FOUND / UNRESPONSIVE; EXITING SYSTEM");
        systemsGo = false;
        return;
    }
}