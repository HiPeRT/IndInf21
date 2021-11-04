#include "../inc/InImage.hpp"

InImage::InImage(uint8_t userButtonPin, uint8_t lightSensorPin)
{
    _userButtonPin = userButtonPin;
    _lightSensorPin = lightSensorPin;
    init();
    wiringPiSetup();
    initUserButton();
    initLightSensor();
    read();
}

void InImage::init()
{
    _userButton = false;
    _lightSensor = false;
}

int8_t InImage::initUserButton()
{
    pinMode(_userButtonPin, INPUT);
    return 0;
}

int8_t InImage::initLightSensor()
{
    pinMode(_lightSensorPin, INPUT);
    return 0;
}

bool InImage::getUserButton()
{
    return _userButton;
}

bool InImage::getLightSensor()
{
    return _lightSensor;
}

void InImage::read()
{
    _userButton = dR(_userButtonPin);
    _lightSensor = dR(_lightSensorPin);
}
