/*
    Program         : HitungHargaParkir.c
    Deskripsi       : Menghitung harga parkir
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 04 March 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include <stdio.h>
#include "Time.h"
#include "date.h"

int main()
{
    short dayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    TIME startTime, endTime;
    DATE startDate, endDate;

    scanf("%d %d %d", &startDate.Tgl, &startDate.Bln, &startDate.Thn);
    scanf(" %d %d %d", &startTime.Hour, &startTime.Minute, &startTime.Second);
    scanf(" %d %d %d", &endDate.Tgl, &endDate.Bln, &endDate.Thn);
    scanf(" %d %d %d", &endTime.Hour, &endTime.Minute, &endTime.Second);

    dayOfMonth[1] = isKabisat(startDate) ? 29 : 28;
    int dayElapsed = 0;
    dayElapsed += (endDate.Thn - startDate.Thn) * 365;

    while (startDate.Bln != endDate.Bln)
    {
        dayElapsed += dayOfMonth[startDate.Bln - 1];
        startDate.Bln++;
    }

    dayElapsed += endDate.Tgl - startDate.Tgl;

    TIME elapsedTime;
    if (dayElapsed > 0)
    {
        TIME beforeDayChange, afterDayChange;
        CreateTIME(&beforeDayChange, 23, 59, 59);
        CreateTIME(&afterDayChange, 0, 0, 0);
        elapsedTime = JPlus(JMinus(startTime, beforeDayChange), JMinus(afterDayChange, endTime));

        if (JEQ(startTime, endTime) || !(JLT(startTime, endTime)))
        {
            SetHour(&elapsedTime, GetHour(elapsedTime) + (dayElapsed * 24) - 24);
        } else
        {
            SetHour(&elapsedTime, GetHour(elapsedTime) + (dayElapsed * 24));
        }
    }
    else
    {
        elapsedTime = JMinus(startTime, endTime);
    }

    int elapsedHour = GetHour(elapsedTime);
    if (GetMinute(elapsedTime) > 0 || GetSecond(elapsedTime) > 0)
    {
        elapsedHour += 1;
    }
    
    printf("%02d:%02d:%02d %d\n", elapsedTime.Hour, elapsedTime.Minute, elapsedTime.Second, elapsedHour > 0 ? 2000 + (elapsedHour - 1) * 1500 : 0);
    return 0;
}
