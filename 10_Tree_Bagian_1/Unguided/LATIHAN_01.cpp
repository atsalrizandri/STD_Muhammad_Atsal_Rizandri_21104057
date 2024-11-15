#include <iostream>
#include <queue>
using namespace std;

// Program Binary Tree dengan menu dan tambahan fungsi

// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

// Inisialisasi
void init()
{
    root = NULL;
}

// Cek Node
bool isEmpty()
{
    return root == NULL;
}

// Buat Node baru
void createNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

// Tambah kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat Tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->left != NULL)
    {
        cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

// Tambah kanan
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu" << endl;
        return NULL;
    }
    if (node->right != NULL)
    {
        cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

// Lihat child dari node
void showChild(Pohon *node)
{
    if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nNode " << node->data << " memiliki:";
    if (node->left)
    {
        cout << "\n  - Child kiri: " << node->left->data;
    }
    else
    {
        cout << "\n  - Child kiri: (tidak ada)";
    }
    if (node->right)
    {
        cout << "\n  - Child kanan: " << node->right->data;
    }
    else
    {
        cout << "\n  - Child kanan: (tidak ada)";
    }
    cout << endl;
}

// Lihat descendant dari node
void showDescendants(Pohon *node)
{
    if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    queue<Pohon *> q;
    q.push(node);
    cout << "\nDescendant dari node " << node->data << " adalah:";
    bool hasDescendants = false;
    while (!q.empty())
    {
        Pohon *current = q.front();
        q.pop();
        if (current->left)
        {
            cout << " " << current->left->data;
            q.push(current->left);
            hasDescendants = true;
        }
        if (current->right)
        {
            cout << " " << current->right->data;
            q.push(current->right);
            hasDescendants = true;
        }
    }
    if (!hasDescendants)
    {
        cout << " (tidak ada descendant)";
    }
    cout << endl;
}

void menu()
{
    char pilihan = '0', data, parentData;
    Pohon *parentNode = nullptr;

    while (pilihan != '6') // Gunakan while biasa
    {
        cout << "\nSelamat datang di Menu Tree";
        cout << "\n1. Buat Root";
        cout << "\n2. Tambah Child Kiri";
        cout << "\n3. Tambah Child Kanan";
        cout << "\n4. Tampilkan Child Node";
        cout << "\n5. Tampilkan Descendant Node";
        cout << "\n6. Selesai";
        cout << "\nMenu yang dipilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case '1':
            if (isEmpty())
            {
                cout << "Masukkan data root: ";
                cin >> data;
                createNode(data);
            }
            else
            {
                cout << "\nTree sudah dibuat!" << endl;
            }
            break;

        case '2':
            cout << "Masukkan data parent: ";
            cin >> parentData;
            parentNode = root;
            cout << "Masukkan data child kiri: ";
            cin >> data;
            insertLeft(data, parentNode);
            break;

        case '3':
            cout << "Masukkan data parent: ";
            cin >> parentData;
            parentNode = root;
            cout << "Masukkan data child kanan: ";
            cin >> data;
            insertRight(data, parentNode);
            break;

        case '4':
            cout << "Masukkan data node: ";
            cin >> data;
            parentNode = root;
            showChild(parentNode);
            break;

        case '5':
            cout << "Masukkan data node: ";
            cin >> data;
            parentNode = root;
            showDescendants(parentNode);
            break;

        case '6':
            cout << "\nProgram Selesai." << endl;
            break;

        default:
            cout << "\nMenu yang dipilih tidak ada, silahkan coba lagi!" << endl;
        }
    }
}

int main()
{
    init();
    menu();
    return 0;
}
