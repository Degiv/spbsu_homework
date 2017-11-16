#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    cout << "Enter a and b to calculate a / b : ";
    cin >> a >> b;

    int unsignedA = a;
    int unsignedB = b;
    if (a < 0)
        unsignedA *= -1;
    if (b < 0)
        unsignedB *= -1;

    int quotient = 0;
    while (unsignedA > 0)
    {
        unsignedA -= unsignedB;
        ++quotient;
    }
    if (a < 0)
        ++quotient;
    if((a < 0 && b > 0) || (a > 0 && b < 0))
        quotient *= -1;

    cout << "Result is : " << quotient;
}