#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int pwm = 10;               // assigns pin 10 to variable pwm
int inPin1 = 6;            // assigns pin 6 to pushbutton 1
int inPin2 = 7;           // assigns pin 17 to pushbutton 2
int ir1 = 8;             // assigns pin 8 to IR Sensor Front 1
int ir2 = 9;            // assigns pin 9 to IR Sensor Front 2
int ir3 = 13;         // assigns pin 13 to IR Sensor Motor

unsigned int val1 = 0;       // variable for reading the pin status button 1
unsigned int val2 = 0;      // variable for reading the pin status button 2

unsigned int state= 3;       // variable for getting status of speed
unsigned int count = 0;     // variable for rotation count

void setup() 
{
  lcd.begin(16, 2);
  pinMode(ir1, INPUT);            // declare IR- Packet as input
  pinMode(ir2, INPUT);           // declare IR- Packet as input
  pinMode(ir3, INPUT);          // declare IR-Motor as input
  pinMode(inPin1, INPUT);      // declare pushbutton as input
  pinMode(inPin2, INPUT);     // declare pushbutton as input
  pinMode(pwm, OUTPUT);      // declares pin 10 as output
  
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
   
  val1 = digitalRead(inPin1);  // read input value
  val2 = digitalRead(inPin2);

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
      state--;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SPEED=");
      lcd.print(state);
      rapid();
    }
  }
   
  
 else if(val1 == LOW & val2 == HIGH )
 {
    if(state == 1)
    {
      lcd.clear();
      lcd.print("Speed Minimum <<<");
      delay(500);
      lcd.clear();
      rapid();
    }
    else
    {
      state--;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SPEED=");
      lcd.print(state);
      rapid();
    }
    
  }

  else if(val1 == HIGH & val2 == HIGH )
 {
    
      lcd.clear();
      lcd.print(" INVALID INPUT ");
      delay(300);
      lcd.clear();
      rapid();
  }
  
  else 
  {
    default_operation();     
  }
}
void rapid()
{
  /*code for operation*/ 
  if (state == 1)
    speed1();
  else if (state == 2)
    speed2();
  else if (state == 3)
    speed3();
  else
    default_operation();
 
}    
  

void default_operation()
{
    if( ir1 == HIGH && ir2 == HIGH)
    { 
      lcd.setCursor(0, 0);lcd.print("Speed Level ");lcd.print(state); 
      lcd.setCursor(0, 1);lcd.print("Count=");lcd.print(count);
      analogWrite(pwm, 255); 
      if(ir3 ==HIGH)
       {
           analogWrite(pwm, 255);
           delay(100);
           analogWrite(pwm, 0); 
           count++; 
           lcd.setCursor(0, 1);lcd.print("Count=");lcd.print(count);
       }
     
     }
}



void speed1 ()
{

  if( ir1 == HIGH && ir2 == HIGH && state == 1)
    { 
      lcd.setCursor(0, 0);lcd.print("Speed Level ");lcd.print(state); 
      lcd.setCursor(0, 1);lcd.print("Count=");lcd.print(count);
      analogWrite(pwm, 150); 
      if(ir3 ==HIGH)
       {
           analogWrite(pwm, 255);
           delay(100);
           analogWrite(pwm, 0); 
           count++; 
           lcd.setCursor(0, 1);lcd.print("Count=");lcd.print(count);
       }
     
     }
  
}


void speed2 ()
{
    if( ir1 == HIGH && ir2 == HIGH && state == 2)
    { 
      lcd.setCursor(0, 0);lcd.print("Speed Level ");lcd.print(state); 
      lcd.setCursor(0, 1);lcd.print("Count=");lcd.print(count);
      analogWrite(pwm, 150); 
      if(ir3 ==HIGH)
       {
           analogWrite(pwm, 200);
           delay(100);
           analogWrite(pwm, 0); 
           count++; 
           lcd.setCursor(0, 1);lcd.print("Count=");lcd.print(count);
       }
     
     }
}


void speed3 ()
{
     if( ir1 == HIGH && ir2 == HIGH && state == 3)
    { 
      lcd.setCursor(0, 0);lcd.print("Speed Level ");lcd.print(state); 
      lcd.setCursor(0, 1);lcd.print("Count=");lcd.print(count);
      analogWrite(pwm, 150); 
      if(ir3 ==HIGH)
       {
           analogWrite(pwm, 255);
           delay(100);
           analogWrite(pwm, 0); 
           count++; 
           lcd.setCursor(0, 1);lcd.print("Count=");lcd.print(count);
       }
     
     }
}



