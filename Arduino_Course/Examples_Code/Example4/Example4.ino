const int buttonPin = 2; // Pin connected to the button
const int ledPin = 3;    // Pin connected to the LED

volatile int LEDstate = LOW; // Variable to store the LED state

void setup() {
    pinMode(buttonPin, INPUT); // Set the button pin as an input
    pinMode(ledPin, OUTPUT);   // Set the LED pin as an output

    // Attach the interrupt to the button pin, triggering on the rising edge
    attachInterrupt(digitalPinToInterrupt(buttonPin), toggleLED, RISING);
}

void loop() {
    
}

// Interrupt Service Routine (ISR) to toggle the LED state
void toggleLED() {
    LEDstate = !LEDstate; // Toggle the LED state
    digitalWrite(ledPin, LEDstate); // Update the LED state
}
