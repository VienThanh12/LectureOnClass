int RED_LIGHT = 2, YELLOW_LIGHT = 0, BLUE_LIGHT = 4;
int Switch = 23;

void setup() {
  // put your setup code here, to run once:
  // Initialize serial communication
  Serial.begin(11520);

  // Set the LED pin as an output
  pinMode(RED_LIGHT, OUTPUT);
  pinMode(YELLOW_LIGHT, OUTPUT);
  pinMode(BLUE_LIGHT, OUTPUT);

  // Set the Switch pin as an output
  pinMode(Switch, INPUT_PULLUP);

  // Initial state: Led Off
  digitalWrite(RED_LIGHT, LOW);
  digitalWrite(YELLOW_LIGHT, LOW);
  digitalWrite(BLUE_LIGHT, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(Switch) == HIGH){
    //digitalWrite(BLUE_LIGHT, LOW);
    if(digitalRead(Switch) == HIGH){
      digitalWrite(BLUE_LIGHT, LOW);
      digitalWrite(RED_LIGHT, HIGH);
      delay(2000);
    }
    //delay(2000);
    //digitalWrite(RED_LIGHT, LOW);
    if(digitalRead(Switch) == HIGH){
      digitalWrite(RED_LIGHT, LOW);
      digitalWrite(YELLOW_LIGHT, HIGH);
      delay(2000);
    }
    //digitalWrite(YELLOW_LIGHT, HIGH);
    //delay(2000);
    //digitalWrite(YELLOW_LIGHT, LOW);
    if(digitalRead(Switch) == HIGH){
      digitalWrite(YELLOW_LIGHT, LOW);
      digitalWrite(BLUE_LIGHT, HIGH);
      delay(2000);
    }
    //digitalWrite(BLUE_LIGHT, HIGH);
  }
  else {
    digitalWrite(YELLOW_LIGHT, LOW);
    digitalWrite(BLUE_LIGHT, LOW);
    digitalWrite(RED_LIGHT, HIGH);
    delay(5000);
  }
}
