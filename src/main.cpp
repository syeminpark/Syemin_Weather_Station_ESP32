#include "lib.h"

void setup()
{
    init();
    welcome();
    Serial.begin(115200);
    Serial.println("serialStart");}
void loop()
{
    welcomeClose();
    switchScreen();
}
