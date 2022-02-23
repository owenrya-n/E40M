const byte ANODE_PINS[8] = {6,7,8,9,10,11,12,13};
const byte CATHODE_PINS[8] = {A3,A2,A1,A0,5,4,3,2};

void setup() {
  // TODO: configure all anode (+) and cathode (-) wires to outputs
  // TODO: turn "off" all the LEDs
  // Hint: You did the same thing in everylight.ino.

  // Initialize serial communication
  // (to be read by Serial Monitor on your computer)
  Serial.begin(115200);
  Serial.setTimeout(100);
  for (byte i = 0; i < 8; i++) {
    pinMode(ANODE_PINS[i], OUTPUT);
    pinMode(CATHODE_PINS[i], OUTPUT);
    digitalWrite(ANODE_PINS[i], HIGH);
    digitalWrite(CATHODE_PINS[i], HIGH);
  }
}

/* Function: display
 * -----------------
 * Runs through one multiplexing cycle of the LEDs, controlling which LEDs are
 * on.
 *
 * During this function, LEDs that should be on will be turned on momentarily,
 * one row at a time. When this function returns, all the LEDs will be off
 * again, so it needs to be called continuously for LEDs to be on.
 */
void display(byte pattern[8][8]) {

  for (int i = 0; i<8; i++){
      for (int J = 0; J<8; J++){
        if(pattern[i][J]){
          digitalWrite(CATHODE_PINS[J], LOW);
          
        }else {
          digitalWrite(CATHODE_PINS[J], HIGH);
        }
    }        
    digitalWrite(ANODE_PINS[i], LOW);
    delayMicroseconds(300);
    digitalWrite(ANODE_PINS[i], HIGH);
  }
}

void loop() {
  // You shouldn't need to edit this function during lab 3a.

  // use 'static' so that it retains its value between successive calls of loop()
  static byte ledOn[8][8];

  byte x = 0;
  byte y = 0;
  static char message[60];

  if (Serial.available()) {
    // Parse the values from the serial string
    x = Serial.parseInt();
    y = Serial.parseInt();
    br = Serial.parseInt();

    // Check for input validity
    if (Serial.read() != '\n') {
      Serial.println("invalid input - check that line ending is set to \"Newline\"; input must be two numbers");
      return;
    }
    if (x < 0 || x > 7 || y < 0 || y > 7 || br  < 0 || br > 16) {
      sprintf(message, "x = %d, y = %d -- indices out of bounds", x, y);
      Serial.println(message);
      return;
    }

    // Print to Serial Monitor to give feedback about input
    sprintf(message, "x = %d, y = %d", x, y);
    Serial.println(message);

    // Toggle the LED state
    ledOn[x][y] = !ledOn[x][y];
  }

  // This function gets called every loop
  display(ledOn);
}
