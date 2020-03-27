#include <stdio.h>
#include "car.h"

void carInit(Car *c)
{
    c->timeSize = 0;
    c->arrivalTime = 0;
    c->finish = 0;
    c->services = 0;
}

void carInput(Car *c)
{
    carInit(c);

    scanf("%s", (*c).name);
    scanf("%s", (*c).kodeJenis);
    scanf("%d", &((*c).arrivalTime));
    (*c).timeSize = 20;
}

void carPrint(Car c)
{
    printf("%s %d %d %d %d\n", c.name, c.timeSize, c.arrivalTime, c.services, c.finish);
}

void carWash(Car *c, int *time, int switchTime)
{
    if ((*c).arrivalTime > *time)
        c->services = *time + (*c).arrivalTime;
    else
        c->services = *time;

    *time += (*c).timeSize;
    c->finish = *time;

    *time += switchTime;
}