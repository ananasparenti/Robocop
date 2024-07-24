#include <Arduino.h>
#include <SoftwareSerial.h>
#include "motors.h"

//déclaration des pins pour le module bluetooth
const byte rxPin = 7;
const byte txPin = 6;
SoftwareSerial BTSerial = SoftwareSerial (rxPin, txPin);
char status;

//déclaration des pins pour les leds RGB
const int ledR = 5;
const int ledG = 10;
const int ledB = 11;

//déclaration des pins pour les moteurs
int go_right_wheel = 4;
int back_right_wheel = 2;
int go_left_wheel = 12;
int back_left_wheel = 13;
int enA = 3;
int enB = 9;
Motors rightMotor = Motors();
Motors leftMotor = Motors();

void setup() //fonction de configuration principale
{
  Serial.begin(115200);
  
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  BTSerial.begin(9600);
  
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);

  rightMotor = Motors(go_right_wheel, back_right_wheel, enA, "right");
  leftMotor = Motors(go_left_wheel, back_left_wheel, enB, "left");
}

void loop() //fonction principale
{
    if (BTSerial.available() > 0) {
      status = BTSerial.read();
      Serial.print("Recieved: ");
      Serial.println(status);
      switch (status) {
        case 'f': //avancer
          analogWrite(ledR, 0);
          analogWrite(ledG, 255);
          analogWrite(ledB, 0);
          rightMotor.horaire();
          leftMotor.anti_horaire();
          break;
        case 'b': //reculer
          analogWrite(ledR, 255);
          analogWrite(ledG, 0);
          analogWrite(ledB, 0);
          rightMotor.anti_horaire();
          leftMotor.horaire();
          break;
        case 'r': //tourner à droite
          analogWrite(ledR, 255);
          analogWrite(ledG, 0);
          analogWrite(ledB, 255);
          rightMotor.stop();
          leftMotor.anti_horaire();
          break;
        case 'l': //tourner à gauche
          analogWrite(ledR, 255);
          analogWrite(ledG, 0);
          analogWrite(ledB, 255);
          rightMotor.horaire();
          leftMotor.stop();
          break;
        case 's': //arrêter le robot
          analogWrite(ledR, 0);
          analogWrite(ledG, 0);
          analogWrite(ledB, 0);
          rightMotor.stop();
          leftMotor.stop();
          break;
        case '1': //accélérer
          rightMotor.accelerate();
          leftMotor.accelerate();
          break;
        case '2': //décélérer
          rightMotor.decelerate();
          leftMotor.decelerate();
          break;
      }
    }
}

//faire attention aux sens de rotation des moteurs, 