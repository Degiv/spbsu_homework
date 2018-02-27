#include <iostream>
#include "string.h"

using namespace std;

int main()
{
    String string1;
    String string2;
    cout << "Enter first string: ";
    input(string1);

    cout << "Enter second string: ";
    input(string2);

    cout << "Enter first and last index of substring: ";
    int first = 0;
    int last = 0;
    cin >> first >> last;
    cout << "Substring of first string is: ";
    String substring = getSubstring(string1, first, last);
    output(substring);

    cout << endl << "Sum of first string and second string: ";
    cont(string1, string2);
    output(string1);

    clear(string1);
    clear(string2);
}
