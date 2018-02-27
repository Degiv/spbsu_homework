#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    Queue numbers;
    int n = 0;
    cout << "Enter size of queue: ";
    cin >> n;

    cout << "Enter queue: ";
    int newValue = 0;
    int priority = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> newValue >> priority;
        enqueue(numbers, newValue, priority);
    }

    int m = 0;
    cout << "Enter times of dequeue(): ";
    cin >> m;
    if (m > n)
        m = n;

    cout << "Result is: ";
    for (int i = 0; i < m; ++i)
        cout << dequeue(numbers) << " ";

    clear(numbers);
}
