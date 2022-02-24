#include "init.h"
#include "rmplexer.h"
#include "gmplexer.h"
#include "gamefunctions.h"
// does some stuff with the LEDs
#define echoPin1 A5
#define echoPin2 1
#define trigPin1 A4
#define trigPin2 0
const byte ANODE_PINS[8] = {6, 7, 8, 9, 10, 11, 12, 13};
const byte CATHODE_PINS[8] = {A3, A2, A1, A0, 5, 4, 3, 2};
const byte settings[8] = {5, 7, 9, 11, 13, 15, 17, 19};
int d1;
int d2;
int clock = 1000;
int prev[2] = {4, 1};
unsigned long timescale = 500UL;
unsigned long freq;
int multiplier = 1;
int dx = 1;
int dy = 1;
int timef=0;

void setup()
{
    setPins();
    delay(2000);
}

void loop()
{

    d1 = ping(echoPin2, trigPin2, 2);
    d2 = ping(echoPin1, trigPin1, 2);
    ramp(d1, 0, clock, settings);
    ramp(d2, 7, clock, settings);
    if (millis() - freq >= timescale-50*timef)
    {
        freq = millis();
        if (prev[0] >= 7 || prev[0] <= 0)
        {
            dx = -dx;
        }
        if (prev[1] >= 7 || prev[1] <= 0)
        {
            dy = -dy;
        }
        prev[0] = iteratex(prev[0], prev[1], dx, dy, multiplier);
        prev[1] = iteratey(prev[0], prev[1], dx, dy, multiplier);
    }

    if (contact(prev[0], prev[1], d1, d2, settings) == 3)
    {
        goalanimation(3);
        delay(1000);
        prev[1]=rand() %2 +3;
        prev[0]=rand() %7;
        dx=-dx;
        dy=-dy;
        timef++;
    }
    if (contact(prev[0], prev[1], d1, d2, settings) == 4)
    {
        goalanimation(4);
        delay(1000);
        prev[1]=rand() %2 +3;
        prev[0]=rand() %7;
        dx=-dx;
        dy=-dy;
        timef++;
    }

    display(prev, clock);
    delay(10);
}
