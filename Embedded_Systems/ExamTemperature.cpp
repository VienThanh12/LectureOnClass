const float BETA = 3950; // should match the Beta Coefficient of the thermistor
int hysteresis = 3;

int myRelay = 8;
volatile byte relayState = LOW;

void pullRelayHIGH() {
    if(relayState != HIGH){
        digitalWrite(myRelay, HIGH);
        relayState = HIGH;
        Serial.println("RELAY ON");
    }
}

void pullRelayLOW() {
    if(relayState != LOW){
        digitalWrite(myRelay, LOW);
        relayState = LOW;
        Serial.println("RELAY OFF");
    }
}

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);

  pinMode(myRelay, OUTPUT);
  digitalWrite(myRelay, LOW);
  relayState = LOW;
  Serial.println("RELAY OFF");
}

void loop() {
  int analogValue = analogRead(A1);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.println(" ℃");
  delay(100);

  float value = analogRead(A0);
  value = value / 9.83615384615 - 24;

  Serial.println(String("Set temperature: ") + value);

  if (celsius >= (value + hysteresis)) {
    pullRelayLOW();
  } else if (celsius <= (value - hysteresis)) {
    pullRelayHIGH();
  }

  delay(1000);
}
