#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cout << "Enter the number : ";
    cin >> n;

    bool *isChecked = new bool [n];
    for (int i = 0; i < n; ++i)
    {
        isChecked[i] = false;
    }

    cout << "Primes before entered number are : ";
    for (int i = 2; i < n; ++i)
    {
        if (!isChecked[i])
        {
            cout << i << ' ';
            for (int j = i; j < n; j += i)
            {
                isChecked[j] = true;
            }
        }
    }
    delete [] isChecked;
}