/*
    Program         : driver.c
    Deskripsi       : ADT Matriks Driver
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 09 April 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include "matrix.h"

int main(int argc, char const *argv[])
{
    int M, N;
    POINT p;

    Matriks Mat;
    createMatriks(&Mat);

    printf("No of data going to be inputted, input as M N (collumn row)\n");
    scanf("%d %d", &M, &N);

    for (int i = 1; i <= M; i++)
    {
        printf("Input for collumn %d with %d data (POINT, x y)\n", i, N);

        for (int j = 0; j < N; j++)
        {
            scanf(" %d %d", &p.x, &p.y);

            addDownAllocate(&Mat, p, i);
        }
    }

    printf("Send command with format l for left, r for right, u for up, and d for down, with space and then the number of steps going to do\n");
    printf("For example (l 4) is going 4 to the left, c <any num> for current position, and q <any num> for quit\n");

    char tempCmd;
    int move;
    while (true)
    {
        scanf("%c %d", &tempCmd, &move);

        switch (tempCmd)
        {
        case 'l':
            if (getAt(Mat, Mat.lastX - move, Mat.lastY) == NULL)
            {
                printf("Illegal Move!\n");
            }
            else
            {
                Mat.lastX -= move;
                printEl(getAt(Mat, Mat.lastX, Mat.lastY));
            }
            break;

        case 'd':
            if (getAt(Mat, Mat.lastX, Mat.lastY + move) == NULL)
            {
                printf("Illegal Move!\n");
            }
            else
            {
                Mat.lastY += move;
                printEl(getAt(Mat, Mat.lastX, Mat.lastY));
            }
            break;

        case 'r':
            if (getAt(Mat, Mat.lastX + move, Mat.lastY) == NULL)
            {
                printf("Illegal Move!\n");
            }
            else
            {
                Mat.lastX += move;
                printEl(getAt(Mat, Mat.lastX, Mat.lastY));
            }
            break;

        case 'u':
            if (getAt(Mat, Mat.lastX, Mat.lastY - move) == NULL)
            {
                printf("Illegal Move!\n");
            }
            else
            {
                Mat.lastY -= move;
                printEl(getAt(Mat, Mat.lastX, Mat.lastY));
            }
            break;

        case 'c':
            printf("%d %d\n", Mat.lastX, Mat.lastY);
            break;
            
        default:
            break;
        }

        if (tempCmd == 'q')
        {
            break;
        }
    }

    return 0;
}
