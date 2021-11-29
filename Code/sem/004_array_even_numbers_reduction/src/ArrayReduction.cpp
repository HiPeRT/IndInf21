#include "../inc/ArrayReduction.hpp"


ArrayReduction::ArrayReduction(uint8_t *numbers, uint8_t lenNumbers)
{
	_numbers = numbers;
    _lenNumbers = lenNumbers;
    _evenNumbersCount = 0;
    for(uint8_t i=0; i<NUM_SUB_ARRAY; i++) {
        _subArray[i] = new SubArray(_numbers);
    }
}

uint8_t ArrayReduction::getEvenNumbersCount()
{
    return _evenNumbersCount;
}

void ArrayReduction::setEvenNumbersCount(uint8_t evenNumbersCount)
{
    _evenNumbersCount = evenNumbersCount;
}

int8_t ArrayReduction::createThreads()
{
    for(uint8_t i=0; i<NUM_THREADS; i++) {
        pthread_attr_init(&_attr);
        uint8_t numElements = _lenNumbers/NUM_THREADS;
        _subArray[i]->setStartIndex(i*(numElements));
        _subArray[i]->setNumElements(numElements);
        int error = (int8_t)pthread_create(&_thread[i], &_attr, evenNumbers, (void*)_subArray[i]);
        if(error) {
            return _ERROR;
        }
    }
    return _OK;
}

void *ArrayReduction::evenNumbers(void *args)
{
    SubArray *subArray = (SubArray*)args;
    uint8_t *evenNumbersCount = new uint8_t[1];
    (*evenNumbersCount) = 0;
    uint8_t startIndex = subArray->getStartIndex();
    uint8_t endIndex = subArray->getStartIndex()+subArray->getNumElements();
    for(uint8_t i=startIndex; i<endIndex; i++) {
        if(! ((subArray->getNumbers()[i]) % 2)) {
            (*evenNumbersCount) ++;
        }
    }
    pthread_exit((void *)evenNumbersCount);
}

int8_t ArrayReduction::joinThreads()
{
    for(uint8_t i=0; i<NUM_THREADS; i++) {
        pthread_join(_thread[i], (void**)&_ret);
        _evenNumbersCount += *_ret;
    }
    return _OK;
}

int8_t ArrayReduction::destroyAttrThreads()
{
    for(uint8_t i=0; i<NUM_THREADS; i++) {
        pthread_attr_destroy(&_attr);
    }
    return _OK;
}
