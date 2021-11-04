#include "../inc/FsmCycleController.hpp"


FsmCycleController::FsmCycleController(FsmTrafficLight *fsmTrafficLight, FsmTrafficLightBlinkingYellow *fsmTrafficLightBlinkingYellow,
                        			   LightSensor *lightSensor)
{
	_state = _INITIAL;
	_oldState = _INITIAL;
	_fsmTrafficLight = fsmTrafficLight;
	_fsmTrafficLightBlinkingYellow = fsmTrafficLightBlinkingYellow;
	_lightSensor = lightSensor;
}

int8_t FsmCycleController::getState()
{
    return _state;
}

void FsmCycleController::setState(int8_t state)
{
    _state = state;
}

int8_t FsmCycleController::getOldState()
{
    return _oldState;
}

void FsmCycleController::setOldState(int8_t oldState)
{
    _oldState = oldState;
}

void FsmCycleController::reset_state()
{
    _state = _INITIAL;
}

bool FsmCycleController::in_error_state()
{
	return _state == _ERROR;
}

int8_t FsmCycleController::initialState()
{
	return _DAY;
}

int8_t FsmCycleController::dayBehaviorState()
{
	if(! _lightSensor->getLightSensor()) {
		return _DAY_TO_NIGHT;
	}
	return _DAY;
}

int8_t FsmCycleController::dayToNightState()
{
	return _NIGHT;
}

int8_t FsmCycleController::nightBehaviorState()
{
	if(_lightSensor->getLightSensor()) {
		return _NIGHT_TO_DAY;
	}
	return _NIGHT;
}

int8_t FsmCycleController::nightToDayState()
{
	return _DAY;
}

void FsmCycleController::sfn()
{
    setOldState(_state);
	switch(_state) {
		case _INITIAL:
			_state = initialState();
			break;
		case _DAY:
			_state = dayBehaviorState();
			break;
		case _DAY_TO_NIGHT:
			_state = dayToNightState();
			break;
		case _NIGHT:
			_state = nightBehaviorState();
			break;
		case _NIGHT_TO_DAY:
			_state = nightToDayState();
			break;
		default:
			_state = _ERROR;
			break;
	}
}

void FsmCycleController::mfn()
{
	switch(_state) {
		case _INITIAL:
			break;
		case _DAY:
			_fsmTrafficLight->sfn();
			_fsmTrafficLight->mfn();
			break;
		case _DAY_TO_NIGHT:
			_fsmTrafficLight->reset_state();
			_fsmTrafficLight->mfn();
			break;
		case _NIGHT:
			_fsmTrafficLightBlinkingYellow->sfn();
			_fsmTrafficLightBlinkingYellow->mfn();
			break;
		case _NIGHT_TO_DAY:
			_fsmTrafficLightBlinkingYellow->reset_state();
			_fsmTrafficLightBlinkingYellow->mfn();
			break;
		default:
			break;
	}
}
