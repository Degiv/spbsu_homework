#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cout << "Enter the length of the sequence : ";
    cin >> n;

    char tmp = 0;
    cin.get(tmp);
    cout << "Enter the sequence : ";
    int i = 0;
    int balance = 0;
    bool isBalanced = true;
    while (i < n && isBalanced)
    {
        cin.get(tmp);
        if (tmp == '(')
            ++balance;
        else
            --balance;
        if (balance < 0)
        {
            isBalanced = false;
        }
        ++i;
    }
    if (balance != 0)
        isBalanced = false;
    if (isBalanced)
        cout << "Entered sequence is right";
    else
        cout << "Entered sequence is false";
}