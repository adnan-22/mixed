#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);    //RS E D4 D5 D6 D7
float roomTemp;
void setup() {
  lcd.begin(20,4);
  analogReference(INTERNAL);//INTERNAK 1.1v for the Vref of ADC
  lcd.setCursor(0,0);
  lcd.print("Ambient Temp:");
}

void loop() {
  roomTemp=(float)100*(1.1/1024)*analogRead(A5);//casting float
  lcd.setCursor(0,1);
  lcd.print(roomTemp,2);
  lcd.setCursor(6,1);
  lcd.print("deg C");
  delay(2000);
}
