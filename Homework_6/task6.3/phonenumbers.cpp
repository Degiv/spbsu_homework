#include "phonenumbers.h"
#include <fstream>
#include <iostream>

using namespace std;

Person* createPerson()
{
    Person *newPerson = new Person;
    newPerson->name[0] = '\n';
    newPerson->phone[0] = '\n';
    return newPerson;
}

bool areEqual(char *str1, char *str2)
{
    int i = 0;
    while ((str1[i] != '\n') || (str2[i] != '\n'))
    {
        if (str1[i] != str2[i])
            return false;
        ++i;
    }
    return true;
}

void input(ifstream &fin, char *str)
{
    char curSymbol = 0;
    fin.get(curSymbol);
    int i = 0;
    while (curSymbol != '\n' && curSymbol != ' ')
    {
        str[i] = curSymbol;
        fin.get(curSymbol);
        ++i;
    }
    str[i] = '\n';
}

void input(char *str)
{
    char curSymbol = 0;
    cin.get(curSymbol);
    int i = 0;
    while (curSymbol != '\n' && curSymbol != ' ')
    {
        str[i] = curSymbol;
        cin.get(curSymbol);
        ++i;
    }
    str[i] = '\n';
}

void show(char *str)
{
    for (int i = 0; str[i] != '\n'; ++i)
    {
        cout << str[i];
    }
}

void show(ofstream &fout, char *str)
{
    for (int i = 0; str[i] != '\n'; ++i)
    {
        fout << str[i];
    }
}
