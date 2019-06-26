//
// Created by JP on 2019-03-22.
//

#include <iostream>
using namespace std;

int cubic()
{
    int num1, res;
    cout << "Please enter a number: " << endl;
    cin >> num1;
    res = num1 * num1 * num1;
    return res;
}

int main()
{
    double answer = cubic();
    cout << "The cube is " << answer << endl;
    return 0;
}