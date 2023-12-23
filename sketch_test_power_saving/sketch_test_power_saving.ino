#include <LowPower.h>

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
LowPower.idle(SLEEP_1S, ADC_OFF, TIMER4_OFF, TIMER3_OFF, TIMER1_OFF, 
		          TIMER0_OFF, SPI_OFF, USART1_OFF, TWI_OFF, USB_OFF);
}
