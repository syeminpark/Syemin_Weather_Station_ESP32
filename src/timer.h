#ifndef timer_h
#define timer_h

void IRAM_ATTR onTimer()
{
    portENTER_CRITICAL_ISR(&timerMux);
    interruptCounter++;
    portEXIT_CRITICAL_ISR(&timerMux);
}

int timerFin(hw_timer_t *Timer)
{
    if (interruptCounter > 0)
    {
        portENTER_CRITICAL(&timerMux);
        interruptCounter--;
        portEXIT_CRITICAL(&timerMux);
        totalInterruptCounter++;
        timerAlarmDisable(Timer);
        return true;
    }
    else
    {
        return false;
    }
}

hw_timer_t *timerInit(hw_timer_t *Timer, int sec)
{

    sec *= 1000000;
    //인자값 0번째 타이머\, 80mhz 신호를 나누기 80 하여 1micros 간격, increment=true
    Timer = timerBegin(0, 80, true);
    //전역 변수, 인터럽트를 수행할 함수의 주소값, 그리고 edge interrupt이 맞는지(아니면 level)
    timerAttachInterrupt(Timer, &onTimer, true);
    //타이머 포인터, 인터럽트가 진행될 카운터(1000000=1초), 인터럽트 이후 자동으로 리로드할 지의 여부)
    timerAlarmWrite(Timer, sec, false);
    timerAlarmEnable(Timer);
    return Timer;
}
#endif