#include "siswa.h"
#include <stdio.h>

void createKelas(kelas *kls)
{
    kls->numOfSiswa = 0;
}

void createSiswa(siswa *swa, char nama[25], char NIM[10])
{
    CreateList(&(swa->hobi));
    strcpy(swa->nama, nama);
    strcpy(swa->NIM, NIM);
}

void printKelas(kelas kls)
{
    for (int i = 0; i < kls.numOfSiswa; i++)
    {
        printf("[ ");
        printf("%s", kls.siswaKelas[i].nama);
        printf(", ");
        printf("%s", kls.siswaKelas[i].NIM);
        printf(", ");
        PrintInfo(kls.siswaKelas[i].hobi);
        printf("],\n");
    }
}

void addSiswa(kelas *kls, siswa swa)
{
    if (kls->numOfSiswa + 1 > MAX)
    {
        return;
    }

    kls->siswaKelas[kls->numOfSiswa] = swa;
    kls->numOfSiswa++;
}

void addHobi(siswa *swa, char namaHobby[25])
{
    hobby temp;
    strcpy(temp.nama, namaHobby);

    InsVLast(&(swa->hobi), temp);
}

void removeSiswa(kelas *kls)
{
    if (kls->numOfSiswa == 0)
    {
        return;
    }

    siswa temp;
    strcpy(temp.nama, "");
    strcpy(temp.NIM, "");

    DelAll(&(kls->siswaKelas[kls->numOfSiswa - 1].hobi));
    kls->siswaKelas[kls->numOfSiswa - 1] = temp;
}