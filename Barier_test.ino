#include <Servo.h>

Servo myServo;  // Create a servo object

int angle = 0;  // Initial angle

void setup() {
  myServo.attach(4);  // Attach the servo to pin 4
}

void loop() {
  // Move the servo to 90 degrees
  for (angle = 0; angle <= 90; angle++) {
    myServo.write(angle);
    delay(15);  // Adjust the delay as needed
  }

 delay(500);
  // Move the servo back to 0 degrees
  for (angle =90; angle >= 0; angle--) {
    myServo.write(angle);
    delay(15);  // Adjust the delay as needed
  }

 
}
