 void setup() {
  //start serial connection
  Serial.begin(9600);
  pinMode(12, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP); //limitswitch
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

}
void loop() {
  int speed=random(0,1000);
  if (digitalRead(12) == LOW && digitalRead(11) == LOW) { //switch off and not at limit
    digitalWrite(2,HIGH); //backwards
    digitalWrite(3,LOW);
    Serial.println("BACKWARDS");
  } else if (digitalRead(12) == LOW && digitalRead(11) == HIGH){ //switch off and at limit
    digitalWrite(2,LOW); //nothing
    digitalWrite(3,LOW);
    Serial.println("STOP");
  } else if (digitalRead(12) == HIGH && digitalRead(11) == HIGH){ //switch on and at limit
    digitalWrite(2,LOW); //forwards
    digitalWrite(3,HIGH);
    Serial.println("FORWARDS");
  } else if (digitalRead(12) == HIGH && digitalRead(11) == LOW){ //switch on and not at limit
    digitalWrite(2,LOW); //fast forwards
    digitalWrite(3,HIGH);
    Serial.println("FORWARDS 2");
  }
  
}
