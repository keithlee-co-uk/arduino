#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver(1000);  // txPin 12

void setup()
{
  Serial.begin(9600);	  // Debugging only
  delay(2000);
  // if (!driver.init())
  //   Serial.println("init failed");
  //  else
  //   Serial.println("init success");
  
  // driver.setModeTx();
  // Serial.print("Speed: ");Serial.println(driver.speed());
  // Serial.print("Mode: ");Serial.println(driver.mode());
}

void loop()
{
  const char *msg = "Hello World!";
  // driver.send((uint8_t *)msg, strlen(msg));
  // driver.waitPacketSent();
  delay(1000);
}