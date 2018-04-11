#include <LiquidCrystal.h>
#include <DHT.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int pir_val = 0;


#define DHTPIN 2     // what pin we're connected to
define DHTTYPE DHT11   // DHT 11 
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{ 
  Serial.begin (9600);//for debugging purpose
  pinMode(6,INPUT);
  pinMode(7, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("*HOME  SECURITY*");
  lcd.setCursor(0, 1);lcd.print("LOADING");
  delay(200);
  lcd.setCursor(0, 1);lcd.print("..");
  delay(200);
  lcd.setCursor(0, 1);lcd.print("...");
  delay(200);
  lcd.setCursor(0, 1);lcd.print(".....");
  delay(200);
  lcd.setCursor(0, 1);lcd.print("......."); 
}

void loop() 
{
  
  lcd.setCursor(0, 1);
  lcd.print("VERIFYING---  ");
 
  lcd.setCursor(0, 1);
  pir_val = digitalRead(6);
  if (pir_val > 0 )
  {
    lcd.print("WHO IS THERE?? ");
   // Serial.println(pir_val); //for debugging purpose
   digitalWrite(7, HIGH); 
   delay(500);
   lcd.setCursor(0, 1);
  }
  else
  {
  lcd.print("HOME- 100% SAFE");
  digitalWrite(7, LOW);  // buzer Aler
  delay(500);
  }
}
