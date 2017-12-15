#pragma once

struct CircularListElement
{
    int value;
    CircularListElement *next;
    CircularListElement *prev;
};

struct CircularList
{
    CircularListElement *pivot;
    CircularListElement *current;
    int size;
};

CircularList* create();
bool isEmpty(CircularList *list);
void empty(CircularList *list);
int size(CircularList *list);
void add(CircularList *list, int newValue);
bool removeCurrent(CircularList *list);
bool moveCurrent(CircularList *list);
void showList(CircularList *list);
