#include <Arduino.h>
#include "Adafruit_BMP3XX.h"
#include "Wire.h"
#include "Adafruit_Sensor.h"
#include "SPI.h"
#include "Adafruit_BNO055.h"
#include "actionTakerLib.h"

void commandParse(String command, bool isCommand, int commandKey)
{
    #define CMD(a,b,c,d) (((uint32_t)(a) << 24) | ((uint32_t)(b) << 16) | ((uint32_t)(c) << 8) | (uint32_t)(d)) //defines CMD as a command that will parse the uint32_t into its individual letters, for the switch command.

    uint32_t commandHash =((uint32_t)command[1] << 24) | ((uint32_t)command[2] << 16) | ((uint32_t)command[3] << 8) |  (uint32_t)command[4]; //this parses the string of letters into the uint32_t that represents those letters

    switch (commandHash) {
    
    case CMD('C','A','M','1'):
        isCommand =  true;
        commandKey = 0;
        break;
    case CMD('C','A','M','0'):
        isCommand =  true;
        commandKey = 1;
        break; 
    case CMD('C', 'A', 'M', 'C'):
        isCommand =  true;
        commandKey = 2;
        break;
    case CMD('C','A','L','1'):
        isCommand =  true;
        commandKey = 3;
        break;
    case CMD('S','E','T','1'):
        isCommand =  true;
        commandKey = 4;
        break; 
    case CMD('C', 'A', 'L', '2'):
        isCommand =  true;
        commandKey = 5;
        break;
    case CMD('F','G','C','1'):
        isCommand =  true;
        commandKey = 6;
        break;
    case CMD('F','G','C','T'):
        isCommand =  true;
        commandKey = 7;
        break; 
    case CMD('F', 'G', 'C', '0'):
        isCommand =  true;
        commandKey = 8;
        break;
    case CMD('A','B','R','T'):
        isCommand =  true;
        commandKey = 9;
        break;
    default:
        isCommand = false;
        commandKey = 10;
        break;
}
}

void commandAction(int commandKey, char commandBuffer[16], bool testResult, Adafruit_BMP3XX bmp, Adafruit_BNO055 bno, int seaLevelPressure)
{
    switch (commandKey)
    {
        case 0: //CAM1  (camera on)
            cameraOn();
            break;

        case 1: //CAM0 (camera off)
            cameraOff();
            break;

        case 2: //CAMC (connect camera to groundstation)
            cameraConnect();
            break;

        case 3: //CAL1 (calibrate BMP388)
            calibrateBMP(bmp, seaLevelPressure, testResult);
            break;

        case 4: //SET1 (set the BMP388 sea level pressure based on the inputted command buffer)
            setPressureBMP(bmp, commandBuffer, seaLevelPressure);
            break;

        case 5: //CAL2 (calibrate BNO055)
            calibrateBNO(bno, testResult);
            break;

        case 6: //FGC1 (flight guidance computer on)
            FGCon();
            break;

        case 7: //FGCT (test the flight guidance computer)
            testFGC(commandBuffer, testResult);
            break;

        case 8: //FGC0 (flight guidance computer off)
            FGCoff();
            break;

        case 9: //ABRT (ABORT LAUNCH - pop chute immediately, cancel all guidance, etc)
            ABORT();
            break;
    }
}