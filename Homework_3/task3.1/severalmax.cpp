#include "severalmax.h"
#include <iostream>

using namespace std;

void siftUp(int *numbers, int position)
{
    while (position != 0 && numbers[position] > numbers[(position - 1) / 2])
    {
        swap(numbers[position], numbers[(position - 1) / 2]);
        position = (position - 1) / 2;
    }
}

void siftDown(int *numbers, int n, int position)
{
    int next = position * 2 + 1;
    bool isHeap = false;
    while (next < n && !isHeap)
    {
        if (next + 1 < n && numbers[next] < numbers[next + 1])
            next++;

        if (numbers[next] > numbers[position])
        {
            swap(numbers[next], numbers[position]);
            position = next;
            next = position * 2 + 1;
        }
        else
        {
            isHeap = true;
        }
    }
}

void buildHeap(int *numbers, int n)
{
    for (int i = 1; i < n; ++i)
    {
        siftUp(numbers, i);
    }
}

int findSeveralMax(int *numbers, int n)
{
    buildHeap(numbers, n);

    bool isFound = false;
    int i = 0;
    int severalMax = 0;
    while (i < n - 1 && !isFound)
    {
        swap(numbers[n - 1 - i], numbers[0]);
        siftDown(numbers, n - i - 1, 0);
        if (numbers[0] == numbers[n - i - 1])
        {
            isFound = true;
            severalMax = numbers[0];
        }
        ++i;
    }

    if (isFound)
    {
        return severalMax;
    }
    else
    {
        return -1;
    }
}
