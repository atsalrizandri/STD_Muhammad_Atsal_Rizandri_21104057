#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Latihan2SLL
{
private:
    Node *first;

public:
    Latihan2SLL()
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

    // Delete Node dengan Nilai Tertentu: Fungsi untuk menghapus node yang memiliki nilai tertentu
    void deleteNode(int numb)
    {
        // pencarian node
        Node *temp = first;
        while (temp->next != nullptr && temp->next->data != numb)
        {
            temp = temp->next;
        }

        // node ditemukan
        if (temp->next != nullptr)
        {
            Node *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }

        // apabila node yang pertama dihapus
        if (first->data == numb)
        {
            Node *temp = first;
            first = first->next;
            delete temp;
            return;
        }
    }

    // Cetak Linked List: Setelah penghapusan, cetak kembali isi linked list
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
    Latihan2SLL list;
    int menu = 0, numb;

    while (menu != 5)
    {
        cout << "\nMenu Input: \n";
        cout << "1. Tambah node di depan\n";
        cout << "2. Tambah node di belakang\n";
        cout << "3. Hapus node dengan nilai tertentu\n";
        cout << "4. Cetak linked list\n";
        cout << "5. Keluar\n";
        cout << "Pilih sesuai urutan: ";
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
            cout << "Masukkan nilai node yang ingin dihapus: ";
            cin >> numb;
            list.deleteNode(numb);
            break;
        case 4:
            list.showList();
            break;
        case 5:
            cout << "Keluar.\n";
            break;
        default:
            cout << "Pilihan anda tidak valid, silakan coba lagi.\n";
        }
    }

    return 0;
}
