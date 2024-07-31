const int potPin = A0;       // Potentiometer connected to analog pin A0
const int ledPin = 9;        // LED connected to digital pin 9 (PWM capable)
const int button1Pin = 2;    // Button 1 connected to digital pin 2 (interrupt capable)
const int button2Pin = 3;    // Button 2 connected to digital pin 3 (interrupt capable)

volatile bool ledState = false;
volatile bool resetBrightness = false;
int potValue = 0;            // Variable to store the potentiometer value
int brightness = 0;          // Variable to store the LED brightness

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);

  attachInterrupt(digitalPinToInterrupt(button1Pin), toggleLED, RISING);
  attachInterrupt(digitalPinToInterrupt(button2Pin), resetLED, RISING);
}

void loop() {
  if (resetBrightness) {
    brightness = 128;  // Default brightness
  } else {
    potValue = analogRead(potPin);
    brightness = map(potValue, 0, 1023, 0, 255);
  }

  if (ledState) {
    analogWrite(ledPin, brightness);
  } else {
    analogWrite(ledPin, 0);
  }

  delay(10); // Small delay to avoid rapid changes
}

void toggleLED() {
  ledState = !ledState;
}

void resetLED() {
  resetBrightness = !resetBrightness;
}
