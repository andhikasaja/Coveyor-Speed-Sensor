#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7); // 0x27 = alamat I2C modul

//LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int sensor = 11;
unsigned long start_time = 0;
unsigned long end_time = 0;
int steps=0;
float steps_old=0;
float temp=0;
float rpm=0;

void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(sensor,INPUT_PULLUP);
  lcd.setCursor(0,0);
  lcd.print(" STEPS - 0");
  lcd.setCursor(0,1);
} 
void loop() {
 start_time=millis();
 end_time=start_time+1000;
 while(millis()<end_time)
 {
   if(digitalRead(sensor))
   {
    steps=steps+1; 
    while(digitalRead(sensor));
   }
   lcd.setCursor(9,0);
   lcd.print(steps);
   lcd.print("   ");
 }
    temp=steps-steps_old;
    steps_old=steps;
    rpm=(temp/20);
    lcd.setCursor(9,1);
    lcd.print(rpm);
    lcd.print("   ");

if( rpm < 60) {
  
    lcd.setCursor(0,0);
    lcd.print("Beban Konveyor Terlalu Berat!");
  }
}
