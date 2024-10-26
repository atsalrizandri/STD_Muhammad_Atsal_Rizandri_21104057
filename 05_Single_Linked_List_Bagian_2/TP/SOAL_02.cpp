#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

typedef Node *List;

// Fungsi memasukkan elemen ke dalam list di akhir
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

// Prosedur pengurutan list menggunakan bubble sort
void bubbleSortList_21104057(List &L)
{
    if (L == nullptr)
        return;

    bool swapped;
    do
    {
        swapped = false;
        Node *current = L;

        while (current->next != nullptr)
        {
            if (current->data > current->next->data)
            {
                // Pertukaran data
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void printList_21104057(List L)
{
    Node *temp = L;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    List L = nullptr;

    for (int x = 1; x <= 5; x++)
    {
        int value;
        cout << "Masukkan nilai pada elemen " << x << ": ";
        cin >> value;
        insertLast_21104057(L, value);
    }

    cout << "List sebelum di-urut: ";
    printList_21104057(L);

    bubbleSortList_21104057(L);

    cout << "List setelah di-urut: ";
    printList_21104057(L);

    return 0;
}
