#include "../inc/ClassTest.hpp"


ClassTest::ClassTest(int8_t maxValue)
{
	_state = _INITIAL;
    _maxValue = maxValue;
}

int8_t ClassTest::getState()
{
    return _state;
}

void ClassTest::setState(int8_t state)
{
    _state = state;
}

void ClassTest::addValueToState(int8_t value)
{
    _state += value;
}


bool ClassTest::checkReachMaxValue()
{
    if(_state == _maxValue) {
        _state = 0;
        return true;
    }
    return false;
}
