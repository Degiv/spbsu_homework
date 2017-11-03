#include <iostream>

using namespace std;

int factorialRecursive(int x)
{
    if (x == 1)
        return 1;
    return x * factorialRecursive(x - 1);
}

int factorialIterative(int x)
{
    int factorial = 1;
    for (int i = 2; i <= x; ++i)
    {
        factorial *= i;
    }
    return factorial;
}

int main()
{
    int x = 0;
    cout << "Enter the number to calculate the factorial : ";
    cin >> x;
    cout << "The factorial by the recursive method : " << factorialRecursive(x) << endl;
    cout << "The factorial by the iterative method : " << factorialIterative(x);
}