/*
    Program         : queuestatic.h
    Deskripsi       : Header ADT Queue statik
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 26 March 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#ifndef Q_S
#define Q_S

#define MAX 5
#include <stdbool.h>

typedef int info;
typedef struct
{
    int front, rear;
    info data[MAX];
} QueueStatic;

void createStaticQueue(QueueStatic *Q);
void enQueueStatic(QueueStatic *Q, info data);
info deQueueStatic(QueueStatic *Q);
info peekStatic(QueueStatic Q);
bool isStaticQueueFull(QueueStatic Q);
bool isStaticQueueEmpty(QueueStatic Q);

#endif