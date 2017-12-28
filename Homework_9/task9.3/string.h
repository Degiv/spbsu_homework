#pragma once
#include <fstream>

struct String
{
    char *data = nullptr;
    int size = 0;
};

bool areEqual(String const &string1, String const &string2);

void input(String &string, std::ifstream &fin);

void output(String const &string);

String clone(String const &string);

void cont(String &string, String const &addition);

String getSubstring(String const &string, int first, int last);

void clear(String &string);

char *getCharArray(String const &string);
