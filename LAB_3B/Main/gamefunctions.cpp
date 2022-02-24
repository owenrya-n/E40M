#include "gamefunctions.h"
const byte ANODE_PINS[8] = {6, 7, 8, 9, 10, 11, 12, 13};
const byte CATHODE_PINS[8] = {A3, A2, A1, A0, 5, 4, 3, 2};

void showscore(int scorep1, int scorep2)
{
}

void goalanimation(int player)
{
    if(player==4){
    for (int i = 0; i<8; i++){
      digitalWrite(ANODE_PINS[7], LOW);
      for (int J = 0; J<8; J++){
        digitalWrite(CATHODE_PINS[J], LOW);
        delay(10);
        digitalWrite(CATHODE_PINS[J], HIGH);
    }
      digitalWrite(ANODE_PINS[7], HIGH);
  }}
  if(player==3){
    for (int i = 0; i<8; i++){
      digitalWrite(ANODE_PINS[0], LOW);
      for (int J = 0; J<8; J++){
        digitalWrite(CATHODE_PINS[J], LOW);
        delay(10);
        digitalWrite(CATHODE_PINS[J], HIGH);
    }
      digitalWrite(ANODE_PINS[0], HIGH);
  }}

}

int contact(int x, int y, int dstp1, int dstp2, const byte stsp[7])
{ //return 1 if player 1 collides return 2 if player 2 collides return 3 for p1 goal return 4 for p2 goal
    int p1pos;
    int p2pos;
    for (int i = 0; i < 7; i++)
    {
        if (dstp1 == stsp[i] || dstp1 + 1 == stsp[i] || dstp1 - 1 == stsp[i])
        {
            p1pos = i;
        }
    }
    for (int j = 0; j < 7; j++)
    {
        if (dstp2 == stsp[j] || dstp2 + 1 == stsp[j] || dstp2 - 1 == stsp[j])
        {
            p2pos = j;
        }
    }
    if (p1pos == x && (y <= 0))
    {
        return 1;
    }
    if (p2pos == x && (y >= 7))
    {
        return 2;
    }
    if (!(p1pos==x || p1pos == x+1 || p1pos == x-1 || p1pos == x+2 || p1pos == x-2)&& (y <= 0))
    {
        return 3;
    }
    if (!(p2pos==x || p2pos == x+1 || p2pos == x-1 || p2pos == x+2 || p2pos == x-2) && (y >= 7))
    {
        return 4;
    }

    else
        return 0;
}
