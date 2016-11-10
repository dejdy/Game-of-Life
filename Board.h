//
// Created by dejdy on 10.11.16.
//

#ifndef GAME_OF_LIFE_BOARD_H
#define GAME_OF_LIFE_BOARD_H


#include "Cell.h"
#include <vector>

using namespace std;

class Board
{
public:
    Board(unsigned int size);
    ~Board();
    void printBoard();
    void loadBoard(const char * path);
    void nextGeneration();
    unsigned int getSize();

private:
    void updateCells();
    int computeLiveNeighbours(int i, int j);
    bool isAlive(int i, int j);
    void processInputLine(string line, int num);
    vector<vector<Cell> > board;
    unsigned int size;
};


#endif //GAME_OF_LIFE_BOARD_H
