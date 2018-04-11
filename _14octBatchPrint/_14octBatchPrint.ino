/*--------------------------------------------------------------
  Program:      Batch Printing Programming

  Description:  Reads value on analog input A2 and calculates
                the voltage assuming that a voltage divider
                network on the pin divides by 11.
  
  Hardware:     Arduino Uno with voltage divider on A2.
                
  Software:     Developed using Arduino 1.0.5 software
                Should be compatible with Arduino 1.0 +

  Date:         14 Sept 2016
 
  Author:       Ritesham Shastri, www.rapidcode.co.in
--------------------------------------------------------------*/

#include <LiquidCrystal.h>
//**********************************************************************
#define NUM_SAMPLES 10

int sum = 0;                    // sum of samples taken
unsigned char sample_count = 0; // current sample number
float voltage = 0.0;    // calculated voltage
float actualvoltage= 0.0;
//*********************************************************************

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
  PrintMessage();
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

//******************************************************************
void PrintMessage()
{
   // take a number of analog samples and add them up
    while (sample_count < NUM_SAMPLES) {
        sum += analogRead(A1);
        sample_count++;
        delay(10);
    }
    // calculate the voltage
    // use 5.0 for a 5.0V ADC reference voltage
    // 5.015V is the calibrated reference voltage
    voltage = ((float)sum / (float)NUM_SAMPLES * 5.015) / 1024.0;
    // send voltage for display on Serial Monitor
    // voltage multiplied by 11 when using voltage divider that
    // divides by 11. 11.132 is the calibrated voltage divide
    // value
   
  actualvoltage = voltage * 11.132;
  if( actualvoltage >= 0 && actualvoltage <= 4)     
  {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Speed Level : 01");
  sample_count = 0;
  sum = 0;
  }
  else if( actualvoltage >= 4 && actualvoltage <= 6)     
  {
  lcd.clear();
  lcd.setCursor(0, 0);
   lcd.print("Speed Level : 02");
  sample_count = 0;
  sum = 0;
  }
  
  else if( actualvoltage >= 6 && actualvoltage <= 12)     
  {
  lcd.clear();
  lcd.setCursor(0, 0);
   lcd.print("Speed Level : 03");
  sample_count = 0;
  sum = 0;
  }
  else    
  {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Speed Error");
  sample_count = 0;
  sum = 0;
  }
  
  lcd.setCursor(0, 1);
  lcd.print("COUNT: ");lcd.print(count);
  
  
    
}
