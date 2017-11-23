#pragma once
#include "list.h"

const int firstSize = 5;

struct HashTable
{
    List* table = new List[firstSize];
    int size = firstSize;
    int elementsCounter = 0;
    int usedCounter = 0;
};

double loadFactor(HashTable &table);

void add(HashTable &table, String value);

void clear(HashTable &table);

