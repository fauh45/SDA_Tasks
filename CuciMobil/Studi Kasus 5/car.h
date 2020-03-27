#ifndef CAR_H_
#define CAR_H_

#include "Time.h"

typedef struct
{
    char name[10];
    char kodeJenis[3];
    int timeSize;
    TIME arrivalTime;
    TIME services;
    TIME finish;
    int switchTime;
} Car;

void carInit(Car *c);
void carInput(Car *c);
void carPrint(Car c);
void carWash(Car *c, TIME *time);
int getTimeSize(Car c);
int getSwitchTime(Car c);

#endif