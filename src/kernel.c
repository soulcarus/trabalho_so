#include "kernel.h"

Task tasks[MAX_TASKS];
int numTasks = 0;

void kernelInit() {
    numTasks = 0;
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i].active = 0;
    }
}

void kernelAddTask(int (*func)()) {
    if (numTasks < MAX_TASKS) {
        tasks[numTasks].taskFunction = func;
        tasks[numTasks].active = 1;
        numTasks++;
    }
}

void kernelRun() {
    int current = 0;
    while (1) {
        if (numTasks > 0 && tasks[current].active) {
            int result = tasks[current].taskFunction();
            if (result == 0) {
                tasks[current].active = 0;
                for (int i = current; i < numTasks - 1; i++) {
                    tasks[i] = tasks[i + 1];
                }
                numTasks--;
            } else {
                current = (current + 1) % numTasks;
            }
        }
    }
}