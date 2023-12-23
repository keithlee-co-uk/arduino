#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;  // rxPin = 11

void setup()
{
    Serial.begin(9600);	// Debugging only
    driver.init();

}

void loop()
{
  uint8_t buf[12];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)) // Non-blocking
    {
      // Message with a good checksum received, dump it.
      Serial.print("Message: ");
      Serial.println((char*)buf);         
    }
   
}