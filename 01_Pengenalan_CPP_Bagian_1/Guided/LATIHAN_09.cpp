#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int r = 10;
    int s;
    system("cls");
    s = 10 + ++r;
    cout << "Nilai r= " << r << endl;
    cout << "Nilai s= " << s << endl;
    getch();
    return 0;
}