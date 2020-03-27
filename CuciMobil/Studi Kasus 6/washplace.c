/*
    Program         : washplace.c
    Deskripsi       : Body Wash Place
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 27 March 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include "washplace.h"

void WashQueue(queue *carQueue, int n)
{
    WashPlace a[n];
    info temp;
    for (int i = 0; i < n; i++)
    {
        a[i].bay = 'A' + i;
        temp = Delete(carQueue, a[i].bay);
        CreateTIME(&a[i].local, 0, 0, 0);
        carWash(&temp, &a[i].local);

        carPrint(temp);
    }

    int min = minTime(a, n);
    while (!IsEmpty(*carQueue))
    {
        min = minTime(a, n);
        temp = Delete(carQueue, a[min].bay);
        carWash(&temp, &a[min].local);

        carPrint(temp);
    }
}

int minTime(WashPlace a[], int n)
{
    int minIdx = 0;
    for (int i = 1; i < n; i++)
    {
        if (JGT(a[minIdx].local, a[i].local))
        {
            minIdx = i;
        }
    }

    return minIdx;
}