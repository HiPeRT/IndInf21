#pragma once

#include "ItalianTrafficLight.hpp"
#include "BlinkingTrafficLight.hpp"

// Phase definition
#define DAY 0
#define NIGHT 1

/*
 * It has the task of managing the modes supported by the traffic light according to the daily phases.
 * In this modeling the phases are alternated by a button managed by the class Phasecontroller.
*/

class Controller 
{
    private:
    ItalianTrafficLight *italianTL;
    BlinkingTrafficLight *blinkingTL;

    public:
    Controller(ItalianTrafficLight *italianTrafficLight, BlinkingTrafficLight *blinkingTrafficLight);
    void start(bool phase);
    void day();
    void night();
};
