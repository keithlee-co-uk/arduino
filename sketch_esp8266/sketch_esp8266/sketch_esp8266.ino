include "WiFiEsp.h"

#ifndef HAVE_HWSERIAL1
#include "SoftwareSerial.h"
SoftwareSerial Serial1(5, 6); // RX, TX
#endif

char ssid = "keep";            // your network SSID (name) 
char pass = "8SI&cpQ3";        // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status

#include <WiFiEsp.h>

//************************

void setup()
{
  // initialize serial for debugging
  Serial1.begin(9600);  // Serial for ESP8266 on pins set above - Note its Serial1 < see the 1
  // initialize ESP module
  WiFi.init(&Serial1); // Serial1 !

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    // don't continue
    while (true);
  }

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: "); // Print title to serial monitor
    Serial.println(ssid); // print SSID
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass); // connect to router - network 
    Serial.print(status); // print connection status 
  }
  
}

void loop()
{

}
