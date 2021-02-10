#ifndef button_h
#define button_h

void IRAM_ATTR enterToggle()
{
    enterState = !enterState;
}

void IRAM_ATTR exitToggle()
{
    exitState = !exitState;
    
}

void enter()
{
    if (enterState == LOW)
    {
        //
        enterState = !enterState;
        Serial.println("enterClicked");
    }
}

void exit()
{
    if (exitState == LOW)
    {
        //
        exitState = !exitState;
        Serial.println("exitClicked");
    }
}
#endif
