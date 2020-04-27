/*
    Program         : driver.c
    Deskripsi       : Driver untuk ADT Tree
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 22 April 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include "tree.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    Tree t;
    int ind, indA;
    initTree(&t);

    insertNode(&t, 'A', None);
    
    ind = insertNode(&t, 'B', t.root);
    insertNode(&t, 'D', ind);
    insertNode(&t, 'E', ind);

    ind = insertNode(&t, 'C', t.root);
    insertNode(&t, 'F', ind);
    insertNode(&t, 'G', ind);
    
    indA = insertNode(&t, 'H', ind);
    printf("%d\n", indA);
    insertNode(&t, 'I', indA);
    insertNode(&t, 'J', indA);

    printf("Depth : %d\n", depth(t, t.root));
    printf("Order : %d\n", order(t, t.root));
    printf("Level of root : %d\n", level(t, t.root));
    printf("Level of 'H' : %d\n", level(t, indA));
    printf("Degree : %d\n", degree(t, t.root));
    printf("InOrder : ");
    printInOrder(t, t.root);
    printf("\n");
    printf("PreOrder : ");
    printPreOrder(t, t.root);
    printf("\n");
    printf("PostOrder : ");
    printPostOrder(t, t.root);
    printf("\n");

    deleteNode(&t, ind);
    printf("PreOrder after deletion : ");
    printPreOrder(t, t.root);
    printf("\n");
    return 0;
}
