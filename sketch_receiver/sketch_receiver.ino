#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver(1000); // rxPin 11

void setup()
{
  Serial.begin(9600);	// Debugging only
  delay(2000);
  if (!driver.init())
    Serial.println("init failed");
  else
    Serial.println("init success");
  
  driver.setModeRx();
  Serial.print("Speed: ");Serial.println(driver.speed());
  Serial.print("Mode: ");Serial.println(driver.mode());
}

void loop()
{
  uint8_t buf[12];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)) // Non-blocking
    Serial.println((char*)buf);
}