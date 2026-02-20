#include <RH_RF95.h>
#include <Arduino.h>

#include "RH_RF95.h"
#include "LibTELCOM.h"

#define RF95_FREQ 915.0
#define RFM95_CS 8
#define RFM95_RST 4
#define RFM95_INT 7

String datastring = "0";

void setupRF(RH_RF95 rf95)
{
    pinMode(RFM95_RST, OUTPUT);
    digitalWrite(RFM95_RST, HIGH);
    delay(100);
    // manual reset
    digitalWrite(RFM95_RST, LOW);
    delay(10);
    digitalWrite(RFM95_RST, HIGH);
    delay(10);
    rf95.init();
    rf95.setFrequency(RF95_FREQ);
    rf95.setTxPower(23, false);
    Serial.println("RF setup complete");
}

void packBufferTELCOM(String command, char navPacket[82], char statPacket[23], char outboundTELCOM[128])
{
    datastring = String("c");
    datastring.toCharArray(&outboundTELCOM[0], 1); //this clause adds the 'c' header to the buffer

    datastring = String(command);
    datastring.toCharArray(&outboundTELCOM[1], 4); //this clause adds the confirmation of the latest command from the groundstation

    datastring = String(navPacket);
    datastring.toCharArray(&outboundTELCOM[5], 82); //this clause adds the navigational data in one big packet to the buffer

    datastring = String(statPacket);
    datastring.toCharArray(&outboundTELCOM[88], 23); //this clause adds the rocket status data in one big packet to the buffer

    Serial.println(outboundTELCOM); //for testing
}

void sendBufferTELCOM(char outboundTELCOM[128], RH_RF95 rf95)
{     
    Serial.println("transmitting the buffer");
    RH_RF95::printBuffer("Transmitting: ", (uint8_t *)outboundTELCOM, sizeof(outboundTELCOM));//prints whats in the buffer to confirm what arrives good or bad
    Serial.println("begin RF transmission");
    rf95.send((uint8_t *)outboundTELCOM, sizeof(outboundTELCOM));
    rf95.waitPacketSent();  
}

void lookForTELCOM(char inboundTELCOM[16], RH_RF95 rf95, bool rcvdTELCOM)
{
    if (rf95.available()){  // Should be a message for us now
    rf95.recv((uint8_t *)inboundTELCOM, (uint8_t *)12);
    rcvdTELCOM = true;
    Serial.println(inboundTELCOM);
    }
}