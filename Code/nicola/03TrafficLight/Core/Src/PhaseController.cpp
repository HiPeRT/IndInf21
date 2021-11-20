#include "../Inc/PhaseController.hpp"

PhaseController::PhaseController(bool *phase)
{
	currentPhase = phase;
}

void PhaseController::checkButton()
{
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 0) setPhase();
}

void PhaseController::setPhase()
{
	*currentPhase = !(*currentPhase);
}
