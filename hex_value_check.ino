#include <IRremote.h>

const int IR_RECEIVER_PIN = A0;  // Change this to the pin where your IR receiver is connected

IRrecv irrecv(IR_RECEIVER_PIN);

decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();  // Start the IR receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Button Pressed: ");
    Serial.println(results.value, HEX);  // Print the hexadecimal value of the button
    irrecv.resume();  // Receive the next value
  }
}
