/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
  Based on the Dallas Temperature Library example
*********/

#include <OneWire.h>
#include <DallasTemperature.h>

// Temperature data wire is connected to the Arduino digital pin 2
#define TEMP_ONE_WIRE_BUS 2


// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(TEMP_ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature temp_sensors(&oneWire);
DeviceAddress deviceAddress;
int numberOfDevices;


void setup(void)
{
  // Start serial communication for debugging purposes
  Serial.begin(9600);
  // Start up the Temperature library
  temp_sensors.begin();

  // Check the Serial is working
  while (!Serial);
  Serial.println("Starting up");

  // Grab a count of temperature devices on the wire
  numberOfDevices = temp_sensors.getDeviceCount();
  Serial.println("getDeviceCount " + String(numberOfDevices));
  

}

void loop(void){
  Serial.println("");
  int tempC = get_temp();
  const String message = "{'temp': \"" + String(tempC) + "\"}";
  Serial.println(message);
  delay(5000);
}


int get_temp(){
  float sumTemps = 0;
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  temp_sensors.requestTemperatures(); 
  
  // Loop through each device, print out temperature data
  for(int i=0; i<numberOfDevices; i++) {
    // Search the wire for address
    if(temp_sensors.getAddress(deviceAddress, i)){
		  float tempC = temp_sensors.getTempC(deviceAddress);
      sumTemps = sumTemps + tempC;
    }
  }
  return int(sumTemps)/numberOfDevices;
}
