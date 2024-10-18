#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    List L;
    createList(L);

    // 3 digit nim terakhir : 057 dibalik 750
    address P1 = allocate(7);
    address P2 = allocate(5);
    address P3 = allocate(0);

    insertFirst(L, P1);
    insertFirst(L, P2);
    insertFirst(L, P3);

    printInfo(L);

    return 0;
}