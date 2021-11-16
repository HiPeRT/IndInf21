#include "../Inc/LightController.hpp"

LightController::LightController()
{

}

void LightController::RedON(int timerValue)
{
    LedRed = GPIO_PIN_SET;
    LedYellow = GPIO_PIN_RESET;
    LedGreen = GPIO_PIN_RESET;
    HAL_GPIO_WritePin(GPIOA, LedRed_Pin, LedRed);
    HAL_GPIO_WritePin(GPIOA, LedYellow_Pin, LedYellow);
    HAL_GPIO_WritePin(GPIOA, LedGreen_Pin, LedGreen);
    HAL_Delay(timerValue);
    //WAIT count == timerValue; count++
}

void LightController::YellowON(int timerValue)
{
    LedRed = GPIO_PIN_RESET;
    LedYellow = GPIO_PIN_SET;
    LedGreen = GPIO_PIN_RESET;
    HAL_GPIO_WritePin(GPIOA, LedRed_Pin, LedRed);
    HAL_GPIO_WritePin(GPIOA, LedYellow_Pin, LedYellow);
    HAL_GPIO_WritePin(GPIOA, LedGreen_Pin, LedGreen);
    HAL_Delay(timerValue);
    //WAIT count == timerValue; count++
}

void LightController::GreenON(int timerValue)
{
    LedRed = GPIO_PIN_RESET;
    LedYellow = GPIO_PIN_RESET;
    LedGreen = GPIO_PIN_SET;
    HAL_GPIO_WritePin(GPIOA, LedRed_Pin, LedRed);
	HAL_GPIO_WritePin(GPIOA, LedYellow_Pin, LedYellow);
	HAL_GPIO_WritePin(GPIOA, LedGreen_Pin, LedGreen);
	HAL_Delay(timerValue);
    //WAIT count == timerValue; count++
}

void LightController::TurnOFF(int timerValue)
{
    LedRed = GPIO_PIN_RESET;
    LedYellow = GPIO_PIN_RESET;
    LedGreen = GPIO_PIN_RESET;
    HAL_GPIO_WritePin(GPIOA, LedRed_Pin, LedRed);
	HAL_GPIO_WritePin(GPIOA, LedYellow_Pin, LedYellow);
	HAL_GPIO_WritePin(GPIOA, LedGreen_Pin, LedGreen);
	HAL_Delay(timerValue);
    //WAIT count == timerValue; count++
}
