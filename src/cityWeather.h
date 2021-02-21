#ifndef cityWeather_h
#define cityWeather_h

void seoul()
{
    tft.fillScreen(ILI9341_BLACK);
    tft.setTextColor(ILI9341_DARKGREY);
    tft.setCursor(15, HEIGHT * 0.7);
    tft.println("Seoul");
}

void ansan()
{
    tft.fillScreen(ILI9341_PINK);
    tft.setCursor(15, HEIGHT * 0.76);
    tft.print("Ansan");
}

void daegu()
{
    tft.fillScreen(ILI9341_RED);
    tft.setCursor(15, HEIGHT * 0.82);
    tft.print("Daegu");
}
#endif // !cityWeather_h
