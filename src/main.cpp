#include <Arduino.h>

/*
 * Shape for led dice
 *
 *  1x      4x
 *  2x  7x  5x
 *  3x      6x
 *
 * */

/* Led-light ID */
const int pinOutLed1 = 13;
const int pinOutLed2 = 12;
const int pinOutLed3 = 11;
const int pinOutLed4 = 10;
const int pinOutLed5 = 9;
const int pinOutLed6 = 8;
const int pinOutLed7 = 7;

/* Speaker */
const int pinOutSpeaker = 7;

/* Tilt switch sensor */
const int pinInnSensor = 5;

/* Configuration for lighting dices */
int dice[6][7] = {
        {0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 1, 1},
        {1, 0, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 0},
};

void setup() {
    Serial.begin(9600);

    pinMode(pinOutLed1, OUTPUT);
    pinMode(pinOutLed2, OUTPUT);
    pinMode(pinOutLed3, OUTPUT);
    pinMode(pinOutLed4, OUTPUT);
    pinMode(pinOutLed5, OUTPUT);
    pinMode(pinOutLed6, OUTPUT);
    pinMode(pinOutLed7, OUTPUT);
    pinMode(pinOutSpeaker, OUTPUT);
    pinMode(pinInnSensor, INPUT);

}

void loop() {
    /* 1 == inactive
     * 0 == active */
    int stateSensor = digitalRead(pinInnSensor);

    if (stateSensor == 0) {
        digitalWrite(pinOutLed1, 1);
        digitalWrite(pinOutLed2, 1);
        digitalWrite(pinOutLed3, 1);
        digitalWrite(pinOutLed4, 1);
        digitalWrite(pinOutLed5, 1);
        digitalWrite(pinOutLed6, 1);
        digitalWrite(pinOutLed7, 1);
    } else {
        digitalWrite(pinOutLed1, 0);
        digitalWrite(pinOutLed2, 0);
        digitalWrite(pinOutLed3, 0);
        digitalWrite(pinOutLed4, 0);
        digitalWrite(pinOutLed5, 0);
        digitalWrite(pinOutLed6, 0);
        digitalWrite(pinOutLed7, 0);
    }

    Serial.print(stateSensor);
    Serial.print('\n');
    delay(100);
}

void sensorAndLedTest() {
    /* 1 == inactive
 * 0 == active */
    int stateSensor = digitalRead(pinInnSensor);

    if (stateSensor == 0) {
        digitalWrite(pinOutLed1, 1);
        digitalWrite(pinOutLed2, 1);
        digitalWrite(pinOutLed3, 1);
        digitalWrite(pinOutLed4, 1);
        digitalWrite(pinOutLed5, 1);
        digitalWrite(pinOutLed6, 1);
        digitalWrite(pinOutLed7, 1);
    } else {
        digitalWrite(pinOutLed1, 0);
        digitalWrite(pinOutLed2, 0);
        digitalWrite(pinOutLed3, 0);
        digitalWrite(pinOutLed4, 0);
        digitalWrite(pinOutLed5, 0);
        digitalWrite(pinOutLed6, 0);
        digitalWrite(pinOutLed7, 0);
    }

    Serial.print(stateSensor);
    Serial.print('\n');
    delay(100);
}