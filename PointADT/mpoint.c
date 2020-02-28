/*
    Program         : mpoint.c
    Deskripsi       : Prosesing Point
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 28 February 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include <stdio.h>
#include "boolean.h"
#include "point.h"

int main()
{
    POINT P;
    int N;
    scanf("%d %d", &P.x, &P.y);

    switch (Kuadran(P))
    {
    case -1:
        printf("%d %d\n", GetX(P), GetY(P));
        printf("%s\n", IsOrigin(P) ? "Titik Origin" : IsOnSumbuY(P) ? "Titik berada pada sumbu Y" : "Titik berada pada sumbu X");
        break;

    case 1:
        printf("%d %d\n", GetX(P), GetY(P));
        NextX(&P);
        printf("%d %d\n", GetX(P), GetY(P));
        break;

    case 2:
        printf("%d %d\n", GetX(P), GetY(P));
        PrevX(&P);
        printf("%d %d\n", GetX(P), GetY(P));
        break;

    case 3:
        scanf(" %d", &N);
        printf("%d %d\n", GetX(P), GetY(P));
        NextX_N(&P, N);
        printf("%d %d\n", GetX(P), GetY(P));
        break;

    case 4:
        scanf(" %d", &N);
        printf("%d %d\n", GetX(P), GetY(P));
        PrevX_N(&P, N);
        printf("%d %d\n", GetX(P), GetY(P));
        break;

    default:
        break;
    }

    return 0;
}
