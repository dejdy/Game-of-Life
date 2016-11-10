//
// Created by dejdy on 10.11.16.
//

#include "Cell.h"
#include <iostream>

using namespace std;

Cell::Cell()
{
    setState(false);
}

Cell::~Cell()
{

}

bool Cell::getState()
{
    return this->state;
}

void Cell::setState(bool s)
{
    this->state = s;
}

void Cell::setNextState(bool s)
{
    this->nextState = s;
}

void Cell::nextGeneration()
{
    this->state = nextState;
}

void Cell::print()
{
    if(getState()) cout << "\033[1;32m*\033[0m ";
    else cout << "\033[1;31m*\033[0m ";
}