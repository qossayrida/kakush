int enA = 3;
int in1 = 6;
int in2 = 7;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 255); // Run motor at full speed
  delay(2000);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(2000);
}
