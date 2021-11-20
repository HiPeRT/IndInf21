#pragma once

#include "LightController.hpp"
#include "Timer.hpp"

#define RED 0
#define YELLOW 1
#define GREEN 2
#define TIMER1 6000
#define TIMER2 3000

/* It has the task of managing which Leds must be switched on and for how long in the Italian version of the traffic light */

class ItalianTrafficLight
{
    private:
    int currentStatus;
    LightController *lightCtrl;
    Timer *timerPt;

    public:
    ItalianTrafficLight(LightController *lightController, Timer *timer);
    void setStatus(int status);
    int getStatus();
    void startCycle();
};
