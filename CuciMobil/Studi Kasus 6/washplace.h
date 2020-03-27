#ifndef WashiWashi
#define WashiWashi

#include "car.h"
#include "queueStatis.h"

typedef struct
{
    char bay;
    TIME local;
} WashPlace;

void WashQueue(queue *carQueue, int n);
int minTime(WashPlace a[], int n);

#endif