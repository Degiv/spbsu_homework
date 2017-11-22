#include <iostream>
#include "hashtable.h"
#include "string.h"
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("filename.txt");
    char token = 0;
    int wordsCounter = 0;
    while(fin.get(token))
    {
        if (token == '\n' || token == ' ')
            wordsCounter++;
    }
    fin.close();

    fin.open("filename.txt");
    HashTable table;
    String curWord;
    for (int i = 0; i < wordsCounter; ++i)
    {
        input(curWord, fin);
        add(table, curWord);
    }
    fin.close();

    cout << "Load factor is: " << loadFactor(table) << endl;
    cout << "Average length of list: " << loadFactor(table) << endl;
    int emptyCounter = 0;
    int indexMax = 0;
    for (int i = 0; i < table.size; ++i)
    {
        if (table.table[i].size > table.table[indexMax].size)
            indexMax = table.table[i].size;

        if (table.table[i].size == 0)
            emptyCounter++;
    }
    cout << "Maximal length of list: " << table.table[indexMax].size << endl;
    cout << "List with maximal length is: ";
    show(table.table[indexMax]);
    cout << endl << "Number of elements in hash-table is: " << table.elementsCounter << endl;
    cout << "Number of empty cells of hash-table is: " << emptyCounter;
}
