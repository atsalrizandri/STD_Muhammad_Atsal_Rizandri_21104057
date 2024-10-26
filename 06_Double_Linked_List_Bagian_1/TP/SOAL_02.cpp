#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

typedef Node *List;

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

// Fungsi menghapus elemen pertama dari list
void deleteFirst_21104057(List &L)
{
    Node *temp = L;
    L = L->next;

    if (L != nullptr)
    {
        L->prev = nullptr;
    }

    delete temp;
    cout << "Elemen pertama telah dihapus." << endl;
}

// Fungsi menghapus elemen terakhir dari list
void deleteLast_21104057(List &L)
{
    if (L->next == nullptr)
    {
        delete L;
        L = nullptr;
        cout << "Elemen terakhir telah dihapus." << endl;
        return;
    }

    Node *temp = L;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
    cout << "Elemen terakhir telah dihapus." << endl;
}

void printList_21104057(List L)
{
    cout << "DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: ";
    Node *temp = L;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << " <-> ";
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
    insertLast_21104057(L, value);

    cout << "Input elemen kedua -> ";
    cin >> value;
    insertLast_21104057(L, value);

    cout << "Input elemen ketiga -> ";
    cin >> value;
    insertLast_21104057(L, value);

    deleteFirst_21104057(L);
    deleteLast_21104057(L);

    printList_21104057(L);
    return 0;
}
