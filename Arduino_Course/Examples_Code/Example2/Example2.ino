int ledPin = 8; // Define digital pin 8 as the pin to control the LED
unsigned long previousMillis = 0; // Store the last time the LED was updated
const long interval = 1000; // Interval at which to blink (milliseconds)

void setup() {
    pinMode(ledPin, OUTPUT); // Set digital pin 8 as an output
}

void loop() {
    unsigned long currentMillis = millis(); // Get the current time

    // Check if it's time to blink the LED
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis; // Save the current time

        // If the LED is off, turn it on. Otherwise, turn it off.
        if (digitalRead(ledPin) == LOW) {
            digitalWrite(ledPin, HIGH); // Turn the LED on
        } else {
            digitalWrite(ledPin, LOW); // Turn the LED off
        }
    }
}
