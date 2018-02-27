#pragma once

struct Node
{
    Node* left = nullptr;
    Node* right = nullptr;
    int frequency = 1;
    char value = 0;
};

struct ListElement
{
    Node* value = nullptr;
    ListElement* next = nullptr;
    ListElement* prev = nullptr;
};

struct List
{
    ListElement* head = nullptr;
    int size = 0;
};

bool isEmpty(List& list);

void add(List& list, char value);

void mergeMins(List& list);

void clear(List& list);
