#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

typedef Node *List;

void insertLast_21104057(List &L, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (L == nullptr)
    {
        L = newNode;
    }
    else
    {
        Node *temp = L;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void searchElement_21104057(List L, int x)
{
    Node *current = L;
    int position = 1;

    while (current != nullptr)
    {
        if (current->data == x)
        {
            cout << "Element ditemukan pada alamat: " << current << " dan pada posisi: " << position << endl;
            return;
        }
        current = current->next;
        position++;
    }

    cout << "Element " << x << " tidak ada di dalam list." << endl;
}

int main()
{
    List L = nullptr;

    for (int y = 1; y <= 6; y++)
    {
        int value;
        cout << "Masukkan nilai pada elemen " << y << ": ";
        cin >> value;
        insertLast_21104057(L, value);
    }

    int searchValue;
    cout << "Masukkan nilai yang dicari: ";
    cin >> searchValue;

    searchElement_21104057(L, searchValue);

    return 0;
}
