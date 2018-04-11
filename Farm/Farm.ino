#include <LiquidCrystal.h>
#include <Servo.h>

Servo myservo;
int pos = 0;// variable to store the servo position

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("ACET PROJECT");
  delay(1000);
  lcd.print("SUBMITTED BY-");
  delay(1000);
  lcd.print("SUCHETA,AKANKSHA");
  delay(1000);
  lcd.print("LOADING ...");
  delay(1000);
  lcd.print("FARMING AUTOMATION!");
  
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
 
  //*********************************************************************
for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }


//********************************************************************** 
 
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  
  lcd.setCursor(0, 1);
  lcd.print("Started...");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("FARM-ROBOT");
  delay(1000);
  // print the number of seconds since reset:
  
}
