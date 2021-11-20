#include "../Inc/Controller.hpp"

Controller::Controller(ItalianTrafficLight *italianTrafficLight, BlinkingTrafficLight *blinkingTrafficLight)
{
    italianTL = italianTrafficLight;
    blinkingTL = blinkingTrafficLight;
}

void Controller::start(bool phase)
{
    switch (phase)
    {
    case DAY:
        day();
        break;

    case NIGHT:
        night();
        break;
    
    default:
        break;
    }
}

void Controller::day() 
{
    blinkingTL->setStatus(OFF);
    italianTL->startCycle();
}

void Controller::night()
{
    italianTL->setStatus(RED);
    blinkingTL->startCycle();
}
