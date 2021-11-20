#pragma once

#include "LightController.hpp"
#include "Timer.hpp"

#define COLOR 2
#define OFF 4
#define TIMER 2000

/* It has the task of managing which Leds must be switched on and for how long in the blinking version of the traffic light */

class BlinkingTrafficLight
{
    private:
    int currentStatus;
    LightController *lightCtrl;
    Timer *timerPt;

    public:
    BlinkingTrafficLight(LightController *lightController, Timer *timer);
    void setStatus(int status);
    int getStatus();
    void startCycle();
};
