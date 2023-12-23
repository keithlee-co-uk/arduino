/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
  Based on the Dallas Temperature Library example
*********/

// Data wire is connected to the Arduino digital pin 10
#define RCWL_0516 10

void setup(void)
{
  // Radar Sensor
  pinMode(RCWL_0516, INPUT);

  // Start serial communication for debugging purposes
  Serial.begin(9600);

}

void loop(void){ 
  // Radar Read
  bool detection = digitalRead(RCWL_0516);

  // Radar check
  if(detection == HIGH)
    Serial.println("I see you");
  else
    Serial.println("Nothing to see");
  
  delay(1000);

}