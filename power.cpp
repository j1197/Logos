//
// Created by JP on 2019-03-25.
//

#include <iostream>
using namespace std;

double pow ()
{
    int a, b;
    cout << "Enter base number: " << endl;
    cin >> a;
    cout << "Enter power: " << endl;
    cin >> b;
    double result = 1;
    int i;
    for (i = 1; i <= b; i++)
    {
//        cout << result << endl;
        result = result * a;
    }
    return result;
}

int main()
{
    double answer = pow ();
    cout << answer << endl;
}