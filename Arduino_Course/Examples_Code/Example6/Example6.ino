#define buttonPin 2 

int state = 1;
const String valid_id = "1211553";
volatile int trials = 2; 


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
  if (Serial.available()) { 
    String receivedData = Serial.readString();
    receivedData.trim();

    if (receivedData == valid_id && trials > 0) { 
      Serial.println("1");
    } else {
      trials--; 
    }
  }
  if (digitalRead(buttonPin)==1){
      trials = 2;
      Serial.print("Trials: ");
      Serial.println(trials);
  }
}


