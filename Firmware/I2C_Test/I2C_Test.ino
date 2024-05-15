#include <Wire.h>
 
 
void setup()
{
  Wire.begin();
 
  /*Serial.begin(9600);
  while (!Serial);             // Leonardo: wait for serial monitor
  Serial.println("\nI2C Scanner");*/
}
 
 
void loop()
{
  Wire.beginTransmission(0x27);
  Wire.write(0xFF);
  Wire.endTransmission();
  delay(2000);
  Wire.beginTransmission(0x27);
  Wire.write(0x00);
  Wire.endTransmission();
  delay(2000);
}
