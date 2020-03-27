/*
    Program         : queueStatis.c
    Deskripsi       : Body implementasi Queue
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 27 March 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include "queueStatis.h"

bool IsFull(queue Q)
{
    return (Q.front == 0 && Q.rear == MAX - 1) || (Q.rear == (Q.front - 1) % (MAX - 1));
}

bool IsEmpty(queue Q)
{
    return (Q.front == -1);
}

void SetFront(queue *Q, int idx)
{
    Q->front = idx;
}

void SetRear(queue *Q, int idx)
{
    Q->rear = idx;
}

info Delete(queue *Q)
{
    if (IsEmpty(*Q))
    {
        printf("QueueStatic : Queue is Empty!");
    }
    else
    {
        info temp = Q->data[Q->front];
        carWash(&temp, &Q->time, 1);
        
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
}

void Initial(queue *Q)
{
    SetFront(Q, -1);
    SetRear(Q, -1);
    (*Q).time = 0;
}

void Insert(queue *Q, info vdata)
{
    if (IsFull(*Q))
    {
        printf("QueueStatic : Queue is Full!");
        return;
    }

    if (Q->front == -1)
    {
        Q->front = 0;
    }

    Q->rear = (Q->rear + 1) % MAX;
    Q->data[Q->rear] = vdata;
}

void Tampil(queue Q)
{
    if (IsEmpty(Q))
        printf("The queue is empty!\n");
    else
    {
        int i;
        if (Q.front <= Q.rear)
        {
            for (i = Q.front; i <= Q.rear; i++)
            {
                carPrint(Q.data[i]);
            }
        }
        else
        {
            for (i = Q.front; i < MAX; i++)
                carPrint(Q.data[i]);

            for (i = 0; i <= Q.rear; i++)
                carPrint(Q.data[i]);
        }
    }
}

int count(queue Q)
{
    return (Q.rear >= Q.front) ? Q.front - Q.rear + 1 : MAX - Q.front + Q.rear + 1;
}
