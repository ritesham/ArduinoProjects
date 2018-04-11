/*****************************************************************************
* Copyright (C) 2016 by Rapidcode Technologies Pvt Ltd.. All Rights Reserved.*
*                                                                            *
* This program is free software: you can redistribute it and/or modify       *
* it under the terms of the GNU General Public License as published by       *
* the Free Software Foundation, either version 3 of the License, or          *
* (at your option) any later version.                                        *
*                                                                            *
* This program is distributed in the hope that it will be useful,            *
* but WITHOUT ANY WARRANTY; without even the implied warranty of             *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the               *
* GNU General Public License for more details.                               *
*                                                                            *
* You should have received a copy of the GNU General Public License          *
* along with this program. If not, see <http://www.gnu.org/licenses/>.       *
*                                                                            *
*  Author:        Ritesham Shastry                                           *
*  Contact:       http://www.rapidcode.co.in      
*  Date modified: 28 Dec 2016
*****************************************************************************/
 
#include <LiquidCrystal.h> // include the LCD library
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int count = 0;
int potPin = A0; //Potentiometer input pin
int potValue1 = 0;
int potValue2 = 0; // final display variable
int relay =   13;  
int ir1 =     6;                    // assigns pin 7 to IR Sensor Front 1
int ir2 =     7;                    // assigns pin 8 to IR Sensor Front 2
int ir3 =     8;                   // assigns pin 13 to IR Sensor Motor
int motor =   9;                    //motor with PWM
void setup()
{
  lcd.begin(16, 2); // lcd rows and columns
  pinMode(ir1, INPUT);           // declare IR- Packet as input
  pinMode(ir2, INPUT);           // declare IR- Packet as input
  pinMode(ir3, INPUT);           // declare IR-Motor as input
  pinMode(relay, OUTPUT);
  pinMode(motor, OUTPUT);
  lcd.print("     PROTO      ");
  delay(500);
  lcd.clear();
  lcd.print("   INSPIRING    ");
  lcd.setCursor(0, 1);
  lcd.print("   TECHNOLOGY   ");
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SPEED: ");
  lcd.setCursor(0, 1);
  lcd.print("COUNT: ");
}

void loop() 
{
  
//***************************************************************************/
// read then divide the input(max 1020 in this case) by 10
  potValue1 = analogRead(potPin) / 10;
// divide by 1.02 to get percentage
  potValue2 = potValue1 / 1.02;
// set cursor to second row, first column
  lcd.setCursor(0, 0);
  lcd.print("SPEED: ");lcd.print(potValue2);lcd.print("%");delay(100);lcd.print(" ");delay(1);
  lcd.setCursor(0, 1);
  lcd.print("PRINT: ");lcd.print(count);delay(100);lcd.print(" ");delay(1);
  
  if(potValue2 > 0 && potValue2 <50){ analogWrite(motor,210);delay(1);  }
  if(potValue2 > 50 && potValue2 <70){ analogWrite(motor,230);delay(1); }
  if(potValue2 > 70 && potValue2 <100){ analogWrite(motor,254);delay(1); }
  
  //************************************************************************/
  if( (digitalRead(ir1) == HIGH) && (digitalRead(ir2) == HIGH) )
  {
    digitalWrite(relay, HIGH); 
    while(1)
    {
      if (digitalRead(ir3) == 1) break;
    }
    count++;
    digitalWrite(relay, LOW); 
    
    lcd.setCursor(0, 1);
    lcd.print("PRINT: ");lcd.print(count);delay(100);lcd.print(" ");delay(1);
    while((digitalRead(ir1) == HIGH) && (digitalRead(ir2) == HIGH) )
   {
      digitalWrite(relay, LOW);
      continue;
  }
        
  }  
} 

