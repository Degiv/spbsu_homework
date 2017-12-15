#pragma once

struct ListElement
{
    int value = 0;
    ListElement* next = nullptr;
};

struct List
{
    ListElement* head = nullptr;
};

bool isEmpty(List &list);

void add(List &list, int newValue);

void clear(List &list);

void show(List &list);
