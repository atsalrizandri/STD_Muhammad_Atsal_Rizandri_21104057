#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

typedef Node *List;

void insertLast_21104057(List &L, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (L == nullptr)
    {
        newNode->prev = nullptr;
        L = newNode;
        cout << "Elemen " << value << " ditambahkan sebagai elemen pertama di list." << endl;
        return;
    }

    Node *temp = L;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    cout << "Elemen " << value << " ditambahkan di akhir list." << endl;
}

void printDepan_21104057(List L)
{
    cout << "Daftar elemen dari depan ke belakang: ";
    Node *temp = L;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << " < - > ";
        }
        temp = temp->next;
    }
    cout << endl;
}

void printBelakang_21104057(List L)
{
    Node *temp = L;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    cout << "Daftar elemen dari belakang ke depan: ";
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->prev != nullptr)
        {
            cout << " < - > ";
        }
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    List L = nullptr;
    int value;

    for (int a = 1; a <= 4; a++)
    {
        cout << "Input elemen ke-" << a << " : ";
        cin >> value;
        insertLast_21104057(L, value);
    }

    printDepan_21104057(L);
    printBelakang_21104057(L);

    return 0;
}
