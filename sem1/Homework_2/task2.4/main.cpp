#include <iostream>

using namespace std;

struct Fraction
{
    int num;
    int den;
};

void insertFraction(Fraction newFraction, Fraction *fractions, int position, int &length)
{
    Fraction tmp = newFraction;
    length++;
    for (int i = position; i < length; ++i)
    {
        swap(fractions[i], tmp);
    }
}

void showFractions(Fraction *fraction, int &length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << fraction[i].num << '/' << fraction[i].den << ' ';
    }
}

void generateFractions(Fraction *fractions, int &length, int maxDenominator)
{
    Fraction newFraction;

    for (int i = 2; i <= maxDenominator; ++i)
    {
        for (int j = 0; j < length - 1; ++j)
        {
            if (fractions[j].den + fractions[j + 1].den <= i)
            {
                newFraction.den = fractions[j].den + fractions[j + 1].den;
                newFraction.num = fractions[j].num + fractions[j + 1].num;
                insertFraction(newFraction, fractions, j + 1, length);
                j++;
            }
        }
    }
}

int main()
{
    int maxDenominator = 0;
    cout << "Enter the the maximum of denominator : ";
    cin >> maxDenominator;

    Fraction *fractions = new Fraction[1000];
    int length = 2;
    fractions[0].num = 0;
    fractions[0].den = 1;
    fractions[1].num = 1;
    fractions[1].den = 1;

    generateFractions(fractions, length, maxDenominator);

    cout << "The simple fractions in range [0, 1] are : ";
    showFractions(fractions, length);

    delete[] fractions;
}