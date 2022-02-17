/*Owen Ryan E40M LAB2B*/
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
  int speed=random(0,1000);
  bool sl = false;
  Serial.println(sl);
  if(digitalRead(11)==LOW){//not at limit
    if(digitalRead(12)==LOW){//off
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
    }
    if(digitalRead(12)==HIGH && sl==false){//on
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      delay(1000);
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      while(digitalRead(12)==HIGH){ //captive loop for rebound
        Serial.println("hold");
                delay(10);
      }
    }
  }else if(digitalRead(11)==HIGH){//at limit
    if(digitalRead(12)==LOW){//off
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
    }
    if(digitalRead(12)==HIGH){//on
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

