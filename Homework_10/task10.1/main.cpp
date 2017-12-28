#include <iostream>
#include <fstream>
#include "matrix.h"
#include <math.h>

using namespace std;

struct index
{
    int y = 0;
    int x = 0;
};

void findNodes(int** map, int n, index &start, index &goal)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (map[i][j] == 'A')
            {
                start.x = j;
                start.y = i;
            }

            if (map[i][j] == 'B')
            {
                goal.x = j;
                goal.y = i;
            }

        }
    }
}

int h(int x1, int y1, int x2, int y2)
{
    return fabs(x1 - x2) + fabs(y1 - y2);
}

bool areCorrect(int n, int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void updateDistLocal(int** map, int** dist, bool** areUsed, int** previousHeight, int** previousWide, int n, int x, int y, int prevX, int prevY)
{
    if (areCorrect(n, x, y) && map[y][x] != '1' && (dist[y][x] == -1 || dist[y][x] > dist[prevY][prevX] + 1))
    {
        dist[y][x] = dist[prevY][prevX] + 1;
        previousHeight[y][x] = prevY;
        previousWide[y][x] = prevX;
    }
}

void updateDist(int** map, int** dist, bool** areUsed, int** previousHeight, int** previousWide, int n, index const &current)
{
    updateDistLocal(map, dist, areUsed, previousHeight, previousWide, n, current.x, current.y + 1, current.x, current.y);
    updateDistLocal(map, dist, areUsed, previousHeight, previousWide, n, current.x + 1, current.y, current.x, current.y);
    updateDistLocal(map, dist, areUsed, previousHeight, previousWide, n, current.x, current.y - 1, current.x, current.y);
    updateDistLocal(map, dist, areUsed, previousHeight, previousWide, n, current.x - 1, current.y, current.x, current.y);
}

void updateCurrentLocal(int** map, bool** areUsed, int** dist, int n, index const &goal, index &current, int &minF, int i, int j, int prevI, int prevJ)
{
    if (j < n && map[i][j] != '1' && !areUsed[i][j] && (minF == -1 || minF > dist[prevI][prevJ] + 1 + h(j, i, goal.x, goal.y)))
    {
        minF = dist[prevI][prevJ] + 1 + h(j, i, goal.x, goal.y);
        current.x = j;
        current.y = i;
    }
}

void updateCurrent(int** map, bool** areUsed, int** dist, int n, index const &goal, index &current, int &minF, int i, int j)
{
    updateCurrentLocal(map, areUsed, dist, n, goal, current, minF, i + 1, j, i, j);
    updateCurrentLocal(map, areUsed, dist, n, goal, current, minF, i - 1, j, i, j);
    updateCurrentLocal(map, areUsed, dist, n, goal, current, minF, i, j + 1, i, j);
    updateCurrentLocal(map, areUsed, dist, n, goal, current, minF, i, j - 1, i, j);
}

void aStar(int** map, int n)
{
    bool** areUsed = createFlags(n);
    int** previousHeight = createMatrix(n);
    int** previousWide = createMatrix(n);
    int** dist = createMatrix(n);
    index start;
    index goal;
    findNodes(map, n, start, goal);
    areUsed[start.y][start.x] = true;
    dist[start.y][start.x] = 0;
    updateDist(map, dist, areUsed, previousHeight, previousWide, n, start);

    index current;
    bool isFound = false;
    while(true)
    {
        int minF = -1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (areUsed[i][j])
                {
                    updateCurrent(map, areUsed, dist, n, goal, current, minF, i, j);
                }
            }
        }

        if (current.x == goal.x && current.y == goal.y)
        {
            isFound = true;
            break;
        }

        if (minF == -1)
            break;

        areUsed[current.y][current.x] = true;
        updateDist(map, dist, areUsed, previousHeight, previousWide, n, current);
    }

    if (!isFound)
        cout << "Path is not found\n";
    else
    {
        cout << "Distance from A to B is: " << dist[goal.y][goal.x] << endl;
        int tmpX = previousWide[goal.y][goal.x];
        int tmpY = previousHeight[goal.y][goal.x];
        int tmp = 0;
        while (tmpX != start.x || tmpY != start.y)
        {
            map[tmpY][tmpX] = 'X';
            tmp = tmpX;
            tmpX = previousWide[tmpY][tmpX];
            tmpY = previousHeight[tmpY][tmp];
        }
    }

    deleteMatrix(dist, n);
    deleteMatrix(previousHeight, n);
    deleteMatrix(previousWide, n);
    deleteFlags(areUsed, n);
}

int main()
{
    ifstream fin("filename.txt");
    char token = 0;
    int n = 0;
    fin >> n;
    fin.get(token);
    int** map = createMatrix(n);

    input(map, n, fin);

    aStar(map, n);

    show(map, n);

    deleteMatrix(map, n);
}
