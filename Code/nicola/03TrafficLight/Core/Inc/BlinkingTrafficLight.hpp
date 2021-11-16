#pragma once

#include "LightController.hpp"

#define COLOR 2
#define OFF 4
#define TIMER 1000 //time in ms

class BlinkingTrafficLight
{
    private:
    int currentStatus;
    LightController *lightCtrl;

    public:
    BlinkingTrafficLight(LightController *lightController);
    void setStatus(int status);
    int getStatus();
    void startCycle();
};