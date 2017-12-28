#include <iostream>
#include <fstream>
#include "tree.h"

using namespace std;

int main()
{
    ifstream fin("codedtext.txt");
    if (!fin)
    {
        cout << "File " << '"' << "codedtext.txt" << '"' << " is not found";
        return 0;
    }

    Node* root = new Node;
    getTree(root, fin);

    char token = 0;
    fin.get(token);
    decode(root, fin);
    clear(root);
}
