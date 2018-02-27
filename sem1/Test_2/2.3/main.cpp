#include <iostream>
#include "list.h"
#include "sort.h"

using namespace std;

int main()
{
    int n = 0;
    cout << "Enter a length of your list: ";
    cin >> n;

    int newValue = 0;
    List numbers;
    cout << "Enter your list: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> newValue;
        add(numbers, newValue);
    }

    sort(numbers);
    cout << "Your list after sorting: ";
    show(numbers);
    clear(numbers);
}
