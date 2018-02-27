#include <iostream>
#include <fstream>
#include "queue.h"

using namespace std;

int** createGraph(int n)
{
    int** graph = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        graph[i] = new int[n];
        for (int j = 0; j < n; ++j)
            graph[i][j] = 0;
    }
    return graph;
}

void getGraph(int** graph, int n, ifstream &fin)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            fin >> graph[i][j];
    }
}

bool* createFlags(int n)
{
    bool* flags = new bool[n];
    for (int i = 0; i < n; ++i)
        flags[i] = false;
    return flags;
}

void showBFS(int** graph, int n)
{
    Queue nodes;
    pushBack(nodes, 0);
    int current = 0;
    bool* areUsed = createFlags(n);

    cout << "Nodes in BFS order: ";
    while (!isEmpty(nodes))
    {
        current = popFront(nodes);
        areUsed[current] = true;
        cout << current << ' ';

        for (int i = 0; i < n; ++i)
        {
            if (graph[current][i] == 1 && !areUsed[i])
                pushBack(nodes, i);
        }
    }

    //nodes already empty
    delete[] areUsed;
}

int main()
{
    ifstream fin("filename.txt");

    int n = 0;
    fin >> n;
    int** graph = createGraph(n);

    getGraph(graph, n, fin);
    fin.close();

    showBFS(graph, n);

    for (int i = 0; i < n; ++i)
        delete[] graph[i];
    delete[] graph;
}
