#include <stdio.h>
#include <string.h>

#include "car.h"

void carInit(Car *c)
{
    c->timeSize = 0;
    CreateTIME(&c->arrivalTime, 0, 0, 0);
    CreateTIME(&c->finish, 0, 0, 0);
    CreateTIME(&c->services, 0, 0, 0);
    c->switchTime = 0;
}

void carInput(Car *c)
{
    carInit(c);

    scanf("%s", (*c).name);
    scanf("%s", (*c).kodeJenis);
    ReadTIME(&(*c).arrivalTime);
    (*c).timeSize = getTimeSize(*c);
    (*c).switchTime = getSwitchTime(*c);
}

void carPrint(Car c)
{
    printf("%s %s %d ", c.name, c.kodeJenis, c.timeSize);
    PrintTIME(c.arrivalTime);
    printf(" ");
    PrintTIME(c.services);
    printf(" ");
    PrintTIME(c.finish);
    printf(" ");
    printf("%d\n", c.switchTime);
}

void carWash(Car *c, TIME *time)
{
    c->services = (JGT((*c).arrivalTime, *time)) ? (*c).arrivalTime : *time;
    // c->finish = c->services;
    *time = NextNDetik(c->services, ((*c).timeSize * 60));
    c->finish = *time;

    *time = NextNDetik(*time, ((*c).switchTime * 60));
}

int getTimeSize(Car c)
{
    if (strcmp(c.kodeJenis, "#01") == 0)
    {
        return 20;
    }
    else if (strcmp(c.kodeJenis, "#02") == 0)
    {
        return 30;
    }
    else if (strcmp(c.kodeJenis, "#03") == 0)
    {
        return 45;
    }
    else if (strcmp(c.kodeJenis, "#04") == 0)
    {
        return 60;
    }
    else if (strcmp(c.kodeJenis, "#05") == 0)
    {
        return 80;
    }
    else if (strcmp(c.kodeJenis, "#06") == 0)
    {
        return 100;
    }
    else if (strcmp(c.kodeJenis, "#07") == 0)
    {
        return 120;
    }
    else if (strcmp(c.kodeJenis, "#08") == 0)
    {
        return 125;
    }

    return 0;
}

int getSwitchTime(Car c)
{
    if (strcmp(c.kodeJenis, "#01") == 0)
    {
        return 1;
    }
    else if (strcmp(c.kodeJenis, "#02") == 0)
    {
        return 2;
    }
    else if (strcmp(c.kodeJenis, "#03") == 0)
    {
        return 4;
    }
    else if (strcmp(c.kodeJenis, "#04") == 0)
    {
        return 5;
    }
    else if (strcmp(c.kodeJenis, "#05") == 0)
    {
        return 6;
    }
    else if (strcmp(c.kodeJenis, "#06") == 0)
    {
        return 8;
    }
    else if (strcmp(c.kodeJenis, "#07") == 0)
    {
        return 9;
    }
    else if (strcmp(c.kodeJenis, "#08") == 0)
    {
        return 10;
    }

    return 0;
}