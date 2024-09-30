#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Masukan jumlah elemen array: ";
    cin >> n;

    int array[n];

    cout << "Masukan nilai tiap elemen array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Data Array : ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Nomor Genap : ";
    for (int i = 0; i < n; i++)
    {
        if (array[i] % 2 == 0)
        {
            cout << array[i] << ", ";
        }
    }
    cout << endl;

    cout << "Nomor Ganjil : ";
    for (int i = 0; i < n; i++)
    {
        if (array[i] % 2 != 0)
        {
            cout << array[i] << ", ";
        }
    }
    cout << endl;

    return 0;
}
