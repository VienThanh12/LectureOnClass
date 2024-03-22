//https://wokwi.com/projects/393053808869202945
#define button_pin 33
#define led_pin 32

void IRAM_ATTR toggleLED(){
  digitalWrite(led_pin, !digitalRead(led_pin));
}

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(115200);
  //Serial.println("Hello, ESP32!");
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT);
  attachInterrupt(button_pin, toggleLED, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
}
