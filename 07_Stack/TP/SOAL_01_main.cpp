#include <iostream>
#include "SOAL_01_stack.cpp"

using namespace std;

void pushString(stack &S, const string &str)
{
    for (int i = str.length() - 1; i >= 0; i--)
    {
        push(S, str[i]);
    }
}

void popAfter(stack &S, int n)
{
    for (int i = 0; i < n; i++)
    {
        pop(S);
    }
    printInfo(S);
}

int main()
{
    stack S;
    createStack(S);

    // NIM 21104057 maka 7 MOD 4 = 3
    string dataBefore = "STRUKTURDATA";
    string dataAfter = "DATA";

    // Push ke stack
    pushString(S, dataBefore);
    cout << "Isi stack awal:\n";
    printInfo(S);

    // Pop beberapa elemen untuk mendapatkan hasil akhir
    cout << "\nIsi stack sesudah pop:\n";
    popAfter(S, 8);

    return 0;
}
