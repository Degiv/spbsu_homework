#include "avltree.h"
#include <iostream>

using namespace std;

int balanceFactor(Node* node)
{
    if (node->left)
    {
        if (node->right)
            return node->left->height - node->right->height;
        else
            return node->left->height;
    }
    else
    {
        if (node->right)
            return - node->right->height;
        else
            return 0;
    }

}

void updateHeight(Node* node)
{
    int leftHeight = 0;
    int rightHeigth = 0;

    if (node->left)
        leftHeight = node->left->height;
    if (node->right)
        rightHeigth = node->right->height;

    node->height = max(rightHeigth, leftHeight) + 1;
}

Node* rotateRight(Node* node)
{
    Node *tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    updateHeight(node);
    updateHeight(tmp);
    return tmp;
}

Node* rotateLeft(Node* node)
{
    Node *tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    updateHeight(node);
    updateHeight(tmp);
    return tmp;
}

Node* balance(Node* node)
{
    updateHeight(node);
    if (balanceFactor(node) == 2)
    {
        if (balanceFactor(node->left) < 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balanceFactor(node) == -2)
    {
        if (balanceFactor(node->right) > 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

Node* recursiveAdd(Node* node, int newValue)
{
    if (node == nullptr)
    {
        node = new Node;
        node->value = newValue;
        return node;
    }

    if (node->value == newValue)
        return node;

    if (node->value > newValue)
        node->left = recursiveAdd(node->left, newValue);
    else
        node->right = recursiveAdd(node->right, newValue);

    return balance(node);
}

void add(AVLtree &tree, int newValue)
{
    tree.root = recursiveAdd(tree.root, newValue);
}

Node* findMax(Node* node)
{
    if (node->right == nullptr)
        return node;
    else
        return findMax(node->right);
}

Node* removeMax(Node* node)
{
    if (node->right == nullptr)
        return node->left;
    else
        node->right = removeMax(node->right);
    return balance(node);
}

Node* recursiveRemove(Node* node, int value)
{
    if (node == nullptr)
        return node;

    if (node->value == value)
    {
        Node* left = node->left;
        Node* right = node->right;
        delete node;
        if (left == nullptr)
            return right;

        Node* maxNode = findMax(left);
        maxNode->right = right;
        maxNode->left = removeMax(left);
        return balance(maxNode);
    }

    if (node->value > value)
        node->left = recursiveRemove(node->left, value);
    else
        node->right = recursiveRemove(node->right, value);

    return balance(node);
}

void remove(AVLtree &tree, int value)
{
    tree.root = recursiveRemove(tree.root, value);
}

bool recursiveContains(Node *node, int value)
{
    if (!node)
        return false;

    if (node->value == value)
        return true;

    if (value < node->value)
        return recursiveContains(node->left, value);
    else
        return recursiveContains(node->right, value);
}

bool contains(AVLtree &tree, int value)
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

void showIncreasing(AVLtree &tree)
{
    if (!tree.root)
        return;
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

void showDecreasing(AVLtree &tree)
{
    if (!tree.root)
        return;
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

void show(AVLtree &tree)
{
    if (!tree.root)
        return;
    showRecursive(tree.root);
}

void recursiveClear(Node* node)
{
    if (node->left)
        recursiveClear(node->left);
    if (node->right)
        recursiveClear(node->right);
    delete node;
}

void clear(AVLtree &tree)
{
    recursiveClear(tree.root);
    tree.root = nullptr;
}
