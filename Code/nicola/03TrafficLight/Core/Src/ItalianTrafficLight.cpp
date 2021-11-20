#include "../Inc/ItalianTrafficLight.hpp"

ItalianTrafficLight::ItalianTrafficLight(LightController *lightController, Timer *timer)
{
    lightCtrl = lightController;
    timerPt = timer;
}

void ItalianTrafficLight::setStatus(int status)
{
    currentStatus = status;
}

int ItalianTrafficLight::getStatus()
{
    return currentStatus;
}

void ItalianTrafficLight::startCycle()
{
    switch (currentStatus)
    {
    case RED:
        lightCtrl->RedON();
        if(timerPt->wait(TIMER1))
		{
        	setStatus(GREEN);
        	timerPt->init();
		}
        break;
    case YELLOW:
        lightCtrl->YellowON();
        if(timerPt->wait(TIMER2))
		{
        	setStatus(RED);
        	timerPt->init();
		}
        break;
    case GREEN:
        lightCtrl->GreenON();
        if(timerPt->wait(TIMER1))
		{
        	setStatus(YELLOW);
        	timerPt->init();
		}
        break;
    
    default:
        break;
    }

}
