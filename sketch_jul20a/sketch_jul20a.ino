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
int state = 0;
int count = 0;

void setup() {
 Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("     PROTO      ");
  delay(1000);
  lcd.clear();
  lcd.print("   INSPIRING    ");
  lcd.setCursor(0, 1);
  lcd.print("   TECHNOLOGY   ");
  delay(1000);
  lcd.clear();
}

void loop() {
  
Serial.println("Hello World!");
delay(500);
  
  lcd.setCursor(0, 0);
  lcd.print("SPEED: ");lcd.print(state+3);
  lcd.setCursor(0, 1);
  lcd.print("COUNT: ");lcd.print(count);
}
