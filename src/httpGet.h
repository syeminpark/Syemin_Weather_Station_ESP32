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

void httpUpdate(int cityNum)
{
    String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + cityP[cityNum] + "," + countryCode + "&APPID=" + openWeatherMapApiKey;
    //c.str()=string을 char의 형태로 변환.
    jsonBuffer = httpGETRequest(serverPath.c_str());
    JSONVar myObject = JSON.parse(jsonBuffer);
    httpinfo.all[cityNum] = JSON.stringify(myObject);
    httpinfo.temp[cityNum] = JSON.stringify(myObject["main"]["temp_max"]);

    httpinfo.humidity[cityNum] = JSON.stringify(myObject["main"]["humidity"]);
    httpinfo.windSpeed[cityNum] = JSON.stringify(myObject["wind"]["speed"]);

    Serial.println("Weather Updated");
}

void httpInit()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        httpUpdate(JEJU);
        httpUpdate(ANSAN);
        httpUpdate(DAEGU);
        httpUpdate(SEOUL);
    }
}

void updatehttpESP()
{
    if (check == 0)
    {
        Serial.println("received");

        WiFi.begin(ssid, password);
        while (WiFi.status() != WL_CONNECTED)
        {
            Serial.println(".");
        }
        httpInit();
        WiFi.disconnect();
        check = 2;
        //automatic update
        cityCounter = yCounter;
    }
}

#endif
