/*
    Program         : queuestatic.c
    Deskripsi       : Body ADT Queue Statik
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 26 March 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include "queuestatic.h"
#include <stdio.h>

void createStaticQueue(QueueStatic *Q)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        Q->data[i] = NULL;
    }

    Q->front = -1;
    Q->rear = -1;
}

void enQueueStatic(QueueStatic *Q, info data)
{
    if (isStaticQueueFull(*Q))
    {
        printf("QueueStatic : Queue is Full!");
        return;
    }

    if (Q->front == -1)
    {
        Q->front = 0;
    }
    
    Q->rear = (Q->rear + 1) % MAX;
    Q->data[Q->rear] = data;
}

info deQueueStatic(QueueStatic *Q)
{
    if (isStaticQueueEmpty(*Q))
    {
        printf("QueueStatic : Queue is Empty!");
        return NULL;
    }

    info temp = Q->data[Q->front];
    Q->data[Q->front] = NULL;

    if (Q->front == Q->rear)
    {
        Q->front = -1;
        Q->rear = -1;
    }
    else
    {
        Q->front = (Q->front + 1) % MAX;
    }
    return temp;
}

info peekStatic(QueueStatic Q)
{
    return Q.data[Q.front];
}

bool isStaticQueueFull(QueueStatic Q)
{
    return (Q.front == 0 && Q.rear == MAX - 1) || (Q.rear == (Q.front - 1) % (MAX - 1));
}

bool isStaticQueueEmpty(QueueStatic Q)
{
    return (Q.front == -1);
}
