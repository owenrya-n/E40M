#include "init.h"
// const declaration
#define echoPin1 A5
//#define echoPin2 1
#define trigPin1 A4
//#define trigPin2 0
const byte ANODE_PINS[8] = {6, 7, 8, 9, 10, 11, 12, 13};
const byte CATHODE_PINS[8] = {A3, A2, A1, A0, 5, 4, 3, 2};
long duration;
int distance;
void setup()
{
    // basic setup stuff mostly defined in init.h
    setPins();
    setBaud();
}

void display(byte pattern[8][8])
{
    // multiplexing function
    /*for (int i = 0; i < 8; i++)
   {
        digitalWrite(ANODE_PINS[i], LOW);
        for (int J = 0; J < 8; J++)
        {
            if (pattern[i][J])
            {
                digitalWrite(CATHODE_PINS[J], LOW);
            }
            else
            {
                digitalWrite(CATHODE_PINS[J], HIGH);
            
            }
        digitalWrite(ANODE_PINS[i], LOW);
        delayMicroseconds(100); // need to lower
        digitalWrite(ANODE_PINS[i], HIGH);
        }
        digitalWrite(ANODE_PINS[i], HIGH);
        
   }
}*/

for (int i = 0; i<8; i++){
      digitalWrite(ANODE_PINS[i], LOW);
      for (int J = 0; J<8; J++){
        digitalWrite(CATHODE_PINS[J], LOW);
        delay(100);
        digitalWrite(CATHODE_PINS[J], HIGH);
    }
      digitalWrite(ANODE_PINS[i], HIGH);
  }
  
}




void loop()
{
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);
    duration = pulseIn(echoPin1, HIGH);
    distance = duration * 0.034 / 2;

    //static byte ledOn[8][8];

    //byte x = 0;
    //byte y = 0;
    static char message[60];

    //y = 0;
    
    if(distance<3){//0
        digitalWrite(CATHODE_PINS[0], LOW);
        digitalWrite(ANODE_PINS[0], LOW);
        delayMicroseconds(100);
        Serial.println("true");
        digitalWrite(CATHODE_PINS[0], HIGH);
        digitalWrite(ANODE_PINS[0], HIGH);
    }else if(distance<6){//1
        digitalWrite(CATHODE_PINS[0], LOW);
        digitalWrite(ANODE_PINS[1], LOW);
        delayMicroseconds(100);
        Serial.println("true");
        digitalWrite(CATHODE_PINS[0], HIGH);
        digitalWrite(ANODE_PINS[1], HIGH);
    }else if(distance<9){//2
        digitalWrite(CATHODE_PINS[0], LOW);
        digitalWrite(ANODE_PINS[2], LOW);
        delayMicroseconds(100);
        Serial.println("true");
        digitalWrite(CATHODE_PINS[0], HIGH);
        digitalWrite(ANODE_PINS[2], HIGH);
    }else if(distance<12){//3
        digitalWrite(CATHODE_PINS[0], LOW);
        digitalWrite(ANODE_PINS[3], LOW);
        delayMicroseconds(100);
        Serial.println("true");
        digitalWrite(CATHODE_PINS[0], HIGH);
        digitalWrite(ANODE_PINS[3], HIGH);
    }else if(distance<15){//4
        digitalWrite(CATHODE_PINS[0], LOW);
        digitalWrite(ANODE_PINS[4], LOW);
        delayMicroseconds(100);
        Serial.println("true");
        digitalWrite(CATHODE_PINS[0], HIGH);
        digitalWrite(ANODE_PINS[4], HIGH);
    }else if(distance<18){//5
        digitalWrite(CATHODE_PINS[0], LOW);
        digitalWrite(ANODE_PINS[5], LOW);
        delayMicroseconds(100);
        Serial.println("true");
        digitalWrite(CATHODE_PINS[0], HIGH);
        digitalWrite(ANODE_PINS[5], HIGH);
    }else if(distance<21){//6
        digitalWrite(CATHODE_PINS[0], LOW);
        digitalWrite(ANODE_PINS[6], LOW);
        delayMicroseconds(100);
        Serial.println("true");
        digitalWrite(CATHODE_PINS[0], HIGH);
        digitalWrite(ANODE_PINS[6], HIGH);
    }else if(distance<24){//7
        digitalWrite(CATHODE_PINS[0], LOW);
        digitalWrite(ANODE_PINS[7], LOW);
        delayMicroseconds(100);
        Serial.println("true");
        digitalWrite(CATHODE_PINS[0], HIGH);
        digitalWrite(ANODE_PINS[7], HIGH);
    }
    
    //Serial.println(distance);
    
    //ledOn[x][y] = !ledOn[x][y];
    //display(ledOn); 
    
    
    
    

    

    // Toggle the LED state
    

    // This function gets called every loop

    
    
}

// digitalWrite(trigPin, LOW);
// delayMicroseconds(2);
//  Sets the trigPin HIGH (ACTIVE) for 10 microseconds
// digitalWrite(trigPin, HIGH);
// delayMicroseconds(10);
// digitalWrite(trigPin, LOW);
// duration = pulseIn(echoPin, HIGH);
// distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
//  Displays the distance on the Serial Monitor
// Serial.print("Distance: ");

// Serial.println(" cm");