#include "queue.h"

using namespace std;

bool isEmpty(Queue &numbers)
{
    return numbers.size == 0;
}

void empty(Queue &numbers)
{
    QueueElement *tmp;
    while (!isEmpty(numbers))
    {
        tmp = numbers.head;
        numbers.head = numbers.head->next;
        delete tmp;

        numbers.size--;
    }
    numbers.back = nullptr;
}

void pushBack(Queue &numbers, int newValue)
{
    QueueElement *newElement = new QueueElement;
    newElement->value = newValue;
    newElement->next = nullptr;

    if (isEmpty(numbers))
        numbers.head = newElement;
    else
        numbers.back->next = newElement;

    numbers.back = newElement;
    numbers.size++;
}

int front(Queue &numbers)
{
    if (isEmpty(numbers))
        return -1;

    return numbers.head->value;
}

int popFront(Queue &numbers)
{
    int answer = numbers.head->value;
    QueueElement *tmp = numbers.head;
    numbers.head = numbers.head->next;
    delete tmp;
    numbers.size--;
    return answer;
}

int size(Queue &numbers)
{
    return numbers.size;
}
