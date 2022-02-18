/* Starter code to blink every LED using the simplest possible iteration
 * through anode and cathode pins.
 *
 * ENGR 40M
 * July 2018
 */

// Define arrays for the anode (+) and cathode (-) wire pins.
// Your pins will probably be different.
// Remember that analog pins (A0, A1, ...) can also act as digital.
const byte ANODE_PINS[8] = {6,7,8,9,10,11,12,13};
const byte CATHODE_PINS[8] = {A3,A2,A1,A0,5,4,3,2};

void setup() {
  // In this function, you need to do two things:
  //  1. Configure all 8 anode (+) and all 8 cathode (-) pins to outputs
  //  2. Turn all 16 pins "off" (does this mean HIGH or LOW?)

  // Here's part 1, as an example (you can use this):
  for (byte i = 0; i < 8; i++) {
    pinMode(ANODE_PINS[i], OUTPUT);
    pinMode(CATHODE_PINS[i], OUTPUT);
    digitalWrite(ANODE_PINS[i], HIGH);
    digitalWrite(CATHODE_PINS[i], HIGH);
  }

  // TODO: Do part 2 (turn all 16 pins off).
  // (Hint: a 'for' loop to loop through the arrays above might help,
  //  or you could even add to the same loop above.)

}

void loop() {
  // TODO: In this function you need to write code that flashes each LED one by one.
  // Hint: Here's some suggested pseudocode:
  //   for each anode (+) wire
  //       activate anode (+) wire (does this mean HIGH or LOW?)
  //       for each cathode (-) wire
  //           activate cathode (-) wire (does this mean HIGH or LOW?)
  //           wait a bit
  //           deactivate cathode (-) wire
  //       end for
  //       deactivate anode (+) wire
  //   end for

    for (int i = 0; i<8; i++){
      digitalWrite(ANODE_PINS[i], LOW);
      for (int J = 0; J<8; J++){
        digitalWrite(CATHODE_PINS[J], LOW);
        delay(100);
        digitalWrite(CATHODE_PINS[J], HIGH);
    }
      digitalWrite(ANODE_PINS[i], HIGH);
  }
}
