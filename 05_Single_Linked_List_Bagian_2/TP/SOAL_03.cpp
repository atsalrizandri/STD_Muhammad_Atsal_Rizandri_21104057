#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

typedef Node *List;

// Fungsi memasukkan elemen ke dalam list secara terurut
void insertSorted_21104057(List &L, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    // Menambahkan elemen di awal jika list kosong atau elemen baru lebih kecil dari elemen pertama
    if (L == nullptr || L->data >= value)
    {
        newNode->next = L;
        L = newNode;
        cout << "Elemen " << value << " ditambahkan di awal list." << endl;
    }
    else
    {
        Node *current = L;
        Node *prev = nullptr;

        // Mencari posisi yang sesuai untuk elemen baru
        while (current != nullptr && current->data < value)
        {
            prev = current;
            current = current->next;
        }

        // Menambahkan elemen baru di antara prev dan current
        newNode->next = current;
        prev->next = newNode;
        cout << "Elemen " << value << " ditambahkan ke dalam list." << endl;
    }
}

void printList(List L)
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

    cout << "Masukkan 4 elemen pertama ke dalam list" << endl;
    for (int x = 1; x <= 4; x++)
    {
        int value;
        cout << "Masukkan nilai elemen " << x << ": ";
        cin >> value;
        insertSorted_21104057(L, value);
    }

    cout << "List sebelum penambahan elemen baru: ";
    printList(L);

    int newValue;
    cout << "Masukkan elemen tambahan yang ingin ditambahkan ke dalam list: ";
    cin >> newValue;
    insertSorted_21104057(L, newValue);

    cout << "List setelah penambahan elemen baru: ";
    printList(L);

    return 0;
}
