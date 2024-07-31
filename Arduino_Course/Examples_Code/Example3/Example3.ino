const int Switch = 2, LED = 3;
int state = 0, LEDstate=0;


void setup(){
  pinMode(Switch, INPUT);
  pinMode(LED, OUTPUT);
}

void loop(){
  if (state == 0 && digitalRead(Switch) == HIGH) {
    state = 1;
    LEDstate=!LEDstate;
  }
  if (state == 1 && digitalRead(Switch) == LOW) {
    state = 0;
  }
  digitalWrite(LED, LEDstate);
}