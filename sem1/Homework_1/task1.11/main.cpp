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

int main()
{
    int n = 0;
    cout << "Enter the length of the array : ";
    cin >> n;

    int *myArray = new int [n];
    cout << "Enter the array : ";
    for (int i = 0; i < n; ++i)
    {
        cin >> myArray[i];
    }

    quickSort(myArray, 0, n - 1);

    cout << "Sorted array : ";
    for (int i = 0; i < n; ++i)
    {
        cout << myArray[i] << ' ';
    }
    delete [] myArray;
}