#pragma once

#include "main.h"

/* Has the task of setting the Leds  */

class LightController 
{
    private:
	GPIO_PinState LedRed = GPIO_PIN_RESET;
	GPIO_PinState LedYellow = GPIO_PIN_RESET;
	GPIO_PinState LedGreen = GPIO_PIN_RESET;

    public:
    LightController();
    void RedON();
    void YellowON();
    void GreenON();
    void TurnOFF();
};
