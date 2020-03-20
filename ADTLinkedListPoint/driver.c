/*
    Program         : driver.c
    Deskripsi       : Driver dari ADT List Point
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 20 March 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "list1.h"

boolean pointUndifined(infotype P);

int main(int argc, char const *argv[])
{
    int N, K;
    printf("Masukan jumlah POINT yang akan di random\nDengan x dan y diantara -50 sampai 50: ");
    scanf("%d", &N);

    List L1;
    POINT temp;
    time_t t;

    srand((unsigned) time(&t));
    CreateList(&L1);

    for (int i = 0; i < N; i++)
    {
        SetX(&temp, (int)((rand() % 100) - 50));
        SetY(&temp, (int)((rand() % 100) - 50));
        
        InsVLast(&L1, temp);
    }
    
    PrintInfo(L1);
    printf("Pada Kuadran apa yang anda ingin cek : ");
    scanf("%d", &K);

    unsigned int jumlah;
    printf("POINT dalam Kuadran %d\n", K);
    jumlah = jmlDiKuadran(L1, K);
    printf("Jumlah dalam Kuadran %d adalah %d\n", K, jumlah);

    List L2;
    printf("Mengcopy Point yang undifined\n");

    L2 = FCopyListCustomCondition(L1, pointUndifined);

    printf("Hasil copy\n");
    PrintInfo(L2);

    printf("Deleting L1 and L2\n");
    DelAll(&L1);
	DelAll(&L2);

    return 0;
}

boolean pointUndifined(infotype P)
{
    if (Kuadran(P) == -1)
    {
        return true;
    }
    
    return false;
}