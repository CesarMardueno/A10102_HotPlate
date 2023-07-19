#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define en_clk 2
#define en_dt 3
#define en_sw 4

int items = 3;
int rotval = 1;   //Contador de pulsos del encoder
bool clkstate = LOW;
bool clklast = HIGH;
bool swstate = HIGH;
bool swlast = HIGH;
bool btn = false;



void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(en_clk,INPUT);
  pinMode(en_dt,INPUT);
  pinMode(en_sw,INPUT_PULLUP);

}

void loop() {
  readRotary();
  swRotary();
  switch(rotval){
    case 1: 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("preheat");
    lcd.setCursor(0,1);
    lcd.print("Soldado");
    delay(100);
    if(btn==true) Preheat(); 
    break;
    case 2:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Soldado");
    lcd.setCursor(0,1);
    lcd.print("Retrabajo");
    delay(100);
    if(btn==true) Soldado(); 
    break;
    case 3:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Retrabajo");
    lcd.setCursor(0,1);
    lcd.print("Preheat");
    delay(100);
    if(btn==true) Retrabajo(); 
    break;
  }

}

int readRotary(){
  clkstate = digitalRead(en_clk);
  if (clkstate != clklast){ //El Encoder se esta moviendo
    Serial.print("Rotary position ");
    if(digitalRead(en_dt) == HIGH){ //Si dt esta en alto mientras se 
      //mueve quiere decir que se mueve negativamente 
      rotval = rotval - 1;
      if(rotval < 1) rotval = 1;
    }
    else{
      rotval++;
      if(rotval > items) rotval = items;
    }
    Serial.println(rotval);
    delay(100);
    return rotval;    
  }
}

void Preheat(){
  lcd.clear();
  lcd.print("on Preheat");
  delay(1000);
  lcd.clear();
}

int Soldado(){
  lcd.clear();
  lcd.print("on Soldado");
  delay(1000);
  lcd.clear();  
}
int Retrabajo(){
  lcd.clear();
  lcd.print("on Retrabajo");
  delay(1000);
  lcd.clear();  
}

int swRotary(){
  swstate = digitalRead(en_sw);
  if(swstate != swlast){
    Serial.println("Rotary pressed");
    btn=true;
    delay(100);
    return btn;
  }
  swlast=swstate;
  btn=false;
  return btn;
}
