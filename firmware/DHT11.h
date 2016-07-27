// 
//    FILE: DHT11.h
// VERSION: 0.4.2
// PURPOSE: DHT11 Temperature & Humidity Sensor library for Arduino
// LICENSE: GPL v3 (http://www.gnu.org/licenses/gpl.html)
//
// DATASHEET: http://www.micro4you.com/files/sensor/DHT11.pdf
//
//     URL: http://playground.arduino.cc/Main/DHT11Lib
//
// HISTORY:
// George Hadjikyriacou - Original version
// see DHT11.cpp file
// 

#ifndef dht11_h
#define dht11_h

#if defined (SPARK)
  #include "application.h"
#else
  #if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
  #else
    #include "WProgram.h"
  #endif
  // here could follow some of the includes only needed on Arduino
  // see bellow

#endif

#define DHT11LIB_VERSION "0.4.2"

#define DHTLIB_OK                               0
#define DHTLIB_ERROR_CHECKSUM   -1
#define DHTLIB_ERROR_TIMEOUT    -2

class dht11
{
public:
    int read(int pin);
        int humidity;
        int temperature;
};
#endif
//
// END OF FILE