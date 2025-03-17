#include <Wire.h>
#include <LiquidCrystal_I2C.h>


int lcdColumns = 16;
int lcdRows = 2;

const String valid_id = "1211553";
int trials = 2;

int redLed = 7; 
int greenLED = 8; 

int is_print=1;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

void setup() {
    Wire.begin(); 
    Serial.begin(9600); 
    Serial.print("master sleeping...");
    delay(2000);
    Serial.println("go");

    pinMode(redLed, OUTPUT); 
    pinMode(greenLED, OUTPUT); 
   
    lcd.init();
    
    lcd.backlight();
}

void loop() {
    Wire.requestFrom(50, 2); 
   
    lcd.setCursor(0, 0);

    if (Serial.available()) { 
      String receivedData = Serial.readString();
      receivedData.trim();

      if (receivedData == valid_id && trials > 0) {
        lcd.clear(); 
        lcd.print("YOU HAVE ACCESS");
        digitalWrite(greenLED,1);
        digitalWrite(redLed,0);
      } else if (trials>0){
        trials--; 
        lcd.clear();
        lcd.print("TRY AGAIN");
        digitalWrite(redLed,1);
        digitalWrite(greenLED,0);
      }
    }

    if (trials==0 && is_print){
      lcd.clear();
      digitalWrite(redLed,0);
      digitalWrite(greenLED,0);
      lcd.print("SYSTEM IS BLOCK");
      is_print=0;
    }


    
    byte res = Wire.read();                        
    if (res==1){
      lcd.clear();
      lcd.print("RESET");
      digitalWrite(redLed,0);
      digitalWrite(greenLED,0);
      trials = 2;
      is_print=1;

      delay(2000);
      lcd.clear();

    }
}



