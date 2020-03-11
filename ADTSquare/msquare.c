/*
    Program         : msquare.c
    Deskripsi       : Main Driver ADT Square
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 06 March 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include "square.h"
#include <stdio.h>

int main()
{
    SQUARE S;
    readSquare(&S);

    initPlot();
    drawAxis();
    drawSquare(S);

    getch();
    endPlot();

    int x, y;
    printf("Move Square by X Y :\n");
    scanf("%d %d", &x, &y);

    moveSquare(x, y, &S);

    initPlot();
    drawAxis();
    drawSquare(S);

    getch();
    endPlot();

    return 0;
}
