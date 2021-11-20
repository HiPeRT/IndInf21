#include "../Inc/BlinkingTrafficLight.hpp"

BlinkingTrafficLight::BlinkingTrafficLight(LightController *lightController, Timer *timer)
{
    lightCtrl = lightController;
    timerPt = timer;
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
    switch (currentStatus)
    {
    case OFF:
        lightCtrl->TurnOFF();
        if(timerPt->wait(TIMER))
		{
        	setStatus(COLOR);
        	timerPt->init();
		}
        break;
    case COLOR:
        lightCtrl->YellowON();
        if(timerPt->wait(TIMER))
		{
        	setStatus(OFF);
        	timerPt->init();
		}
        break;
    
    default:
        break;
    }
}
