#include <LiquidCrystal.h>

#define speed1 190
#define speed2 220
#define speed3 255

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int pwm =     10;               // assigns pin 10 to variable pwm
int inPin1 =  6;                // assigns pin 6 to pushbutton 1
int inPin2 =  7;                // assigns pin 17 to pushbutton 2
int ir1 =     8;                // assigns pin 8 to IR Sensor Front 1
int ir2 =     9;                // assigns pin 9 to IR Sensor Front 2
int ir3 =     13;               // assigns pin 13 to IR Sensor Motor

int val1 = 1;          // variable for reading the pin status button 1
int val2 = 1;          // variable for reading the pin status button 2

int state= 3;          // variable for getting status of speed
int count = 0;         // variable for rotation count

long lastDebounceTime1 = 0;  // the last time the switch1 was pressed
long lastDebounceTime2 = 0;  // the last time the switch2 was pressed
long debounceDelay = 60;    // the debounce time; increase if the output is still sensitive


void setup() 
{
  
 
  lcd.begin(16, 2);
  pinMode(ir1, INPUT);           // declare IR- Packet as input
  pinMode(ir2, INPUT);           // declare IR- Packet as input
  pinMode(ir3, INPUT);           // declare IR-Motor as input
  pinMode(inPin1, INPUT);        // declare pushbutton as input
  pinMode(inPin2, INPUT);        // declare pushbutton as input
  pinMode(pwm, OUTPUT);          // declares pin 10 as output
  analogWrite(pwm, 0);
  
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
   analogWrite(pwm, 0);
  
   if (digitalRead(inPin1) != 0) {
    lastDebounceTime1 = millis(); // reset the debouncing timer  
    val1 = digitalRead(inPin1);  // read input value1
    while((millis() - lastDebounceTime1) < debounceDelay);
  }

  if (digitalRead(inPin2) != 0) {
    lastDebounceTime2 = millis(); // reset the debouncing timer
    val2 = digitalRead(inPin2);  // read input value2
    while((millis() - lastDebounceTime2) < debounceDelay);
   }

    //pushButton programming----------------------------------
  if(val1 == LOW )  {  
     state++;
    
     if(state > 3)
      state=3;
  }     
 
 if(val2 == LOW)  {
     state--;
     
    if(state < 0)
      state=0;   
  }    
rapid();    
}

void rapid(){
int Set_speed=0;
if (state == 1) Set_speed=speed1;
if (state == 2) Set_speed=speed2;
if (state == 3) Set_speed=speed3;

printMessage();

 if( (digitalRead(ir1) == HIGH) && (digitalRead(ir2) == HIGH) ){
  
   analogWrite(pwm, Set_speed); 

   while(1){
     if (digitalRead(ir3) == 1) break;
   }
 
   count++;
   analogWrite(pwm, 0); 
   printMessage();
 }
}

void printMessage(){

if(state == 1){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SPEED: ");lcd.print(state);lcd.print(" MIN");
  lcd.setCursor(0, 1);
  lcd.print("COUNT: ");lcd.print(count);
}

if(state == 2){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SPEED: ");lcd.print(state);
  lcd.setCursor(0, 1);
  lcd.print("COUNT: ");lcd.print(count);
}

if(state == 3){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SPEED: ");lcd.print(state);lcd.print(" MAX");
  lcd.setCursor(0, 1);
  lcd.print("COUNT: ");lcd.print(count);
}
 
}
