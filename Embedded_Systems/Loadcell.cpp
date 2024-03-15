int val=0;
int temp=0;
const int ledPin = 23;
const int freq = 5000;
const int ledChannel= 0;
const int resolution= 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ledcSetup(ledChannel,freq,resolution);
  ledcAttachPin(ledPin, ledChannel);

}

void loop() {
  delay(1000); // this speeds up the simulation
  val = analogRead(14);
  temp = analogRead(12);

  temp = map(temp, 3813,462,-24,80);
  Serial.print("temp: "); 
  Serial.println(temp);
}
