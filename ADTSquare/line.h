/*
    Program         : line.h
    Deskripsi       : Spesifikasi ADT Line
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 06 March 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/
#include "point.h"

#ifndef Line_h
#define Line_h

/* Definisi tipe data */
typedef struct
{
    POINT startPoint;
    POINT endPoint;
} LINE;

/* Konstruktor */
void CreateLine(LINE *L, POINT P1, POINT P2);
/*
    I.S : P1 dan P2 terdefinisi
    F.S : L terdefinisi dengan L.startPoint=P1 dan L.endPOint=P2
    Deskripsi : Membentuk sebuah L dari komponen-komponennya
*/

/* Selektor */
POINT getStartPoint(LINE L);
/* Mengirimkan komponen titik awal dari L Line */

POINT getEndPoint(LINE L);
/* Mengirimkan komponen titik akhir dari L Line */

/* Set Nilai */
void setStartPoint(LINE *L, POINT newStartPoint);
/* Mengubah komponen titik awal dari L Line */

void setEndPoint(LINE *L, POINT newEndPoint);
/* Mengubah komponen titik akhir dari L Line */

/* I/O */
void readLine(LINE *L);
/*
    I.S : L sembarang
    F.S : mengulangi membaca dua buah nilai titik awal dan titik akhir sehingga dapat membentuk
          LINE yang valid. dapat menggunakan CreateLine
*/

void printLine(LINE L);
/* NIlai L ditulis ke layar dengan format ((x,y), (x,y)) */

/* Operasi Relasional */
boolean EQ(LINE L1, LINE L2);
/*  Mengirimkan true jika L1 = L2
    L1 dikatakan sama dengan L2
    Jika Titik Awal dari L1 = Titik Awal dari L2 dan Titik Akhir dari L1 = Titik Akhir dari L2 */

boolean NEQ(LINE L1, LINE L2);
/*  Mengirimkan true jika L1 tidak sama dengan L2
    Negasi dari fungsi EQ */

/* Menentukan posisi L */
boolean isOnSbX(LINE L);
/* Menghasilkan true jika L terletak pada sumbu X */

boolean isOnSbY(LINE L);
/* Menghasilkan true jika L terletak pada sumbu Y */

int getKuadran(LINE L);
/*  Menghasilkan Kuadran dari L, dimana StartPoint dan EndPoint 
    Precondition : L tidak terletak di salah satu sumbu dan 
    StartPoint serta EndPOint selalu berada pada kuadran yang sama */

/* Predikat Lain */
boolean isTegakLurus(LINE L1, LINE L2);
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */

boolean isSejajar(LINE L1, LINE L2);
/* Menghasilkan true jika L1 “sejajar” terhadap L2 */

boolean isConnected(LINE L1, LINE L2);
/* Checking if line is connected on either end or not */

/* Operasi Lain-lain */
void moveLine(LINE *L, int deltaX, int deltaY);
/*
    I.S : L terdefinisi
    F.S : digeser sejauh deltaX terhadap absis dan sejauh deltaY terhadap ordinat
    Deskripsi : StartPoint dan EndPoint digeser
*/

void mirror(LINE *L, boolean sbX, boolean sbY);
/*
    I.S : L terdefinisi
    F.S : L dicerminkan tergantung nilai sbX atau sbY
    Deskripsi : Jika sbX true maka dicerminkan terhadap sumbu X
                Jika sbY true maka dicerminkan terhadap sumbu Y    
*/

int calculatePanjang(LINE L);
/* Menghitung panjang L dengan menggunakan rumus phitagoras terhadap StartPoint dan EndPoint */

int lenghtOfLine(LINE L);
/* Calculate the lenght of a line */

#endif