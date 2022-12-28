#include <iostream>
#include "SudokuHeader.h"

using namespace std;

int main()
{
    SudokuGame a;
    int difficulty,
            r,
            c,
            n,
            count;

    choose:
    cout << endl
         << setw(47) << "Choose Difficulty" << endl
         << setw(42) << "1- Easy" << endl
         << setw(44) << "2- Medium" << endl
         << setw(42) << "3- Hard" << endl
         << setw(38) <<"-> ";
    cin >> difficulty;

    try
    {
        if (difficulty == 1)
        {
            a.sudokuGenerator(difficulty);
            count = 81 - 36;
        }

        else if (difficulty == 2)
        {
            a.sudokuGenerator(difficulty);
            count = 81 - 30;
        }

        else if (difficulty == 3)
        {
            a.sudokuGenerator(difficulty);
            count = 81 - 25;
        }

        else
        {
            throw (difficulty);
        }
    }
    catch (int difficulty)
    {
        cout << endl << "Wrong choice!" << endl;
        goto choose;
    }

    while (count != 0)
    {
        a.displayGame();

        cout << endl << "Enter your input to fill the Sudoku: ";
        cin >> r;
        
        if (r == 0)
        {
            break;
        }

        cin >> c >> n;

        if (a.inputs(r, c, n))
        {
            count--;
        }

        else
        {
            cout << endl << "You entered wrong number!" << endl;
        }
    }

    if (count == 0)
    {
        cout << endl << "Nice job!" << endl << endl;
    }

    else
    {
        cout << endl << "You gave up :(" << endl << endl;
    }

    a.showSolution();

    return 0;
}
