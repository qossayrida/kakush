const int potPin = A0;       // Potentiometer connected to analog pin A0
const int gameLEDPin = 2;    // Game LED connected to digital pin 2
const int reactionLEDPins[] = {3, 4, 5}; // Reaction time LEDs connected to digital pins 3, 4, and 5
const int buttonPin = 6;     // Button connected to digital pin 6

void setup() {
  pinMode(gameLEDPin, OUTPUT);
  for (int i = 0; i < 3; i++) {
    pinMode(reactionLEDPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the potentiometer value to set the delay (difficulty level)
  int potValue = analogRead(potPin);
  int delayTime = map(potValue, 0, 1023, 1000, 5000); // Delay between 1 and 5 seconds

  // Random delay before the LED lights up
  delay(random(1000, delayTime));

  // Turn on the game LED
  digitalWrite(gameLEDPin, HIGH);

  // Measure reaction time
  unsigned long startTime = millis();
  while (digitalRead(buttonPin) == LOW) {
    // Wait for the button press
  }
  unsigned long reactionTime = millis() - startTime;

  // Turn off the game LED
  digitalWrite(gameLEDPin, LOW);

  // Display reaction time
  if (reactionTime < 500) {
    // Fast reaction
    for (int i = 0; i < 3; i++) {
      digitalWrite(reactionLEDPins[i], HIGH);
    }
  } else if (reactionTime < 1000) {
    // Moderate reaction
    for (int i = 0; i < 2; i++) {
      digitalWrite(reactionLEDPins[i], HIGH);
    }
  } else {
    // Slow reaction
    digitalWrite(reactionLEDPins[0], HIGH);
  }

  // Wait for 3 seconds before resetting the game
  delay(3000);

  // Reset the reaction time LEDs
  for (int i = 0; i < 3; i++) {
    digitalWrite(reactionLEDPins[i], LOW);
  }

  // Small delay to avoid rapid resets
  delay(500);
}