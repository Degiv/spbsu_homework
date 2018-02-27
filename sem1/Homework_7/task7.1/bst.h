#pragma once

struct Node
{
    int value = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};

struct BST
{
    Node* root = nullptr;
};

bool isEmpty(BST const &tree);

void add(BST &tree, int newValue);

void remove(BST &tree, int value);

bool contains(BST const &tree, int value);

void showIncreasing(BST const &tree);

void showDecreasing(BST const &tree);

void show(BST const &tree);

void clear(BST &tree);
