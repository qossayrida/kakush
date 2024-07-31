#include <LiquidCrystal.h>

// Initialize the LCD with the numbers of the interface pins
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

// Define pin for the PIR sensor
const int pirPin = 10;

void setup() {
  // Set up the LCD's number of columns and rows
  lcd_1.begin(16, 2);
  
  // Initialize the PIR sensor pin
  pinMode(pirPin, INPUT);
  
  // Print a message to the LCD
  lcd_1.print("PIR Sensor:");
}

void loop() {
  // Read the state of the PIR sensor
  int pirState = digitalRead(pirPin);
  
  // Print the PIR sensor state on the LCD
  lcd_1.setCursor(0, 1);
  if (pirState == HIGH) {
    lcd_1.print("Motion detected");
  } else {
    lcd_1.print("No motion      "); // Clear previous reading
  }
  
  // Wait before the next reading
  delay(500);
}
