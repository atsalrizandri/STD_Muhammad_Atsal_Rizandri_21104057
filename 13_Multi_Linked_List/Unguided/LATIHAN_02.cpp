#include <iostream>
#include <string>
using namespace std;

struct Buku
{
    string judulBuku;
    string pengembalian;
    Buku *nextBuku;
};

struct Anggota
{
    string namaAnggota;
    string idAnggota;
    Buku *headBuku;
    Anggota *nextAnggota;
};

Anggota *createAnggota(string nama, string id)
{
    Anggota *newAnggota = new Anggota;
    newAnggota->namaAnggota = nama;
    newAnggota->idAnggota = id;
    newAnggota->headBuku = nullptr;
    newAnggota->nextAnggota = nullptr;
    return newAnggota;
}

Buku *createBuku(string judul, string tanggal)
{
    Buku *newBuku = new Buku;
    newBuku->judulBuku = judul;
    newBuku->pengembalian = tanggal;
    newBuku->nextBuku = nullptr;
    return newBuku;
}

void addAnggota(Anggota *&headAnggota, string nama, string id)
{
    Anggota *newAnggota = createAnggota(nama, id);
    if (!headAnggota)
    {
        headAnggota = newAnggota;
    }
    else
    {
        Anggota *temp = headAnggota;
        while (temp->nextAnggota)
        {
            temp = temp->nextAnggota;
        }
        temp->nextAnggota = newAnggota;
    }
}

void addBuku(Anggota *headAnggota, string idAnggota, string judulBuku, string tanggal)
{
    Anggota *temp = headAnggota;
    while (temp && temp->idAnggota != idAnggota)
    {
        temp = temp->nextAnggota;
    }
    if (temp)
    {
        Buku *newBuku = createBuku(judulBuku, tanggal);
        if (!temp->headBuku)
        {
            temp->headBuku = newBuku;
        }
        else
        {
            Buku *tempBuku = temp->headBuku;
            while (tempBuku->nextBuku)
            {
                tempBuku = tempBuku->nextBuku;
            }
            tempBuku->nextBuku = newBuku;
        }
    }
}

void deleteAnggota(Anggota *&headAnggota, string idAnggota)
{
    Anggota *prev = nullptr;
    Anggota *curr = headAnggota;
    while (curr && curr->idAnggota != idAnggota)
    {
        prev = curr;
        curr = curr->nextAnggota;
    }
    if (curr)
    {
        if (!prev)
        {
            headAnggota = curr->nextAnggota;
        }
        else
        {
            prev->nextAnggota = curr->nextAnggota;
        }
        Buku *tempBuku = curr->headBuku;
        while (tempBuku)
        {
            Buku *hapus = tempBuku;
            tempBuku = tempBuku->nextBuku;
            delete hapus;
        }
        delete curr;
    }
}

void showData(Anggota *headAnggota)
{
    Anggota *temp = headAnggota;
    while (temp)
    {
        cout << "Anggota: " << temp->namaAnggota << ", ID: " << temp->idAnggota << endl;
        Buku *tempBuku = temp->headBuku;
        while (tempBuku)
        {
            cout << "  Buku: " << tempBuku->judulBuku
                 << ", Pengembalian: " << tempBuku->pengembalian << endl;
            tempBuku = tempBuku->nextBuku;
        }
        temp = temp->nextAnggota;
    }
}

int main()
{
    Anggota *headAnggota = nullptr;
    int menu = 0;

    while (menu != 5)
    {
        cout << "\nSistem Manajemen Buku Perpustakaan" << endl;
        cout << "1. Tambah Anggota" << endl;
        cout << "2. Tambah Pinjam Buku" << endl;
        cout << "3. Hapus Anggota" << endl;
        cout << "4. Tampilkan Data Anggota dan Buku Pinjam" << endl;
        cout << "5. Akhiri" << endl;
        cout << "Pilih menu: ";
        cin >> menu;
        cin.ignore();

        if (menu == 1)
        {
            string nama, id;
            cout << "Masukkan Nama Anggota: ";
            getline(cin, nama);
            cout << "Masukkan ID Anggota: ";
            cin >> id;
            addAnggota(headAnggota, nama, id);
        }
        else if (menu == 2)
        {
            string id, judul, tanggal;
            cout << "Masukkan Judul Buku: ";
            getline(cin, judul);
            cout << "Masukkan ID Anggota: ";
            cin >> id;
            cout << "Masukkan Tanggal Pengembalian (dd/mm/yyyy): ";
            cin >> tanggal;
            addBuku(headAnggota, id, judul, tanggal);
        }
        else if (menu == 3)
        {
            string id;
            cout << "Masukkan ID Anggota yang akan dihapus: ";
            cin >> id;
            deleteAnggota(headAnggota, id);
        }
        else if (menu == 4)
        {
            showData(headAnggota);
        }
        else if (menu == 5)
        {
            cout << "Program berakhir, sampai jumpa!" << endl;
        }
        else
        {
            cout << "Menu yang dipilih tidak valid, silahkan coba lagi." << endl;
        }
    }

    return 0;
}