#include <LiquidCrystal.h>
LiquidCrystal lcd(2,4,9,10,11,12);
int relay =   3;         // assigns pin 10 to variable pwm
int ir1 =     7;                    // assigns pin 7 to IR Sensor Front 1
int ir2 =     8;                    // assigns pin 8 to IR Sensor Front 2
int ir3 =     13;                   // assigns pin 13 to IR Sensor Motor
int count = 0;                     // variable for rotation count

void setup() 
{  
  lcd.begin(16, 2);
  pinMode(ir1, INPUT);           // declare IR- Packet as input
  pinMode(ir2, INPUT);           // declare IR- Packet as input
  pinMode(ir3, INPUT);           // declare IR-Motor as input
  pinMode(relay, OUTPUT);     // declares pin 3 as output
  lcd.print("     PROTO      ");
  delay(2000);
  lcd.clear();
  lcd.print("   INSPIRING    ");
  lcd.setCursor(0, 1);
  lcd.print("   TECHNOLOGY   ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SPEED: MAX ");
  lcd.setCursor(0, 1);
  lcd.print("COUNT: ");lcd.print(count);
}

void loop() 
{ 
  if( (digitalRead(ir1) == HIGH) && (digitalRead(ir2) == HIGH) )
  { 
      PrintMessage();      
      digitalWrite(relay, HIGH); 
      while(1)
      {
         if (digitalRead(ir3) == 1) break;
       }
 
      count++;
      digitalWrite(relay, LOW); 
      lcd.setCursor(0, 1);
      lcd.print("COUNT: ");lcd.print(count);  
     while( (digitalRead(ir1) == HIGH) && (digitalRead(ir2) == HIGH) )
     digitalWrite(relay, LOW); 
  }
}

void PrintMessage()
{
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SPEED: MAX");
  lcd.setCursor(0, 1);
  lcd.print("COUNT: ");lcd.print(count);  

}
