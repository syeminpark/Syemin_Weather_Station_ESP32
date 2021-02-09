#include "lib.h"

void menu();

void setup()
{
    init();
    welcome();
    Serial.begin(115200);
    Serial.println("serialStart");
}
void loop()
{
    httpGet();
    if (welcomeClose())
    {
        // menu();
    }
    enter();
    exit();

    // yValue = analogRead(JoyY);
    // enterClick = digitalRead(JoySW);
    // exitClick = digitalRead(TOUCH);

    // Serial.print("Yval: ");
    // Serial.println(yValue);
    // delay(1000);

    // Serial.print("enterclick: ");
    // Serial.println(enterClick);
    // delay(1000);

    // Serial.print("exitclick: ");
    // Serial.println(exitClick);
    // delay(1000);
}

void menu()
{

    tft.setCursor(15, HEIGHT * 0.7);
    tft.setTextSize(2);
    tft.setTextColor(ILI9341_DARKGREY);
    tft.drawRGBBitmap(50, 10, (uint16_t *)corea.pixel_data, corea.width, corea.height);

    tft.println("Seoul");
    tft.fillCircle(8, HEIGHT * 0.72, 3, ILI9341_MAROON);

    tft.fillCircle(WIDTH * 0.48, HEIGHT * 0.56, 3, ILI9341_CASET);
    tft.fillCircle(WIDTH * 0.46, HEIGHT * 0.58, 3, ILI9341_CASET);
    tft.fillCircle(WIDTH * 0.62, HEIGHT * 0.7, 3, ILI9341_CASET);
    tft.fillTriangle(WIDTH * 0.44, HEIGHT * 0.51, WIDTH * 0.52, HEIGHT * 0.51, WIDTH * 0.48, HEIGHT * 0.56, ILI9341_MAROON);
    tft.setCursor(15, HEIGHT * 0.76);
    tft.print("Daegu");
    tft.setCursor(15, HEIGHT * 0.82);
    tft.print("Ansan");
    tft.setTextSize(1);
    tft.setCursor(WIDTH * 0.52, HEIGHT * 0.56);
    tft.setTextColor(ILI9341_BLACK);
    tft.println("Seoul");
    tft.setCursor(WIDTH * 0.5, HEIGHT * 0.58);
    tft.print("Ansan");
    tft.setCursor(WIDTH * 0.46, HEIGHT * 0.69);
    tft.print("Daegu");
}
