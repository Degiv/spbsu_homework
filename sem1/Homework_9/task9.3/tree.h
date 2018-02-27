#pragma once
#include <fstream>

struct Node
{
    char value = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};

void getTree(Node* node, std::ifstream &fin);

void decode(Node* root, std::ifstream &fin);

void clear(Node* root);
