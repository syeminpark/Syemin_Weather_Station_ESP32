#include "lib.h"

void setup()
{
    init();
    welcome();
    Serial.begin(115200);
    Serial.println("serialStart");
}
void loop()
{
    httpGet();
    //void toggleVal(boolean state, const int pin, String axis)
    welcomeClose();
    toggleVal(JoyX, &xState);
    toggleVal(JoyY, &yState);
}
