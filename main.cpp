#include <iostream>
#include <chrono>
#include "SudokuHeader.h"

using namespace std;

int main()
{
    SudokuGame a;
    Player p;
    int difficulty,
            r,
            c,
            n,
            count,
            score;
    string name;

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

    auto start = chrono::high_resolution_clock::now();  // Starting Time

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
        auto end = chrono::high_resolution_clock::now();  // Ending Time
        cout << endl << "Nice job!" << endl;
        cout << endl << "Please enter player name: ";
        cin >> name;
        cout << endl << endl;
        
        score = p.ScoreCalculator(chrono::duration_cast<chrono::seconds>(end - start).count(), difficulty);
        p.setScore(score, difficulty, name);
    }

    else
    {
        cout << endl << "You gave up :(" << endl;
        cout << endl << "Please enter player name: ";
        cin >> name;
        cout << endl << endl;

        score = p.ScoreCalculator(0, 0);
        p.setScore(score, difficulty, name);
    }

    a.showSolution();
    cout << endl << endl << endl;
    p.showScore();

    return 0;
}
