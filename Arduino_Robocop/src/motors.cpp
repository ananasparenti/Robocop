#include <Arduino.h>
#include "motors.h"

Motors:: Motors() {} //constructeur vide pour dévier la société

//constructeur de la classe Motors, c'est super pratique d'ailleurs
Motors::Motors(int horaire, int anti_horaire, int enable, const char *motors) {
    Serial.println("Création moteurs.");
    pinMode(horaire, OUTPUT);
    pinMode(anti_horaire, OUTPUT);
    pinMode(enable, OUTPUT);
    this->motors = motors;
    this->enable = enable; // récupération des valeurs des pins enA et enB
    sens_horaire = horaire;
    sens_anti_horaire = anti_horaire;
    direction = STOP;
    //this->stop(); // par sécurité, on arrête les moteurs dés le début du programme, ça casse tout finalement
}

void Motors::SetSpeed() { // fonction pour régler la vitesse des moteurs
    int puissance = map(vitesse, 0, 9, 25, 255); // map permet de convertir une valeur d'un intervalle à un autre
    analogWrite(enable, puissance);
    Serial.print(this->motors);
    Serial.print(": puissance ");
    Serial.println(vitesse);
}

void Motors::decelerate() { // fonction pour ralentir les moteurs
    vitesse--;
    if (vitesse < 0) {
        vitesse = 0;
    }
    this->SetSpeed();
}

void Motors::accelerate() { // fonction pour accélérer les moteurs
    vitesse++;
    if (vitesse > 9) {
        vitesse = 9;
    }
    this->SetSpeed();
}

void Motors::stop() { // fonction pour arrêter les moteurs
    digitalWrite(sens_horaire, LOW);
    digitalWrite(sens_anti_horaire, LOW);
    direction = STOP;
    delay(100);
    Serial.print(this->motors);
    Serial.println(" STOP ");
}

void Motors::horaire() { // fonction pour faire tourner les moteurs dans le sens horaire
    if (direction == BACKWARD) {
        this->stop();
    }
    digitalWrite(sens_horaire, HIGH);
    digitalWrite(sens_anti_horaire, LOW);
    direction = FORWARD;
    Serial.print(this->motors);
    Serial.print(" FORWARD ");
    Serial.print(" vitesse :");
    Serial.println( vitesse);
}

void Motors::anti_horaire() { // fonction pour faire tourner les moteurs dans le sens anti-horaire
    if (direction == FORWARD) {
        this->stop();
    }
    digitalWrite(sens_horaire, LOW);
    digitalWrite(sens_anti_horaire, HIGH);
    direction = BACKWARD;
    Serial.print(this->motors);
    Serial.println(" BACKWARD ");
    Serial.print(" vitesse :");
    Serial.println( vitesse);
}
