/*
  Lab 10, Circuit 1
  Arduino power consumption: baseline
  Description: This circuit will turn an LED either ON or OFF for the purposes of collecting power consumption
  data.
  By: Sasha Dauz, 
  Written: April 22, 2025
  I/O Pins
  A0:  
  A1:  
  A2:  
  A3:  
  A4:  
  A5:  
  D0:  
  D1:  
  D2:  
  D3:  
  D4:  
  D5:  
  D6:  
  D7: LED
  D8:  
  D9:  
  D10: 
  D11: 
  D12: 
  D13: 
*/

void setup()
{
  // GLobally disable interrupts
  cli();

  // Enable output on D7 for LED
  DDRD = 0x80;

  // Configure Timer/Counter 0 to be called whenever a pushbutton is pressed (consider connecting to D8)
  // MUST BE PORTB BECAUSE YOU'RE MADE TO USE PIN CHANGE INTERRUPT 0
  TCCR0A = 
  TCCR0B = 
  TIMSK0 = 

  // Globally re-enable interrupts
  sei();
}

void loop() {
  // Nothing to see here...
}

ISR(PCINTO0_vect) {
  if (PINB & 0x01) {
    // Toggle LED
    PORTD ^= 0x80;
}
