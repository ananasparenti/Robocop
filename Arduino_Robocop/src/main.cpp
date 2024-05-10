#include <Arduino.h>
#include <SoftwareSerial.h>
#include "motors.h"

const byte rxPin = 7;
const byte txPin = 6;
SoftwareSerial BTSerial = SoftwareSerial (rxPin, txPin);
char status;

int go_right_wheel = 10;
int back_right_wheel = 11;
int go_left_wheel = 12;
int back_left_wheel = 13;
int enA = 8;
int enB = 9;
Motors rightMotor = Motors(go_right_wheel, back_right_wheel, enA);
Motors leftMotor = Motors(go_left_wheel, back_left_wheel, enB);

void setup()
{
  Serial.begin(115200);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  BTSerial.begin(9600);
  BTSerial.print("AT+NAME=Robocop\r\n"); // Set the name of the bluetooth module
}

void loop()
{
    if (BTSerial.available() > 0) {
      status = BTSerial.read();
      switch (status) {
        case 'f':
          Serial.println("avant");
          rightMotor.horaire();
          leftMotor.anti_horaire();
          break;
        case 'b':
          Serial.println("arriere");
          rightMotor.anti_horaire();
          leftMotor.horaire();
          break;
        case 'r':
          Serial.println("droite");
          rightMotor.stop();
          leftMotor.anti_horaire();
          break;
        case 'l':
          Serial.println("gauche");
          rightMotor.horaire();
          leftMotor.stop();
          break;
        case 's':
          Serial.println("stop");
          rightMotor.stop();
          leftMotor.stop();
          break;
        case '1':
          Serial.println("accelerer");
          rightMotor.accelerate();
          leftMotor.accelerate();
          break;
        case '2':
          Serial.println("decelerer");
          rightMotor.decelerate();
          leftMotor.decelerate();
          break;
      }
    }
}
