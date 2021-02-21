#ifndef httpGet_h
#define httpGet_h

String httpGETRequest(const char *serverName)
{
    HTTPClient http;
    http.begin(serverName);
    int httpResponseCode = http.GET();
    String payload = "{}";
    if (httpResponseCode > 0)
    {
        payload = http.getString();
    }
    http.end();

    return payload;
}
void httpUpdate()
{
    if ((millis() - lastUpdate) > timerDelay)
    {
        if (WiFi.status() == WL_CONNECTED)
        {
            String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city[1] + "," + countryCode + "&APPID=" + openWeatherMapApiKey;
            //c.str()=string을 char의 형태로 변환.
            jsonBuffer = httpGETRequest(serverPath.c_str());

            JSONVar myObject = JSON.parse(jsonBuffer);

            tft.setTextColor(ILI9341_WHITE);
            tft.setTextSize(1);
            tft.setCursor(0, 0);

            tft.print("JSON object = ");
            tft.println(myObject);
            tft.print("Temperature: ");
            tft.println(myObject["main"]["temp"]);
            tft.print("Pressure: ");
            tft.println(myObject["main"]["pressure"]);
            tft.print("Humidity: ");
            tft.println(myObject["main"]["humidity"]);
            tft.print("Wind Speed: ");
            tft.println(myObject["wind"]["speed"]);
        }
        lastTime = millis();
    }
}

void httpInit(int cityNum)
{
    if (WiFi.status() == WL_CONNECTED)
    {
        String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city[cityNum] + "," + countryCode + "&APPID=" + openWeatherMapApiKey;
        //c.str()=string을 char의 형태로 변환.
        jsonBuffer = httpGETRequest(serverPath.c_str());
        JSONVar myObject = JSON.parse(jsonBuffer);
        all[cityNum] = JSON.stringify(myObject);
        temp[cityNum] = JSON.stringify(myObject["main"]["temp_max"]);
        tempMax[cityNum] = JSON.stringify(myObject["main"]["temp_min"]);
        tempMin[cityNum] = JSON.stringify(myObject["main"]["temp"]);
        humidity[cityNum] = JSON.stringify(myObject["main"]["humidity"]);
        windSpeed[cityNum] = JSON.stringify(myObject["wind"]["speed"]);
    }
}

#endif