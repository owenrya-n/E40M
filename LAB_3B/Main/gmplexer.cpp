#include "gmplexer.h"

const byte ANODE_PINS[8] = {6, 7, 8, 9, 10, 11, 12, 13};
const byte CATHODE_PINS[8] = {A3, A2, A1, A0, 5, 4, 3, 2};

void display(int pos[2], int delay){
    digitalWrite(CATHODE_PINS[pos[0]], LOW);
    digitalWrite(ANODE_PINS[pos[1]], LOW);
    delayMicroseconds(delay);
    digitalWrite(CATHODE_PINS[pos[0]], HIGH);
    digitalWrite(ANODE_PINS[pos[1]], HIGH);
}

int iteratex(int x, int y, int xp, int yp, int t){ //should return x and ypos with time inc
    x=x+t*xp;
    //y=y+t*yp;
    return x;
}

int iteratey(int x, int y, int xp, int yp, int t){ //should return x and ypos with time inc
    //x=x+t*xp;
    y=y+t*yp;
    return y;
}

void draw_rebound(unsigned long freq, unsigned long timescale, int prev[2], int dy, int dx, int multiplier, int clock){
    if (millis() - freq >= timescale)
    {
        freq = millis();
        if (prev[0] >= 7 || prev[0] <= 0)
        {
            dx = -dx;
        }
        if (prev[1]>= 7 ||  prev[1] <= 0){
            dy=-dy;
        }
        prev[0] = iteratex(prev[0], prev[1], dx, dy, multiplier);
        prev[1] = iteratey(prev[0], prev[1], dx, dy, multiplier);
    }

    display(prev, clock);
}