#include <iostream>

using namespace std;

int fibonacciNumber(int n)
{
    if (n == 1)
        return 1;

    int current = 1;
    int previous = 0;
    for (int i = 2; i <= n; ++i)
    {
        current = current + previous;
        previous = current - previous;
    }

    return current;
}

int main()
{
    int n = 0;
    cout << "Enter the index of Fibonacci number: ";
    cin >> n;

    cout << "The Fibonacci number is: " << fibonacciNumber(n);
}
