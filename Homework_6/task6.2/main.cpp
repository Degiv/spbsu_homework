#include <iostream>
#include "circular.h"

using namespace std;

int main()
{
    int n = 0;
    int m = 0;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

    CircularList *warriors = create();
    for (int i = 1; i <= n; ++i)
        add(warriors, i);

    while(warriors->size > 1)
    {
        for (int i = 0; i < m - 1; ++i)
            moveCurrent(warriors);

        removeCurrent(warriors);
    }

    cout << endl << "Warrior with number " << warriors->current->value << " will survive";

    removeCurrent(warriors);
    delete warriors->pivot;
    delete warriors;
}
