#include "list.h"

void add(List& list, char value)
{
    ListElement* tmp = list.head;
    while (tmp != nullptr)
    {
        if (tmp->value->value == value)
        {
            tmp->value->frequency++;
            return;
        }
        tmp = tmp->next;
    }

    Node* newNode = new Node;
    ListElement* newElement = new ListElement;
    newNode->value = value;
    newElement->value = newNode;
    newElement->next = list.head;
    if (list.head)
        list.head->prev = newElement;
    list.size++;
    list.head = newElement;
}

bool isEmpty(List& list)
{
    return list.size == 0;
}

void removeNode(List& list, ListElement* element)
{
    if (element->prev)
        element->prev->next = element->next;

    if (element->next)
        element->next->prev = element->prev;

    if (list.head == element)
        list.head = list.head->next;

    delete element;
    list.size--;
}

void addNode(List& list, Node* newNode)
{
    ListElement* newElement = new ListElement;
    newElement->value = newNode;
    newElement->next = list.head;
    if (list.head)
        list.head->prev = newElement;
    list.head = newElement;
    list.size++;
}

void mergeMins(List& list)
{
    ListElement* min1 = list.head;
    ListElement* min2 = nullptr;

    ListElement* tmp = list.head->next;
    while (tmp != nullptr)
    {
        if (tmp->value->frequency < min1->value->frequency)
        {
            min2 = min1;
            min1 = tmp;
        }
        else if (!min2 || (tmp->value->frequency < min2->value->frequency))
        {
            min2 = tmp;
        }
        tmp = tmp->next;
    }

    Node* newNode = new Node;
    newNode->frequency = min1->value->frequency + min2->value->frequency;
    newNode->left = min1->value;
    newNode->right = min2->value;

    removeNode(list, min1);
    removeNode(list, min2);
    addNode(list, newNode);
}

void clear(List& list)
{
    ListElement* tmp = nullptr;
    while (!isEmpty(list))
    {
        tmp = list.head;
        list.head = list.head->next;
        delete tmp;
        list.size--;
    }
}
