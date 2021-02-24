#ifndef cityWeather_h
#define cityWeather_h

int KtoC(String k)
{
    //convert kelvin to celcius
    float tempK = atoi(k.c_str());
    float tempC = tempK - 273.15;
    int tempC2 = tempC;

    //반올림
    if (tempC - tempC2 > 0.5)
    {
        tempC2 += 1;
    }
    return tempC2;
}

void cityInfo(String cityName, int cityNum)
{
    char cityNameList[10];

    strcpy(cityNameList, cityName.c_str());
    tft.fillScreen(ILI9341_BLACK);
    tft.setTextColor(ILI9341_DARKGREY);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    for (int i = 0; i < 5; i++)
    {
        float x = 0.1 + i * 0.2;
        tft.setCursor(WIDTH * x, HEIGHT * 0.05);
        tft.print(cityNameList[i]);
    }

    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(4);

    int tempC = KtoC(httpinfo.temp[cityNum]);
    if (tempC < 10)
    {
        tft.setCursor(WIDTH * 0.4, HEIGHT * 0.55);
    }
    else
    {
        tft.setCursor(WIDTH * 0.35, HEIGHT * 0.55);
    }
    tft.print(tempC);
    tft.setTextSize(2);
    tft.print(" C");

    tft.drawLine(WIDTH * 0.35, HEIGHT * 0.7, WIDTH * 0.65, HEIGHT * 0.7, ILI9341_DARKCYAN);

    tft.setTextColor(ILI9341_DARKGREY);
    tft.setCursor(WIDTH * 0.1, HEIGHT * 0.8);
    tft.setTextSize(1);
    tft.println("HUMIDITY");
    // tft.println(windSpeed[0]);m/s SSE
    tft.setTextSize(2);
    tft.setCursor(WIDTH * 0.1, HEIGHT * 0.85);
    tft.print(httpinfo.humidity[cityNum]);
    tft.print(" %");

    tft.setCursor(WIDTH * 0.6, HEIGHT * 0.8);
    tft.setTextSize(1);
    tft.println("WIND SPEED");
    tft.setTextSize(2);
    tft.setCursor(WIDTH * 0.6, HEIGHT * 0.85);
    tft.print(httpinfo.windSpeed[cityNum]);
    tft.setTextSize(1);
    tft.print(" SSE");
}

void snowIcon(int i)
{
    //top line
    tft.drawLine(120, 120 + i, 120, 200 + i, ILI9341_CYAN);

    //왼쪽 아래부터 오른쪽 위
    tft.drawLine(80, 180 + i, 160, 140 + i, ILI9341_CYAN);
    //왼쪽 위부터 오른쪽 아래
    tft.drawLine(80, 140 + i, 160, 180 + i, ILI9341_CYAN);

    //위쪽 가지 왼쪽
    tft.drawLine(120, 140 + i, 106, 126 + i, ILI9341_CYAN);
    //위쪽 가지 오른쪽
    tft.drawLine(120, 140 + i, 134, 126 + i, ILI9341_CYAN);

    //아래쪽 가지 왼쪽
    tft.drawLine(120, 180 + i, 106, 194 + i, ILI9341_CYAN);
    //아래쪽 가지 오른쪽
    tft.drawLine(120, 180 + i, 134, 194 + i, ILI9341_CYAN);

    //왼쪽위 가지 위쪽 가지
    tft.drawLine(100, 150 + i, 100, 136 + i, ILI9341_CYAN);
    //왼쪽위 가지 아래쪽 가지
    tft.drawLine(100, 150 + i, 86, 156 + i, ILI9341_CYAN);

    //왼쪽아래 가지 위쪽 가지
    tft.drawLine(100, 170 + i, 86, 164 + i, ILI9341_CYAN);
    //왼쪽아래 가지 아래쪽 가지
    tft.drawLine(100, 170 + i, 100, 184 + i, ILI9341_CYAN);

    //오른쪽위 가지 위쪽 가지
    tft.drawLine(140, 150 + i, 140, 136 + i, ILI9341_CYAN);
    //오른쪽위 가지 아래쪽 가지
    tft.drawLine(140, 150 + i, 154, 156 + i, ILI9341_CYAN);

    //오른쪽아래 가지 위쪽 가지
    tft.drawLine(140, 170 + i, 154, 164 + i, ILI9341_CYAN);
    //오른쪽아래 가지 아래쪽 가지
    tft.drawLine(140, 170 + i, 140, 184 + i, ILI9341_CYAN);
}

#endif // !cityWeather_h
