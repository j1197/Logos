//
// Created by JP on 2019-03-22.
//

#include <iostream>
using namespace std;
int main()
{
    string colour, pluralNoun, celebrity;
    cout << "Enter a colour: \n";
    getline( cin, colour);
    cout << "Enter a plural noun: \n";
    getline( cin, pluralNoun);
    cout << "Enter a celebrity: \n";
    getline( cin, celebrity);
    cout << "Roses are " << colour << "\n";
    cout << pluralNoun << " are blue \n";
    cout << " I love " << celebrity << "\n";
    return 0;
}