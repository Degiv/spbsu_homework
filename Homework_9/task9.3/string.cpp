#include "string.h"
#include <iostream>
#include <fstream>

using namespace std;

bool areEqual(String const &string1, String const &string2) {
    if (string1.size != string2.size)
        return false;

    for (int i = 0; i < string1.size; ++i) {
        if (string1.data[i] != string2.data[i])
            return false;
    }
    return true;
}

void clear(String &string)
{
    delete[] string.data;
    string.size = 0;
}

String clone(String const &string)
{
    String newString;
    newString.size = string.size;
    newString.data = new char[newString.size];
    for (int i = 0; i < newString.size; i++)
    {
        newString.data[i] = string.data[i];
    }
    return newString;
}

void cont(String &string, String const &addition) {
	int newSize = string.size + addition.size;
	char *newData = new char[newSize];

	for (int i = 0; i < string.size; ++i)
		newData[i] = string.data[i];

	for (int i = string.size; i < newSize; ++i)
		newData[i] = addition.data[i - string.size];

	delete[] string.data;
	string.size = newSize;
	string.data = newData;
}

char* getCharArray(String const &string)
{
    return string.data;
}

// [first, last)
String getSubstring(String const &string, int first, int last) {
	String result;
	if (last > string.size || first >= last)
		return result;

	int newSize = last - first;
	char* subData = new char[newSize];

	for (int i = first; i < last; ++i)
		subData[i - first] = string.data[i];

	result.data = subData;
	result.size = newSize;

	return result;
}

void input(String &string, ifstream &fin)
{
    clear(string);
    const int maxSize = 1000;
    char tmp[maxSize];
    char curSymbol = 0;
    fin.get(curSymbol);
    int size = 0;

    bool isEnd = false;
    while (curSymbol != '\n' && curSymbol != ' ' && !isEnd)
    {
        tmp[size] = curSymbol;
        size++;
        isEnd = !fin.get(curSymbol);
    }

    string.data = new char [size];
    string.size = size;
    for (int i = 0; i < size; ++i)
    {
        string.data[i] = tmp[i];
    }
}

void output(String const &string)
{
    for (int i = 0; i < string.size; i++)
        std::cout << string.data[i];
}
