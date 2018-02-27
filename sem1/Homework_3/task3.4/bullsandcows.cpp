#pragma once
#include "bullsandcows.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace std;

void generateNum(int* secretNum, const int n)
{
    srand((unsigned int) time(NULL));

    const int numOfNumerals = 10;
    bool usedNumerals[numOfNumerals];
    for (int i = 0; i < numOfNumerals; ++i)
        usedNumerals[i] = false;

    secretNum[0] = rand() % 9 + 1;
    usedNumerals[secretNum[0]] = true;

    for (int i = 1; i < n; ++i)
    {
        secretNum[i] = rand() % (10 - i);
        int j = 0;
        while (j <= secretNum[i])
        {
            if (usedNumerals[j])
                ++secretNum[i];
            ++j;
        }
        usedNumerals[secretNum[i]] = true;
    }
}

void getPlayerNum(int* playerNum, int n)
{
    char tmp = 0;
    for (int i = 0; i < n; ++i)
    {
        cin.get(tmp);
        playerNum[i] = tmp - '0';
    }
    cin.get(tmp);
}

void countBullsAndCows(int* playerNum, int* secretNum, const int n, bool *isFinished)
{
    int cowsCounter = 0;
    int bullsCounter = 0;
    const int numOfNumerals = 10;

    bool *areChecked = new bool [numOfNumerals];
    for (int i = 0; i < numOfNumerals; ++i)
    {
        areChecked[i] = false;
    }

    for (int i = 0; i < n; ++i)
    {
        areChecked[secretNum[i]] = true;
    }

    for (int i = 0; i < n; ++i)
    {
        if (playerNum[i] == secretNum[i])
        {
            bullsCounter++;
        }

        if (areChecked[playerNum[i]])
        {
            cowsCounter++;
        }
    }

    cout << "Number of cows : " << cowsCounter << endl;
    cout << "Number of bulls : " << bullsCounter << endl;

    if (bullsCounter == n)
    {
        *isFinished = true;
    }

    delete[] areChecked;
}

void beginBullsAndCows()
{
    const int n = 4;
    int secretNum[n];

    generateNum(secretNum, n);

    bool isFinished = false;
    int playerNum[n];
    while (!isFinished)
    {
        cout << "Enter a four-digit number : ";
        getPlayerNum(playerNum, n);

        countBullsAndCows(playerNum, secretNum, n, &isFinished);
    }

    cout << "Congratulations! You won!";
}
