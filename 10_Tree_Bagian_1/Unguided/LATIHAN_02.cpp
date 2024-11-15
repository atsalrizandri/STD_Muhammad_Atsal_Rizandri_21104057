#include <iostream>
#include <climits>
using namespace std;

// Deklarasi Pohon
struct Pohon
{
    int data;
    Pohon *left, *right;
};

Pohon *root = NULL;

// Fungsi untuk membuat node baru
Pohon *createNode(int data)
{
    return new Pohon{data, NULL, NULL};
}

// Fungsi untuk memeriksa apakah pohon valid sebagai BST
bool is_valid_bst(Pohon *node, int min_val, int max_val)
{
    // Jika node kosong, maka valid
    if (node == NULL)
        return true;

    // Memeriksa data node berada dalam rentang yang valid
    if (node->data <= min_val || node->data >= max_val)
        return false;

    // Memeriksa subtree kiri dan kanan
    return is_valid_bst(node->left, min_val, node->data) &&
           is_valid_bst(node->right, node->data, max_val);
}

void test_is_valid_bst()
{
    Pohon *valid_bst = createNode(25);
    valid_bst->left = createNode(18);
    valid_bst->right = createNode(30);
    valid_bst->left->left = createNode(10);
    valid_bst->left->right = createNode(20);
    valid_bst->right->left = createNode(28);
    valid_bst->right->right = createNode(35);

    Pohon *invalid_bst = createNode(25);
    invalid_bst->left = createNode(18);
    invalid_bst->right = createNode(30);
    invalid_bst->left->left = createNode(10);
    invalid_bst->left->right = createNode(28);
    invalid_bst->right->right = createNode(35);

    cout << "Uji Valid BST:" << endl;
    cout << (is_valid_bst(valid_bst, INT_MIN, INT_MAX) ? "Valid BST" : "Invalid BST") << endl;

    cout << "Uji Invalid BST:" << endl;
    cout << (is_valid_bst(invalid_bst, INT_MIN, INT_MAX) ? "Valid BST" : "Invalid BST") << endl;
}

int main()
{
    test_is_valid_bst();
    return 0;
}
