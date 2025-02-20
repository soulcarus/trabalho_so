#ifndef KERNEL_H
#define KERNEL_H

#define MAX_TASKS 5

typedef struct {
    int (*taskFunction)();
    int active;
} Task;

void kernelInit();
void kernelAddTask(int (*func)());
void kernelRun();

#endif