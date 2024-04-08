#include <bits/stdc++.h>
using namespace std;
char calender(int m, int y)
{
    int year = floor(log10(y)) + 1;
    if (year != 4 || m <= 0 || m > 12)
    {
        cout << "Invalid Month or Year";
        return '\0';
    }
    if (m == 1)
    {
        m = 13;
        y--;
    }
    else if (m == 2)
    {
        m = 14;
        y--;
    }
    int yf = y / 100;
    int yl = y % 100;
    int h = 1 + (13 * (m + 1) / 5 + yl + yl / 4 + yf + 5 * yf);
    h = h % 7;
    cout << "Mon\tTue\tWed\tThur\tFri\tSat\tSun\n";
    int k;
    switch (h)
    {
    case 1:
        cout << "\t\t\t\t\t";
        k = 2;
        break;
    case 2:
        cout << "\t\t\t\t\t\t";
        k = 1;
        break;
    case 3:
        cout << "";
        k = 7;
        break;
    case 4:
        cout << "\t";
        k = 6;
        break;
    case 5:
        cout << "\t\t";
        k = 5;
        break;
    case 6:
        cout << "\t\t\t";
        k = 4;
        break;
    default:
        cout << "\t\t\t\t";
        k = 3;
    }
    int date, day;
    for (date = 1; date <= k; date++)
        cout << date << "\t";
    if (m == 14)
    {
        if (((y + 1) % 4 == 0) && ((y + 1) % 100 != 0) || ((y + 1) % 400 == 0))
            day = 29;
        else
            day = 28;
    }
    else if (m <= 8 && (m % 2 != 0 || m == 8))
        day = 31;
    else if (m > 8 && m % 2 != 0)
        day = 30;
    else
        day = 31;
    for (int i = 1; i <= 5; i++)
    {
        cout << "\n";
        for (int j = 1; j <= 7 && date <= day; j++, date++)
            cout << date << "\t";
    }
    return '\0';
}