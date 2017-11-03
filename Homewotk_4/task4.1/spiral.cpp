#include "spiral.h"
#include <iostream>

using namespace std;

void showBySpiral(int **numbers, int n)
{
    const int firstIndex = n / 2;
    cout << numbers[firstIndex][firstIndex] << ' ';
    int leftBorder = firstIndex;
    int upBorder = firstIndex - 1;
    int rightBorder = firstIndex;
    int downBorder = firstIndex;
    int i = firstIndex;
    int j = firstIndex - 1;

    while (j >= 0)
    {
        while (i <= rightBorder)
        {
            cout << numbers[j][i] << ' ';
            i++;
        }
        rightBorder++;

        while (j <= downBorder)
        {
            cout << numbers[j][i] << ' ';
            j++;
        }
        downBorder++;

        while (i >= leftBorder)
        {
            cout << numbers[j][i] << ' ';
            i--;
        }
        leftBorder--;

        while (j >= upBorder)
        {
            cout << numbers[j][i] << ' ';
            j--;
        }
        upBorder--;
    }
}
