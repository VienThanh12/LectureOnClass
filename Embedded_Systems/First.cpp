void setup() {
  Serial.begin(11520);
  pinMode(2, OUTPUT);
  pinMode(23, INPUT_PULLUP);
}
void loop() {
  if(digitalRead(23) == LOW) {
    digitalWrite(2, HIGH);
    delay(2000);
    digitalWrite(2, LOW);
    delay(2000);
  }
  else {
    digitalWrite(2, LOW);
  }
}

