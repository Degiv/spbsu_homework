#include "hashtable.h"

using namespace std;

int exponention(int x, int n, int mod)
{
    if (n == 0)
        return 1;

    if (n % 2 == 0)
        return exponention((x * x) % mod, n / 2, mod) % mod;

    return (x * exponention(x, n - 1, mod)) % mod;
}

int hashFunction(String const &string, int mod)
{
    const int factor = 13;
    int result = 0;
    for (int i = 0; i < string.size; ++i)
    {
        result = (result + exponention(factor, i, mod) * string.data[i]) % mod;
    }
    return result;
}

double loadFactor(HashTable const &table)
{
    return (double) table.usedCounter / table.size;
}

void add(HashTable &table, String value);

void update(HashTable &table)
{
    String tmp;
    HashTable newTable;
    delete[] newTable.table;
    newTable.size = table.size * 2 + 1;
    newTable.table = new List[newTable.size];
    //cout << "new(" << (int)newTable.table <<")\n";
    for (int i = 0; i < table.size; ++i)
    {
        while (!isEmpty(table.table[i]))
        {
            tmp = pop(table.table[i]);
            add(newTable, tmp);
            clear(tmp);
        }
    }
    delete[] table.table;
    //cout << "delete(" << (int)table.table << ")\n";
    table.table = newTable.table;
    table.size = newTable.size;
    table.usedCounter = newTable.usedCounter + 1;
}

void add(HashTable &table, String value)
{
    table.usedCounter++;
    if (loadFactor(table) > 1.0)
        update(table);

    int index = hashFunction(value, table.size);

    if (!isEmpty(table.table[index]))
        table.usedCounter--;

    if (add(table.table[index], value))
        table.elementsCounter++;
}

void clear(HashTable &table)
{
    for (int i = 0; i < table.size; ++i)
    {
        clear(table.table[i]);
    }
    table.elementsCounter = 0;
    table.usedCounter = 0;
    table.size = firstSize;
    table.table = nullptr;
}
