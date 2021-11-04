#include "../inc/FsmTrafficLightBlinkingYellow.hpp"


FsmTrafficLightBlinkingYellow::FsmTrafficLightBlinkingYellow(TrafficLight *trafficLight,
                                               uint32_t blinkingYellowPauseTimeMs)
{
	_state = _INITIAL;
	_oldState = _INITIAL;
	_trafficLight = trafficLight;
	initTimers(blinkingYellowPauseTimeMs);
}

void FsmTrafficLightBlinkingYellow::initTimers(uint32_t blinkingYellowPauseTimeMs)
{
	_timerBlinkingYellow = new Timer(blinkingYellowPauseTimeMs);
}

int8_t FsmTrafficLightBlinkingYellow::getState()
{
    return _state;
}

void FsmTrafficLightBlinkingYellow::setState(int8_t state)
{
    _state = state;
}

int8_t FsmTrafficLightBlinkingYellow::getOldState()
{
    return _oldState;
}

void FsmTrafficLightBlinkingYellow::setOldState(int8_t oldState)
{
    _oldState = oldState;
}

void FsmTrafficLightBlinkingYellow::reset_state()
{
    _state = _INITIAL;
}

bool FsmTrafficLightBlinkingYellow::in_error_state()
{
	return _state == _ERROR;
}

int8_t FsmTrafficLightBlinkingYellow::initialState()
{
	(*_timerBlinkingYellow).start();
	return _YELLOW_ON;
}

int8_t FsmTrafficLightBlinkingYellow::yellowOnState()
{
	if((*_timerBlinkingYellow).expired()) {
		(*_timerBlinkingYellow).start();
		return _YELLOW_OFF;
	}
	return _YELLOW_ON;
}

int8_t FsmTrafficLightBlinkingYellow::yellowOffState()
{
	if((*_timerBlinkingYellow).expired()) {
		(*_timerBlinkingYellow).start();
		return _YELLOW_ON;
	}
	return _YELLOW_OFF;
}

void FsmTrafficLightBlinkingYellow::sfn()
{
    setOldState(_state);
	switch(_state) {
		case _INITIAL:
			_state = initialState();
			break;
		case _YELLOW_ON:
			_state = yellowOnState();
			break;
		case _YELLOW_OFF:
			_state = yellowOffState();
			break;
		default:
			_state = _ERROR;
			break;
	}
}

void FsmTrafficLightBlinkingYellow::mfn()
{
	if(_state == _INITIAL) {
		_trafficLight->turnOffLeds();
	}
	bool yellowLed = (_state == _YELLOW_ON);
	_trafficLight->setYellowLed(yellowLed);
}
