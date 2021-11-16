#pragma once

#include "LightController.hpp"

#define RED 0
#define YELLOW 1
#define GREEN 2
#define TIMER1 3000 //time in ms
#define TIMER2 2000 //time in ms

class ItalianTrafficLight
{
    private:
    int currentStatus;
    LightController *lightCtrl;

    public:
    ItalianTrafficLight(LightController *lightController);
    void setStatus(int status);
    int getStatus();
    void startCycle();
};
