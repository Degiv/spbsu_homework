#include "bst.h"
#include <iostream>

using namespace std;

bool isEmpty(BST const &tree)
{
    return tree.root;
}

Node* recursiveAdd(Node* node, int newValue)
{
    if (!node)
    {
        node = new Node;
        node->value = newValue;
        return node;
    }

    if (newValue > node->value)
    {
        node->right = recursiveAdd(node->right, newValue);
        return node;
    }

    node->left = recursiveAdd(node->left, newValue);
    return node;

}

void add(BST &tree, int newValue)
{
    tree.root = recursiveAdd(tree.root, newValue);
}

Node* findMax(Node* node)
{
    if (node->right)
        return findMax(node->right);
    else
        return node;
}

Node* removeMax(Node* node)
{
    if (node->right)
    {
        node->right = removeMax(node->right);
        return node;
    }

    return node->left;
}

Node* recursiveRemove(Node* node, int value)
{
    if (!node)
        return node;

    if (node->value == value)
    {
        Node* left = node->left;
        Node* right = node->right;
        delete node;

        if (!left)
            return right;
        if (!right)
            return left;

        Node* maxNode = findMax(left);
        maxNode->left = removeMax(left);
        maxNode->right = right;
        return maxNode;
    }

    if (value > node->value)
    {
        node->right = recursiveRemove(node->right, value);
        return node;
    }

    node->left = recursiveRemove(node->left, value);
    return node;
}

void remove(BST &tree, int value)
{
    tree.root = recursiveRemove(tree.root, value);
}

bool recursiveContains(Node* node, int value)
{
    if (!node)
        return false;

    if (value == node->value)
        return true;

    if (value > node->value)
        return recursiveContains(node->right, value);

    return recursiveContains(node->left, value);
}

bool contains(BST const &tree, int value)
{
    return recursiveContains(tree.root, value);
}

void showIncreasingRecursive(Node* node)
{
    if (node->left)
        showIncreasingRecursive(node->left);

    cout << node->value << ' ';

    if (node->right)
        showIncreasingRecursive(node->right);

}

void showIncreasing(BST const &tree)
{
    showIncreasingRecursive(tree.root);
}

void showDecreasingRecursive(Node* node)
{
    if (node->right)
        showDecreasingRecursive(node->right);

    cout << node->value << ' ';

    if (node->left)
        showDecreasingRecursive(node->left);
}

void showDecreasing(BST const &tree)
{
    showDecreasingRecursive(tree.root);
}

void showRecursive(Node* node)
{
    cout << node->value << ' ';

    if (node->left)
    {
        cout << '(';
        showRecursive(node->left);
        cout << ')' << ' ';
    }
    else
        cout << "null" << ' ';

    if (node->right)
    {
        cout << '(';
        showRecursive(node->right);
        cout << ')';
    }
    else
        cout << "null";
}

void show(BST const &tree)
{
    showRecursive(tree.root);
}

void clearRecursive(Node* node)
{
    if (node->left)
        clearRecursive(node->left);
    if (node->right)
        clearRecursive(node->right);
    delete node;
}

void clear(BST &tree)
{
    clearRecursive(tree.root);
    tree.root = nullptr;
}


