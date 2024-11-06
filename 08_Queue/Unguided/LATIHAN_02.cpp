#include <iostream>
using namespace std;

struct Node
{
    string namaMhs;
    string nimMhs;
    Node *next;
};

Node *front = nullptr;
Node *back = nullptr;

bool isEmpty()
{
    return front == nullptr;
}

void enqueueAntrian(string nama, string nim)
{
    Node *newNode = new Node();
    newNode->namaMhs = nama;
    newNode->nimMhs = nim;
    newNode->next = nullptr;

    if (isEmpty())
    {
        front = back = newNode;
    }
    else
    {
        back->next = newNode;
        back = newNode;
    }
    cout << "Mahasiswa \"" << nama << "\" dengan NIM " << nim << " telah ditambahkan ke dalam antrian." << endl;
}

void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        Node *temp = front;
        cout << "Mahasiswa \"" << temp->namaMhs << "\" dengan NIM " << temp->nimMhs << " telah dihapus dari antrian." << endl;
        front = front->next;
        delete temp;

        if (front == nullptr)
        {
            back = nullptr;
        }
    }
}

int countQueue()
{
    int count = 0;
    Node *temp = front;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void clearQueue()
{
    while (!isEmpty())
    {
        dequeueAntrian();
    }
    cout << "Antrian telah dikosongkan." << endl;
}

void viewQueue()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        Node *temp = front;
        int index = 1;
        cout << "Data antrian mahasiswa:" << endl;
        while (temp != nullptr)
        {
            cout << index++ << ". Nama: " << temp->namaMhs << ", NIM: " << temp->nimMhs << endl;
            temp = temp->next;
        }
    }
}

int main()
{
    int chooseMenu = 0;
    while (chooseMenu != 5)
    {
        cout << "\nSelamat datang mahasiswa, silahkan pilih menu:" << endl;
        cout << "1. Tambah data antrian" << endl;
        cout << "2. Hapus data antrian" << endl;
        cout << "3. Lihat data antrian" << endl;
        cout << "4. Kosongkan data antrian" << endl;
        cout << "5. Keluar antrian" << endl;
        cout << "Menu yang anda pilih? ";
        cin >> chooseMenu;

        if (chooseMenu == 1)
        {
            string nama, nim;

            cout << "Masukkan Nama Mahasiswa: ";
            cin >> nama;
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> nim;

            enqueueAntrian(nama, nim);
        }
        else if (chooseMenu == 2)
        {
            dequeueAntrian();
        }
        else if (chooseMenu == 3)
        {
            viewQueue();
            cout << "Jumlah antrian = " << countQueue() << endl;
        }
        else if (chooseMenu == 4)
        {
            clearQueue();
        }
        else if (chooseMenu == 5)
        {
            cout << "Program diakhiri, sampai jumpa!." << endl;
        }
        else
        {
            cout << "Tidak ada pilihan yang anda masukkan, mohon ulangi." << endl;
        }
    }

    return 0;
}
