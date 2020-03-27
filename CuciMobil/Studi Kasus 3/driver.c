/*
    Program         : driver.c
    Deskripsi       : Driver dari queue cuci mobil
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 27 March 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include "queueStatis.h"

int main(int argc, char const *argv[])
{
    int N;
    printf("No. Of car : ");
    scanf("%d", &N);

    queue Q;
    Initial(&Q);

    info temp;
    for (int i = 0; i < N; i++)
    {
        carInput(&temp);

        Insert(&Q, temp);
    }

    printf("Queue :\n");
    Tampil(Q);

    printf("Serving All...\n");
    while (!IsEmpty(Q))
    {
        temp = Delete(&Q);

        carPrint(temp);
    }
    
    return 0;
}
