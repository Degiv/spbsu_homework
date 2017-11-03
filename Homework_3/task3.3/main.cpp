#include <iostream>
#include "mysorts.h"
#include "numerals.h"

using namespace std;

int main()
{
    int n = 0;
    cout << "Enter the length of number : ";
    cin >> n;

    char tmp = 0;
    cout << "Enter the number : ";
    int *numerals = new int [n];
    cin.get(tmp);
    inputNumerals(numerals, n);

    countingSort(numerals, n, 0, 9);

    showNumerals(numerals, n);

    delete[] numerals;
}
