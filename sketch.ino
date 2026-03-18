#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE); //SDA-22, SCL-21

volatile int v1 = 0;
volatile int v2 = 0;
volatile int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  u8g2.begin();
  pinMode(26, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
  v1 = digitalRead(26);
  attachInterrupt(digitalPinToInterrupt(26), encoder, CHANGE);
}

int bulbs = 0;
int lastbulb = 0;

void loop() {

  noInterrupts();
  int safeCounter = counter;
  interrupts();

  bulbs = (safeCounter / 5);
  if (lastbulb == bulbs) return; else lastbulb = bulbs;

  u8g2.clearBuffer();
  for (int i = 1 ; i < 5 ; bulbs--, i++) {

    if (bulbs > 0)
      u8g2.drawDisc(20*i, 32, 6);
      else
      u8g2.drawCircle(20*i, 32, 6);
  }
  u8g2.sendBuffer();
}

void encoder() {
  
  v1 = digitalRead(26);
  if (v1 != v2) {
    if (digitalRead(27) != v1) {
      if (counter > 23) return;
      counter++;
    } else {
      if (counter < 2) return;
      counter--;
    }
  } 
  /*Serial.print("Counter value: ");
  Serial.println(counter);
  Serial.print("Time is: ");
  Serial.println(millis()); */
  v2 = v1;
}
