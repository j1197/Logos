//
// Created by JP on 2019-03-23.
//

#include <iostream>
using namespace std;

double calc()
{
    int num1, num2;
    char opname;
    cout << "Enter the first number: " << endl;
    cin >> num1;
    cout << "Enter the second number: " << endl;
    cin >> num2;
    cout << "Enter A for Addition, S for Subtraction, M for Multiplication, D for Division " << endl;
    cin >> opname;
    if (opname == 'A')
    {
        return num1 + num2;
    }
    else if ( opname == 'S')
    {
        return num1 - num2;
    }
    else if ( opname == 'M')
    {
        return num1 * num2;
    }
    else if ( opname == 'D')
    {
        return num1 / num2;
    }
    else
    {
        return 0;
    }
}
int main()
{
    double result;
    result = calc();
    cout << result << endl;
    return 0;
}