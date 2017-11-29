#include <iostream>
#include <fstream>
#include "huffman.h"

using namespace std;

int main()
{
    ifstream fin("filename.txt");
    ofstream fout("codedtext.txt");

    int sizeTable = 0;
    Symbol* table = nullptr;
    Node* headTree = nullptr;
    encode(fout, fin, table, sizeTable, headTree);
    cout << "Frequency table: " << endl;
    showTable(table, sizeTable);
    delete[] table;
}
