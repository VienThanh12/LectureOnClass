int d = 0;

void setup() {
  // put your setup code here, to run once:
  DDRD = 0b11111111; // The Port D Data Direction Register - read/write 
  // Port D Arduino digital pin 0 to 7

  PORTD = 0b00000000; // The Port D Data Register - read/write

  DDRB = 0b00000000;
  PORTB |= 0b00000011;

  // Arduino digital pins 8 to 13
}

/*
DDRB - The Port B Data Direction Register - read/write
PORTB - The Port B Data Register - read/write
PINB - The Port B Input Pins Register - read only 

*/

void loop() {
  // put your main code here, to run repeatedly:
  
  if ((PINB & 0b00000001) == 0)
  {
    PORTD = 0b10000001;
    delay(500);
    PORTD = 0b01000010;
    delay(500);
    PORTD = 0b00100100;
    delay(500);
    PORTD = 0b00011000;
    delay(500);
    PORTD = 0b00000000;
  }
  if ((PINB & 0b00000010) == 0)
  {
    PORTD = 0b11111111;
    delay(500);
    PORTD = 0b01111110;
    delay(500);
    PORTD = 0b00111100;
    delay(500);
    PORTD = 0b00011000;
    delay(500);
    PORTD = 0b00000000;
  }
  
}
