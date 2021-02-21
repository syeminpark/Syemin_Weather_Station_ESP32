#ifndef button_h
#define button_h

void toggle(boolean **status, int **count, String direction, const int pin)
{

    if (**status)
    {
        if (millis() - time2 > debounce * 1.5)
        {
            time2 = millis();
            if (direction == "ascend")
            {
                (**count)++;
                if (pin == JoyY && **count > 2)
                {
                    **count = 0;
                }
                else if (pin == JoyX && **count > 1)
                {
                    **count = 1;
                }
            }
            else
            {
                (**count)--;
                if (pin == JoyY && **count < 0)
                {
                    **count = 2;
                }
                else if (pin == JoyX && **count < 0)
                {
                    **count = 0;
                }
            }
            if (pin == JoyY)
            {
                mapTri();
                cityCircle();
            }
            **status = false;
        }
    }
}

void toggleVal(const int pin, boolean *state, int *count, int val)
{
    if (val > 4000 || val < 100)
    {
        String direction = "";
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

        toggle(&state, &count, direction, pin);
    }
    else
    {
        *state = true;
    }
}

void initButton()
{
    if (stage > 0)
    {
        toggleVal(JoyX, &xState, &xCounter, xVal);
        if (stage < 3)
        {
            toggleVal(JoyY, &yState, &yCounter, yVal);
        }
    }
}

#endif
