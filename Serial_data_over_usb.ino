#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the library by creating an object of the LiquidCrystal_I2C class
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the I2C address of your LCD

String receivedText = ""; // Store received text

void setup() {
  // Initialize the LCD
  lcd.init();

  // Turn on the backlight
  lcd.backlight();

  // Initialize the serial communications
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();

    // Display each character as it is received
    lcd.setCursor(receivedText.length() % 16, 0); // Scroll text if it's longer than the LCD width
    lcd.print(c);

    // Append the character to the received text
    receivedText += c;

    // Check if Enter key is pressed and clear the screen
    if (c == '\r' || c == '\n') {
      lcd.clear();
      receivedText = "";
    }
  }
}
