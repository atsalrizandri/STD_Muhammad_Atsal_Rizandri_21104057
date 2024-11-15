#include <iostream>
using namespace std;

// Deklarasi Pohon
struct Pohon
{
    int data;
    Pohon *left, *right;
};

// Fungsi untuk membuat node baru
Pohon *createNode(int data)
{
    return new Pohon{data, NULL, NULL};
}

// Fungsi rekursif untuk menghitung jumlah simpul daun
int cari_simpul_daun(Pohon *node)
{
    // Jika node kosong, kembalikan 0
    if (node == NULL)
        return 0;

    // Jika node adalah simpul daun, kembalikan 1
    if (node->left == NULL && node->right == NULL)
        return 1;

    // Hitung simpul daun di subtree kiri dan kanan
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

void test_cari_simpul_daun()
{
    Pohon *root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);
    root->right->left->left = createNode(55);

    int jumlah_simpul_daun = cari_simpul_daun(root);
    cout << "Jumlah simpul daun: " << jumlah_simpul_daun << endl;
}

int main()
{
    test_cari_simpul_daun();
    return 0;
}
