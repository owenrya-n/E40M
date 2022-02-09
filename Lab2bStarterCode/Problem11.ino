/*
PROBLEM P11
 */
void setup() {
  Serial.begin(115200);
  Serial.println("Setup completed");
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop() {
  byte user_input = 0;

  if (Serial.available() > 0) {
    user_input = Serial.read();

    if (digitalRead(2)== HIGH) Serial.println("S1 High")else 
    if (digitalRead(2)== LOW Serial.println("S1 low")
    if (digitalRead(3)== HIGH) Serial.println("S2 High")else 
    if (digitalRead(3)== LOW) Serial.println("S2 low")
  }
}

