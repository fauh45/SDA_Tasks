/*
    Program         : mline.c
    Deskripsi       : Main driver ADT Line
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 06 March 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/
#include "line.h"
#include <stdio.h>

int main()
{
    LINE L1, L2;
    readLine(&L1);
    printLine(L1);
    printf("\n");
    readLine(&L2);
    printLine(L2);

    printf("\nEqual ? %s\n", EQ(L1, L2) ? "Yes" : "No");
    mirror(&L1, true, false);
    printLine(L1);

    printf("\n");
    move(&L2, 10, 23);
    printLine(L2);

    printf("Jarak : %d\n", calculatePanjang(L1));

    return 0;
}
