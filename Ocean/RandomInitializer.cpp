#include "RandomInitializer.h"

unsigned RandomInitializer::numOfPrey(unsigned _size)
{
    return rand() % 100 + 1;
}

unsigned RandomInitializer::numOfPred(unsigned _size)
{
    return rand() % 100 + 1;
}

unsigned RandomInitializer::numOfObs(unsigned _size)
{
    return  rand() % 100 + 1;
}
