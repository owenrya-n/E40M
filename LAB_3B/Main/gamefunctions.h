#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H
#include <Arduino.h>

void showscore(int scorep1, int scorep2);
int contact(int x, int y, int dstp1, int dstp2, const byte stsp[7]);
void goalanimation(int player);
#endif
