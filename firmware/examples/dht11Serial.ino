// This example program reads a DHT11 temperature and humidity sensor 
// connected to photon pin 6 and outputs it to the Rx/Tx Pins at 57600 baud.
#include "DHT11/DHT11.h"

#define DHT11_PIN 6

dht11 DHT;
SYSTEM_THREAD(ENABLED);
void setup() {
    Serial1.begin(57600);
    Serial1.println("DHT TEST PROGRAM ");
    Serial1.print("LIBRARY VERSION: ");
    Serial1.println(DHT11LIB_VERSION);
    Serial1.println();
    Serial1.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
}

void loop() {
    int chk;
    Serial1.print("DHT11, \t");
    chk = DHT.read(DHT11_PIN);    // READ DATA
    switch (chk) {
        case DHTLIB_OK:  
            Serial1.print("OK,\t"); 
            break;
        case DHTLIB_ERROR_CHECKSUM: 
            Serial1.print("Checksum error,\t"); 
            break;
        case DHTLIB_ERROR_TIMEOUT: 
            Serial1.print("Time out error,\t"); 
            break;
        default: 
            Serial1.print("Unknown error,\t"); 
            break;
    }
    // DISPLAY DATA
    Serial1.print(DHT.humidity,1);
    Serial1.print(",\t");
    Serial1.println(DHT.temperature,1);
    delay(1000);
}

