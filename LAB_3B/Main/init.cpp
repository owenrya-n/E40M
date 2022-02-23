#include "init.h"
//basic initialization stuff
#define echoPin1 A5
#define echoPin2 1
#define trigPin1 A4
#define trigPin2 0
const byte ANODE_PINS[8] = {6, 7, 8, 9, 10, 11, 12, 13};
const byte CATHODE_PINS[8] = {A3, A2, A1, A0, 5, 4, 3, 2};

void setPins()
{
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  for (byte i = 0; i < 8; i++)
  {
    pinMode(ANODE_PINS[i], OUTPUT);
    pinMode(CATHODE_PINS[i], OUTPUT);
    digitalWrite(ANODE_PINS[i], HIGH);
    digitalWrite(CATHODE_PINS[i], HIGH);
  }
}

void setBaud()
{
  Serial.begin(115200);
  Serial.setTimeout(100);
}