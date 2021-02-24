#ifndef menu_h
#define menu_h

void map();
void cityCircle();
void mapTri();

void mapSetup()
{
    map();
    mapTri();
    cityCircle();
}
void map()
{
    tft.fillScreen(ILI9341_BLACK);
    tft.drawRGBBitmap(50, 10, (uint16_t *)corea.pixel_data, corea.width, corea.height);
    
    tft.setTextSize(2);
    tft.setTextColor(ILI9341_DARKGREY);
    tft.setCursor(15, HEIGHT * 0.7);
    tft.println("Seoul");
    tft.setCursor(15, HEIGHT * 0.76);
    tft.print("Ansan");
    tft.setCursor(15, HEIGHT * 0.82);
    tft.print("Daegu");

    tft.fillCircle(WIDTH * 0.49, HEIGHT * 0.56, 3, ILI9341_CASET);
    tft.fillCircle(WIDTH * 0.46, HEIGHT * 0.58, 3, ILI9341_CASET);
    tft.fillCircle(WIDTH * 0.62, HEIGHT * 0.7, 3, ILI9341_CASET);

    tft.setTextSize(1);
    tft.setCursor(WIDTH * 0.53, HEIGHT * 0.55);
    tft.setTextColor(ILI9341_BLACK);
    tft.println("Seoul");
    tft.setCursor(WIDTH * 0.5, HEIGHT * 0.58);
    tft.print("Ansan");
    tft.setCursor(WIDTH * 0.46, HEIGHT * 0.69);
    tft.print("Daegu");
}

void cityCircle()
{
    tft.fillCircle(8, citySelect[yCounter], 3, ILI9341_MAROON);
    tft.fillCircle(8, citySelect[yCounter - 1], 3, ILI9341_BLACK);
    tft.fillCircle(8, citySelect[yCounter + 1], 3, ILI9341_BLACK);
    tft.fillCircle(8, citySelect[yCounter - 2], 3, ILI9341_BLACK);
    tft.fillCircle(8, citySelect[yCounter + 2], 3, ILI9341_BLACK);
}

void mapTri()
{
    int xPad = 8;
    int yPad = 15;

    for (int i = 0; i < 3; i++)
    {
        tft.fillTriangle(triP[0][i] - xPad, triP[1][i] - yPad, triP[0][i] + xPad, triP[1][i] - yPad, triP[0][i], triP[1][i], ILI9341_WHITE);
    }
    tft.fillTriangle(triP[0][yCounter] - xPad, triP[1][yCounter] - yPad, triP[0][yCounter] + xPad, triP[1][yCounter] - yPad, triP[0][yCounter], triP[1][yCounter], ILI9341_MAROON);
}

#endif // !menu_h