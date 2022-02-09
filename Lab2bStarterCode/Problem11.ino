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

    if (digitalRead(2)== 1) Serial.println("S1 High")else 
    if (digitalRead(2)== 0 Serial.println("S1 low")
    if (digitalRead(3)== 1) Serial.println("S2 High")else 
    if (digitalRead(3)== 0) Serial.println("S2 low")
  }
}

