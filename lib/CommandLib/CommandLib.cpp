#include <Arduino.h>

void commandParse(String command, bool isCommand, int commandKey)
{
    #define CMD(a,b,c,d) (((uint32_t)(a) << 24) | ((uint32_t)(b) << 16) | ((uint32_t)(c) << 8) | (uint32_t)(d)) //defines CMD as a command that will parse the uint32_t into its individual letters, for the switch command.

    uint32_t commandHash =((uint32_t)command[0] << 24) | ((uint32_t)command[1] << 16) | ((uint32_t)command[2] << 8) |  (uint32_t)command[3]; //this parses the string of letters into the uint32_t that represents those letters

    switch (commandHash) {

    case CMD('C','A','M','1'):
        commandKey = 0;
        break;
    case CMD('C','A','M','0'):
        commandKey = 1;
        break; 
    case CMD('C', 'A', 'M', 'C'):
        commandKey = 2;
        break;
    case CMD('C','A','L','1'):
        commandKey = 3;
        break;
    case CMD('S','E','T','1'):
        commandKey = 4;
        break; 
    case CMD('C', 'A', 'L', '2'):
        commandKey = 5;
        break;
    case CMD('F','G','C','1'):
        commandKey = 6;
        break;
    case CMD('F','G','C','T'):
        commandKey = 7;
        break; 
    case CMD('F', 'G', 'C', '0'):
        commandKey = 8;
        break;
    case CMD('A','B','R','T'):
        commandKey = 9;
        break;
    case CMD('P','A','I','R'):
        commandKey = 10;
        break;
    
}
}