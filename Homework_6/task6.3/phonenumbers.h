#pragma once
#include <fstream>

using namespace std;

const int maxSize = 50;

struct Person
{
    char name[maxSize];
    char phone[maxSize];
};

Person* createPerson();
bool areEqual(char *str1, char *str2);
void input(ifstream &fin, char *str);
void input(char *str);
void show(char *str);
void show(ofstream &fout, char *str);
