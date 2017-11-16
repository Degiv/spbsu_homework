#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cout << "Enter the length of string: ";
    cin >> n;
    char *str = new char [n];
    char tmp = 0;
    cout << "Enter the string : ";
    cin.get(tmp); //Считываем перевод строки до цикла, чтобы  он не попал в массив
    for (int i = 0; i < n; ++i)
    {
        cin.get(tmp);
        str[i] = tmp;
    }

    bool isPalindrome = true;
    int i = 0;
    while (i < (n / 2) && isPalindrome)
    {
        if (str[i] != str[n - i - 1])
        {
            isPalindrome = false;
        }
        ++i;
    }

    if (isPalindrome)
    {
        cout << "The entered string is a palindrome";
    }
    else
    {
        cout << "The entered string is not a palindrome";
    }
    delete [] str;
}