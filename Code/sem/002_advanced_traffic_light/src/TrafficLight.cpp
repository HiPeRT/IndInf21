#include "../inc/TrafficLight.hpp"


TrafficLight::TrafficLight(OutImage *outImage)
{
    _outImage = outImage;
}

void TrafficLight::setGreenLed(bool greenLed)
{
    _outImage->setGreenLed(greenLed);
}

void TrafficLight::setYellowLed(bool yellowLed)
{
    _outImage->setYellowLed(yellowLed);
}

void TrafficLight::setRedLed(bool redLed)
{
    _outImage->setRedLed(redLed);
}

void TrafficLight::turnOffLeds()
{
    setGreenLed(false);
    setYellowLed(false);
    setRedLed(false);
}

