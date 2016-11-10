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
    if(getState()) cout << "1 ";
    else cout << "0 ";
}