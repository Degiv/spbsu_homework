#include <iostream>
#include <fstream>
#include "tree.h"

using namespace std;

int main()
{
    ifstream fin("expression.txt");
    Tree tree;
    getTree(fin, tree);
    cout << "Expression is: ";
    showTree(tree);
    cout << endl << "Result is: " << calculate(tree);
    fin.close();
}


