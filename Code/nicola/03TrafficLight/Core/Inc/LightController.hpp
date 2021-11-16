#pragma once

#include "main.h"

class LightController 
{
    private:
	GPIO_PinState LedRed = GPIO_PIN_RESET;
	GPIO_PinState LedYellow = GPIO_PIN_RESET;
	GPIO_PinState LedGreen = GPIO_PIN_RESET;

    public:
    LightController();
    void RedON(int timerValue);
    void YellowON(int timerValue);
    void GreenON(int timerValue);
    void TurnOFF(int timerValue);
};
