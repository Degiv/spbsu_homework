#include "huffman.h"

using namespace std;

void showTable(Symbol* table, int sizeTable)
{
    for (int i = 0; i < sizeTable; ++i)
    {
        if (table[i].value == '\n')
            cout << "\\n";
        else
            cout << table[i].value;
        cout << ' ' << table[i].frequency << endl;
    }
}

void showTree(std::ofstream& fout, Node* headTree)
{
    fout << headTree->frequency << ' ';
    bool left = true;

    if (headTree->left)
    {
        fout << '(';
        showTree(fout, headTree->left);
        fout << ')';
    }
    else
        left = false;

    if (headTree->right)
    {
        fout << '(';
        showTree(fout, headTree->right);
        fout << ')';
    }
    else
    {
        if (!left)
        {
            if (headTree->value == '\n')
                fout << "'\\n'";
            else
                fout << "'" << headTree->value << "'";
        }
    }
}

Symbol* getTable(List& nodes)
{
    Symbol* table = new Symbol[nodes.size];
    ListElement* tmp = nodes.head;
    for (int i = 0; i < nodes.size; ++i)
    {
        table[i].frequency = tmp->value->frequency;
        table[i].value = tmp->value->value;
        tmp = tmp->next;
    }
    return table;
}

void getCodeTable(Code *codeTable, Symbol* symbols, int index, Node* headTree, bool& isFound)
{
    bool left = true;
    if (headTree->left)
    {
        getCodeTable(codeTable, symbols, index, headTree->left, isFound);
        if (isFound)
        {
            codeTable[index].code[codeTable[index].size] = '0';
            codeTable[index].size++;
            return;
        }
    }
    else
        left = false;

    if (headTree->right)
    {
        getCodeTable(codeTable, symbols, index, headTree->right, isFound);
        if (isFound)
        {
            codeTable[index].code[codeTable[index].size] = '1';
            codeTable[index].size++;
        }
    }
    else
    {
        if(!left && (headTree->value == symbols[index].value))
            isFound = true;
    }
}

void showCode(ofstream& fout, char token, Code* codeTable, Symbol* table, int sizeTable)
{
    for (int i = 0; i < sizeTable; ++i)
    {
        if (token == table[i].value)
        {
            for (int j = 0; j < codeTable[i].size; ++j)
                fout << codeTable[i].code[j];
            return;
        }
    }
}

void clear(Node* headTree)
{
    if (headTree->left)
        clear(headTree->left);
    if (headTree->right)
        clear(headTree->right);

    delete headTree;
}

void encode(ofstream& fout, ifstream& fin, Symbol*& table, int& sizeTable, Node*& headTree)
{
    char token = 0;
    List nodes;
    while (fin.get(token))
    {
        add(nodes, token);
    }

    sizeTable = nodes.size;
    table = getTable(nodes);

    while (nodes.size > 1)
        mergeMins(nodes);

    headTree = nodes.head->value;
    showTree(fout, headTree);
    fout << endl;

    Code* codeTable = new Code[sizeTable];
    bool isFound = false;
    for (int i = 0; i < sizeTable; ++i)
    {
        isFound = false;
        getCodeTable(codeTable, table, i, headTree, isFound);
    }

    fin.close();
    fin.open("filename.txt");
    while (fin.get(token))
    {
        showCode(fout, token, codeTable, table, sizeTable);
    }
    fout.close();

    clear(nodes);
    clear(headTree);
    delete[] codeTable;
}

