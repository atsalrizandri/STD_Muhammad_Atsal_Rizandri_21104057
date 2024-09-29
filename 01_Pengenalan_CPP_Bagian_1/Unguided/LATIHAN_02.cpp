#include <iostream>
using namespace std;

string satuan(int angka)
{
    switch (angka)
    {
    case 1:
        return "satu";
    case 2:
        return "dua";
    case 3:
        return "tiga";
    case 4:
        return "empat";
    case 5:
        return "lima";
    case 6:
        return "enam";
    case 7:
        return "tujuh";
    case 8:
        return "delapan";
    case 9:
        return "sembilan";
    default:
        return "";
    }
}

string kata(int angka)
{
    if (angka == 0)
        return "nol";
    if (angka == 100)
        return "seratus";
    if (angka >= 10 && angka < 20)
    {
        switch (angka)
        {
        case 10:
            return "sepuluh";
        case 11:
            return "sebelas";
        case 12:
            return "dua belas";
        case 13:
            return "tiga belas";
        case 14:
            return "empat belas";
        case 15:
            return "lima belas";
        case 16:
            return "enam belas";
        case 17:
            return "tujuh belas";
        case 18:
            return "delapan belas";
        case 19:
            return "sembilan belas";
        }
    }
    if (angka >= 20)
    {
        string puluh = "";
        switch (angka / 10)
        {
        case 2:
            puluh = "dua puluh";
            break;
        case 3:
            puluh = "tiga puluh";
            break;
        case 4:
            puluh = "empat puluh";
            break;
        case 5:
            puluh = "lima puluh";
            break;
        case 6:
            puluh = "enam puluh";
            break;
        case 7:
            puluh = "tujuh puluh";
            break;
        case 8:
            puluh = "delapan puluh";
            break;
        case 9:
            puluh = "sembilan puluh";
            break;
        }
        return puluh + (angka % 10 != 0 ? " " + satuan(angka % 10) : "");
    }
    return satuan(angka);
}

int main()
{
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;
    cout << angka << " : " << kata(angka) << endl;
    return 0;
}
