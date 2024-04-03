// Libraries allowing SPI and I2C communication
#include<SPI.h>
#include<Wire.h>

// OLED display
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

// RCT lib
#include "RTClib.h"

RTC_DS1307 rtc;
Adafruit_SSD1306 display (128, 64, &Wire, -1);

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Task 
// Step 1. The display shows the time for 2 seconds.  Done 
// Step 2. The display shows the date and name of day for 2 seconds. Done
// Step 3 (Optional) Convert the time from a number to an analogue clock. 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("display not found");
    while(1);
  }
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
  DateTime now = rtc.now();


  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, 10);
  display.print(now.hour(), DEC);
  display.print(':');
  if(now.minute() < 10)
    display.print('0'); 
  display.print(now.minute(), DEC);
  display.print(':');
  display.print(now.second(), DEC);
  display.display();

  delay(2000);

  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, 10);
  display.print(now.year(), DEC);
  display.print('/');
  display.print(now.month(), DEC);
  display.print('/');
  display.print(now.day(), DEC);
  display.println("");
  display.print("(");
  display.print(daysOfTheWeek[now.dayOfTheWeek()]);
  display.print(") ");
  display.display();
  delay(2000);


}
