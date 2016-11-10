//
// Created by dejdy on 10.11.16.
//

#ifndef GAME_OF_LIFE_GAME_H
#define GAME_OF_LIFE_GAME_H


#include "Board.h"

class Game
{
public:
    Game(int);
    ~Game();
    void initGame();
    void start(int generations);

private:
    Board * board;
};


#endif //GAME_OF_LIFE_GAME_H
