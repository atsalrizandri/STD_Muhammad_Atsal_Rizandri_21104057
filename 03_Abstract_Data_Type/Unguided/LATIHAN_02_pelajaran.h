#include <iostream>
#include <string>
#ifndef PELAJARAN_H
#define PELAJARAN_H
using namespace std;

struct pelajaran
{
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
