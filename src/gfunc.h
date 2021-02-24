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
            cityInfo(cityP[SEOUL], SEOUL);
            
            snowIcon(-45);

            cityCounter = 3;

            break;

        case 1:
            cityInfo(cityP[ANSAN], ANSAN);
            snowIcon(-45);

            cityCounter = 3;
            break;

        case 2:
            cityInfo(cityP[DAEGU], DAEGU);
            snowIcon(-45);

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
