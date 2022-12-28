#include <iostream>  // keke
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

    char choice;

    choose:
    cout << "Choose Difficulty" << endl
         << "1- Easy" << endl
         << "2- Medium" << endl
         << "3- Hard" << endl;
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
        cin >> r >> c >> n;

        if (a.inputs(r, c, n))
        {
            count--;
        }

        cout << endl << "Do you want to continue (Y/N): ";
        cin >> choice;

        if (choice == 'N')
        {
            break;
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
