#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

typedef Node *List;

// Fungsi menambahkan elemen di awal list
void insertFirst_21104057(List &L, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = L;
    newNode->prev = nullptr;

    if (L != nullptr)
    {
        L->prev = newNode;
    }

    L = newNode;
    cout << "Elemen " << value << " ditambahkan di awal list." << endl;
}

// Fungsi menambahkan elemen di akhir list
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

void printList_21104057(List L)
{
    cout << "DAFTAR ANGGOTA LIST: ";
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

int main()
{
    List L = nullptr;

    int value;

    cout << "Input elemen kesatu -> ";
    cin >> value;
    insertFirst_21104057(L, value);

    cout << "Input elemen kedua ->  ";
    cin >> value;
    insertFirst_21104057(L, value);

    cout << "Input elemen ketiga -> ";
    cin >> value;
    insertLast_21104057(L, value);

    printList_21104057(L);

    return 0;
}
