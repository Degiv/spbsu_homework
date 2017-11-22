#include "hashtable.h"

int exponention(int x, int n, int mod)
{
    if (n == 0)
        return 1;

    if (n % 2 == 0)
        return exponention((x * x) % mod, n / 2, mod) % mod;

    return (x * exponention(x, n - 1, mod)) % mod;
}

int hashFunction(String &string, int mod)
{
    const int factor = 13;
    int result = 0;
    for (int i = 0; i < string.size; ++i)
    {
        result = (result + exponention(factor, i, mod) * string.data[i]) % mod;
    }
    return result;
}

double loadFactor(HashTable &table)
{
    return (double)table.elementsCounter / (double)table.size;
}

void add(HashTable &table, String value);

void update(HashTable &table)
{
    HashTable newTable;
    newTable.size = table.size * 2 + 1;
    newTable.table = new List[newTable.size];
    for (int i = 0; i < table.size; ++i)
    {
        while (!isEmpty(table.table[i]))
        {
            add(newTable, pop(table.table[i]));
        }
    }
    table.table = newTable.table;
    table.size = newTable.size;
}

void add(HashTable &table, String value)
{
    table.elementsCounter++;
    if (loadFactor(table) > 1.0)
        update(table);

    int index = hashFunction(value, table.size);
    if (!add(table.table[index], value))
        table.elementsCounter--;
}
