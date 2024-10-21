#include <iostream>
#include <string>

using namespace std;

// Definisi struktur Node untuk menyimpan data buku
struct Node
{
    int idBuku;
    string judulBuku;
    string penulisBuku;
    Node *next;
    Node *prev;
};

// Definisi tipe data untuk list
struct DoubleLinkedList
{
    Node *first;
    Node *tail;
};

// Fungsi untuk membuat list kosong
void createList(DoubleLinkedList &L)
{
    L.first = nullptr;
    L.tail = nullptr;
}

// Fungsi untuk menambahkan buku di akhir linked list
void addDataBook(DoubleLinkedList &L, int idBuku, string judulBuku, string penulisBuku)
{
    Node *newNode = new Node;
    newNode->idBuku = idBuku;
    newNode->judulBuku = judulBuku;
    newNode->penulisBuku = penulisBuku;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (L.first == nullptr)
    {
        L.first = newNode;
        L.tail = newNode;
    }
    else
    {
        newNode->prev = L.tail;
        L.tail->next = newNode;
        L.tail = newNode;
    }
    cout << "Buku dengan ID " << idBuku << " berhasil ditambahkan." << endl;
}

// Fungsi untuk menampilkan semua buku dari awal ke akhir
void showBookFromFirst(DoubleLinkedList L)
{
    Node *temp = L.first;
    if (temp == nullptr)
    {
        cout << "Daftar buku kosong." << endl;
        return;
    }
    while (temp != nullptr)
    {
        cout << "ID Buku: " << temp->idBuku << ", Judul: " << temp->judulBuku << ", Penulis: " << temp->penulisBuku << endl;
        temp = temp->next;
    }
}

// Fungsi untuk menampilkan semua buku dari akhir ke awal
void showBookFromLast(DoubleLinkedList L)
{
    Node *temp = L.tail;
    if (temp == nullptr)
    {
        cout << "Daftar buku kosong." << endl;
        return;
    }
    while (temp != nullptr)
    {
        cout << "ID Buku: " << temp->idBuku << ", Judul: " << temp->judulBuku << ", Penulis: " << temp->penulisBuku << endl;
        temp = temp->prev;
    }
}

int main()
{
    DoubleLinkedList listBuku;
    int choose, idBuku;
    string judulBuku, penulisBuku;

    createList(listBuku);

    while (true)
    {
        cout << "\nPerpustakaan buku:\n";
        cout << "1. Tambah buku\n";
        cout << "2. Tampilkan buku dari awal ke akhir\n";
        cout << "3. Tampilkan buku dari akhir ke awal\n";
        cout << "4. Selesai\n";
        cout << "Anda memilih: ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            cout << "Masukkan ID Buku: ";
            cin >> idBuku;
            cout << "Masukkan Judul Buku: ";
            cin.ignore();
            getline(cin, judulBuku);
            cout << "Masukkan Penulis Buku: ";
            getline(cin, penulisBuku);
            addDataBook(listBuku, idBuku, judulBuku, penulisBuku);
            break;
        case 2:
            cout << "Daftar Buku dari awal ke akhir:\n";
            showBookFromFirst(listBuku);
            break;
        case 3:
            cout << "Daftar Buku dari akhir ke awal:\n";
            showBookFromLast(listBuku);
            break;
        case 4:
            cout << "Program selesai" << endl;
            return 0;
        default:
            cout << "Menu yang dipilih tidak valid, coba lagi." << endl;
        }
    }

    return 0;
}