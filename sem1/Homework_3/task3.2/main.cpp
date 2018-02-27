#include <iostream>
#include "chararray.h"

using namespace std;

int main()
{
    int n = 0;
    cout << "Enter the length of string : ";
    cin >> n;

    char *mainStr = new char[n];
    char tmp = 0;
    cout << "Enter the string : ";
    cin.get(tmp);
    inputString(mainStr, n);


    int m = 0;
    cout << "Enter the length of the substring : ";
    cin >> m;

    char *subStr = new char[m];
    cout << "Enter the substring : ";
    cin.get(tmp);
    inputString(subStr, m);

    bool isFound = findSymbols(mainStr, n, subStr, m);

    if (isFound)
    {
        cout << "By rearranging the elements of a string, you can get a substring";
    }
    else
    {
        cout << "By rearranging the elements of a string, you can not get a substring";
    }

    delete[] mainStr;
}
