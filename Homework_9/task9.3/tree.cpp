#include "tree.h"
#include <iostream>
#include "string.h"

using namespace std;

void getTree(Node* node, ifstream &fin)
{
    char token = 0;
    fin.get(token);
    while (token != '(' && token != '\'')
        fin.get(token);

    if (token == '\'')
    {
        fin.get(token);
        if (token == '\\')
        {
            fin.get(token);
            if (token == 'n')
            {
                node->value = '\n';
                fin.get(token);
            }
            else
                node->value = '\\';
        }
        else
        {
            node->value = token;
            fin.get(token);
        }
        return;
    }

    node->left = new Node;
    getTree(node->left, fin);
    fin.get(token);

    fin.get(token);
    node->right = new Node;
    getTree(node->right, fin);
    fin.get(token);
}

void decode(Node* root, std::ifstream &fin)
{
    String code;
    input(code, fin);

    const int maxSize = 1000;
    char text[maxSize];
    int textSize = 0;

    Node* tmp = nullptr;
    int i = code.size - 1;
    while (i >= 0)
    {
        tmp = root;
        while(tmp->left && i >= 0)
        {
            if (code.data[i] == '0')
                tmp = tmp->left;
            if (code.data[i]== '1')
                tmp = tmp->right;
            i--;
        }
        text[textSize] = tmp->value;
        textSize++;
    }

    for (int i = textSize - 1; i >= 0; --i)
    {
        cout << text[i];
    }
    clear(code);
}

void clear(Node* root)
{
    if (root->left)
    {
        clear(root->left);
        clear(root->right);
    }

    delete root;
}
