//
// Created by dejdy on 10.11.16.
//

#ifndef GAME_OF_LIFE_CELL_H
#define GAME_OF_LIFE_CELL_H


class Cell
{
public:
    Cell();
    ~Cell();
    bool getState();
    void setState(bool s);
    void setNextState(bool s);
    void nextGeneration();
    void print();
private:
    bool state;
    bool nextState;
};


#endif //GAME_OF_LIFE_CELL_H
