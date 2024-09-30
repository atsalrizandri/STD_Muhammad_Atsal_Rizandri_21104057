#include <iostream>
using namespace std;

int main()
{
    int x, y, z;

    cout << "Masukan ukuran dimensi pertama: ";
    cin >> x;
    cout << "Masukan ukuran dimensi kedua: ";
    cin >> y;
    cout << "Masukan ukuran dimensi ketiga: ";
    cin >> z;

    int ***array = new int **[x];
    for (int i = 0; i < x; i++)
    {
        array[i] = new int *[y];
        for (int j = 0; j < y; j++)
        {
            array[i][j] = new int[z];
        }
    }

    cout << "Masukan nilai dari tiap elemen array" << endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "Element [" << i << "][" << j << "][" << k << "]: ";
                cin >> array[i][j][k];
            }
        }
    }

    cout << "\nArray tiga dimensi" << endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "Element [" << i << "][" << j << "][" << k << "] = " << array[i][j][k] << endl;
            }
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
