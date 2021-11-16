#include "../Inc/BlinkingTrafficLight.hpp"

BlinkingTrafficLight::BlinkingTrafficLight(LightController *lightController)
{
    lightCtrl = lightController;
}

void BlinkingTrafficLight::setStatus(int status)
{
    currentStatus = status;
}

int BlinkingTrafficLight::getStatus()
{
    return currentStatus;
}

void BlinkingTrafficLight::startCycle()
{
    switch (getStatus())
    {
    case OFF:
        lightCtrl->TurnOFF(TIMER);
        setStatus(COLOR);        
        break;
    case COLOR:
        lightCtrl->YellowON(TIMER);
        setStatus(OFF);
        break;
    
    default:
        break;
    }
}
