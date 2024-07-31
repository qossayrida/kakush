
#include <LiquidCrystal.h>

// Initialize the LCD with the numbers of the interface pins
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

// Define pins for the ultrasonic sensor
const int trigPin = 10;
const int echoPin = 9;

void setup() {
  // Set up the LCD's number of columns and rows
  lcd_1.begin(16, 2);
  
  // Initialize the sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Print a message to the LCD
  lcd_1.print("Distance: ");
}

void loop() {
  // Send a pulse to the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the pulse from the sensor
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  float distance = duration * 0.034 / 2;
  
  // Print the distance on the LCD
  lcd_1.setCursor(0, 1);
  lcd_1.print("                "); // Clear previous reading
  lcd_1.setCursor(0, 1);
  lcd_1.print(distance);
  lcd_1.print(" cm");
  
  // Wait before the next reading
  delay(500);
}
