#include "../inc/OutImage.hpp"

OutImage::OutImage(uint8_t greenLedPin, uint8_t yellowLedPin, uint8_t redLedPin)
{
    _greenLedPin = greenLedPin;
    _yellowLedPin = yellowLedPin;
    _redLedPin = redLedPin;
    init();
    wiringPiSetup();
    initGreenLed();
    initYellowLed();
    initRedLed();
    write();
}

void OutImage::init()
{
    _greenLed = false;
    _yellowLed = false;
    _redLed = false;
}

int8_t OutImage::initGreenLed()
{
    pinMode(_greenLedPin, OUTPUT);
    return 0;
}

int8_t OutImage::initYellowLed()
{
    pinMode(_yellowLedPin, OUTPUT);
    return 0;
}

int8_t OutImage::initRedLed()
{
    pinMode(_redLedPin, OUTPUT);
    return 0;
}

void OutImage::setGreenLed(bool greenLed)
{
    _greenLed = greenLed;
}

void OutImage::setYellowLed(bool yellowLed)
{
    _yellowLed = yellowLed;
}

void OutImage::setRedLed(bool redLed)
{
    _redLed = redLed;
}

void OutImage::write()
{
    dW(_greenLedPin, _greenLed);
    dW(_yellowLedPin, _yellowLed);
    dW(_redLedPin, _redLed);
}
