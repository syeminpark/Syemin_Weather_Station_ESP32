#include "lib.h"

void setup()
{
    Serial.begin(115200);
    Serial.println("serialStart");
    init();
    welcome();
}
void loop()
{
    welcomeClose();
    switchScreen();
    updatehttpESP();
}
