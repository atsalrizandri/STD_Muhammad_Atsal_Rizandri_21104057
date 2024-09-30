#include <iostream>
using namespace std;

int nilaiMaksimum(int array[], int panjang)
{
    int maksimum = array[0];
    for (int i = 1; i < panjang; i++)
    {
        if (array[i] > maksimum)
        {
            maksimum = array[i];
        }
    }
    return maksimum;
}

int nilaiMinimum(int array[], int panjang)
{
    int minimum = array[0];
    for (int i = 1; i < panjang; i++)
    {
        if (array[i] < minimum)
        {
            minimum = array[i];
        }
    }
    return minimum;
}

double nilaiRataRata(int array[], int panjang)
{
    int total = 0;
    for (int i = 0; i < panjang; i++)
    {
        total += array[i];
    }
    return static_cast<double>(total) / panjang;
}

int main()
{
    int panjang;

    cout << "Jumlah elemen array: ";
    cin >> panjang;

    int array[panjang];

    cout << "Masukan nilai dari tiap elemen array" << endl;
    for (int i = 0; i < panjang; i++)
    {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> array[i];
    }

    int menu;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Nilai maksimum\n";
        cout << "2. Nilai minimum\n";
        cout << "3. Nilai rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
        {
            int maksimum = nilaiMaksimum(array, panjang);
            cout << "Nilai maksimum: " << maksimum << endl;
            break;
        }
        case 2:
        {
            int minimum = nilaiMinimum(array, panjang);
            cout << "Nilai minimum: " << minimum << endl;
            break;
        }
        case 3:
        {
            double rata = nilaiRataRata(array, panjang);
            cout << "Nilai rata-rata: " << rata << endl;
            break;
        }
        case 4:
            cout << "Keluar" << endl;
            break;
        default:
            cout << "Menu yang dipilih tidak ada. Silahkan pilih dengan benar.\n";
        }

    } while (menu != 4);

    return 0;
}
