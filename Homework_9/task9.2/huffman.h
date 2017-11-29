#pragma once
#include <fstream>
#include <iostream>
#include "list.h"

struct Symbol
{
    char value = 0;
    int frequency = 0;
};

int const maxSize = 50;
struct Code
{
    char code[maxSize];
    int size = 0;
};

void showTable(Symbol* table, int sizeTable);

void showTree(std::ofstream& fout, Node* headTree);

void encode(std::ofstream& fout, std::ifstream& fin, Symbol*& table, int& sizeTable, Node*& headTree);
