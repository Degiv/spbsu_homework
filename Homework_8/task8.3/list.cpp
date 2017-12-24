#include "list.h"
#include <iostream>

using namespace std;

bool isEmpty(List const &list)
{
    return list.size == 0;
}

bool contains(List const &list, String value)
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
        //cout << "new(" << (int)list.head << ")\n";
        list.head->value = clone(newValue);
        list.size++;
        return true;
    }

    if (contains(list, newValue))
            return false;

    list.size++;
    ListElement* newElement = new ListElement;
    //cout << "new(" << (int)newElement << ")\n";
    newElement->value = clone(newValue);
    newElement->next = list.head;
    list.head = newElement;
    return true;
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
    //cout << "delete(" << (int)tmpElement << ")\n";
    list.size--;
    return tmpValue;
}

void show(List const &list)
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
    ListElement* tmp = list.head;
    while (!isEmpty(list))
    {
        tmp = tmp->next;
        delete[] list.head->value.data;
        //cout << "delete(" << (int)list.head->value.data << ")\n";
        delete list.head;
        //cout << "delete(" << (int)list.head << ")\n";
        list.head = tmp;
        list.size--;
    }
    list.head = nullptr;
}
