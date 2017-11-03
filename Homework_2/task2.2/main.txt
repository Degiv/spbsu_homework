#include <iostream>

using namespace std;

int exponentiation(int a, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return exponentiation(a * a, n / 2);
    return a * exponentiation(a, n - 1);
}

int main()
{
    int a = 0;
    int n = 0;
    cout << "Enter 'a' and 'n' to calculate a^n : ";
    cin >> a >> n;
    cout << "Result is : " << exponentiation(a, n);
}