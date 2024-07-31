#include <LiquidCrystal.h>

// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2); 
  
  lcd.setCursor(0, 0);
  lcd.print("Qossay Abu Rida");
}

void loop(){
}