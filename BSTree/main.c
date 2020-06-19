/*
    Program         : main.c
    Deskripsi       : driver program for BSTree
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 19 June 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include "binstree.h"

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i;
    BinTree BT = Nil;
    infotype X[20] = {
        "Endah", "Charly", "Badu", "Abdul", "Ade", "Baihaqi",
        "Fatimah", "Gagah", "Wildan", "Cucu", "Dudi", "Dudy",
        "Fajar", "Desi", "Fatnam", "Fairuz", "Bahrum", "Badu",
        "Abah", "Cantika"};

    for (i = 0; i < 20; i++)
    {
        InsSearchTree(&BT, X[i]);
    }

    printf("Inorder dari Tree : ");
    Inorder(BT);

    infotype searchTerm;
    printf("\nSearch name : ");
    scanf("%[^\n]", searchTerm);

    address node;
    node = Search2(BT, searchTerm);

    printf("\nFound %s on memory address %x\n", searchTerm, node);

    return 0;
}
