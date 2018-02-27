#include <iostream>
#include <stdio.h>

using namespace std;

int fibonacciNumberRecursive(int n)
{
    if (n == 1 || n == 2)
        return 1;

    return fibonacciNumberRecursive(n - 1) + fibonacciNumberRecursive(n - 2);
}

int fibonacciNumberIterative(int n)
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
    cout << "Enter the index of Fibonacci number : ";
    cin >> n;

    cout << "The Fibonacci number by recursive method : " << fibonacciNumberRecursive(n) << endl;;

    cout << "The Fibonacci number by iterative method : " << fibonacciNumberIterative(n);
}