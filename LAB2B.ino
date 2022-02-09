/*
E40M LAB 2B OWEN RYAN
*/

//initialization
int status = 0; //motion state tracker
int reg_speed = 100;
int hi_speed = 250;
void setup(){
    pinMode(2, OUTPUT); //motor control pin 2
    pinMode(3, OUTPUT); //motor control pin 1
    pinMode(4, INPUT); //limit switch pole
    pinMode(5, INPUT); //DPDT switch pole
}

//loop
void loop(){
    if(digitalRead(5) == 1){ //switch is on!!
        if(digitalRead(4) != 1){ //motor is at limit
            analogWrite(2, reg_speed); //forward
            digitalWrite(3, LOW);
            status = 1;
        }
        if(digitalRead(4) == 1){ //motor is not at limit
            analogWrite(2, hi_speed); //fast forward
            digitalWrite(3, LOW);
            status = 2;
        }
    }else if(digitalRead(5 == 0)){ //switch is off!!
        if(digitalRead(4) != 1){ //motor is at limit
            digitalWrite(3, LOW);//do nothing
            digitalWrite(2, LOW);
            status = 0;
        }
        if(digitalRead(4) == 1){ //motor is not at limit
            analogWrite(3, reg_speed);//backwards
            digitalWrite(2, LOW);
            status = -1;
        }
    }
    serial.println(status);
}