#include <iostream>
#include "avltree.h"

using namespace std;

int main()
{
    AVLtree tree;
    int way = 1;
    int value = 0;

    while (way != 0)
    {
        cout << "0. Exit" << endl;
        cout << "1. Add value" << endl;
        cout << "2. Remove value" << endl;
        cout << "3. Check for value" << endl;
        cout << "4. Show tree with increasing order" << endl;
        cout << "5. Show tree with decreasing order" << endl;
        cout << "6. Show tree in special form" << endl;
        cout << "Enter a number: ";
        cin >> way;

        switch(way)
        {
            case 1:
                cout << "Enter a new value: ";
                cin >> value;
                add(tree, value);
                break;

            case 2:
                cout << "Enter value for remove: ";
                cin >> value;
                remove(tree, value);
                break;

            case 3:
                cout << "Enter a value for check: ";
                cin >> value;

                if (contains(tree, value))
                    cout << "Value is found" << endl;
                else
                    cout << "Value is not found" << endl;
                break;

            case 4:
                showIncreasing(tree);
                cout << endl;
                break;

            case 5:
                showDecreasing(tree);
                cout << endl;
                break;

            case 6:
                show(tree);
                cout << endl;
                break;
        }
        cout << endl;
    }
}
