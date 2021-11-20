#pragma once

#include "main.h"

/* Manages the phases and relates them with the press of a button */

class PhaseController
{
	private:
	bool *currentPhase;

	public:
	PhaseController(bool *phase);
	void checkButton();
	void setPhase();
};
