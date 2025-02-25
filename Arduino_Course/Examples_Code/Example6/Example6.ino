const int potPin = A0;     
const int ledPin = 9;        
const int button1Pin = 2;    

volatile bool ledState = false;
int potValue = 0;           
int brightness = 0;          

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(button1Pin, INPUT);

  attachInterrupt(digitalPinToInterrupt(button1Pin), toggleLED, RISING);
}

void loop() {
  
  potValue = analogRead(potPin);
  brightness = map(potValue, 0, 1023, 0, 255);

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
