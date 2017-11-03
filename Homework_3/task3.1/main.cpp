#include <iostream>
#include "severalmax.h"

using namespace std;

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

    int severalMax = findSeveralMax(numbers, n);

    if (severalMax == -1)
    {
        cout << "The maximum that is contained more than once is not found";
    }
    else
    {
        cout << "The maximum that is contained more than once is : " << findSeveralMax(numbers, n);
    }

    delete[] numbers;
}
