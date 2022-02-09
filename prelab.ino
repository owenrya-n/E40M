void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);   
  digitalWrite(3, LOW);   

  digitalWrite(LED_BUILTIN, HIGH);
  delay(14);
  digitalWrite(LED_BUILTIN, LOW);
  delay(14);

}