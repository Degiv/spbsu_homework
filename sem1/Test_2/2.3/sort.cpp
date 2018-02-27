#include "sort.h"
#include <iostream>

using namespace std;

void update(List &list, ListElement* element, ListElement*& parent)
{
    ListElement* tmp = list.head;
    ListElement* prev = nullptr;
    while (tmp->value <= element->value)
    {
        if (tmp == element)
        {
            parent = element;
            return;
        }

        prev = tmp;
        tmp = tmp->next;
    }
    if (prev)
        prev->next = element;

    if (tmp == list.head)
        list.head = element;

    parent->next = element->next;

    element->next = tmp;
    return;
}

void sort(List &list)
{
    if (!list.head || !list.head->next)
        return;

    ListElement* prev = list.head;
    ListElement* cur = list.head->next;
    ListElement* next = nullptr;
    while (cur)
    {
        next = cur->next;
        update(list, cur, prev);
        cur = next;
    }
}
