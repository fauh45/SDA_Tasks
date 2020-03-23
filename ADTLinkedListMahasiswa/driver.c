/*
    Program         : driver.c
    Deskripsi       : Driver dari ADT Link List Mahasiswa
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 20 March 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include <stdio.h>

#include "list1.h"

boolean over170(infotype Mhs);

int main(int argc, char const *argv[])
{
    int N;
    printf("How Many Mahasiswa do you want to add : ");
    scanf("%d", &N);

    List L1;
    infotype temp;
    CreateList(&L1);

    printf("Addition Format (Name(one word) Height)\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%s %d", temp.nama, &temp.tinggi);

        InsertNew(&L1, temp);
    }

    printf("Content of List :\n");
    PrintInfo(L1);

    printf("Copying mahasiswa over 170cm\n");
    List L2 = FCopyListCustomCondition(L1, over170);

    printf("Content of New List :\n");
    PrintInfo(L2);

    printf("Content of New List after removal of Duplicates :\n");
    makeUniqueList(&L2);
    PrintInfo(L2);

    return 0;
}

boolean over170(infotype Mhs)
{
    return Mhs.tinggi > 170;
}
