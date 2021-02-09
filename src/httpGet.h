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
void httpGet()
{
    if ((millis() - lastTime) > timerDelay)
    {
        if (WiFi.status() == WL_CONNECTED)
        {
            String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city[1] + "," + countryCode + "&APPID=" + openWeatherMapApiKey;
            //c.str()=string을 char의 형태로 변환.
            jsonBuffer = httpGETRequest(serverPath.c_str());

            JSONVar myObject = JSON.parse(jsonBuffer);

            // tft.setTextSize(1);
            // tft.setCursor(0, 0);

            // tft.print("JSON object = ");
            // tft.println(myObject);
            // tft.print("Temperature: ");
            // tft.println(myObject["main"]["temp"]);
            // tft.print("Pressure: ");
            // tft.println(myObject["main"]["pressure"]);
            // tft.print("Humidity: ");
            // tft.println(myObject["main"]["humidity"]);
            // tft.print("Wind Speed: ");
            // tft.println(myObject["wind"]["speed"]);
        }
        lastTime = millis();
    }
}

#endif