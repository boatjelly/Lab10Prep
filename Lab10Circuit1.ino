/*
  Lab 10, Circuit 1
  Arduino power consumption: baseline
  Description: This circuit will turn an LED either ON or OFF for the purposes of collecting power consumption
  data.
  By: Sasha Dauz, 
  Written: April 22, 2025
  I/O Pins
  ...
  D7: [OUTPUT] LED
  D8: [INPUT] Pushbutton
  ...
*/

void setup()
{
  // GLobally disable interrupts
  cli();

  // Enable output on D7 for LED
  DDRD = 0x80;

  // Configure Timer/Counter 0 to be called whenever a pushbutton is pressed (consider connecting to D8)
  // MUST BE PORTB BECAUSE YOU'RE MADE TO USE PIN CHANGE INTERRUPT 0
  PCICR = 0x01; // Enable Pin Change Interrupt 0 
  PCMSK0 = 0x01; // Enable Pin Change Interrupt 0 to be called whenever Pushbutton connected to D8 is pushed

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
