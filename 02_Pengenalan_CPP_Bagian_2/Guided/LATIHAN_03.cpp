#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int maks3(int a, int b, int c);
// mendeklarasikan prototype fungsi

int main()
{
    system("cls");
    int x, y, z;
    cout << "Masukan nilai bilangan ke-1 = ";
    cin >> x;

    cout << "Masukan nilai bilangan ke-2 = ";
    cin >> y;

    cout << "Masukan nilai bilangan ke-3 = ";
    cin >> z;

    cout << "Nilai maksimumnya adalah = " << maks3(x, y, z);
    getche();
    return 0;
}

/* badan fungsi */
int maks3(int a, int b, int c)
{
    /* deklarasi variabel lokal dalam fungsi */
    int temp_max = a;
    if (b > temp_max)
        temp_max = b;
    if (c > temp_max)
        temp_max = c;
    return (temp_max);
}