#include "circular.h"
#include <iostream>

using namespace std;

CircularList* create()
{
    CircularList *newList = new CircularList;
    newList->pivot = new CircularListElement;
    newList->pivot->value = 0;
    newList->pivot->next = newList->pivot;
    newList->pivot->prev = newList->pivot;
    newList->current = nullptr;
    newList->size = 0;
    return newList;
}

bool isEmpty(CircularList *list)
{
    return list->size == 0;
}

void add(CircularList *list, int newValue)
{
    CircularListElement *newElement = new CircularListElement;
    newElement->value = newValue;
    newElement->prev = list->pivot->prev;
    newElement->next = list->pivot;

    if (isEmpty(list))
        list->current = newElement;

    list->pivot->prev = newElement;
    newElement->prev->next = newElement;
    list->size++;
}
bool removeCurrent(CircularList *list)
{
    if (isEmpty(list))
        return false;
    CircularListElement *tmp = list->current;

    list->current->prev->next = list->current->next;
    list->current->next->prev = list->current->prev;

    list->size--;
    if (isEmpty(list))
        list->current = nullptr;
    else
    {
        list->current = list->current->next;
        if (list->current == list->pivot)
            list->current = list->current->next;
    }
    delete tmp;
    return true;
}

bool moveCurrent(CircularList *list)
{
    if (isEmpty(list))
        return false;

    list->current = list->current->next;
    if (list->current == list->pivot)
        list->current = list->current->next;
    return true;
}
void empty(CircularList *list)
{
    while (!isEmpty(list))
    {
        removeCurrent(list);
    }
}

void showList(CircularList *list)
{
    if (isEmpty(list))
        return;
    CircularListElement *tmp = list->current;
    for (int i = 0; i < list->size; ++i)
    {
        cout << tmp->value << ' ';
        tmp = tmp->next;
        if (tmp == list->pivot)
            tmp = tmp->next;
    }
}
