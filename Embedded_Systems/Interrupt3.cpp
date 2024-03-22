bool ok = false;
hw_timer_t * timer1 = NULL;
hw_timer_t * timer2 = NULL;
hw_timer_t * timer3 = NULL;
#define button_pin 19
#define LED_pin1 32
#define LED_pin2 33
#define LED_pin3 25

void IRAM_ATTR onTimer1(){
  digitalWrite(LED_pin1, !digitalRead(LED_pin1));
}
//void IRAM_ATTR onTimer2(){
//  digitalWrite(LED_pin2, !digitalRead(LED_pin2));
//}
//void IRAM_ATTR onTimer3(){
//  digitalWrite(LED_pin3, !digitalRead(LED_pin3));
//}

//void IRAM_ATTR stopBlink(){
//}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");


  timer1 = timerBegin(0, 80, true);
  timerAttachInterrupt(timer1, &onTimer1, true);
  timerAlarmWrite(timer1, 1200, true);
  timerAlarmEnable(timer1);

  //timer2 = timerBegin(2, 80, true);
  //timerAttachInterrupt(timer2, &onTimer2, true);
  //timerAlarmWrite(timer2, 800000, true);
  //timerAlarmEnable(timer2);

  //timer3 = timerBegin(2, 80, true);
  //timerAttachInterrupt(timer3, &onTimer3, true);
  //timerAlarmWrite(timer3, 1200000, true);
  //timerAlarmEnable(timer3);

  //attachInterrupt(19, stopBlink, FALLING);
}

void loop() {

  if (ok == true){
    
    Serial.println("stop blink");
    //timerAlarmDisable(timer1);
    //timerAlarmDisable(timer2);
    //timerAlarmDisable(timer3);
    //digitalWrite(LED_pin1, LOW);
    //digitalWrite(LED_pin2, LOW);
    //digitalWrite(LED_pin3, LOW);
    //delay(5000);
    //timerAlarmEnable(timer1);
    //timerAlarmEnable(timer2);
    //timerAlarmEnable(timer3);

    //ok = false;
  }
  
}
