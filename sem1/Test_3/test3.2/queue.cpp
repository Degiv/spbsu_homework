#include "queue.h"

bool isEmpty(Queue numbers)
{
    return numbers.size == 0;
}

void enqueue(Queue &numbers, int newValue, int priority)
{
    QueueElement* newElement = new QueueElement;
    newElement->priority = priority;
    newElement->value = newValue;
    newElement->next = numbers.head;

    while (newElement->next && (newElement->next->priority > newElement->priority))
    {
        newElement->previous = newElement->next;
        newElement->next = newElement->next->next;
    }

    if (newElement->previous)
        newElement->previous->next = newElement;
    else
        numbers.head = newElement;

    if (newElement->next)
        newElement->next->previous = newElement;
    else
        numbers.tail = newElement;

    numbers.size++;
}

int dequeue(Queue &numbers)
{
    if (isEmpty(numbers))
        return -1;
    int result = numbers.head->value;

    QueueElement* tmp = numbers.head;
    numbers.head = numbers.head->next;
    numbers.size--;
    delete tmp;
    return result;
}

void clear(Queue &numbers)
{
    while (!isEmpty(numbers))
        dequeue(numbers);
}
