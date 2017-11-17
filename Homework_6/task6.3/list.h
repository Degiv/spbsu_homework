#pragma once
#include "phonenumbers.h"

struct ListElement
{
    Person value;
    ListElement *next;
};

struct List
{
    ListElement *head;
    int size;
};

List* createList();

bool isEmpty(List *myList);

void pushBack(List *myList, Person newValue);

ListElement* findName(List *myList, char *phone);

ListElement* findPhone(List *myList, char* name);

void showList(ofstream &fout, List *myList);
