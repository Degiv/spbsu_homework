#pragma once

struct QueueElement
{
    int value = -1;
    int priority = -1;
    QueueElement* next = nullptr;
    QueueElement* previous = nullptr;
};

struct Queue
{
    QueueElement* head = nullptr;
    QueueElement* tail = nullptr;
    int size = 0;
};

bool isEmpty(Queue numbers);

void enqueue(Queue &numbers, int newValue, int priority);

int dequeue(Queue &numbers);

void clear(Queue &numbers);
