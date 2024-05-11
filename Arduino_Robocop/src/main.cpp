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
int enA = 3;
int enB = 9;
Motors rightMotor = Motors();
Motors leftMotor = Motors();

void setup()
{
  Serial.begin(115200);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  BTSerial.begin(9600);
  rightMotor = Motors(go_right_wheel, back_right_wheel, enA, "right");
  leftMotor = Motors(go_left_wheel, back_left_wheel, enB, "left");
  //BTSerial.print("AT+NAME=Robocop\r\n"); // Set the name of the bluetooth module
}

void loop()
{
    if (BTSerial.available() > 0) {
      status = BTSerial.read();
      switch (status) {
        case 'f':
          rightMotor.horaire();
          leftMotor.anti_horaire();
          break;
        case 'b':
          rightMotor.anti_horaire();
          leftMotor.horaire();
          break;
        case 'r':
          rightMotor.stop();
          leftMotor.anti_horaire();
          break;
        case 'l':
          rightMotor.horaire();
          leftMotor.stop();
          break;
        case 's':
          rightMotor.stop();
          leftMotor.stop();
          break;
        case '1':
          rightMotor.accelerate();
          leftMotor.accelerate();
          break;
        case '2':
          rightMotor.decelerate();
          leftMotor.decelerate();
          break;
      }
    }
}
