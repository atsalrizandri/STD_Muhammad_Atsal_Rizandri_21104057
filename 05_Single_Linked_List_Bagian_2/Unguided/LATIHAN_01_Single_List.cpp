#include <iostream>
#include <string>
#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

using namespace std;

// Definisi tipe data elemen dan pointer ke elemen
struct Mahasiswa
{
    int nim;
    string nama;
    Mahasiswa *next;
};

// Definisi tipe data untuk list
struct List
{
    Mahasiswa *head;
};

// Fungsi untuk membuat list kosong
void createList(List &L)
{
    L.head = nullptr;
}

// Fungsi untuk menambahkan data mahasiswa ke dalam linked list
void addDataStudent(List &L, int nim, string nama)
{
    Mahasiswa *newNode = new Mahasiswa;
    newNode->nim = nim;
    newNode->nama = nama;
    newNode->next = nullptr;

    if (L.head == nullptr)
    {
        L.head = newNode;
    }
    else
    {
        Mahasiswa *temp = L.head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Mahasiswa dengan NIM " << nim << " berhasil ditambahkan." << endl;
}

// Fungsi untuk mencari mahasiswa berdasarkan NIM
Mahasiswa *findDataStudent(List L, int nim)
{
    Mahasiswa *temp = L.head;
    while (temp != nullptr)
    {
        if (temp->nim == nim)
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// Fungsi untuk mencetak semua elemen di list
void printInfo(List L)
{
    Mahasiswa *temp = L.head;
    while (temp != nullptr)
    {
        cout << "NIM: " << temp->nim << ", Nama: " << temp->nama << endl;
        temp = temp->next;
    }
}

#endif