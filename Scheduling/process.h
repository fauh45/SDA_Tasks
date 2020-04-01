/*
    Program         : process.h
    Deskripsi       : Header untuk ADT Proses
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 29 March 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#ifndef proc_h
#define proc_h

#include <stdbool.h>

typedef struct
{
    char name;
    int arrivalTime;
    int executeTime;
    int timeNeeded;
} Process;

void initProcess(Process *proc);
void printProcess(Process proc);
void inputProcess(Process *proc);
bool processing(Process *proc, int *time, int quantum);

#endif
