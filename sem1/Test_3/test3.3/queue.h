#pragma once

struct QueueElement
{
    int value;
    QueueElement *next = nullptr;
};

struct Queue
{
    QueueElement *head = nullptr;
    QueueElement *back = nullptr;
    int size = 0;
};

bool isEmpty(Queue &symbols);

void empty(Queue &symbols);

void pushBack(Queue &symbols, int newValue);

int front(Queue &symbols);

int popFront(Queue &symbols);

int size(Queue &symbols);
