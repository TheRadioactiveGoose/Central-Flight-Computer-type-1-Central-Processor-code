#ifndef LibTELCOM_H
#define LibTELCOM_H

#include <Arduino.h>
#include "RH_RF95.h"

void setupRF(RH_RF95 rf95);
void packBufferTELCOM(String command, char navPacket[82], char statPacket[23], char outboundTELCOM[128]);
void sendBufferTELCOM(char outboundTELCOM[128], RH_RF95 rf95);
void lookForTELCOM(char inboundTELCOM[16], RH_RF95 rf95, bool rcvdTELCOM);

#endif