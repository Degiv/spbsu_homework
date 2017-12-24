#include <iostream>
#include "string.h"

using namespace std;


int exponention(int x, int n, int mod)
{
    if (n == 0)
        return 1;

    if (n % 2 == 0)
        return exponention((x * x) % mod, n / 2, mod) % mod;

    return (x * exponention(x, n - 1, mod)) % mod;
}

int hashFunction(String string, int size, int mod, int ratio)
{
    int result = 0;
    for (int i = 0; i < size; ++i)
    {
        result += string.data[i] * exponention(ratio, size - 1 - i, mod);
        result %= mod;
    }

    return result;
}

int* rabinCarp(String main, String substring, int &size)
{
    int mod = 111;
    int ratio = 11;
    int substringHash = hashFunction(substring, substring.size, mod, ratio);
    int mainHash = hashFunction(main, substring.size, mod, ratio);

    int* occurences = new int[main.size];
    size = 0;
    bool areEqual = false;
    for (int i = 0; i < main.size - substring.size + 1; ++i)
    {
        if (mainHash == substringHash)
        {
            areEqual = true;
            int k = 0;
            while(areEqual && k < substring.size)
            {
                if (main.data[i + k] != substring.data[k])
                    areEqual = false;
                ++k;
            }

            if (areEqual)
            {
                occurences[size] = i;
                ++size;
            }
        }
        mainHash = (mainHash + mod - (main.data[i] * exponention(ratio, substring.size - 1, mod)) % mod) * ratio + main.data[i + substring.size];
        mainHash %= mod;
    }

    int* result = new int[size];
    for (int i = 0; i < size; ++i)
        result[i] = occurences[i];
    delete[] occurences;
    return result;
}

int main()
{
    String main;
    cout << "Enter string: ";
    input(main);

    String substring;
    cout << "Enter another string for searching in first string: ";
    input(substring);

    int size = 0;
    int* occurrences = rabinCarp(main, substring, size);
    cout << "Occurrences in: ";
    for (int i = 0; i < size; ++i)
        cout << occurrences[i] << ' ';

    clear(main);
    clear(substring);
    delete[] occurrences;
}
