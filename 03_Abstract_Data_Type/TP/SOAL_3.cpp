#include <iostream>
using namespace std;

int main()
{
    int x = 2;
    int *ptrA = &x;

    cout << "nilai yang ditunjuk ptrA melalui alamat variabel x: " << *ptrA << endl;

    return 0;
}