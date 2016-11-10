//
// Created by dejdy on 10.11.16.
//

#include "Game.h"
#include <iostream>
using namespace std;

Game::Game(int size)
{
    board = new Board(size);
}

Game::~Game()
{
    delete board;
}

void Game::start(int num)
{
    board->loadBoard("/home/dejdy/Plocha/in.txt");

    for(int i = 0; i < num; i++)
    {
        board->printBoard();
        board->nextGeneration();
        cout << endl;
    }

}