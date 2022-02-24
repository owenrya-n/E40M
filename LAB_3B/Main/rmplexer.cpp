#include "rmplexer.H"
//method composition of Display loop for the player controlled rows
const byte ANODE_PINS[8] = {6,7,8,9,10,11,12,13};
const byte CATHODE_PINS[8] = {A3,A2,A1,A0,5,4,3,2};
long duration1;
long duration2;
int distance1;
int distance2;
int echopin;
int trigpin;
int duration;
int distance;
void blink(int row, int column, int delay){ //turns on an LED for delay microseconds
        digitalWrite(CATHODE_PINS[row], LOW);
        digitalWrite(ANODE_PINS[column], LOW);
        if(row+1<=7)digitalWrite(CATHODE_PINS[row+1], LOW);
        if(row-1>=0)digitalWrite(CATHODE_PINS[row-1], LOW);
        delayMicroseconds(delay);
        digitalWrite(CATHODE_PINS[row], HIGH);
        digitalWrite(ANODE_PINS[column], HIGH);
        if(row+1<=7)digitalWrite(CATHODE_PINS[row+1], HIGH);
        if(row-1>=0)digitalWrite(CATHODE_PINS[row-1], HIGH);
}

void ramp(int dst, int row, int delay, const byte stsp[8]){
    for(int i=0; i<7; i++){
        if(dst==stsp[i]){
            blink(i, row, delay);
        }
    }
}

 int ping(int echopin, int trigpin, int time){
    digitalWrite(trigpin, HIGH);
    delayMicroseconds(time);
    digitalWrite(trigpin, LOW);
    duration = pulseIn(echopin, HIGH);
    distance = duration * 0.034 / 2;
    return distance;
}
