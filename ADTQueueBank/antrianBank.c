/*
    Program         : antrianBank.c
    Deskripsi       : Body ADT Antrian Bank
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 18 April 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include "antrianBank.h"
#include <stdio.h>

void initBank(Bank *b)
{
    b->counterCS.CS1 = 0;
    b->counterCS.CS2 = 0;
    b->counterTeller.Teller1 = 0;
    b->counterTeller.Teller2 = 0;
    b->counterTeller.Teller3 = 0;

    CreateList(&(b->antrianCS));
    CreateList(&(b->antrianTeller));
}

void tambahAntrian(Bank *b, char tipe)
{
    infotype temp;
    if (tipe == 'T')
    {
        temp.kode = 'T';
        if (Last(b->antrianTeller) == Nil)
        {
            temp.noAntrian = 1;
        }
        else
        {
            temp.noAntrian = Info(Last(b->antrianTeller)).noAntrian + 1;
        }

        InsVLast(&(b->antrianTeller), temp);
    }
    else if (tipe == 'C')
    {
        temp.kode = 'C';
        if (Last(b->antrianCS) == Nil)
        {
            temp.noAntrian = 1;
        }
        else
        {
            temp.noAntrian = Info(Last(b->antrianCS)).noAntrian + 1;
        }

        InsVLast(&(b->antrianCS), temp);
    }
}

infotype panggilAntrian(Bank *b, char tipe, int noTeller)
{
    infotype temp;
    temp.kode = 'E';
    temp.noAntrian = 0;
    if (tipe == 'T')
    {
        if (ListEmpty(b->antrianTeller))
	    {
		    printf("List Kosong !\n");
		    return temp;
	    }

        DelVFirst(&(b->antrianTeller), &temp);
        switch (noTeller)
        {
        case 1:
            b->counterTeller.Teller1++;
            break;

        case 2:
            b->counterTeller.Teller2++;
            break;

        case 3:
            b->counterTeller.Teller3++;
            break;

        default:
            break;
        }
    }
    else if (tipe == 'C')
    {
        if (ListEmpty(b->antrianCS))
	    {
		    printf("List Kosong !\n");
		    return temp;
	    }

        DelVFirst(&(b->antrianCS), &temp);
        switch (noTeller)
        {
        case 1:
            b->counterCS.CS1++;
            break;

        case 2:
            b->counterCS.CS2++;
            break;

        default:
            break;
        }
    }

    return temp;
}

void printStatus(Bank b)
{
    printf("Jumlah yang di layani :\n");
    printf("CS 1 : %d\n", b.counterCS.CS1);
    printf("CS 2 : %d\n", b.counterCS.CS2);
    printf("Teller 1 : %d\n", b.counterTeller.Teller1);
    printf("Teller 2 : %d\n", b.counterTeller.Teller2);
    printf("Teller 3 : %d\n", b.counterTeller.Teller3);
    printf("Antrian CS : \n");
    PrintInfo(b.antrianCS);
    printf("Antrian Teller : \n");
    PrintInfo(b.antrianTeller);
}