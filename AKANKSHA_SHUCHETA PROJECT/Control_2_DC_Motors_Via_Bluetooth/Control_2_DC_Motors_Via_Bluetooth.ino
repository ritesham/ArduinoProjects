#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 11, 12, 13);
int motor1Pin1 = 6; // pin 2 on L293D IC--3--
int motor1Pin2 = 7; // pin 7 on L293D IC--4--
int enable1Pin = 5; // pin 1 on L293D IC --6--
int motor2Pin1 = 9; // pin 10 on L293D IC--8--
int motor2Pin2 = 10; // pin 15 on L293D IC--9--
int enable2Pin = 8; // pin 9 on L293D IC--11--
int state;
int flag=0;        //makes sure that the serial only prints once the state
int stateStop=0;
void setup() {
    // sets the pins as outputs:
    //-----------------------------
    lcd.begin(16, 2);
  lcd.print(" SMART FARMING");
  lcd.setCursor(0, 1);
  lcd.print("LOADING");
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("..");
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("...");
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print(".....");
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print(".......");
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("PROJECT-");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("SUCHETA");
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.print("AKANKSHA");
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.print("-KANCHAN");
  delay(2000);
    
    //-----------------------------
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enable1Pin, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enable2Pin, OUTPUT);
    // sets enable1Pin and enable2Pin high so that motor can turn on:
    digitalWrite(enable1Pin, HIGH);
    digitalWrite(enable2Pin, HIGH);
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void loop() {
  //-------------------------------
  
 
  //--------------------------------  
  //if some date is sent, reads it and saves in state
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }   
    // if the state is '1' the DC motor will go forward
    if (state == '1') {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("Go Forward!");
          lcd.setCursor(0, 1);
          lcd.print("Go Forward!");
          flag=1;
        }
    }
    
    // if the state is '2' the motor will turn left
    else if (state == '2') {
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Turn LEFT");
          lcd.setCursor(0, 1);
          lcd.print("Turn LEFT");
          flag=1;
        }
        delay(1500);
        state=3;
        stateStop=1;
    }
    // if the state is '3' the motor will Stop
    else if (state == '3' || stateStop == 1) {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("STOP!");
          lcd.setCursor(0, 1);
          lcd.print("STOP!!!!!!");
          flag=1;
        }
        stateStop=0;
    }
    // if the state is '4' the motor will turn right
    else if (state == '4') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("Turn RIGHT");
          lcd.setCursor(0, 1);
          lcd.print("Turn RIGHT");
          flag=1;
        }
        delay(1500);
        state=3;
        stateStop=1;
    }
    // if the state is '5' the motor will Reverse
    else if (state == '5') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Reverse!");
          lcd.setCursor(0, 1);
          lcd.print("Reverse!");
          flag=1;
        }
    }
   
}
