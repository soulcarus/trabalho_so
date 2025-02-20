#include "kernel.h"

void setup() {
    Serial.begin(9600);
    setupPins();

    kernelInit();
    kernelAddTask(taskGreenLight);
    kernelAddTask(taskYellowLight);
    kernelAddTask(taskRedLight);
    kernelAddTask(taskPedestrianSensor);

    Serial.println("Semáforo Inteligente Iniciado");
    kernelRun();
}

void loop() {
    //
}