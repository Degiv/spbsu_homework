#include <iostream>

using namespace std;

void showPartitions(int *parts, int remainder, int previous)
{
    if (remainder == 0)
    {
        for (int i = 1; i <= previous; ++i)
        {
            cout << parts[i];
            if (i != previous)
                cout << " + ";
        }
        cout << endl;
        return;
    }

    for (int i = parts[previous]; i <= remainder; ++i)
    {
        parts[previous + 1] = i;
        showPartitions(parts, remainder - i, previous + 1);
    }
}

int main()
{
    int n = 0;
    cout << "Enter the number : ";
    cin >> n;

    int *parts = new int[n + 1];
    parts[0] = 1;

    cout << "The entered number can be represented as :" << endl;
    showPartitions(parts, n, 0);

    delete[] parts;
}