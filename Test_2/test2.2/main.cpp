#include <fstream>
#include <iostream>

using namespace std;

struct Date
{
    int day = -1;
    int month = 0;
    int year = 0;
};

bool isNumeral(char token)
{
    return (token >= '0') && (token <= '9');
}

Date minimum(Date first, Date second)
{
    if (first.day == -1)
        return second;

    if (second.day == -1)
        return first;

    if (first.year != second.year)
    {
        if (first.year < second.year)
            return first;
        else
            return second;
    }

    if (first.month != second.month)
    {
        if (first.month < second.month)
            return first;
        else
            return second;
    }

    if (first.day != second.day)
    {
        if (first.day < second.day)
            return first;
        else
            return second;
    }

    return first;
}

int main()
{
    ifstream fin("filename.txt");

    char token = 0;
    bool isEnd = false;
    bool isDate = false;
    Date minDate;
    Date newDate;
    int i = 0;
    isEnd = !fin.get(token);
    while (!isEnd)
    {
        if (token == ' ')
        {
            isDate = true;
            isEnd = !fin.get(token);
            i = 0;
            newDate.day = 0;
            newDate.month = 0;
            newDate.year = 0;
            while (!isEnd && isDate && i < 2)
            {
                if (isNumeral(token))
                {
                    newDate.day = newDate.day * 10 + (token - '0');
                    isEnd = !fin.get(token);
                }
                else
                    isDate = false;
                i++;
            }

            if (!isEnd && isDate && token == '.')
            {
                isEnd = !fin.get(token);
            }
            else
                isDate = false;

            i = 0;
            while (!isEnd && isDate && i < 2)
            {
                if (isNumeral(token))
                {
                    newDate.month = newDate.month * 10 + (token - '0');
                    isEnd = !fin.get(token);
                }
                else
                    isDate = false;
                i++;
            }

            if (!isEnd && isDate && token == '.')
            {
                isEnd = !fin.get(token);
            }
            else
                isDate = false;

            i = 0;
            while (!isEnd && isDate && i < 4)
            {
                if (isNumeral(token))
                {
                    newDate.year = newDate.year * 10 + (token - '0');
                    isEnd = !fin.get(token);
                }
                else
                    isDate = false;
                i++;
            }

            if (!isEnd && isDate && token != ' ')
            {
                isDate = false;
            }

            if (isDate)
            {
                minDate = minimum(minDate, newDate);
            }
        }

        if (token != ' ')
            isEnd = !fin.get(token);
    }

    cout << "Minimum of dates is: ";
    if (minDate.day < 10)
        cout << '0';
    cout << minDate.day << '.';

    if (minDate.month < 10)
        cout << '0';
    cout << minDate.month << '.';

    for (int i = 1000; i >= 10; i /= 10)
    {
        if (minDate.year < i)
            cout << '0';
    }
    cout << minDate.year;
    fin.close();
}
