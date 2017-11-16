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

void heapSort(int *numbers, int n)
{
    buildHeap(numbers, n);

    for (int i = 0; i < n; ++i)
    {
        swap(numbers[n - 1 - i], numbers[0]);
        siftDown(numbers, n - i - 1, 0);
    }
}

int main()
{
    int n = 0;
    cout << "Enter the length of array : ";
    cin >> n;

    int *numbers = new int[n];
    cout << "Enter the array : ";
    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
    }

    heapSort(numbers, n);

    cout << "The sorted array : ";
    for (int i = 0; i < n; ++i)
    {
        cout << numbers[i] << ' ';
    }

    delete[] numbers;
}