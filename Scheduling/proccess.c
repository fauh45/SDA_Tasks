#include "process.h"

#include <stdio.h>

void initProcess(Process *proc)
{
    proc->arrivalTime = 0;
    proc->executeTime = 0;
    proc->timeNeeded = 0;
}

void printProcess(Process proc)
{
    printf("%c %d %d %d\n", proc.name, proc.arrivalTime, proc.executeTime, proc.timeNeeded);
}

void inputProcess(Process *proc)
{
    initProcess(proc);
    scanf(" %c %d %d", &proc->name, &proc->arrivalTime, &proc->timeNeeded);
}

bool processing(Process *proc, int *time, int quantum)
{
    if (proc->timeNeeded <= quantum)
    {
        *time += (*proc).timeNeeded;
        (*proc).timeNeeded = 0;
        (*proc).executeTime = *time;

        return true;
    }
    else
    {
        *time += quantum;
        (*proc).timeNeeded -= quantum;

        return false;
    }
}