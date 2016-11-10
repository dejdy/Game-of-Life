#include <iostream>
#include "Board.h"

using namespace std;

int main()
{

    Board b(10);
    b.loadBoard("/home/dejdy/Plocha/in.txt");
    cout << endl;
    b.printBoard();
    b.nextGeneration();
    cout << endl;
    b.printBoard();
    return 0;
}