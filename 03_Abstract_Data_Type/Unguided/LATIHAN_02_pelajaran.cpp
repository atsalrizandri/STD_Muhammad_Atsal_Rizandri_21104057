#include <iostream>
#include "LATIHAN_02_pelajaran.h"

pelajaran create_pelajaran(string namapel, string kodepel)
{
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;

    return pel;
}

void tampil_pelajaran(pelajaran pel)
{
    cout << "Nama pelajaran : " << pel.namaMapel << endl;
    cout << "Kode pelajaran : " << pel.kodeMapel << endl;
}