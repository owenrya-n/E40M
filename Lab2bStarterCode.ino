/*Owen Ryan E40M LAB2B*/
/*
Trick  1: Hesitant Box: Finger pauses for one second before resetting switch if switch is flipped before finger returns to resting position
Trick 2: Slow Box: Finger slowly returns to switch if switch is flipped before finger returns to resting position
*/
void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(12, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP); //limitswitch
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}
void loop() {
  int choice=random(0,10);
  bool sl = false;s
  Serial.println(sl);
  if(digitalRead(11)==LOW){//not at limit
    if(digitalRead(12)==LOW){//off & backwards
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
    }
    if(digitalRead(12)==HIGH && sl==false){//on & forwards
    if(choice >= 5){ //Hesitant box activated
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      delay(1000);}
      digitalWrite(2,LOW);
      if(choice >= 5) digitalWrite(3,HIGH); 
      if(choice << 5) analogWrite(3, 110); //Slow Box Activated
      while(digitalRead(12)==HIGH){ //captive loop for rebound
        Serial.println("hold");
                delay(10);
      }
    }
  }else if(digitalRead(11)==HIGH){//at limit 
    if(digitalRead(12)==LOW){//off & stopped
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
    }
    if(digitalRead(12)==HIGH){//on & forwards
      sl = true;
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      while(digitalRead(12)==HIGH){ //captive loop for slow
        Serial.println("hold");
                delay(10);
      }
       sl = false;
    }
  }
}

