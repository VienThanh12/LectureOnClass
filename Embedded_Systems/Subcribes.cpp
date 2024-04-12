#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
// WiFi credentials and MQTT server details
const char* ssid = "seamk-titelab";
const char* password = "Sula289tite";
const char* mqtt_server = "test.mosquitto.org";
// GPIO pin where the LED is connected
#define led_pin 32
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);
void initWiFi() {
 WiFi.mode(WIFI_STA);
 WiFi.begin(ssid, password);
 Serial.print("Connecting to WiFi ..");
 while (WiFi.status() != WL_CONNECTED) {
   Serial.print('.');
   delay(1000);
 }
 Serial.println(WiFi.localIP());
}
void reconnect() {
 while (!mqttClient.connected()) {
   Serial.print("Attempting MQTT connection...");
   // Attempt to connect
   if (mqttClient.connect("espClient")) {
     Serial.println("connected");
     // Subscribe to the topic
     mqttClient.subscribe("Led_Test");
   } else {
     Serial.print("failed, rc=");
     Serial.print(mqttClient.state());
     Serial.println(" try again in 5 seconds");
     delay(5000);
   }
 }
}
// Callback function that will be executed when a message is received on the subscribed topic
void callback(char* topic, byte* payload, unsigned int length) {
 Serial.print("Message arrived in topic: ");
 Serial.println(topic);
 Serial.print("Message:");
 String message;
 for (int i = 0; i < length; i++) {
   message += (char)payload[i];
 }
 Serial.println(message);
 Serial.println("-----------------------");
 // Turn the LED ON or OFF based on the message content
 if (message == "On") {
   digitalWrite(led_pin, HIGH); // Turn the LED on
 } else if (message == "Off") {
   digitalWrite(led_pin, LOW); // Turn the LED off
 }
}
void setup() {
 Serial.begin(9600);
 pinMode(led_pin, OUTPUT);
 initWiFi();
 mqttClient.setServer(mqtt_server, 1883);
 mqttClient.setCallback(callback);
}
void loop() {
 if (!mqttClient.connected()) {
   reconnect();
 }
 mqttClient.loop();
}
