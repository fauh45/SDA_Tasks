/* 	Program			: ADT queue statis
	Compiler		: Turbo C++
	Di modifikasi	: 27 Maret 2020
*/

#ifndef queue_H
#define queue_H

#include <stdio.h>
#include <stdbool.h>

#include "process.h"

#define MAX 5

typedef Process info;
typedef struct
{
	info data[MAX];
	int front;
	int rear;
	int time;
	int quantum;
} queue;

bool IsFull(queue Q);
bool IsEmpty(queue Q);
void SetFront(queue *Q, int idx);
void SetRear(queue *Q, int idx);
info Delete(queue *Q);
void Initial(queue *Q);
void Insert(queue *Q, info vdata);
void Tampil(queue Q);
int count(queue Q);
void SJN(queue *Q);
void RoundRobin(queue *Q, bool useSJN);

#endif
