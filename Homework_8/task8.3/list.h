#pragma once
#include "string.h"

struct ListElement
{
    String value;
    ListElement* next = nullptr;
};

struct List
{
    ListElement* head = nullptr;
    int size = 0;
};

bool isEmpty(List const &list);

bool contains(List const &list, String value);

bool add(List &list, String newValue);

String pop(List &list);

void show(List const &list);

void clear(List &list);

