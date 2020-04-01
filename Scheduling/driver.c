/*
    Program         : driver.c
    Deskripsi       : Driver dari queue cuci mobil
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 27 March 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include "queueStatis.h"

int main(int argc, char const *argv[])
{
    int N, quantum;
    bool SJN;
    printf("No. Of process : ");
    scanf("%d", &N);

    printf("Quantum time : ");
    scanf("%d", &quantum);

    char res;
    while(true) {
        printf("Use SJN? (y/n) ");
        scanf(" %c", &res);

        if (res == 'n'|| res == 'y')
        {
            SJN = res == 'n'? false : true;
            break;
        }
    }

    queue Q;
    Initial(&Q);
    Q.quantum = quantum;

    info temp;
    for (int i = 0; i < N; i++)
    {
        inputProcess(&temp);

        Insert(&Q, temp);
    }

    printf("Queue :\n");
    Tampil(Q);

    printf("Serving All...\n");
    // while (!IsEmpty(Q))
    // {
    //     temp = Delete(&Q);

    //     printProcess(temp);
    // }
    RoundRobin(&Q, SJN);
    
    return 0;
}
