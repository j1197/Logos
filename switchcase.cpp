//
// Created by JP on 2019-03-23.
//

#include <iostream>
using namespace std;

string dayoftheWeek()
{
    int dayNum;
    string dayName;
    cout << "Enter the number of the day: " << endl;
    cin >> dayNum;
    switch(dayNum)
    {
        case 0:
            dayName = "Sunday";
            break;
        case 1:
            dayName = "Monday";
            break;
        case 2:
            dayName = "Tuesday";
            break;
        case 3:
            dayName = "Wednesday";
            break;
        case 4:
            dayName = "Thursday";
            break;
        case 5:
            dayName = "Friday";
            break;
        case 6:
            dayName = "Saturday";
            break;
        default:
            dayName = "Invalid";
            break;
    }
    return dayName;
}

int main()
{
    string result;
    result = dayoftheWeek();
    cout << result;
    return 0;

}