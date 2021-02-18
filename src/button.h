#ifndef button_h
#define button_h

void toggle(boolean **status, int *count, String direction)
{

    if (**status)
    {
        if (millis() - time2 > debounce * 1.5)
        {
            time2 = millis();
            if (direction == "ascend")
            {

                (*count)++;
            }
            else
            {
                (*count)--;
            }

            if (*count >= 3)
            {
                *count = 0;
            }
            else if (*count <= -1)
            {
                *count = 2;
            }
            mapTri();
        }

        Serial.print(direction);
        Serial.println(*count);
        **status = false;
    }
}

void toggleVal(const int pin, boolean *state)
{
    String direction = "";
    int val = analogRead(pin);
    if (pin == JoyY)
    {
        val = map(val, 0, 4095, 4095, 0);
    }

    if (val > 4000)
    {
        direction = "ascend";
    }
    else if (val < 100)
    {
        direction = "descend";
    }
    else
    {
        *state = true;
    }

    if (val > 4000 || val < 100)
    {
        if (pin == JoyX)
        {
            toggle(&state, &xCounter, direction);
            cityCircle();
        }

        else if (pin == JoyY)
        {
            //위로 이동
            toggle(&state, &yCounter, direction);
            cityCircle();
        }
    }
}

#endif
