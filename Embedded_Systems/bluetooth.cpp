#include<Arduino.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup(){
  Serial.begin(9600);
  SerialBT.begin("OPPOA92");
}

void loop(){
  if(Serial.available()){
    SerialBT.write(Serial.read());
  }
  if(SerialBT.available()){
    Serial.write(SerialBT.read());
  }
  delay(100);
}
