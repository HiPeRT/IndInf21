#include "../inc/Timer.hpp"


Timer::Timer(uint32_t pauseTimeMs)
{
    _pauseTimeMs = pauseTimeMs;
    _enable = false;
}

uint32_t Timer::getPauseTimeMs()
{
    return _pauseTimeMs;
}

void Timer::setPauseTimeMs(uint32_t pauseTimeMs)
{
    _pauseTimeMs = pauseTimeMs;
}

uint32_t Timer::start()
{
    _startTimeMs = millis();
    _enable = true;
    return _startTimeMs;
}

bool Timer::expired()
{
    if(_enable && millis() >= (_startTimeMs + _pauseTimeMs)) {
        // _enable = false; // rise front
        return true;
    }
    return false;
}
