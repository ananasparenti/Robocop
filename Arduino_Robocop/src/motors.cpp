#include <Arduino.h>
#include "motors.h"

Motors::Motors(int horaire, int anti_horaire, int enable) { //constructor of the class
    pinMode(horaire, OUTPUT);
    pinMode(anti_horaire, OUTPUT);
    pinMode(enable, OUTPUT);
    this->enable = enable; // récupération des valeurs des pins, cella là pour ma classe
    sens_horaire = horaire;
    sens_anti_horaire = anti_horaire;
    direction = STOP;
    this->stop(); // par sécurité, on arrête les moteurs dés le début du programme
}

void Motors::SetSpeed(int speed) {
    int puissance = map(speed, 0, 9, 25, 255); // map permet de convertir une valeur d'un intervalle à un autre
    analogWrite(enable, puissance);
}

void Motors::decelerate() {
    vitesse--;
    if (vitesse < 0) {
        vitesse = 0;
    }
    this->SetSpeed(vitesse);
}

void Motors::accelerate() {
    vitesse++;
    if (vitesse > 9) {
        vitesse = 9;
    }
    this->SetSpeed(vitesse);
}

void Motors::stop() {
    digitalWrite(sens_horaire, LOW);
    digitalWrite(sens_anti_horaire, LOW);
    direction = STOP;
    delay(100);
}

void Motors::horaire() {
    if (direction == BACKWARD) {
        this->stop();
    }
    digitalWrite(sens_horaire, HIGH);
    digitalWrite(sens_anti_horaire, LOW);
    direction = FORWARD;
}

void Motors::anti_horaire() {
    if (direction == FORWARD) {
        this->stop();
    }
    digitalWrite(sens_horaire, LOW);
    digitalWrite(sens_anti_horaire, HIGH);
    direction = BACKWARD;
}
