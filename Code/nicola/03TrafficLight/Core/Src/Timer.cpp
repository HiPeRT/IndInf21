#include "../Inc/Timer.hpp"

Timer::Timer(){}

uint32_t Timer::millis()
{
	return uwTick;
}

void Timer::init()
{
	start = millis();
}

bool Timer::wait(uint32_t pauseTime)
{
	if(millis() >= (start + pauseTime))
	{
		return true;
	}
	return false;
}

