//
// Created by JP on 2019-03-23.
//

#include <iostream>
using namespace std;

int max(int num1, int num2, int num3)
{
    if ( num1 >= num2 && num1 >= num3 )
    {
        return num1;
    }
    else if ( ( num1 >= num2 && num1 <= num3 ) || ( num1 <= num2 && num2 <= num3 ))
    {
        return num3;
    }
    else
    {
        return num2;
    }
}

int main()
{
    int answer;
    answer = max(135,90,67);
    cout << answer << " is greater." << endl;
    return 0;
}