#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int i = 1;
    int jum;
    cout << "masukan banyak baris: ";
    cin >> jum;
    while (i <= jum)
    {
        cout << "baris ke-" << i << endl;
        i++; // sama dengan i=i+1
    }
    getch();
    return 0;
}