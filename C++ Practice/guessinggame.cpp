//
// Created by JP on 2019-03-24.
//

#include <iostream>
using namespace std;

int main() {
    int guess;
    int secretNum = 35;
    int numofguesses = 0;
    bool outofGuesses = false;

    while (guess != secretNum && !outofGuesses) {

        if (numofguesses <= 5) {
            cout << "Guess a number: " << endl;
            cin >> guess;
            numofguesses++;
        } else {

            outofGuesses = true;
        }
    }
    if (outofGuesses)
    {
        cout << "Game over." << endl;
    }
    else
    {
        cout << "You win!" << endl;
    }
}