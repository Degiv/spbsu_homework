#include "list.h"
#include <iostream>

bool isEmpty(List &list)
{
    return list.size == 0;
}

bool contains(List &list, String value)
{
    ListElement* tmp = list.head;
    for (int i = 0; i < list.size; ++i)
    {
        if (areEqual(tmp->value, value))
            return true;
        tmp = tmp->next;
    }
    return false;
}

//false => list already contains the value
bool add(List &list, String newValue)
{
    if (isEmpty(list))
    {
        list.head = new ListElement;
        list.head->value = newValue;
        list.size++;
        return true;
    }

    if (contains(list, newValue))
    {
        return false;
    }
    else
    {
        list.size++;
        ListElement* newElement = new ListElement;
        newElement->value = clone(newValue);
        newElement->next = list.head;
        list.head = newElement;
        return true;
    }
}

String pop(List &list)
{
    String result;
    if (isEmpty(list))
        return result;

    ListElement* tmpElement = list.head;
    String tmpValue = clone(tmpElement->value);
    list.head = list.head->next;
    clear(tmpElement->value);
    delete tmpElement;
    list.size--;
    return tmpValue;
}

void show(List &list)
{
    ListElement* tmp = list.head;
    for (int i = 0; i < list.size; ++i)
    {
        output(tmp->value);
        std::cout << ' ';
        tmp = tmp->next;
    }
}

void clear(List &list)
{
    while (!isEmpty(list))
    {
        pop(list);
    }
    list.head = nullptr;
}
