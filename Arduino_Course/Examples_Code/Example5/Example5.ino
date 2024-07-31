const int buttonPin = 2; // Pin connected to the button
const int ledPin = 3;    // Pin connected to the LED

volatile int LEDstate = LOW; // Variable to store the LED state
volatile unsigned long lastDebounceTime = 0; // Variable to store the last debounce time
const unsigned long debounceDelay = 50; // Debounce time in milliseconds

void setup() {
    pinMode(buttonPin, INPUT); // Set the button pin as an input
    pinMode(ledPin, OUTPUT);   // Set the LED pin as an output

    // Attach the interrupt to the button pin, triggering on the rising edge
    attachInterrupt(digitalPinToInterrupt(buttonPin), toggleLED, RISING);
}

void loop() {
    
}

// Interrupt Service Routine (ISR) to toggle the LED state with debouncing
void toggleLED() {
    unsigned long currentTime = millis();
    if (currentTime - lastDebounceTime > debounceDelay) {
        LEDstate = !LEDstate; // Toggle the LED state
        lastDebounceTime = currentTime; // Update the last debounce time
      	digitalWrite(ledPin, LEDstate); // Update the LED state
    }
}
