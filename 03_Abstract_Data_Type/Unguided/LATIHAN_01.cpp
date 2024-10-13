#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float totalNilaiAkhir(float uts, float uas, float tugas)
{
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main()
{
    const int maxMahasiswa = 10;
    Mahasiswa mahasiswa[maxMahasiswa];
    int jumlahMahasiswa = 0;

    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> jumlahMahasiswa;

    if (jumlahMahasiswa > maxMahasiswa)
    {
        cout << "Jumlah mahasiswa melebihi batas maksimal!\n";
        return 1;
    }

    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        cout << "Masukkan data mahasiswa ke-" << i + 1 << ":\n";
        cout << "Nama: ";
        cin.ignore();
        getline(cin, mahasiswa[i].nama);
        cout << "NIM: ";
        cin >> mahasiswa[i].nim;
        cout << "UTS: ";
        cin >> mahasiswa[i].uts;
        cout << "UAS: ";
        cin >> mahasiswa[i].uas;
        cout << "Tugas: ";
        cin >> mahasiswa[i].tugas;

        mahasiswa[i].nilaiAkhir = totalNilaiAkhir(mahasiswa[i].uts, mahasiswa[i].uas, mahasiswa[i].tugas);
    }

    cout << "\nData Mahasiswa:\n";
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        cout << "Mahasiswa ke-" << i + 1 << ":\n";
        cout << "Nama: " << mahasiswa[i].nama << endl;
        cout << "NIM: " << mahasiswa[i].nim << endl;
        cout << "UTS: " << mahasiswa[i].uts << endl;
        cout << "UAS: " << mahasiswa[i].uas << endl;
        cout << "Tugas: " << mahasiswa[i].tugas << endl;
        cout << "Nilai Akhir: " << mahasiswa[i].nilaiAkhir << endl;
        cout << "---------------------\n";
    }

    return 0;
}
