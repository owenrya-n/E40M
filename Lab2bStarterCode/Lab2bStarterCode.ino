/*
PROBLEM P10
 */
void setup() {
  Serial.begin(115200);
  Serial.println("Setup completed");
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  byte user_input = 0;

  if (Serial.available() > 0) {
    user_input = Serial.read();

    if (digitalRead(2) == HIGH) {
      Serial.println("Forward");
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
    } else if (user_input == 'r') {
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
    } else if (user_input == 's') {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
    } else {
      Serial.println("Invalid character");
    }
  }
}
