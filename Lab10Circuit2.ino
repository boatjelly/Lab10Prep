/*
  Lab 10, Circuit 2
  Sleep modes
  Description: This circuit will utilize two pushbuttons. One pushbutton will put the microcontroller into a sleep
  mode. The second pushbutton will exit the sleep mode and turn an LED either ON or OFF.
  By: Sasha Dauz, 
  Written: April 22, 2025
  I/O Pins
  A0: [INPUT] Pushbutton (Sleep)
  ...
  D7: [OUTPUT] LED
  D8: [INPUT] Pushbutton (Toggle LED)
  ...
*/

void setup()
{
  // GLobally disable interrupts
  cli();

  // Enable output on D7 for LED
  DDRD = 0x80;
  
  PCICR = 0x03; // Enable Pin Change Interrupt 0, 1 on Port B, Port C respectively
  PCMSK0 = 0x01; // Enable Pin Change Interrupt 0 to be called whenever Pushbutton connected to D8 is pushed
  PCMSK1 = 0x01; // Enable Pin Change Interrupt 1 to be called whenever Pushbutton connected to A0 is pushed

  // Globally re-enable interrupts
  sei();
}

void loop() {
  // Conditional logic to activate sleep mode
  // LED should be OFF when microcontroller is asleep

  
}

ISR(PCINT0_vect) {
  if (PINB & 0x01) {
    // Toggle LED
    PORTD ^= 0x80;
}

ISR(PCINT1_vect) {
  /* 
  instead of triggering the sleep condition in the ISR, it is recommended that you set a flag in the INT1 ISR, which will cause
  conditional logic in the loop function to activate the sleep mode
  */
}
