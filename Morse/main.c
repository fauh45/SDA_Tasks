/*
    Program         : main.c
    Deskripsi       : Main Program Morse Code
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 11 June 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include "tree.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    Tree morse = createTree();
    char temp[150], src[150], dest[150];
    createMorseTree(&morse);

    printf("Morse Tree Inorder : ");
    inorder(morse.root);
    
    printf("\nPlease choose the desired function : \n1. Text to Morse\n2. Morse to Text\n3. Text File to Morse\n4. Exit\n");
    printf("Your option : ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter the text, max 150 char : ");
        scanf(" %[^\n]", temp);

        createCodeString(morse, temp);
        break;

    case 2:
        printf("Input the morse code divided by space, max 150 char : ");
        scanf("%s", temp);

        convertMorseString(morse, temp);
        break;

    case 3:
        printf("Please input the name of the source file : ");
        scanf("%s", src);

        printf("Please input the name of the destination file : ");
        scanf("%s", dest);

        convertFileToMorse(morse, src, dest);
        break;

    default:
        break;
    }

    return 0;
}
