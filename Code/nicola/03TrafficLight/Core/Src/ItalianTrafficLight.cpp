#include "../Inc/ItalianTrafficLight.hpp"


ItalianTrafficLight::ItalianTrafficLight(LightController *lightController)
{
    lightCtrl = lightController;
};

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
        lightCtrl->RedON(TIMER1);
        setStatus(GREEN);        
        break;
    case YELLOW:
        lightCtrl->YellowON(TIMER2);
        setStatus(RED);
        break;
    case GREEN:
        lightCtrl->GreenON(TIMER1);
        setStatus(YELLOW);
        break;
    
    default:
        break;
    }

}
