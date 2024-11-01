#include <iostream>
using namespace std;

// deklarasi variebal array untuk stack dan variabel maksimal untuk menentukan batas dan posisi dari top stack
char stackKalimat[100];
int maksimal = 100, top = 0;

// fungsi memeriksa apakah stack penuh berdasarkan top di stack dengan maksimal
bool isFull_21104057()
{
    return (top == maksimal);
}

// fungsi memeriksa apakah stack kosong berdasarkan isinya dengan nilai 0
bool isEmpty_21104057()
{
    return (top == 0);
}

// fungsi menambahkan karakter dari kalimat yang nanti diinput ke dalam stack
// terdapat pengecekan juga apakah stack sudah mencapai penuh dengan pemanggilan fungsi full
void push_21104057(char data)
{
    if (isFull_21104057())
    {
        cout << "Stack penuh" << endl;
    }
    else
    {
        stackKalimat[top] = data;
        top++;
    }
}

// fungsi menghapus karakter dari kalimat yang telah dimasukkan ke stack sebelumnya
// terdapat juga pengecekan apakah stack sudah kosong dengan pemanggilan fungsi empty
void pop_21104057()
{
    if (isEmpty_21104057())
    {
        cout << "Stack kosong" << endl;
    }
    else
    {
        top--;
    }
}

// fungsi ini bertugas untuk mendapatkan karakter paling atas atau top stack namun tanpa dihapus
// hanya mendapatkan nilainya saja
char peek_21104057()
{
    if (!isEmpty_21104057())
    {
        return stackKalimat[top - 1];
    }
    return '\0';
}

// fungsi memeriksa apakah kalimat merupakan palindrom atau bukan
bool isPalindrome_21104057(string kalimat)
{
    // memasukkan setiap karakter kalimat ke dalam stack *disini menghilangkan spasi dan diubah ke huruf kecil
    for (char c : kalimat)
    {
        if (isalpha(c))
        { // Memastikan hanya huruf yang dimasukkan
            push_21104057(tolower(c));
        }
    }

    // membandingkan karakter satu per satu dari awal kalimat dengan yang diambil dari stack
    for (char c : kalimat)
    {
        if (isalpha(c))
        {
            if (tolower(c) != peek_21104057())
            {
                return false; // fungsi mengembalikan nilai false karena tidak sama atau palindrom
            }
            pop_21104057(); // memanggil fungsi pop untuk menghapus karakter top stack setelah perbandingan dilakukan
        }
    }
    return true; // Fungsi mengembalikan nilai true apabila semua karakter cocok dan merupkan palindrom
}

int main()
{
    // deklarasi variabel untuk menampung kalimat yang diinput
    string kalimat;

    // user menginputkan kalimat dan menerima lalu disimpan ke dalam variabel kalimat bertipe data string
    cout << "Masukan Kalimat : ";
    cin >> kalimat;

    // memanggil fungsi pengecekan apakah kalimat yang diinput merupakan palindrom atau bukan
    if (isPalindrome_21104057(kalimat))
    {
        cout << "Kalimat tersebut adalah : Palindrom" << endl;
    }
    else
    {
        cout << "Kalimat tersebut adalah : Bukan Palindrom" << endl;
    }

    return 0;
}
