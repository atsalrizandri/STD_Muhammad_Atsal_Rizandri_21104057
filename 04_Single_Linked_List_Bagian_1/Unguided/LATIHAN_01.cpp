#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Latihan1SLL
{
private:
    Node *first;

public:
    Latihan1SLL()
    {
        first = nullptr;
    }

    // Insert Node di Depan: Fungsi untuk menambah node baru di awal linked list
    void insertAhead(int numb)
    {
        Node *newNode = new Node();
        newNode->data = numb;
        newNode->next = first;
        first = newNode;
    }

    // Insert Node di Belakang: Fungsi untuk menambah node baru di akhir linked list
    void insertBehind(int numb)
    {
        Node *newNode = new Node();
        newNode->data = numb;
        newNode->next = nullptr;

        if (first == nullptr)
        {
            first = newNode;
        }
        else
        {
            Node *temp = first;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Cetak Linked List: Fungsi untuk mencetak seluruh isi linked list
    void showList()
    {
        Node *temp = first;
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Latihan1SLL list;
    int menu = 0, numb;

    while (menu != 4)
    {
        cout << "\n--Menu Input-- \n";
        cout << "1. Tambah node di depan\n";
        cout << "2. Tambah node di belakang\n";
        cout << "3. Cetak linked list\n";
        cout << "4. Keluar\n";
        cout << "Pilih inputan menu: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "Masukkan nilai node di depan: ";
            cin >> numb;
            list.insertAhead(numb);
            break;
        case 2:
            cout << "Masukkan nilai node di belakang: ";
            cin >> numb;
            list.insertBehind(numb);
            break;
        case 3:
            list.showList();
            break;
        case 4:
            cout << "Keluar.\n";
            break;
        default:
            cout << "Pilihan anda tidak valid, silakan coba lagi.\n";
        }
    }

    return 0;
}
