#include "../inc/FsmTrafficLight.hpp"


FsmTrafficLight::FsmTrafficLight(TrafficLight *trafficLight, UserRequest *userRequest,
                        		 uint32_t greenPauseTimeMs, uint32_t yellowPauseTimeMs, uint32_t redPauseTimeMs)
{
	_state = _INITIAL;
	_oldState = _INITIAL;
	_trafficLight = trafficLight;
	_userRequest = userRequest;
	initTimers(greenPauseTimeMs, yellowPauseTimeMs, redPauseTimeMs);
}

void FsmTrafficLight::initTimers(uint32_t greenPauseTimeMs, uint32_t yellowPauseTimeMs, uint32_t redPauseTimeMs)
{
	_timerGreen = new Timer(greenPauseTimeMs);
	_timerYellow = new Timer(yellowPauseTimeMs);
	_timerRed = new Timer(redPauseTimeMs);
}

int8_t FsmTrafficLight::getState()
{
    return _state;
}

void FsmTrafficLight::setState(int8_t state)
{
    _state = state;
}

int8_t FsmTrafficLight::getOldState()
{
    return _oldState;
}

void FsmTrafficLight::setOldState(int8_t oldState)
{
    _oldState = oldState;
}

void FsmTrafficLight::reset_state()
{
    _state = _INITIAL;
}

bool FsmTrafficLight::in_error_state()
{
	return _state == _ERROR;
}

int8_t FsmTrafficLight::initialState()
{
	(*_timerGreen).start();
	return _GREEN;
}

int8_t FsmTrafficLight::greenState()
{
	if((*_timerGreen).expired()) {
		return _GREEN_WAITING_REQUEST;
	}
	if(_userRequest->getRetainedRequest()) {
		_userRequest->setRetainedRequest(false);
		return _GREEN_RECEIVED_REQUEST;
	}
	return _GREEN;
}

int8_t FsmTrafficLight::greenReceivedRequestState()
{
	if((*_timerGreen).expired()) {
		(*_timerYellow).start();
		return _YELLOW;
	}
	return _GREEN_RECEIVED_REQUEST;
}

int8_t FsmTrafficLight::greenWaitingRequestState()
{
	if(_userRequest->getRetainedRequest()) {
		(*_timerYellow).start();
		_userRequest->setRetainedRequest(false);
		return _YELLOW;
	}
	return _GREEN_WAITING_REQUEST;
}

int8_t FsmTrafficLight::yellowState()
{
	if((*_timerYellow).expired()) {
		(*_timerRed).start();
		return _RED;
	}
	return _YELLOW;
}

int8_t FsmTrafficLight::redState()
{
	if((*_timerRed).expired()) {
		(*_timerGreen).start();
		return _GREEN;
	}
	return _RED;
}

void FsmTrafficLight::sfn()
{
    setOldState(_state);
	switch(_state) {
		case _INITIAL:
			_state = initialState();
			break;
		case _GREEN:
			_state = greenState();
			break;
		case _GREEN_WAITING_REQUEST:
			_state = greenWaitingRequestState();
			break;
		case _GREEN_RECEIVED_REQUEST:
			_state = greenReceivedRequestState();
			break;
		case _YELLOW:
			_state = yellowState();
			break;
		case _RED:
			_state = redState();
			break;
		default:
			_state = _ERROR;
			break;
	}
}

void FsmTrafficLight::mfn()
{
	if(_state == _INITIAL) {
		_trafficLight->turnOffLeds();
	}
	bool greenLed = (_state == _GREEN) || (_state == _GREEN_WAITING_REQUEST) || (_state == _GREEN_RECEIVED_REQUEST);
	bool yellowLed = (_state == _YELLOW);
	bool redLed = (_state == _RED);
	_trafficLight->setGreenLed(greenLed);
	_trafficLight->setYellowLed(yellowLed);
	_trafficLight->setRedLed(redLed);
}
