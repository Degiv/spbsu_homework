#pragma once
#include "phonenumbers.h"

struct ListElement
{
    Person value;
    ListElement *next = nullptr;
};

struct List
{
    ListElement *head = nullptr;
    int size;
};

List* createList();

bool isEmpty(List *myList);

void pushBack(List *myList, Person newValue);

ListElement* findName(List *myList, char *phone);

ListElement* findPhone(List *myList, char* name);

void showList(ofstream &fout, List *myList);

void clearList(List *myList);
