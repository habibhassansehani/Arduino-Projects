#include <LiquidCrystal.h>

// Define the LCD screen
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

void setup() {
  // Set up the number of columns and rows on the LCD
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  // Clear the LCD screen
  lcd.clear();

  // Print "Hello" on the first row
  lcd.setCursor(0, 0);
  lcd.print("Hello");

  // Print "World" on the second row
  lcd.setCursor(0, 1);
  lcd.print("World");

  // Wait for a moment (you can adjust the delay time)
  delay(2000);
}
