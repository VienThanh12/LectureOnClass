// https://wokwi.com/projects/392421180341653505
#include <ESP32Servo.h>

int vertical, horizontal;
int x, y;
const int controllerVert = 12;
const int controllerHori = 14;

const int servoPin_1 = 18;
const int servoPin_2 = 19;

Servo servo_1;
Servo servo_2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  vertical=analogRead(controllerVert);
  horizontal=analogRead(controllerHori);
  Serial.println(vertical);
  Serial.println(horizontal);

  servo_1.attach(servoPin_1);
  servo_2.attach(servoPin_2);
  x = 90;
  y = 90;
  servo_1.write(x);
  servo_2.write(y);

}

void loop() {
  vertical = analogRead(controllerVert);
  horizontal = analogRead(controllerHori);
  Serial.println(horizontal);
  if(vertical == 4095 && x > 0){
    //Serial.print(x);
    //Serial.print(" ");
    //Serial.println(vertical); 
    x -= 1;
    delay(15);
    servo_1.write(x);
  }
  else if (vertical == 2048 && x <= 90 && x >= 0){
    x += 1;
    delay(15);
    servo_1.write(x);
  }
  else if (vertical == 2048 && x <= 180 && x >= 90){
    x -= 1;
    delay(15);
    servo_1.write(x);
  }
  else if(vertical == 0 && x < 180 && x >= 90){
    delay(15);
    x += 1;
    servo_1.write(x);
  }
  else {
    x = x;
  }

  if(horizontal == 4095 && y > 0){
    //Serial.print(x);
    //Serial.print(" ");
    //Serial.println(horizontal); 
    y -= 1;
    delay(15);
    servo_2.write(y);
  }
  else if (horizontal == 2048 && y <= 90 && y >= 0){
    y += 1;
    delay(15);
    servo_2.write(y);
  }
  else if (horizontal == 2048 && y <= 180 && y >= 90){
    y -= 1;
    delay(15);
    servo_2.write(y);
  }
  else if(horizontal == 0 && y < 180 && y >= 90){
    delay(15);
    y += 1;
    servo_2.write(y);
  }
  else {
    y = y;
  }
}
