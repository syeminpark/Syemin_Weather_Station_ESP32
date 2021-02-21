#ifndef gfunc_h
#define gfunc_h

void transition()
{
    tft.fillScreen(ILI9341_RED);
    tft.fillScreen(ILI9341_ORANGE);
    tft.fillScreen(ILI9341_YELLOW);
    tft.fillScreen(ILI9341_GREEN);
    tft.fillScreen(ILI9341_CYAN);
    tft.fillScreen(ILI9341_DARKCYAN);
    tft.fillScreen(ILI9341_PURPLE);
    tft.fillScreen(ILI9341_BLACK);
}

void switchScreen()
{
    switch (stage)
    {
    case 1:

        mapSetup();
        stage = 2;
        break;

    case 2:
        if (xCounter > 0)
        {
            stage = 3;
            cityCounter = yCounter;
        }
        break;

    case 3:
        switch (cityCounter)
        {
        case 0:
            seoul();

            tft.setTextColor(ILI9341_WHITE);
            tft.setTextSize(1);
            tft.setCursor(0, 0);
            // tft.println(all[0]);
            // #define WIDTH 240
            // #define HEIGHT 320
            // tft.drawLine(80, 160, 160, 160, ILI9341_CYAN);

            //top line
            tft.drawLine(120, 120, 120, 200, ILI9341_CYAN);

            //왼쪽 아래부터 오른쪽 위
            tft.drawLine(80, 180, 160, 140, ILI9341_CYAN);

            //왼쪽 위부터 오른쪽 아래
            tft.drawLine(80, 140, 160, 180, ILI9341_CYAN);

            //위쪽 가지 왼쪽
            tft.drawLine(120, 140, 106, 126, ILI9341_CYAN);

            //위쪽 가지 오른쪽
            tft.drawLine(120, 140, 134, 126, ILI9341_CYAN);

            //아래쪽 가지 왼쪽
            tft.drawLine(120, 180, 106, 194, ILI9341_CYAN);

            //아래쪽 가지 오른쪽 
            tft.drawLine(120, 180, 134, 194, ILI9341_CYAN);

            // tft.fillRoundRect(80, 155, 80, 5, 30, ILI9341_CYAN);
            // tft.fillRoundRect(115, 120, 5, 80, 30, ILI9341_CYAN);

            // tft.drawRoundRect(WIDTH * 0.01, HEIGHT                                   * 0.01, WIDTH * 0.98, HEIGHT * 0.98, 50, ILI9341_DARKGREY);
            // tft.drawRoundRect(WIDTH * 0.01, HEIGHT * 0.05, WIDTH * 0.5, HEIGHT * 0.5, 50, ILI9341_DARKGREY);

            // tft.println(temp[0]);kelvin 276.15K − 273.15 = 3°C

            // tft.println(tempMax[0]);
            // tft.println(tempMin[0]);
            // tft.println(humidity[0]); percetaage
            // tft.println(windSpeed[0]);m/s SSE
            cityCounter = 3;

            break;

        case 1:
            ansan();

            tft.setTextColor(ILI9341_WHITE);
            tft.setTextSize(3);
            tft.setCursor(0, 0);
            tft.println(temp[1]);
            tft.println(tempMax[1]);
            tft.println(tempMin[1]);
            tft.println(humidity[1]);
            tft.println(windSpeed[1]);

            cityCounter = 3;
            break;

        case 2:
            daegu();

            tft.setTextColor(ILI9341_WHITE);
            tft.setTextSize(3);
            tft.setCursor(0, 0);
            tft.println(temp[2]);
            tft.println(tempMin[2]);
            tft.println(tempMax[2]);
            tft.println(humidity[2]);
            tft.println(windSpeed[2]);

            cityCounter = 3;
            break;

        case 3:
            if (xCounter < 1)
            {
                stage = 1;
            }
            break;
        }
    }
}
#endif
