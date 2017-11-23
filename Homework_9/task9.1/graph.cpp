#include "graph.h"
#include <iostream>

using namespace std;

int** create(int n)
{
    int** graph = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        graph[i] = new int[n];
        for (int j = 0; j < n; ++j)
            graph[i][j] = -1;
    }
    return graph;
}

void getGraph(int** graph, int m, ifstream &fin)
{
    int first = 0;
    int second = 0;
    int weight = 0;

    for (int i = 0; i < m; ++i)
    {
        fin >> first >> second >> weight;
        first--;
        second--;
        graph[first][second] = weight;
        graph[second][first] = weight;
    }
}

void clear(int** graph, int n)
{
    for (int i = 0; i < n; ++i)
    {
        delete[] graph[i];
    }
    delete[] graph;
}

void dijkstra(int** graph, int n)
{
    int* dist = new int[n];
    dist[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        dist[i] = -1;
    }

    int* ordered = new int[n];
    ordered[0] = 0;

    int* prevs = new int[n];
    prevs[0] = -1;

    int first = 0;
    int second = 0;
    for (int i = 1; i < n; ++i)
    {
        first = -1;
        for (int j = 0; j < n; ++j)
        {
            if (dist[j] != -1)
            {
                for (int k = 0; k < n; ++k)
                {
                    if (dist[k] == -1 && graph[j][k] != -1 && (first == -1 || (dist[j] + graph[j][k] < dist[first] + graph[first][second])))
                    {
                        first = j;
                        second = k;
                    }
                }
            }
        }
        ordered[i] = second;
        dist[second] = dist[first] + graph[first][second];
        prevs[second] = first;
    }

    for (int i = 0; i < n; ++i)
    {
        cout << "Distance from town 1 to town " << ordered[i] + 1 << " is: " << dist[ordered[i]] << endl;

        cout << "Through this path: ";
        int tmp = ordered[i];
        while (tmp != -1)
        {
            cout << tmp + 1 << ' ';
            tmp = prevs[tmp];
        }
        cout << endl << endl;
    }

    delete[] prevs;
    delete[] ordered;
    delete[] dist;
}
