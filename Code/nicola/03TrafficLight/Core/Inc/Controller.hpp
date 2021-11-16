#pragma once

#include "ItalianTrafficLight.hpp"
#include "BlinkingTrafficLight.hpp"

#define DAY 0
#define NIGHT 1

class Controller 
{
    private:
    ItalianTrafficLight *italianTL;
    BlinkingTrafficLight *blinkingTL;

    public:
    Controller(ItalianTrafficLight *italianTrafficLight, BlinkingTrafficLight *blinkingTrafficLight);
    void start(int phase);
    void day();
    void night();
};