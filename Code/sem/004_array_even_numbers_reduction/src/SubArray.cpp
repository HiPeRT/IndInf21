#include "../inc/SubArray.hpp"


SubArray::SubArray(uint8_t *numbers)
{
	_numbers = numbers;
}

uint8_t *SubArray::getNumbers()
{
    return _numbers;
}


uint8_t SubArray::getStartIndex()
{
    return _startIndex;
}

void SubArray::setStartIndex(uint8_t startIndex)
{
    _startIndex = startIndex;
}

uint8_t SubArray::getNumElements()
{
    return _numElements;
}

void SubArray::setNumElements(uint8_t numElements)
{
    _numElements = numElements;
}
