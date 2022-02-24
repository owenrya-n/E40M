#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H
#include <Arduino.h>

void showscore(int scorep1, int scorep2);
void newgame();
int trackgoal(int posx);
void speedchange();
int contact(int x, int y, int dstp1, int dstp2, const byte stsp[7]);
const byte bounce(int x, int y, int xp, int yp, int p1, int p2, int t);
#endif
