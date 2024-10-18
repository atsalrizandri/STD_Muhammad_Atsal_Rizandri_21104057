#include <iostream>
#include "list.h"
using namespace std;

void createList(List &L)
{
    // this procedure will initialize the list L
    first(L) = NULL;
}

address allocate(infotype x)
{
    address p = new elmlist;
    info(p) = x;
    next(p) = NULL;

    return p;
}

void insertFirst(List &L, address P)
{
    next(P) = first(L);
    first(L) = P;
}

void printInfo(List L)
{
    address p = first(L);
    while (p != NULL)
    {
        cout << info(p) << ", ";
        p = next(p);
    }
    cout << endl;
}

void insertLast(List &L, address P)
{
    if (L.first == NULL)
    {
        L.first = P;
    }
    else
    {
        address Q = L.first;
        while (Q->next != NULL)
        {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(List &L, address P, address Q)
{
    P->next = Q->next;
    Q->next = P;
}

void deleteLast(List &L)
{
    if (L.first == NULL)
    {
        cout << "List kosong, tidak ada yang dihapus." << endl;
    }
    else if (L.first->next == NULL)
    {
        delete L.first;
        L.first = NULL;
    }
    else
    {
        address Q = L.first;
        while (Q->next->next != NULL)
        {
            Q = Q->next;
        }
        delete Q->next;
        Q->next = NULL;
    }
}

void deleteAfter(List &L, address P)
{
    if (P != NULL && P->next != NULL)
    {
        address Q = P->next;
        P->next = Q->next;
        delete Q;
    }
}

address searchInfo(List L, int x)
{
    address P = L.first;
    while (P != NULL)
    {
        if (P->info == x)
        {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
