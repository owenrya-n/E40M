#ifndef RMPLEXER_H
#define RMPLEXER_H
#include <Arduino.h>

void blink(int row, int column, int delay);
void ramp(int dst, int row, int delay, const byte stsp[8]);
int ping(int echopin, int trigpin, int time);
#endif
