#ifndef GMPLEXER_H
#define GMPLEXER_H
#include <Arduino.h>

void display(int pos[2], int delay);
int iteratey(int x, int y, int xp, int yp, int t);
int iteratex(int x, int y, int xp, int yp, int t);
void draw_rebound(unsigned long freq, unsigned long timescale, int* prev, int dy, int dx, int multiplier, int clock);
#endif
