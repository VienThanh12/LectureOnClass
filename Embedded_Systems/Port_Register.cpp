int d = 0;

void setup() {
  // put your setup code here, to run once:
  DDRD = 0b11111111;

  PORTD = 0b00000001;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (PORTD == 0x80)
  {
    d = 1;
  }
  if (PORTD == 0x1)
  {
    d = 0;
  }
  if(d == 0){
    // left
    PORTD = PORTD << 1;
  }

  if(d == 1){
    // right
    PORTD = PORTD >> 1;
  }

  delay(2000);
}
