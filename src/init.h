#ifndef init_h
#define init_h

void init()
{
    tft.begin();
    WiFi.mode(WIFI_STA);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.println(".");
    }
    httpInit();
    WiFi.disconnect();

    if (esp_now_init() != ESP_OK)
    {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    esp_wifi_set_ps(WIFI_PS_NONE);
    esp_now_register_recv_cb(OnDataRecv);
}
void welcome()
{
    transition();
    timer = timerInit(timer, 5);

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
    if (timerFin(timer) && stage == 0)
    {
        stage = 1;
        transition();
    }
}
#endif