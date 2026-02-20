#ifndef CommandLib_H
#define CommandLib_H

#include <Arduino.h>
#include "actionTakerLib.h"

void commandParse(String command, bool isCommand, int commandKey);
void commandAction(int commandKey, char commandBuffer[16], bool testResult);

#endif