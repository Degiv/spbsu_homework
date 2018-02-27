#include <iostream>

using namespace std;

enum State
{
    sign, afterSign, integer, afterDot, fraction, afterE, afterESign, exponent, error
};

bool isNumber(char token)
{
    return (token >= '0' && token <= '9');
}

int main()
{
    cout << "Enter your expression: ";
    char current = 0;
    cin.get(current);
    State status = sign;

    while (current != '\n')
    {
        switch(status)
        {
        case sign:
            if (current == '+' || current == '-')
                status = afterSign;
            else if (isNumber(current))
                status = integer;
            else
                status = error;
            break;

        case afterSign:
            if (isNumber(current))
                status = integer;
            else
                status = error;
            break;

        case integer:
            if (isNumber(current))
                status = integer;
            else if (current == '.')
                status = afterDot;
            else if (current == 'E')
                status = afterE;
            else
                status = error;
            break;

        case afterDot:
            if (isNumber(current))
                status = fraction;
            else
                status = error;
            break;

        case fraction:
            if (isNumber(current))
                status = fraction;
            else if (current == 'E')
                status = afterE;
            else
                status = error;
            break;

        case afterE:
            if (current == '+' || current == '-')
                status = afterESign;
            else if (isNumber(current))
                status = exponent;
            else
                status = error;
            break;

        case afterESign:
            if (isNumber(current))
                status = exponent;
            else
                status = error;
            break;

        case exponent:
            if (isNumber(current))
                status = exponent;
            else
                status = error;
            break;
        }
        cin.get(current);
    }

    if (status == integer || status == fraction || status == exponent)
        cout << "Entered expression is real number";
    else
        cout << "Entered expression is not real number";
}
