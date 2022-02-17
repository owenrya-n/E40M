//Var Init
char text = 0;

//Initialization
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    text = Serial.read();
    Serial.println(text);
}
  if(text='f'){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
  }else if (text='r'){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
  }else if (text='s') {
    digitalWrite(2, LOW);
    digitalWrite(2, LOW);
  }
}