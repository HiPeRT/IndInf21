#include "../inc/LightSensor.hpp"


LightSensor::LightSensor(InImage *inImage)
{
    _inImage = inImage;
}

bool LightSensor::getLightSensor()
{
    return _inImage->getLightSensor();
}
