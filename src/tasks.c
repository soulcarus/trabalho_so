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

int taskTrafficLight(int state) {
    static unsigned long lastTime = 0;
    unsigned long now = millis();
    int timeLimit;
    if (state == 0) {  // Verde
        timeLimit = pedestrianRequest ? 2000 : 5000;
        if (now - lastTime < timeLimit) {
            digitalWrite(LED_GREEN, HIGH);
            digitalWrite(LED_YELLOW, LOW);
            digitalWrite(LED_RED, LOW);
            Serial.println("Semáforo: Verde");
            return 0;
        }
    } else if (state == 1) {
        timeLimit = 2000;
        if (now - lastTime < timeLimit) {
            digitalWrite(LED_GREEN, LOW);
            digitalWrite(LED_YELLOW, HIGH);
            digitalWrite(LED_RED, LOW);
            Serial.println("Semáforo: Amarelo");
            return 0;
        }
    } else {
        timeLimit = 5000;
        if (now - lastTime < timeLimit) {
            digitalWrite(LED_GREEN, LOW);
            digitalWrite(LED_YELLOW, LOW);
            digitalWrite(LED_RED, HIGH);
            Serial.println("Semáforo: Vermelho");
            return 0;
        }
    }
    lastTime = now;
    pedestrianRequest = 0;
    return 1;
}

int taskPedestrianSensor( int state) {
    if (digitalRead(BUTTON_PIN) == LOW) {
        pedestrianRequest = 1;
        Serial.println("Pedestre solicitou atravessar");
    }
    return 0;
}