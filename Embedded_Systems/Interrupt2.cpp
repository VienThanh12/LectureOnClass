#define LED_pin 32
hw_timer_t * timer = NULL;

void IRAM_ATTR onTimer(){
  digitalWrite(LED_pin, !digitalRead(LED_pin));
}
void setup() {
 
  Serial.begin(115200);
  Serial.println("Hello, ESP32");
  pinMode(LED_pin, OUTPUT);
  
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 1000000, true);
  timerAlarmEnable(timer);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Delay start");
  delay(10000); // this speeds up the simulation
  Serial.println("Delay end");
}
