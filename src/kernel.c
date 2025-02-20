#include "kernel.h"

Task tasks[MAX_TASKS];
int numTasks = 0;
int semaphoreState = 0;  // 0 = Verde, 1 = Amarelo, 2 = Vermelho

void kernelInit() {
    numTasks = 0;
    semaphoreState = 0;
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i].active = 0;
    }
}

void kernelAddTask(int (*func)(int)) {
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
            int result = tasks[current].taskFunction(semaphoreState);
            if (result == 1) {  // Próximo estado
                semaphoreState = (semaphoreState + 1) % 3;  // Ciclo: 0 -> 1 -> 2 -> 0
            }
            current = (current + 1) % numTasks;
        }
    }
}