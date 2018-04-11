/*****************************************************************************
* Copyright (C) 2016 by Rapidcode Technologies Pvt Ltd.. All Rights Reserved.*
******************************************************************************
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
*  Contact:       http://www.rapidcode.co.in                                 *
*****************************************************************************/
 
// Include the Hitachi HD44780 library

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int pwm =     10;               // assigns pin 10 to variable pwm
int inPin1 =  6;                // assigns pin 6 to pushbutton 1
int inPin2 =  7;                // assigns pin 17 to pushbutton 2
int ir1 =     8;                // assigns pin 8 to IR Sensor Front 1
int ir2 =     9;                // assigns pin 9 to IR Sensor Front 2
int ir3 =     13;               // assigns pin 13 to IR Sensor Motor

int val1 = 0;          // variable for reading the pin status button 1
int val2 = 0;          // variable for reading the pin status button 2

int state= 3;          // variable for getting status of speed
int count = 0;         // variable for rotation count

void setup() 
{
  
 
  lcd.begin(16, 2);
  pinMode(ir1, INPUT);           // declare IR- Packet as input
  pinMode(ir2, INPUT);           // declare IR- Packet as input
  pinMode(ir3, INPUT);           // declare IR-Motor as input
  pinMode(inPin1, INPUT);        // declare pushbutton as input
  pinMode(inPin2, INPUT);        // declare pushbutton as input
  pinMode(pwm, OUTPUT);          // declares pin 10 as output
  
  lcd.print("     PROTO      ");
  delay(2000);
  lcd.clear();
  lcd.print("   INSPIRING    ");
  lcd.setCursor(0, 1);
  lcd.print("   TECHNOLOGY   ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SPEED: ");lcd.print(state);
  lcd.setCursor(0, 1);
  lcd.print("COUNT: ");lcd.print(count);
}

void loop() 
{
   
  val1 = digitalRead(inPin1);  // read input value1
  val2 = digitalRead(inPin2);  // read input value2

    //pushButton programming----------------------------------
  if(val1 == HIGH && val2 == LOW )
  {  
     if(state == 3)
      {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("SPEED: ");lcd.print(state);lcd.print(" MAX");
          lcd.setCursor(0, 1);
          lcd.print("COUNT: ");lcd.print(count);
          rapid();
     }
    else
    {
      state++;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("SPEED: ");lcd.print(state);
          lcd.setCursor(0, 1);
          lcd.print("COUNT: ");lcd.print(count);
      rapid();      
    }
    
  }   
  
  
  
  else if(val1 == LOW && val2 == HIGH )
 {
    if(state == 1)
    {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("SPEED: ");lcd.print(state);lcd.print(" MIN");
          lcd.setCursor(0, 1);
          lcd.print("COUNT: ");lcd.print(count);
          rapid();
    }
    else
    {
      state--;
      lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("SPEED: ");lcd.print(state);
          lcd.setCursor(0, 1);
          lcd.print("COUNT: ");lcd.print(count);
      rapid();
    }
    
  }

  else if(val1 == HIGH && val2 == HIGH )
 {
      lcd.clear();
      lcd.print(" INVALID INPUT ");
      delay(100);
      rapid();
  }
  
  else 
  {
    rapid();     
  }
    
    
}
 

void rapid()
{
  /*code for operation*/ 
  if (state == 1)
    speed1();
  if (state == 2)
    speed2();
  if (state == 3)
    speed3();
}  
  

void speed1 ()
{

  if( (digitalRead(ir1) == HIGH) && (digitalRead(ir2) == HIGH) )
  { 
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("SPEED: ");lcd.print(state);lcd.print(" MIN");
          lcd.setCursor(0, 1);
          lcd.print("COUNT: ");lcd.print(count);
      
      analogWrite(pwm, 190); 
      while( digitalRead(ir3) ==LOW);
 
      if(digitalRead(ir3) ==HIGH)
       {
           count++;
           analogWrite(pwm, 0); 
           lcd.setCursor(0, 1);
           lcd.print("COUNT: ");lcd.print(count);
       }
     
     }
}


void speed2 ()
{

  if( (digitalRead(ir1) == HIGH) && (digitalRead(ir2) == HIGH) )
  { 
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("SPEED: ");lcd.print(state);
          lcd.setCursor(0, 1);
          lcd.print("COUNT: ");lcd.print(count);
      
      analogWrite(pwm, 220); 
      while( digitalRead(ir3) ==LOW);
    
      if(digitalRead(ir3) ==HIGH)
       {
           count++;
           analogWrite(pwm, 0); 
           lcd.setCursor(0, 1);
           lcd.print("COUNT: ");lcd.print(count);
       }
     
     }
}


void speed3 ()
{

  if( (digitalRead(ir1) == HIGH) && (digitalRead(ir2) == HIGH) )
  { 
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("SPEED: ");lcd.print(state);lcd.print(" MAX");
          lcd.setCursor(0, 1);
          lcd.print("COUNT: ");lcd.print(count);
      
      analogWrite(pwm, 255); 
      while( digitalRead(ir3) ==LOW);
     
      if(digitalRead(ir3) ==HIGH)
       {
           count++;
           analogWrite(pwm, 0); 
           lcd.setCursor(0, 1);
           lcd.print("COUNT: ");lcd.print(count);
       }
     
     }
}


