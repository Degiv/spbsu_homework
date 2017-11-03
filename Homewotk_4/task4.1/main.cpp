#include <iostream>
#include "spiral.h"

using namespace std;



int main()
{
    int n = 0;
    cout << "Enter n : ";
    cin >> n;

    int **numbers = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        numbers[i] = new int[n];
    }

    cout << "Enter n x n array : " << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> numbers[i][j];
        }
    }

    cout << "Entered array by spiral : ";
    showBySpiral(numbers, n);

    for (int i = 0; i < n; ++i)
        delete[] numbers[i];

    delete[] numbers;
}
