#include <iostream>
using namespace std;

// fungsi/prosedur yang menampilkan isi sebuah array integer 2D
void showArray(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
void splitPosition(int arrA[3][3], int arrB[3][3], int x, int y)
{
    int temp = arrA[x][y];
    arrA[x][y] = arrB[x][y];
    arrB[x][y] = temp;
}

// fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer
void splitValuePointer(int *ptrA, int *ptrB)
{
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
}

int main()
{
    // 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
    int arrA[3][3] = {{2, 4, 6}, {6, 4, 2}, {4, 6, 2}};
    int arrB[3][3] = {{1, 5, 7}, {7, 5, 1}, {5, 7, 1}};

    cout << "Array A sebelum tukar posisi: " << endl;
    showArray(arrA);
    cout << "Array B sebelum tukar posisi: " << endl;
    showArray(arrB);

    splitPosition(arrA, arrB, 2, 2);

    cout << "\nArray A setelah tukar posisi: " << endl;
    showArray(arrA);
    cout << "Array B setelah tukar posisi: " << endl;
    showArray(arrB);

    // Deklarasi dua pointer integer
    int a = 8, b = 16;
    int *ptrA = &a;
    int *ptrB = &b;

    cout << "\nSebelum pertukaran nilai yang ditunjuk pointer: " << endl;
    cout << "ptrA menunjuk ke nilai: " << *ptrA << endl;
    cout << "ptrB menunjuk ke nilai: " << *ptrB << endl;

    splitValuePointer(ptrA, ptrB);

    cout << "\nSetelah pertukaran nilai yang ditunjuk pointer:" << endl;
    cout << "ptrA menunjuk ke nilai: " << *ptrA << endl;
    cout << "ptrB menunjuk ke nilai: " << *ptrB << endl;

    return 0;
}
