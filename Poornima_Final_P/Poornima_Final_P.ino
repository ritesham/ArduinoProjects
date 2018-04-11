#include <LiquidCrystal.h>
#include <DHT.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int pir_val = 0;
int ir_val = 0;

int ledPin = 10;
int state = 0;
int flag = 0;

#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11 
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{ 
  dht.begin();
  Serial.begin (9600);//for debugging purpose
  pinMode(6,INPUT);
  pinMode(9,INPUT);
  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);
  lcd.begin(16, 2);
 
  lcd.print("*HOME  SECURITY*");
  Serial.println("*HOME  SECURITY*");
  
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
  if(Serial.available()>0)
  {
    state = Serial.read();
    flag=0;
  }
  
  if(state =='a')
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("Light on");
    lcd.setCursor(0, 1);
   lcd.print("  Light on   ");
  }
 else if( state == 'b')
 {
  digitalWrite(ledPin, LOW);
   Serial.println("Light off");
   lcd.setCursor(0, 1);
   lcd.print("  Light off   "); 
   
 }
else
{
   Serial.println("Press [a]-ON | [b]- OFF"); 
}

  int h = dht.readHumidity();
  int t = dht.readTemperature();
  lcd.setCursor(0, 1);
  lcd.print("VERIFYING---  ");
  
  lcd.setCursor(0, 1);
  Serial.print("TEMP= ");
  lcd.print("*T:");
  
  Serial.print(t);
  lcd.print(t);
  
  lcd.print("C");
  Serial.println("*C");
   
  lcd.print("   *H:");
  Serial.print("HUMID= ");
 
  lcd.print(h);
  Serial.print(h);
  lcd.print(" %");
  Serial.println("%");
  
  delay(2000);
 
  lcd.setCursor(0, 1);
  ir_val = digitalRead(9);
  if (ir_val > 0 )
  {
  digitalWrite(7, LOW);  // buzer Aler
  delay(500);
  }
  else
  {
   lcd.setCursor(0, 1);
   lcd.print("  GATE OPENED   ");
   Serial.println("GATE OPENED ");
  
   digitalWrite(7, HIGH);
   
   delay(1000);
  }
  pir_val = digitalRead(6);
  if (pir_val > 0 )
  {
    lcd.print("WHO IS THERE??  ");
   Serial.println("WHO IS THERE??  ");
   digitalWrite(7, HIGH); 
   delay(1000);
   lcd.setCursor(0, 1);
  }
  else
  {
  lcd.print("HOME- 100% SAFE");
   Serial.println("HOME- 100% SAFE");
  digitalWrite(7, LOW);  // buzer Aler
  delay(1000);
  }
}
