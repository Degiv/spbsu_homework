#pragma once
#include <fstream>

int** create(int n);

void getGraph(int** graph, int m, std::ifstream &fin);

void clear(int** graph, int n);

void dijkstra(int** graph, int n);

