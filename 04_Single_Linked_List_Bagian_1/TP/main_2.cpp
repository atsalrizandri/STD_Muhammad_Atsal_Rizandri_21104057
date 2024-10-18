#include <iostream>
#include "list.h"

int main()
{
    List L;
    createList(L);

    for (int i = 0; i < 10; i++)
    {
        int digit;
        cout << "Digit " << (i + 1) << ": ";
        cin >> digit;

        address P = allocate(digit);
        insertLast(L, P);
    }

    cout << "Isi list: ";
    printInfo(L);

    return 0;
}
