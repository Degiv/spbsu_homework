#include <iostream>
#include <fstream>
#include "graph.h"

using namespace std;

int main()
{
    ifstream fin("filename.txt");
    int n = 0;
    int m = 0;
    fin >> n >> m;
    int** graph = create(n);
    getGraph(graph, m, fin);
    dijkstra(graph, n);
    clear(graph, n);
}
