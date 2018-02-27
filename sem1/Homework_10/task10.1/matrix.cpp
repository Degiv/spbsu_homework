#include "matrix.h"

using namespace std;

int** createMatrix(int n)
{
    int** result = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        result[i] = new int[n];
        for (int j = 0; j < n; ++j)
            result[i][j] = -1;
    }
    return result;
}

void deleteMatrix(int** matrix, int n)
{
    for (int i = 0; i < n; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void input(int** map, int n, ifstream &fin)
{
    char token = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            fin.get(token);
            map[i][j] = token;
        }
        fin.get(token);
    }
}

void show(int** map, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << (char)map[i][j] << ' ';
        cout << endl;
    }
}


bool** createFlags(int n)
{
    bool** result = new bool*[n];
    for (int i = 0; i < n; ++i)
    {
        result[i] = new bool[n];
        for (int j = 0; j < n; ++j)
            result[i][j] = false;
    }
    return result;
}

void deleteFlags(bool** matrix, int n)
{
    for (int i = 0; i < n; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
