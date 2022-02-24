#include "gamefunctions.h"

void showscore(int scorep1, int scorep2){

}

void newgame(int state){

}

int trackgoal(int posx){

}

void speedchange(){

}

int contact(int x, int y, int dstp1, int dstp2, const byte stsp[7]){ //return 1 if player 1 collides return 2 if player 2 collides return 3 for p1 goal return 4 for p2 goal
    int p1pos;
    int p2pos;
    for(int i=0; i<7; i++){
        if(dstp1==stsp[i] || dstp1+1==stsp[i]){
            p1pos=i;
        }
    }
     for(int j=0; j<7; j++){
        if(dstp2==stsp[j] || dstp2+1==stsp[j]){
            p2pos=j;
        }
    }
    if(p1pos==x && (y<=0)){
        return 1;
    }
    if(p2pos==x && (y>=7)){
        return 2;
    }
    if(p1pos!=x && (y<=0)){
        return 3;
    }
    if(p2pos!=x && (y>=7)){
        return 4;
    }
    
    
    else return 0;

}


const byte bounce(int x, int y, int xp, int yp, int p1, int p2, int t){

}