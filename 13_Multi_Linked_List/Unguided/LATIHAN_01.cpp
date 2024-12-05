#include <iostream>
#include <string>
using namespace std;

struct Proyek
{
    string namaProyek;
    int durasi;
    Proyek *nextProyek;
};

struct Pegawai
{
    string namaPegawai;
    string idPegawai;
    Proyek *headProyek;
    Pegawai *nextPegawai;
};

Pegawai *createPegawai(string nama, string id)
{
    Pegawai *newPegawai = new Pegawai;
    newPegawai->namaPegawai = nama;
    newPegawai->idPegawai = id;
    newPegawai->headProyek = nullptr;
    newPegawai->nextPegawai = nullptr;
    return newPegawai;
}

Proyek *createProyek(string nama, int durasi)
{
    Proyek *newProyek = new Proyek;
    newProyek->namaProyek = nama;
    newProyek->durasi = durasi;
    newProyek->nextProyek = nullptr;
    return newProyek;
}

void addPegawai(Pegawai *&headPegawai, string nama, string id)
{
    Pegawai *newPegawai = createPegawai(nama, id);
    if (!headPegawai)
    {
        headPegawai = newPegawai;
    }
    else
    {
        Pegawai *temp = headPegawai;
        while (temp->nextPegawai)
        {
            temp = temp->nextPegawai;
        }
        temp->nextPegawai = newPegawai;
    }
}

void addProyek(Pegawai *headPegawai, string idPegawai, string namaProyek, int durasi)
{
    Pegawai *temp = headPegawai;
    while (temp && temp->idPegawai != idPegawai)
    {
        temp = temp->nextPegawai;
    }
    if (temp)
    {
        Proyek *newProyek = createProyek(namaProyek, durasi);
        if (!temp->headProyek)
        {
            temp->headProyek = newProyek;
        }
        else
        {
            Proyek *tempProyek = temp->headProyek;
            while (tempProyek->nextProyek)
            {
                tempProyek = tempProyek->nextProyek;
            }
            tempProyek->nextProyek = newProyek;
        }
    }
}

void deleteProyek(Pegawai *headPegawai, string idPegawai, string namaProyek)
{
    Pegawai *temp = headPegawai;
    while (temp && temp->idPegawai != idPegawai)
    {
        temp = temp->nextPegawai;
    }
    if (temp)
    {
        Proyek *prev = nullptr;
        Proyek *curr = temp->headProyek;
        while (curr && curr->namaProyek != namaProyek)
        {
            prev = curr;
            curr = curr->nextProyek;
        }
        if (curr)
        {
            if (!prev)
            {
                temp->headProyek = curr->nextProyek;
            }
            else
            {
                prev->nextProyek = curr->nextProyek;
            }
            delete curr;
        }
    }
}

void showData(Pegawai *headPegawai)
{
    Pegawai *temp = headPegawai;
    while (temp)
    {
        cout << "\nPegawai: " << temp->namaPegawai << ", ID: " << temp->idPegawai << endl;
        Proyek *tempProyek = temp->headProyek;
        while (tempProyek)
        {
            cout << "  Proyek: " << tempProyek->namaProyek
                 << ", Durasi: " << tempProyek->durasi << " bulan" << endl;
            tempProyek = tempProyek->nextProyek;
        }
        temp = temp->nextPegawai;
    }
}

int main()
{
    Pegawai *headPegawai = nullptr;

    // instruksi 1, memasukkan data pegawai
    addPegawai(headPegawai, "Andi", "P001");
    addPegawai(headPegawai, "Budi", "P002");
    addPegawai(headPegawai, "Citra", "P003");

    // instruksi 2, menambahkan proyek ke pegawai
    addProyek(headPegawai, "P001", "Aplikasi Mobile", 12);
    addProyek(headPegawai, "P002", "Sistem Akuntansi", 8);
    addProyek(headPegawai, "P003", "E-commerce", 10);

    // instruksi 3, menambahkan proyek baru
    addProyek(headPegawai, "P001", "Analisis Data", 6);

    // instruksi 4, menghapus salah satu proyek dari salah satu pegawai
    deleteProyek(headPegawai, "P001", "Aplikasi Mobile");

    // instruksi 5, menampilkan data pegawai dan proyek
    showData(headPegawai);

    return 0;
}
