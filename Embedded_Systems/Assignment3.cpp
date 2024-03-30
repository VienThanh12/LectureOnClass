// https://wokwi.com/projects/393519583157947393
/*

The task has an electrical circuit as shown in the picture.
Make a program to control the square on the screen.
The square is controlled by switches. For example, the up button moves the square upwards and the down button moves it in the opposite direction.

*/
#include<SPI.h>
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

Adafruit_SSD1306 display (128, 64, &Wire, -1);

void drawRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t color);

int x = 54, y = 22;
int cnt_1 = 0, cnt_2 = 0, cnt_3 = 0, cnt_4 = 0;

void IRAM_ATTR drawup_1(){
  cnt_1 = 0;
}

void IRAM_ATTR drawup_2(){
  cnt_2 = 0;
}

void IRAM_ATTR drawup_3(){
  cnt_3 = 0;
}

void IRAM_ATTR drawup_4(){
  cnt_4 = 0;
}

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("display not found");
    while(1);
  }

  display.clearDisplay();
  display.display();

  display.drawRect(x, y, 20, 20, WHITE);
  display.display();
  
  pinMode(12, INPUT);
  attachInterrupt(12, drawup_1, RISING);

  pinMode(14, INPUT);
  attachInterrupt(14, drawup_2, RISING);
  
  pinMode(19, INPUT);
  attachInterrupt(19, drawup_3, RISING);

  pinMode(18, INPUT);
  attachInterrupt(18, drawup_4, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(12) == HIGH){
    if(cnt_1 == 0){
      display.clearDisplay();
      display.display();
      y -= 1;
      display.drawRect(x, y, 25, 25, WHITE);
      display.display();
      cnt_1 = 1;
    }
  }
  
  if(digitalRead(14) == HIGH){
    if(cnt_2 == 0){
      display.clearDisplay();
      display.display();
      x += 1;
      display.drawRect(x, y, 25, 25, WHITE);
      display.display();
      cnt_2 = 1;
    }
  }
  
  if(digitalRead(19) == HIGH){
    if(cnt_3 == 0){
      display.clearDisplay();
      display.display();
      x -= 1;
      display.drawRect(x, y, 25, 25, WHITE);
      display.display();
      cnt_3 = 1;
    }
  }
  
  if(digitalRead(18) == HIGH){
    if(cnt_4 == 0){
      display.clearDisplay();
      display.display();
      y += 1;
      display.drawRect(x, y, 25, 25, WHITE);
      display.display();
      cnt_4 = 1;
    }
  }
}

