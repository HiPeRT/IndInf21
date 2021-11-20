#pragma once
#include "main.h"

/* Timer based on SysTick */

class Timer
{
	private:
	  uint32_t elapsed;
	  uint32_t start;

	public:
	Timer();
	uint32_t millis();
	void init();
	bool wait(uint32_t pauseTime);
};
