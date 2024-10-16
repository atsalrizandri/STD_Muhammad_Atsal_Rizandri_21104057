#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Latihan3SLL
{
private:
    Node *first;

public:
    Latihan3SLL()
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

    // Cari Node dengan Nilai Tertentu: Fungsi untuk mencari apakah sebuah nilai ada di dalam linked list
    bool searchNode(int numb)
    {
        Node *temp = first;
        while (temp != nullptr)
        {
            if (temp->data == numb)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Hitung Panjang Linked List: Fungsi untuk menghitung jumlah node yang ada di dalam linked list
    int lenghtList()
    {
        int lenght = 0;
        Node *temp = first;
        while (temp != nullptr)
        {
            lenght++;
            temp = temp->next;
        }
        return lenght;
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
    Latihan3SLL list;
    int menu = 0, numb;

    while (menu != 6)
    {
        cout << "\n--Menu Input-- \n";
        cout << "1. Tambah node di depan\n";
        cout << "2. Tambah node di belakang\n";
        cout << "3. Cari node dengan nilai tertentu\n";
        cout << "4. Hitung panjang linked list\n";
        cout << "5. Cetak linked list\n";
        cout << "6. Keluar\n";
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
            cout << "Masukkan nilai node yang ingin dicari: ";
            cin >> numb;
            if (list.searchNode(numb))
            {
                cout << "Node dengan nilai " << numb << " ditemukan.\n";
            }
            else
            {
                cout << "Node dengan nilai " << numb << " tidak ditemukan.\n";
            }
            break;
        case 4:
            cout << "Panjang linked list: " << list.lenghtList() << endl;
            break;
        case 5:
            list.showList();
            break;
        case 6:
            cout << "Keluar.\n";
            break;
        default:
            cout << "Pilihan anda tidak valid, silakan coba lagi.\n";
        }
    }

    return 0;
}
