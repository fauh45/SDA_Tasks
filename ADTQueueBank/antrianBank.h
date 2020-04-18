/*
    Program         : antrianBank.h
    Deskripsi       : Header ADT Antrian Bank
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 18 April 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#pragma once

#include "list1.h"

typedef struct
{
    int CS1;
    int CS2;
} CS;

typedef struct
{
    int Teller1;
    int Teller2;
    int Teller3;
} Teller;

typedef struct
{
    CS counterCS;
    Teller counterTeller;
    List antrianCS;
    List antrianTeller;
} Bank;

void initBank(Bank *b);
void tambahAntrian(Bank *b, char tipe);
infotype panggilAntrian(Bank *b, char tipe, int noTeller);
void printStatus(Bank b);