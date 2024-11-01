#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

// Fungsi pembalikan kalimat yang ditukar menggunakan stack
void reverseWords_21104057(string kalimat)
{
    stack<char> charStack;
    stringstream sentence(kalimat);
    string word;

    // menampilkan data stack array yang dibalik
    cout << "Datastack Array :" << endl;
    cout << "Data : ";

    // pemisahan kalimat menjadi kata per kata
    while (sentence >> word)
    {
        // menginput setiap karakter ke dalam stack dengan push
        for (char c : word)
        {
            charStack.push(c);
        }

        // mengeluarkan setiap karakter yang ada didalam stack
        while (!charStack.empty())
        {
            cout << charStack.top();
            charStack.pop();
        }
        cout << " "; // penambahan spasi untuk setiap kata yang dibalik
    }

    cout << endl;
}

int main()
{
    // deklarasi variabel kalimat untuk menampung kalimat yang diinput
    string kalimat;

    // menerima dan menyimpan kalimat ke dalam variabel
    cout << "Masukkan Kata: ";
    getline(cin, kalimat);

    // fungsi reverse dipanggil untuk membalikkan seluruh kata dari kalimat yang diinput user
    reverseWords_21104057(kalimat);

    return 0;
}
