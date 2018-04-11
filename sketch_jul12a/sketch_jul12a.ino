#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int outpin =10;
unsigned int state= 3;       // variable for getting status of speed
unsigned int count = 0;     // variable for rotation count
int ir3 = 13;
int ir1 = 8;             // assigns pin 8 to IR Sensor Front 1
int ir2 = 9;

void setup() {
   Serial.begin(9600);
lcd.begin(16, 2);
 pinMode(ir1, INPUT);            // declare IR- Packet as input
 pinMode(ir2, INPUT);           // declare IR- Packet as input
 pinMode(ir3, INPUT);          // declare IR-Motor as input
 pinMode(outpin, OUTPUT);

lcd.print("     PROTO      ");
  delay(2000);
  lcd.clear();
  lcd.print("   INSPIRING    ");
  lcd.setCursor(0, 1);
  lcd.print("   TECHNOLOGY   ");
  delay(2000);
//  lcd.clear();
//  lcd.setCursor(0, 0);
//  lcd.print("SPEED: ");lcd.print(state);
//  lcd.setCursor(0, 1);
//  lcd.print("COUNT: ");lcd.print(count);
}

void loop() {
  // put your main code here, to run repeatedly:
    if( ir2 == HIGH)
    {
       analogWrite(outpin, 255);
          
          count++; 
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("SPEED: ");lcd.print(state);lcd.print(" MAX");
          lcd.setCursor(0, 1);
          lcd.print("COUNT: ");lcd.print(count);
          delay(1000);
          Serial.println(count);
          
    }

/*for (int i =0; i<=5; i++)
{
   digitalWrite(outpin, HIGH);
   delay(500);
   
   digitalWrite(outpin, LOW);
   delay(1000);
}
delay(1000);*/
}
