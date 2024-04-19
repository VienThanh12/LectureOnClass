#include <ESP32Servo.h>

const int servoPin = 5;
Servo servo;
int Switch = 18;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello, ESP32!");
  servo.attach(servoPin);
  pinMode(Switch, INPUT_PULLUP);
}

void loop() {
  servo.write(0);
  delay(1000);
  servo.write(90);
  delay(1000);
  servo.write(180);
  delay(1000);
  
}
