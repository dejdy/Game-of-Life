//
// Created by dejdy on 10.11.16.
//

#include <iostream>
#include <fstream>
#include "Board.h"

Board::Board(unsigned int size)
{
    this->size = size;
    vector<Cell> line(size, Cell());

    for(int i = 0; i < size; i++)
    {
        this->board.push_back(line);
    }
}

Board::~Board()
{

}

unsigned int Board::getSize()
{
    return this->size;
}

void Board::printBoard()
{
    for(unsigned int i = 0; i < this->getSize(); i++)
    {
        for (unsigned int j = 0; j < this->getSize(); j++)
            board[i][j] . print();

        cout << endl;
    }
}

void Board::processInputLine(string line, int num)
{
    int loaded = 0;
    for(int i = 0; i < line.size(); i++)
    {
        if(line[i] == ' ') continue;
        if(line[i] == '1')
            this->board[num][loaded].setState(true);


        if(line[i] == '0')
            this->board[num][loaded].setState(false);

        loaded++;
        if(loaded >= this->getSize()) return;
    }
}

void Board::loadBoard(const char * path)
{
    string line;
    ifstream file(path);
    if (file.is_open())
    {
        for(int i = 0; i < this->getSize(); i++)
        {
            getline (file,line);
            processInputLine(line, i);
        }
        file.close();
    }

    else cout << "Unable to open file";

}

bool Board::isAlive(int i, int j)
{
    if(i < 0 || j < 0 || i >= size || j >= size)
        return false;
    else return board[i][j] . getState();
}

int Board::computeLiveNeighbours(int i, int j)
{
    int count = 0;
    if( isAlive(i+1, j+1) )  count++;
    if( isAlive(i+1, j) )  count++;
    if( isAlive(i+1, j-1) )  count++;
    if( isAlive(i, j+1) )  count++;
    if( isAlive(i, j-1) )  count++;
    if( isAlive(i-1, j+1) )  count++;
    if( isAlive(i-1, j) )  count++;
    if( isAlive(i-1, j-1) )  count++;

    return count;
}

/**
 *
    Každá živá buňka s méně než dvěma živými sousedy zemře.
    Každá živá buňka se dvěma nebo třemi živými sousedy zůstává žít.
    Každá živá buňka s více než třemi živými sousedy zemře.
    Každá mrtvá buňka s právě třemi živými sousedy oživne.

 * */
void Board::nextGeneration()
{
    int live;
    for(int i = 0; i < this->getSize(); i++)
    {
        for(int j = 0; j < this->getSize(); j++)
        {
            live = computeLiveNeighbours(i, j);
            if(live < 2) board[i][j].setNextState(false);
            if(live > 3) board[i][j].setNextState(false);
            if(live == 3) board[i][j].setNextState(true);
            if(live == 2 && board[i][j] . getState()) board[i][j].setNextState(true);
            if(live == 2 && !board[i][j] . getState()) board[i][j].setNextState(false);
        }
    }
    updateCells();
}

/**
 * Changes cell state to new one, it has already been computed
 */
void Board::updateCells()
{
    for(int i = 0; i < this->getSize(); i++)
    {
        for(int j = 0; j < this->getSize(); j++)
        {
            this->board[i][j] . nextGeneration();
        }
    }
}