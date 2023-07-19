#define en_clk 2
#define en_dt 3
#define en_sw 4

int rotval = 0;   //Contador de pulsos del encoder
bool clkstate = LOW;
bool clklast = HIGH;
bool swstate = HIGH;
bool swlast = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(en_clk,INPUT);
  pinMode(en_dt,INPUT);
  pinMode(en_sw,INPUT_PULLUP);
}

void loop() {
 readRotary();
 swRotary();

}

void readRotary(){
  clkstate = digitalRead(en_clk);
  if (clkstate != clklast){ //El Encoder se esta moviendo
    Serial.print("Rotary position ");
    if(digitalRead(en_dt) == HIGH){ //Si dt esta en alto mientras se 
      //mueve quiere decir que se mueve negativamente 
      rotval = rotval - 1;
      if(rotval < 0) rotval = 0;
    }
    else{
      rotval++;
      if(rotval > 10) rotval = 10;
    }
    Serial.println(rotval);
    delay(200);
  }
}

void swRotary(){
  swstate = digitalRead(en_sw);
  if(swstate != swlast){
    Serial.println("Rotary pressed");
    delay(100);
  }
  swlast=swstate;
}
