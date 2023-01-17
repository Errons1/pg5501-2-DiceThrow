#include <Arduino.h>
#include "pitches.h"

/*
 * Shape for led dice
 *
 *  1x      4x
 *  2x  7x  5x
 *  3x      6x
 *
 * */

/* Led-light ID */
int pinOutLed1 = 13;
int pinOutLed2 = 12;
int pinOutLed3 = 11;
int pinOutLed4 = 10;
int pinOutLed5 = 9;
int pinOutLed6 = 8;
int pinOutLed7 = 7;

/* Speaker */
const int pinOutSpeaker = 3;

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

int melody[] = {
        NOTE_G3, NOTE_A3, NOTE_B3, NOTE_CS3,
        NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C3,
        NOTE_GS3, NOTE_AS3, NOTE_C4, NOTE_D4,
        NOTE_A3, NOTE_B3, NOTE_C4, NOTE_D4,

        NOTE_A3, NOTE_B3, NOTE_CS4, NOTE_DS4,
        NOTE_A3, NOTE_B3, NOTE_C4, NOTE_D4,
        NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_E4,
        NOTE_B3, NOTE_C4, NOTE_D4, NOTE_E4,

        NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_F4,
        NOTE_C4, NOTE_D4, NOTE_E4, NOTE_FS4,
        NOTE_CS4, NOTE_DS4, NOTE_F4, NOTE_G4,
        NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_GS4,

        BREAK, BREAK,
        NOTE_A3, NOTE_AS3, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
        4, 4, 4, 4,
        4, 4, 4, 4,
        4, 4, 4, 4,
        4, 4, 4, 4,

        5, 5, 5, 5,
        5, 5, 5, 5,
        5, 5, 5, 5,
        5, 5, 5, 5,

        6, 6, 6, 6,
        6, 6, 6, 6,
        6, 6, 6, 6,
        6, 6, 6, 6,

        2, 2,
        2, 2, 2, 1
};


void showDice(long number);

void hideDice();

void sensorAndLedTest();

void numberTest();

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

//    sensorAndLedTest();
//    numberTest();

    if (stateSensor == 0) {
        for (int thisNote = 0; thisNote < 54; thisNote++) {
            hideDice();
            int noteDuration = 600 / noteDurations[thisNote];

            long number = random(0, 6);
            showDice(number);
            Serial.print('\n');
            Serial.print(number);
            Serial.print('\n');

            tone(3, melody[thisNote], noteDuration);

            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);
            noTone(3);
        }

        hideDice();
        long number = random(0, 6);
        showDice(number);
    }

}

void showDice(long number) {
    for (int i = 0; i < 7; ++i) {
        if (dice[number][i] == 1) {
            Serial.print(i);
            switch (i) {
                case 0:
                    digitalWrite(pinOutLed1, 1);
                    break;
                case 1:
                    digitalWrite(pinOutLed2, 1);
                    break;
                case 2:
                    digitalWrite(pinOutLed3, 1);
                    break;
                case 3:
                    digitalWrite(pinOutLed4, 1);
                    break;
                case 4:
                    digitalWrite(pinOutLed5, 1);
                    break;
                case 5:
                    digitalWrite(pinOutLed6, 1);
                    break;
                case 6:
                    digitalWrite(pinOutLed7, 1);
                    break;
            }
        }
    }
}

void hideDice() {
    digitalWrite(pinOutLed1, 0);
    digitalWrite(pinOutLed2, 0);
    digitalWrite(pinOutLed3, 0);
    digitalWrite(pinOutLed4, 0);
    digitalWrite(pinOutLed5, 0);
    digitalWrite(pinOutLed6, 0);
    digitalWrite(pinOutLed7, 0);
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

void numberTest() {
    for (int number = 0; number < 6; ++number) {
        for (int i = 0; i < 7; ++i) {
            if (dice[number][i] == 1) {
                Serial.print(i);
                switch (i) {
                    case 0:
                        digitalWrite(pinOutLed1, 1);
                        break;
                    case 1:
                        digitalWrite(pinOutLed2, 1);
                        break;
                    case 2:
                        digitalWrite(pinOutLed3, 1);
                        break;
                    case 3:
                        digitalWrite(pinOutLed4, 1);
                        break;
                    case 4:
                        digitalWrite(pinOutLed5, 1);
                        break;
                    case 5:
                        digitalWrite(pinOutLed6, 1);
                        break;
                    case 6:
                        digitalWrite(pinOutLed7, 1);
                        break;
                }
            }
        }
        delay(1000);
        hideDice();
        delay(1000);
    }
}

