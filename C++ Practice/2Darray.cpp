//
// Created by JP on 2019-03-25.
//
#include <iostream>
using namespace std;

int main()
{
    int numberGrid[5][3] = { {10,20} , {30,40} , {50,60} , {70,80} , {90,100}};
    for ( int i = 0; i <= 4; i++ )
    {
        for ( int j = 0; j <= 1; j++)
        {
            cout<<numberGrid[i][j];
        }
        cout << endl;
    }

}