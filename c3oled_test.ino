#include <Arduino.h>
#include <U8g2lib.h>

#undef LED_BUILTIN
#define LED_BUILTIN 8

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, 6, 5, U8X8_PIN_NONE);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_courR10_tr);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);

  u8g2.firstPage();
  do {
    u8g2.setCursor(33, 40);
    u8g2.print("NANO");
    u8g2.setCursor(33, 60);
    u8g2.print(" ");
    u8g2.drawFrame(28, 24, 72, 40);
  } while (u8g2.nextPage());
}
