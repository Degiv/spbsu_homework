#pragma once

struct String
{
    char *data;
    int size = 0;
};

bool areEqual(String &string1, String &string2);

void input(String &string);

void output(String &string);

String clone(String &string);

void cont(String &string, String &addition);

String getSubstring(String &string, int first, int last);

void clear(String &string);

char *getCharArray(String &string);
