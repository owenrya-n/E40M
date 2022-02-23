#include "init.h"
#include "rmplexer.h"
#include "gmplexer.h"
#include "gamefunctions.h"
// does some stuff with the LEDs
#define echoPin1 A5
//#define echoPin2 1
#define trigPin1 A4
//#define trigPin2 0
const byte ANODE_PINS[8] = {6, 7, 8, 9, 10, 11, 12, 13};
const byte CATHODE_PINS[8] = {A3, A2, A1, A0, 5, 4, 3, 2};
const byte settings[8] = {5, 7, 9, 11, 13, 15, 17, 19};
int d1;
int d2;
int clock = 200;
int prev[2] = {4, 1};
unsigned long timescale = 400UL;
unsigned long freq;
int multiplier = 1;
int dx = 1;
int dy = 1;

void setup()
{
    setPins();
    setBaud();
}

void loop()
{

    // d1 = ping(echoPin2, trigPin2, 2);
    d2 = ping(echoPin1, trigPin1, 2);
    // ramp(d1, 0, clock, settings);
    // ramp(d2, 7, clock, settings);
    // Serial.println(prev[0]);
    // Serial.println(iteratex(0, 0, 1, 1, timescale));
    if (millis() - freq >= timescale)
    {
        freq = millis();
        if (prev[0] >= 7)
        {
            dx = -dx;
        }
        prev[0] = iteratex(prev[0], prev[1], dx, dy, multiplier);
        prev[1] = iteratey(prev[0], prev[1], dx, dy, multiplier);
    }

    display(prev, clock);
    delay(10);
    // Serial.println(prev_rnd[0]);
    Serial.println(prev[0]);
}
