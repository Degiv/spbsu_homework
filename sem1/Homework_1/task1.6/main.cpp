#include <iostream>

using namespace std;

void inputString(char* myString, int length)
{
    char tmp = 0;
    cin.get(tmp);
    for (int i = 0; i < length; ++i)
    {
        cin.get(tmp);
        myString[i] = tmp;
    }
}
int main()
{
    int n = 0;
    cout << "Enter the length of the string 's' : ";
    cin >> n;

    int m = 0;
    cout << "Enter the length of the string 's1' : ";
    cin >> m;

    char *s = new char [n];
    cout << "Enter the string 's' : ";
    inputString(s, n);

    char *s1 = new char [m];
    cout << "Enter the string 's1' : ";
    inputString(s1, m);

    int substringCounter = 0;
    bool areEqual = true;
    int j = 0;
    for (int i = 0; i < (n - m + 1); ++i)
    {
        areEqual = true;
        j = 0;
        while (j < m && areEqual)
        {
            if (s[i + j] != s1[j])
                areEqual = false;
            ++j;
        }
        if (areEqual)
            ++substringCounter;
    }

    cout << "The string 's1' is included in the string 's' " << substringCounter <<" times";
    delete [] s;
    delete [] s1;
}