#include "list.h"
#include <iostream>

using namespace std;

bool isEmpty(List &list)
{
    return list.head == nullptr;
}

void add(List &list, int newValue)
{
    ListElement* newElement = new ListElement;
    newElement->value = newValue;
    newElement->next = list.head;
    list.head = newElement;
}

void clear(List &list)
{
    ListElement* tmp = nullptr;
    while (!isEmpty(list))
    {
        tmp = list.head;
        list.head = list.head->next;
        delete tmp;
    }
}

void show(List &list)
{
    ListElement* tmp = list.head;
    while (tmp != nullptr)
    {
        cout << tmp->value << ' ';
        tmp = tmp->next;
    }
}
