#pragma once
#include <iostream>
#include <fstream>

int** createMatrix(int n);

void deleteMatrix(int** matrix, int n);

void input(int** map, int n, std::ifstream &fin);

void show(int** map, int n);

bool** createFlags(int n);

void deleteFlags(bool** flags, int n);
