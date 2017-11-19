#pragma once

struct Node
{
    int value = 0;
    int height = 1;
    Node *left = nullptr;
    Node *right = nullptr;
};

struct AVLtree
{
    Node *root = nullptr;
};

void add(AVLtree &tree, int newValue);

void remove(AVLtree &tree, int value);

bool contains(AVLtree &tree, int value);

void showIncreasing(AVLtree &tree);

void showDecreasing(AVLtree &tree);

void show(AVLtree &tree);
