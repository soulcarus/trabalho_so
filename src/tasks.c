#include <Arduino.h>

#define LED_RED 11
#define LED_YELLOW 12
#define LED_GREEN 13
#define BUTTON_PIN 2

void setupPins() {
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

int pedestrianRequest = 0;

int taskGreenLight() {
    static unsigned long lastTime = 0;
    unsigned long now = millis();
    int baseTime = pedestrianRequest ? 2000 : 5000;

    if (now - lastTime < baseTime) {
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_RED, LOW);
        Serial.println("Semáforo: Verde");
        return 1;
    }
    lastTime = now;
    pedestrianRequest = 0;
    return 0;
}

int taskYellowLight() {
    static unsigned long lastTime = 0;
    unsigned long now = millis();
    if (now - lastTime < 2000) {
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_YELLOW, HIGH);
        digitalWrite(LED_RED, LOW);
        Serial.println("Semáforo: Amarelo");
        return 1;
    }
    lastTime = now;
    return 0;
}

int taskRedLight() {
    static unsigned long lastTime = 0;
    unsigned long now = millis();
    if (now - lastTime < 5000) {
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_RED, HIGH);
        Serial.println("Semáforo: Vermelho");
        return 1;
    }
    lastTime = now;
    return 0;
}

int taskPedestrianSensor() {
    if (digitalRead(BUTTON_PIN) == LOW) {
        pedestrianRequest = 1;
        Serial.println("Pedestre solicitou atravessar");
    }
    return 1;
}