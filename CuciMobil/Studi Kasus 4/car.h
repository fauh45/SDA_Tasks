#ifndef CAR_H_
#define CAR_H_

typedef struct
{
    char name[10];
    char kodeJenis[3];
    int timeSize;
    int arrivalTime;
    int services;
    int finish;
    int switchTime;
} Car;

void carInit(Car *c);
void carInput(Car *c);
void carPrint(Car c);
void carWash(Car *c, int *time);
int getTimeSize(Car c);
int getSwitchTime(Car c);

#endif