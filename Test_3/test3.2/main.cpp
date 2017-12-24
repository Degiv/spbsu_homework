#include <iostream>

using namespace std;

int** getNumbers(int n, int m)
{
    int** result = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        result[i] = new int[m];
        for (int j = 0; j < m; ++j)
            cin >> result[i][j];
    }
    return result;
}

bool** createFlags(int n, int m)
{
    bool** result = new bool*[n];
    for (int i = 0; i < n; ++i)
    {
        result[i] = new bool[m];
        for (int j = 0; j < m; ++j)
            result[i][j] = false;
    }
    return result;
}

void clearLine(bool** areLineMins, int index, int m)
{
    for (int i = 0; i < m; ++i)
        areLineMins[index][i] = false;
}

void clearColumn(bool** areColumnMins, int index, int n)
{
    for (int i = 0; i < n; ++i)
        areColumnMins[i][index] = false;
}

void findMins(int** numbers, bool** areLineMins, bool** areColumnMins, int n, int m)
{
    int curMin = 0; // index
    for (int i = 0; i < n; ++i)
    {
        curMin = 0;
        areLineMins[i][curMin] = true;
        for (int j = 1; j < m; ++j)
        {
            if (numbers[i][curMin] == numbers[i][j])
                areLineMins[i][j] = true;
            if (numbers[i][curMin] > numbers[i][j])
            {
                clearLine(areLineMins, i, m);
                curMin = j;
                areLineMins[i][curMin] = true;
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        curMin = 0;
        areColumnMins[curMin][i] = true;
        for (int j = 1; j < n; ++j)
        {
            if (numbers[curMin][i] == numbers[j][i])
                areColumnMins[j][i] = true;
            if (numbers[curMin][i] > numbers[j][i])
            {
                clearColumn(areColumnMins, i, n);
                curMin = j;
                areColumnMins[curMin][i] = true;
            }
        }
    }
}

void showSadlePoints(int** numbers, bool** areLineMins, bool** areColumnMins, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (areLineMins[i][j] && areColumnMins[i][j])
                cout << "point " << numbers[i][j] << " with coordinate (" << j + 1 << ", " << n - i <<") is saddle point" << endl;
        }
    }
}

void deleteNumbers(int** numbers, int n)
{
    for (int i = 0; i < n; ++i)
        delete[] numbers[i];
    delete numbers;
}

void deleteFlags(bool** flags, int n)
{
    for (int i = 0; i < n; ++i)
        delete[] flags[i];
    delete flags;
}

int main()
{
    int n = 0;
    cout << "Enter the height: ";
    cin >> n;

    int m = 0;
    cout << "Enter the width: ";
    cin >> m;

    cout << "Enter your array: " << endl;
    int** numbers = getNumbers(n, m);

    bool** areLineMins = createFlags(n, m);
    bool** areColumnMins = createFlags(n, m);
    findMins(numbers, areLineMins, areColumnMins, n, m);

    cout << "Saddle point is:" << endl;
    showSadlePoints(numbers, areLineMins, areColumnMins, n, m);

    deleteNumbers(numbers, n);
    deleteFlags(areLineMins, n);
    deleteFlags(areColumnMins, n);
}
