#include "../Inc/LightController.hpp"

LightController::LightController(){}

void LightController::RedON()
{
    LedRed = GPIO_PIN_SET;
    LedYellow = GPIO_PIN_RESET;
    LedGreen = GPIO_PIN_RESET;
    HAL_GPIO_WritePin(GPIOA, LedRed_Pin, LedRed);
    HAL_GPIO_WritePin(GPIOA, LedYellow_Pin, LedYellow);
    HAL_GPIO_WritePin(GPIOA, LedGreen_Pin, LedGreen);
}

void LightController::YellowON()
{
    LedRed = GPIO_PIN_RESET;
    LedYellow = GPIO_PIN_SET;
    LedGreen = GPIO_PIN_RESET;
    HAL_GPIO_WritePin(GPIOA, LedRed_Pin, LedRed);
    HAL_GPIO_WritePin(GPIOA, LedYellow_Pin, LedYellow);
    HAL_GPIO_WritePin(GPIOA, LedGreen_Pin, LedGreen);
}

void LightController::GreenON()
{
    LedRed = GPIO_PIN_RESET;
    LedYellow = GPIO_PIN_RESET;
    LedGreen = GPIO_PIN_SET;
    HAL_GPIO_WritePin(GPIOA, LedRed_Pin, LedRed);
	HAL_GPIO_WritePin(GPIOA, LedYellow_Pin, LedYellow);
	HAL_GPIO_WritePin(GPIOA, LedGreen_Pin, LedGreen);
}

void LightController::TurnOFF()
{
    LedRed = GPIO_PIN_RESET;
    LedYellow = GPIO_PIN_RESET;
    LedGreen = GPIO_PIN_RESET;
    HAL_GPIO_WritePin(GPIOA, LedRed_Pin, LedRed);
	HAL_GPIO_WritePin(GPIOA, LedYellow_Pin, LedYellow);
	HAL_GPIO_WritePin(GPIOA, LedGreen_Pin, LedGreen);
}
