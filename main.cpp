#include <iostream>
#include "SudokuHeader.h"

using namespace std;

int main()
{
    SudokuGame a;
    int diff;

    cout<< "Difficulty 1, 2 , 3,4: ";
    cin>>diff;


    a.generate();
    a.displayGame();
    a.sudokuDifficulty(diff);

    return 0;
}
