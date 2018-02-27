#pragma once
#include <fstream>

using namespace std;

struct Node
{
    int value = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};

struct Tree
{
    Node* root = nullptr;
};

void getTree(ifstream &fin, Tree &tree);

void showTree(Tree &tree);

int calculate(Tree &tree);

void clear(Tree &tree);
