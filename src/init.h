#ifndef init_h
#define init_h

void init()
{

    tft.begin();
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
    pinMode(JoySW, INPUT_PULLUP);
    pinMode(JoyY, INPUT);
    pinMode(TOUCH, INPUT);

    attachInterrupt(digitalPinToInterrupt(JoySW), enterToggle, RISING);
    attachInterrupt(digitalPinToInterrupt(TOUCH), exitToggle, FALLING);
}

void welcome()
{
    tft.fillScreen(ILI9341_BLACK);

    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);

    tft.fillCircle(WIDTH * 0.5, HEIGHT * 0.4, 50, ILI9341_RED);
    tft.fillCircle(WIDTH * 0.5, HEIGHT * 0.4, 45, ILI9341_ORANGE);
    tft.fillCircle(WIDTH * 0.5, HEIGHT * 0.4, 40, ILI9341_YELLOW);
    tft.fillCircle(WIDTH * 0.5, HEIGHT * 0.4, 35, ILI9341_GREEN);
    tft.fillCircle(WIDTH * 0.5, HEIGHT * 0.4, 30, ILI9341_CYAN);
    tft.fillCircle(WIDTH * 0.5, HEIGHT * 0.4, 25, ILI9341_DARKCYAN);
    tft.fillCircle(WIDTH * 0.5, HEIGHT * 0.4, 20, ILI9341_PURPLE);
    tft.fillCircle(WIDTH * 0.5, HEIGHT * 0.4, 15, ILI9341_BLACK);
    tft.fillRect(WIDTH * 0.2, HEIGHT * 0.4, 200, 100, ILI9341_BLACK);

    tft.setCursor(65, HEIGHT * 0.5);
    tft.println("Syemin");
    tft.setCursor(60, HEIGHT * 0.58);
    tft.print("Weather");
    tft.setCursor(60, HEIGHT * 0.66);
    tft.print("Station");

    timer = timerInit(timer, 5);
}

boolean welcomeClose()
{
    if (timerFin(timer))
    {

        tft.fillScreen(ILI9341_BLACK);
        return true;
    }
    else
    {
        return false;
    }
}
#endif