#pragma once
#include "mysorts.h"

void countingSort(int *numbers, int n, int first, int last)
{
    int length = last - first + 1;
    int *counters = new int [length];
    for (int i = 0; i < length; ++i)
    {
        counters[i] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        counters[numbers[i] - first]++;
    }

    int i = 0;
    int j = 0;
    while (i < n)
    {
        while (counters[j] == 0)
        {
            ++j;
        }
        numbers[i] = first + j;
        counters[j]--;
        ++i;
    }

    delete[] counters;
}
