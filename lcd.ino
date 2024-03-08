#include <LiquidCrystal.h>

// Create an LCD object
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

void setup() {
  // Set up the LCD columns and rows
  lcd.begin(16, 2);

  // Print "Hello, World!" on the LCD
  lcd.print("Hello, World!");
}

void loop() {
  // Nothing to do here
  
  delay(1000);
    lcd.clear();
   lcd.print("Star Map project");
   lcd.setCursor(0,1);
   lcd.print("Owais Froqi 1490");

}
