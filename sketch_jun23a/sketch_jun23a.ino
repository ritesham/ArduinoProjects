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
*  Contact:       http://www.rapidcode.co.in                                 *
*****************************************************************************/
 
// Include the Hitachi HD44780 library
#include <LiquidCrystal.h>
 
// Initialize the library with the following Arduino's interface pins: 7, 6, 5, 4, 3, 2
// Number 7 means Arduino's digital I/O port number 7.
// Number 6 means Arduino's digital I/O port number 6.
// And so on... Check the schematics for more information.
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
 
unsigned char i; // Define variable "i" to be used in both loops
 
void setup()
{
// Define the number of LCD's columns and rows
lcd.begin(16, 2); // For this tutorial I am using a 16x2 LCD which means that there are 16 columns and 2 rows
}
 
void loop()
{
  
// This first loop prints a sequence of "x" on the first row
for (i=0 ; i<=15 ; i++)
 {
  lcd.setCursor(i, 0); // Set the cursor to column i and row 0 (first row)
  lcd.print("x");      // Print a message to the LCD
  delay(500);          // 500ms delay
  lcd.clear();         // Clear the LCD  
 }
// This second loop prints a sequence of "x" on the second row
for (i=0 ; i<=15 ; i++)
 {
  lcd.setCursor(i, 1); // Set the cursor to column i and row 1 (second row)
  lcd.print("x");      // Print a message to the LCD
  delay(500);          // 500ms delay
  lcd.clear();         // Clear the LCD  
 }
}
