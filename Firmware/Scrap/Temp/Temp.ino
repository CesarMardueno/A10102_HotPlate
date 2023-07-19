#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define readtemp A0

int items = 2;


void setup() {
  lcd.init();

}

void loop() {
  switch(items){
    case 1: 
    Preheat();
    break;
    case 2:
    Add_Profile();
    break;
  }

}

void Preheat(){
  
}

int Add_Profile(){
  
}

int TempRead(){
  int lec = analogRead(readtemp);
  
}

int PID(){
  
}
