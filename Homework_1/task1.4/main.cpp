#include <iostream>

using namespace std;

int main()
{
    const int numberOfSums = 28;
    const int numberOfNumerals = 10;
    int sum[numberOfSums];
    for (int i = 0; i < numberOfSums ; ++i)
    {
        sum[i] = 0;
    }

    for (int i = 0; i < numberOfNumerals; ++i)
    {
        for (int j = 0; j < numberOfNumerals; ++j)
        {
            for (int k = 0; k < numberOfNumerals; ++k)
            {
                ++sum[i + j + k];
            }
        }
    }

    int luckyTicketsCounter = 0;
    for (int i = 0; i < numberOfSums; ++i)
    {
        luckyTicketsCounter += sum[i] * sum[i];
    }

    cout << "In total there are " << luckyTicketsCounter << " lucky tickets";
}