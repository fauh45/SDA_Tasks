/*
    Program         : matrix.h
    Deskripsi       : Header ADT Matriks
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 09 April 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#pragma once
#include <stdlib.h>
#include "boolean.h"
#include <stdio.h>
#include <string.h>
#include "point.h"

// Data type
typedef struct Elemen *address;

typedef struct Elemen
{
    POINT p;
    address down;
    address right;
} Elemen;

typedef struct
{
    address topLeft;
    int lastX;
    int lastY;
} Matriks;

void createMatriks(Matriks *M);
address allocate(POINT P);
void addDown(Matriks *M, address E, int col);
void addDownAllocate(Matriks *M, POINT P, int col);
boolean isEmpty(Matriks M);
address getAt(Matriks Mat, int M, int N);
void printEl(address El);