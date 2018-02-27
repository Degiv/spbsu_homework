#pragma once
#include "numerals.h"
#include <iostream>

using namespace std;

void showNumerals(int *numerals, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << numerals[i];
    }
}

void inputNumerals(int *numerals, int n)
{
    char tmp = 0;
    for (int i = 0; i < n; ++i)
    {
        cin.get(tmp);
        numerals[i] = tmp - '0';
    }
}
