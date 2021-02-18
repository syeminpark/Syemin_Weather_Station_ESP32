#ifndef init_h
#define init_h

void welcomeClose();

void init()
{

    tft.begin();
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
    pinMode(JoyY, INPUT);
    pinMode(JoyX, INPUT);
}

void welcome()
{
    timer = timerInit(timer, 5);

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
}

void welcomeClose()
{
    if (timerFin(timer))
    {
        unsigned int colorList[] = {ILI9341_RED, ILI9341_ORANGE, ILI9341_YELLOW, ILI9341_GREEN, ILI9341_CYAN, ILI9341_DARKCYAN, ILI9341_PURPLE};
        for (int i = 0; i < 50; i++)
        {
            tft.fillCircle(WIDTH * 0.5, HEIGHT * 0.4, 50+i, colorList[i]);
            tft.fillCircle(WIDTH * 0.5, HEIGHT * 0.4, 45+i, colorList[i + 1]);
            tft.fillCircle(WIDTH * 0.5, HEIGHT * 0.4, 40+i, colorList[i + 2]);
            tft.fillCircle(WIDTH * 0.5, HEIGHT * 0.4, 35+i, colorList[i + 3]);
            tft.fillCircle(WIDTH * 0.5, HEIGHT * 0.4, 30+i, colorList[i + 4]);
            tft.fillCircle(WIDTH * 0.5, HEIGHT * 0.4, 25+i, colorList[i + 5]);
            tft.fillCircle(WIDTH * 0.5, HEIGHT * 0.4, 20+i, colorList[i + 6]);

        }
        tft.fillScreen(ILI9341_BLACK);
        mapSetup();
    }
}
#endif