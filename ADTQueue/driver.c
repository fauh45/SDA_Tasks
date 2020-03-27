/*
    Program         : driver.c
    Deskripsi       : Driver Program untuk Queue statik dan dinamik
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 26 March 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include <stdio.h>

#include "queuestatic.h"

int main(int argc, char const *argv[])
{
    printf("Static Queue Test\n");
    QueueStatic QS;
    createStaticQueue(&QS);

    printf("enQueue-ing\n");
    enQueueStatic(&QS, 5);
    enQueueStatic(&QS, 4);
    enQueueStatic(&QS, 3);
    enQueueStatic(&QS, 2);
    enQueueStatic(&QS, 1);

    printf("enQueue-ing more than capacity\n");
    enQueueStatic(&QS, 0);

    printf("\nPeeking\n");
    printf("%d\n", peekStatic(QS));

    printf("deQueue-ing until empty\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", deQueueStatic(&QS));
    }
    
    printf("deQueue-ing when empty\n");
    deQueueStatic(&QS);

    return 0;
}
