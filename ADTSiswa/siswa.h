#pragma once

#include "list1.h"
#define MAX 25

typedef struct siswa
{
    char nama[25];
    char NIM[10];
    List hobi;
} siswa;

typedef struct
{
    siswa siswaKelas[MAX];
    int numOfSiswa;
} kelas;

void createKelas(kelas *kls);
void createSiswa(siswa *swa, char nama[25], char NIM[10]);
void printKelas(kelas kls);
void addSiswa(kelas *kls, siswa swa);
void addHobi(siswa *swa, char namaHobby[25]);
void removeSiswa(kelas *kls);