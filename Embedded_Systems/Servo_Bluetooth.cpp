#include<Arduino.h>
#include "BluetoothSerial.h"
#include <ESP32Servo.h>

BluetoothSerial SerialBT;

const int servoPin = 18;
Servo servo;

void setup(){
  Serial.begin(9600);
  SerialBT.begin("OPPOA92");
  
  servo.attach(servoPin);

}

void loop(){

  if(SerialBT.available()){
    char x = SerialBT.read();
    
    if(x == '1') {
      servo.write(90);
    } 
    if(x == '0') {
      servo.write(0);
    }
  }

  if(Serial.available()){
    SerialBT.write(Serial.read());
  }

  if(SerialBT.available()){
    Serial.write(SerialBT.read());
  }
  
}
