#include "tree.h"
#include <fstream>
#include <iostream>

using namespace std;

Node* getTreeRecursive(ifstream &fin, Node* node, char &curSymbol)
{
    node = new Node;

    fin.get(curSymbol);
    if (curSymbol == '(')
    {
        fin.get(curSymbol);
        node->value = curSymbol;
        fin.get(curSymbol);
        node->left = getTreeRecursive(fin, node->left, curSymbol);
        node->right = getTreeRecursive(fin, node->right, curSymbol);
        fin.get(curSymbol);
    }
    else
    {
        node->value = curSymbol - '0';
        fin.get(curSymbol);
    }
    return node;
}

void getTree(ifstream &fin, Tree &tree)
{
    char curSymbol = 0;
    tree.root = getTreeRecursive(fin, tree.root, curSymbol);
}

void showTreeRecursive(Node* node)
{
    if (node->left)
    {
        cout << '(' << (char)node->value << ' ';
        showTreeRecursive(node->left);
        cout << ' ';
        showTreeRecursive(node->right);
        cout << ')';
    }
    else
    {
        cout << node->value;
    }
}

void showTree(Tree &tree)
{
    showTreeRecursive(tree.root);
}

int calculateRecursive(Node* node)
{
    if (node->left)
    {
        switch(node->value)
        {
            case '+':
                return calculateRecursive(node->left) + calculateRecursive(node->right);

            case '-':
                return calculateRecursive(node->left) - calculateRecursive(node->right);

            case '*':
                return calculateRecursive(node->left) * calculateRecursive(node->right);

            case '/':
                return calculateRecursive(node->left) / calculateRecursive(node->right);
        }
    }
    else
        return node->value;
}

int calculate(Tree &tree)
{
    return calculateRecursive(tree.root);
}
