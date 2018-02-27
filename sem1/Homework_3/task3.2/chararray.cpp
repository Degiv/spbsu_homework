#include "chararray.h"
#include <iostream>

using namespace std;

void inputString(char* str, int length)
{
    char tmp = 0;
    for (int i = 0; i < length; ++i)
    {
        cin.get(tmp);
        str[i] = tmp;
    }
}

bool findSymbols(char* str, int n, char* symbols, int m)
{
    const int numOfSymbols = 128;
    int symbolsCounters[numOfSymbols];

    for (int i = 0; i < numOfSymbols; ++i)
    {
        symbolsCounters[i] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        symbolsCounters[str[i]]++;
    }

    for (int i = 0; i < m; ++i)
    {
        symbolsCounters[symbols[i]]--;
        if (symbolsCounters[symbols[i]] < 0)
        {
            return false;
        }
    }
    return true;
}
