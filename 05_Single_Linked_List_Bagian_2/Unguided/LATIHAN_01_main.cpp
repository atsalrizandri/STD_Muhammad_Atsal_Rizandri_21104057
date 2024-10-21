#include <iostream>
#include "LATIHAN_01_Single_List.cpp"

using namespace std;

int main()
{
    List listMahasiswa;
    int choice, nim;
    string nama;

    createList(listMahasiswa);

    while (true)
    {
        cout << "\nMenu Mahasiswa:\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Cari Mahasiswa\n";
        cout << "3. Cetak Semua Mahasiswa\n";
        cout << "4. Selesai\n";
        cout << "Pilih menu : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, nama);
            addDataStudent(listMahasiswa, nim, nama);
            break;
        case 2:
            cout << "Masukkan NIM yang ingin dicari: ";
            cin >> nim;
            {
                Mahasiswa *found = findDataStudent(listMahasiswa, nim);
                if (found != nullptr)
                {
                    cout << "Mahasiswa dengan NIM " << nim << " ditemukan, atas nama " << found->nama << endl;
                }
                else
                {
                    cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
                }
            }
            break;
        case 3:
            cout << "Daftar Mahasiswa:\n";
            printInfo(listMahasiswa);
            break;
        case 4:
            cout << "Program Selesai" << endl;
            return 0;
        default:
            cout << "Pilihan anda tidak valid, coba lagi." << endl;
        }
    }

    return 0;
}