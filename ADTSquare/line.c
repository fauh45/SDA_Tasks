/*
    Program         : line.c
    Deskripsi       : Body ADT Line
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 06 March 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/
#include <stdio.h>
#include <math.h>
#include "line.h"

/* Konstruktor */
void CreateLine(LINE *L, POINT P1, POINT P2)
/*
    I.S : P1 dan P2 terdefinisi
    F.S : L terdefinisi dengan L.startPoint=P1 dan L.endPOint=P2
    Deskripsi : Membentuk sebuah L dari komponen-komponennya
*/
{
    L->startPoint = P1;
    L->endPoint = P2;
}

/* Selektor */
POINT getStartPoint(LINE L)
/* Mengirimkan komponen titik awal dari L Line */
{
    return L.startPoint;
}

POINT getEndPoint(LINE L)
/* Mengirimkan komponen titik akhir dari L Line */
{
    return L.endPoint;
}

/* Set Nilai */
void setStartPoint(LINE *L, POINT newStartPoint)
/* Mengubah komponen titik awal dari L Line */
{
    L->startPoint = newStartPoint;
}

void setEndPoint(LINE *L, POINT newEndPoint)
/* Mengubah komponen titik akhir dari L Line */
{
    L->endPoint = newEndPoint;
}

/* I/O */
void readLine(LINE *L)
/*
    I.S : L sembarang
    F.S : mengulangi membaca dua buah nilai titik awal dan titik akhir sehingga dapat membentuk
          LINE yang valid. dapat menggunakan CreateLine
*/
{
    POINT startPoint, endPoint;
    scanf("%d %d", &startPoint.x, &startPoint.y);
    scanf(" %d %d", &endPoint.x, &endPoint.y);

    CreateLine(L, startPoint, endPoint);
}

void printLine(LINE L)
/* NIlai L ditulis ke layar dengan format ((x,y), (x,y)) */
{
    printf("((%d,%d),(%d,%d))", L.startPoint.x, L.startPoint.y, L.endPoint.x, L.endPoint.y);
}

/* Operasi Relasional */
boolean EQ(LINE L1, LINE L2)
/*  Mengirimkan true jika L1 = L2
    L1 dikatakan sama dengan L2
    Jika Titik Awal dari L1 = Titik Awal dari L2 dan Titik Akhir dari L1 = Titik Akhir dari L2 */
{
    return (L1.endPoint.x == L2.endPoint.x) && (L1.endPoint.y == L2.endPoint.y) && (L1.startPoint.x == L2.startPoint.x) && (L1.startPoint.y == L2.startPoint.y);
}

boolean NEQ(LINE L1, LINE L2)
/*  Mengirimkan true jika L1 tidak sama dengan L2
    Negasi dari fungsi EQ */
{
    return !(EQ(L1, L2));
}

/* Menentukan posisi L */
boolean isOnSbX(LINE L)
/* Menghasilkan true jika L terletak pada sumbu X */
{
    return L.startPoint.y == 0 && L.endPoint.y == 0;
}

boolean isOnSbY(LINE L)
/* Menghasilkan true jika L terletak pada sumbu Y */
{
    return L.startPoint.x == 0 && L.endPoint.x == 0;
}

int getKuadran(LINE L)
/*  Menghasilkan Kuadran dari L, dimana StartPoint dan EndPoint 
    Precondition : L tidak terletak di salah satu sumbu dan 
    StartPoint serta EndPOint selalu berada pada kuadran yang sama */
{
    return 1;
}

/* Predikat Lain */
boolean isTegakLurus(LINE L1, LINE L2)
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
{
    if ((L1.endPoint.x == L1.startPoint.x) || (L2.endPoint.x == L2.startPoint.x))
    {
        return false;
    }

    float m1, m2;
    m1 = (float)(L1.endPoint.y - L1.startPoint.y) / (L1.endPoint.x - L1.startPoint.x);
    m2 = (float)(L2.endPoint.y - L2.startPoint.y) / (L2.endPoint.x - L2.startPoint.x);

    return m1 * m2 == -1;
}

boolean isSejajar(LINE L1, LINE L2)
/* Menghasilkan true jika L1 “sejajar” terhadap L2 */
{
    if ((L1.endPoint.x == L1.startPoint.x) || (L2.endPoint.x == L2.startPoint.x))
    {
        return false;
    }

    float m1, m2;
    m1 = (float)(L1.endPoint.y - L1.startPoint.y) / (L1.endPoint.x - L1.startPoint.x);
    m2 = (float)(L2.endPoint.y - L2.startPoint.y) / (L2.endPoint.x - L2.startPoint.x);

    return m1 == m2;
}

boolean isConnected(LINE L1, LINE L2)
/* Checking if line is connected on either end or not */
{
    if (pointEQ(getEndPoint(L1), getEndPoint(L2)))
    {
        return true;
    }

    if (pointEQ(getEndPoint(L1), getStartPoint(L2)))
    {
        return true;
    }

    if (pointEQ(getStartPoint(L1), getEndPoint(L2)))
    {
        return true;
    }

    if (pointEQ(getStartPoint(L1), getStartPoint(L2)))
    {
        return true;
    }

    return false;
}
/* Operasi Lain-lain */
void moveLine(LINE *L, int deltaX, int deltaY)
/*
    I.S : L terdefinisi
    F.S : digeser sejauh deltaX terhadap absis dan sejauh deltaY terhadap ordinat
    Deskripsi : StartPoint dan EndPoint digeser
*/
{
    CreateLine(L, CreatePoint(GetX(getStartPoint(*L)) + deltaX, GetY(getStartPoint(*L)) + deltaY), CreatePoint(GetX(getEndPoint(*L)) + deltaX, GetY(getEndPoint(*L)) + deltaY));
}

void mirror(LINE *L, boolean sbX, boolean sbY)
/*
    I.S : L terdefinisi
    F.S : L dicerminkan tergantung nilai sbX atau sbY
    Deskripsi : Jika sbX true maka dicerminkan terhadap sumbu X
                Jika sbY true maka dicerminkan terhadap sumbu Y    
*/
{
    CreateLine(L, CreatePoint(sbX ? -GetX(getStartPoint(*L)) : GetX(getStartPoint(*L)), sbY ? -GetY(getStartPoint(*L)) : GetY(getStartPoint(*L))), CreatePoint(sbX ? -GetX(getEndPoint(*L)) : GetX(getEndPoint(*L)), sbY ? -GetY(getEndPoint(*L)) : GetY(getEndPoint(*L))));
}

int calculatePanjang(LINE L)
/* Menghitung panjang L dengan menggunakan rumus phitagoras terhadap StartPoint dan EndPoint */
{
    return sqrt(pow((L.endPoint.x - L.startPoint.x), 2) + pow((L.endPoint.y - L.startPoint.y), 2));
}

int lenghtOfLine(LINE L)
/* Calculate the lenght of a line */
{
    return Jarak(L.startPoint, L.endPoint);
}