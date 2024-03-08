#include <IRremote.h>

#define IR_PIN 11
#define LED_PIN 13

IRrecv irrecv(IR_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned long key_value = results.value;

    // Uncomment the next line to print the received IR code to the Serial Monitor
    // Serial.println(key_value, HEX);

    // Example actions for specific buttons
    switch (key_value) {
      case 0xFFA25D: // Button 1
        digitalWrite(LED_PIN, HIGH);
        break;

      case 0xFF629D: // Button 2
        digitalWrite(LED_PIN, LOW);
        break;

      // Add more cases for other buttons and actions

      default:
        // No action for other buttons
        break;
    }

    irrecv.resume();  // Receive the next value
  }
}
