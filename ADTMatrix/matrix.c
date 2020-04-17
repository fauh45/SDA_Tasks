/*
    Program         : matrix.c
    Deskripsi       : Body ADT Matrix
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 09 April 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include "matrix.h"

void createMatriks(Matriks *M)
{
    M->topLeft = NULL;
    M->lastX = 1;
    M->lastY = 1;
}

address allocate(POINT P)
{
    address E = (address)malloc(sizeof(Elemen));

    if (E != NULL)
    {
        E->down = NULL;
        E->right = NULL;
        E->p = P;
    }

    return E;
}

void addDownAllocate(Matriks *M, POINT P, int col)
{
    address E = allocate(P);

    if (E != NULL)
    {
        addDown(M, E, col);
    }
}

void addDown(Matriks *M, address E, int col)
{
    if (isEmpty(*M))
    {
        M->topLeft = E;
    }
    else
    {
        int currCol = 1;
        address curr = M->topLeft;

        while (curr->right != NULL)
        {
            if (currCol == col)
            {
                break;
            }

            curr = curr->right;

            currCol++;
        }

        if (curr->right == NULL && currCol != col)
        {
            curr->right = E;
        }
        else
        {
            while (curr->down != NULL)
            {
                curr = curr->down;
            }

            curr->down = E;
        }
    }
}

boolean isEmpty(Matriks M)
{
    return M.topLeft == NULL;
}

address getAt(Matriks Mat, int M, int N)
{
    if (isEmpty(Mat))
    {
        return NULL;
    }

    if (M < 1 || N < 1)
    {
        return NULL;
    }

    int currCol = 1;
    int currRow = 1;
    address curr = Mat.topLeft;

    while (curr != NULL)
    {
        if (currCol == M)
        {
            break;
        }
        curr = curr->right;

        currCol++;
    }

    if (curr == NULL)
    {
        return NULL;
    }

    while (curr != NULL)
    {
        if (currRow == N)
        {
            break;
        }
        curr = curr->down;

        currRow++;
    }

    if (curr == NULL)
    {
        return NULL;
    }

    return curr;
}

void printEl(address El)
{
    PrintPoint(El->p);
}