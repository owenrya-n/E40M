#include "init.h"
#include "rmplexer.h"
#define echoPin1 A5
#define echoPin2 1
#define trigPin1 A4
#define trigPin2 0
const byte ANODE_PINS[8] = {6, 7, 8, 9, 10, 11, 12, 13};
const byte CATHODE_PINS[8] = {A3, A2, A1, A0, 5, 4, 3, 2};
const byte settings[8] = {5, 7, 9, 11, 13, 15, 17, 19};
int d1;
int d2;

void setup()
{
    setPins();
}

void loop()
{
    d1 = ping(echoPin2, trigPin2, 2);
    d2 = ping(echoPin1, trigPin1, 2);
    ramp(d1, 0, 200, settings);
    ramp(d2, 7, 200, settings);
}
