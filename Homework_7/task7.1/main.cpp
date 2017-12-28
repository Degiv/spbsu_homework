#include <iostream>
#include "bst.h"

using namespace std;

enum Command
{
    exit, addValue, removeValue, containsValue, showInc, showDec, showSpec
};

Command setCommand(int tmp)
{
    return static_cast<Command>(tmp);
}

int main()
{
    BST tree;

    int tmp = 1;
    Command way = setCommand(tmp);
    int value = 0;
    while (tmp != 0)
    {
        cout << "0. Exit" << endl;
        cout << "1. Add value" << endl;
        cout << "2. Remove value" << endl;
        cout << "3. Check for value" << endl;
        cout << "4. Show tree with increasing order" << endl;
        cout << "5. Show tree with decreasing order" << endl;
        cout << "6. Show tree in special form" << endl;
        cout << "Enter a number: ";
        cin >> tmp;
        way = setCommand(tmp);
        switch(way)
        {
            case addValue:
                cout << "Enter a new value: ";
                cin >> value;
                add(tree, value);
                break;

            case removeValue:
                cout << "Enter value for remove: ";
                cin >> value;
                remove(tree, value);
                break;

            case containsValue:
                cout << "Enter a value for check: ";
                cin >> value;
                if (contains(tree, value))
                    cout << "Value is found";
                else
                    cout << "Value is not found";
                break;

            case showInc:
                cout << "Tree in increasing order: ";
                showIncreasing(tree);
                break;

            case showDec:
                cout << "Tree in decreasing order: ";
                showDecreasing(tree);
                break;

            case showSpec:
                show(tree);
        }
        cout << endl;
    }
    clear(tree);
}
