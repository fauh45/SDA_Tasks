/*
    Program         : mcircle.c
    Deskripsi       : Menyelesaikan masalah Andi dengan Luas lingkaran
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 28 February 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include <stdio.h>
#include "circle.h"

int main()
{
    Circle C1, C2;
    printf("Masukan C1 (x y r) :\n");
    scanf("%d %d %f", &C1.P.x, &C1.P.y, &C1.r);
    printf("Masukan C2 (x y r) :\n");
    scanf("%d %d %f", &C2.P.x, &C2.P.y, &C2.r);

    float Area1, Area2;
    Area1 = Area(C1);
    Area2 = Area(C2);

    printf("%s\n", Area1 == Area2 ? "dua buah Circle memiliki luas area yang sama": Area1 > Area2 ? "Circle 1 memiliki luas area yang lebih besar dibandingkan Circle 2" : "Circle 1 memiliki luas area yang lebih kecil dibandingkan Circle 2");

    return 0;
}
