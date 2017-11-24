#include <fstream>
#include <iostream>
#include "list.h"

using namespace std;

List* createList()
{
    List* newList = new List;
    newList->head = nullptr;
    newList->size = 0;
    return newList;
}

bool isEmpty(List *myList)
{
    return myList->size == 0;
}

void pushBack(List *myList, Person newValue)
{
    if (isEmpty(myList))
    {
        myList->head = new ListElement;
        myList->head->value = newValue;
        myList->size++;
        return;
    }
    ListElement *newElement = new ListElement;
    newElement->value = newValue;
    newElement->next = myList->head;
    myList->head = newElement;
    myList->size++;
}

ListElement* findPhone(List *myList, char* phone)
{
    ListElement *tmp = myList->head;
    while (tmp != nullptr && !areEqual(tmp->value.phone, phone))
        tmp = tmp->next;
    return tmp;
}

ListElement* findName(List *myList, char* name)
{
    ListElement *tmp = myList->head;
    while (tmp != nullptr && !areEqual(tmp->value.name, name))
        tmp = tmp->next;
    return tmp;
}

void showList(ofstream &fout, List *myList)
{
    ListElement *tmp = myList->head;
    fout << myList->size << endl;
    for (int i = 0; i < myList->size; ++i)
    {
        show(fout, tmp->value.phone);
        fout << ' ';
        show(fout, tmp->value.name);
        fout << endl;
        tmp = tmp->next;
    }
    fout << "end";
}
