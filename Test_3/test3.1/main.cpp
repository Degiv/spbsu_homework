#include <iostream>

using namespace std;

void quickSort(int *myArray, int first, int last)
{
    int i = first;
    int j = last;
    int pivot = myArray[(first + last) / 2];

    while (i <= j)
    {
        while (myArray[i] < pivot)
            ++i;
        while (myArray[j] > pivot)
            --j;
        if (i <= j)
        {
            swap(myArray[i], myArray[j]);
            ++i;
            --j;
        }
    }

    if (j > first)
        quickSort(myArray, first, j);
    if (i < last)
        quickSort(myArray, i, last);
}

int* getNumbers(int &size)
{
    const int maxSize = 1000;
    int tmp[maxSize];
    int i = -1;
    bool isFirst = true;
    while (tmp[i] != 0 || isFirst)
    {
        isFirst = false;
        ++i;
        cin >> tmp[i];
    }

    size = i + 1;
    int* result = new int[size];
    for (int j = 0; j < size; ++j)
        result[j] = tmp[j];

    return result;
}

void showNumbers(int* numbers, int size)
{
    bool isFirst = true;
    int counter = 1;
    int prev = 0;
    if (size != 0)
        prev = numbers[0];

    for (int i = 1; i < size; ++i)
    {
        if (numbers[i] == prev)
        {
            counter++;
        }
        else
        {
            cout << prev << " contains " << counter << " times" << endl;
            counter = 1;
        }
        prev = numbers[i];
    }
    cout << prev << " contains " << counter << " times";
}

int main()
{
    int size = 0;
    cout << "Enter your array of numbers: ";
    int* numbers = getNumbers(size);

    quickSort(numbers, 0, size);

    showNumbers(numbers, size);

    delete[] numbers;
}
