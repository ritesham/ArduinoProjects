 #define BUZZ_PIN 4  
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position


int val;
//----------------------------------------------------
// we'll use trigPin for emitting 
int trigPin = 3; 
// we'll listen for the pulse on the echoPin 
int echoPin = 2; 
// variables for calculations 
long duration, distance_inch, distance_cm; 
//---------------------------------------------------
void setup() 
{
  // initialize serial communication 
  Serial.begin (9600);
  // initialize pins
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  //---------------------------------------------------
  
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  //---------------------------------------------------

} void loop() {
  // emit a pulse 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
// get the time that it takes for the pulse to return
// pulseIn waits for the pulse and returns number of microseconds 
// divided by two because sound travels there and back again 
duration = pulseIn(echoPin, HIGH) / 2; 
// convert to inches and centimeters by using this formula
distance_inch = duration / 74;
distance_cm = duration / 29; 
// print the results 
Serial.print(distance_inch);
Serial.print(" inch; "); 
Serial.print(distance_cm);
Serial.println(" cm"); 
Serial.println("");
delay(1000); 
//----------------------------------------------------------
if ( distance_inch <12)
{
   
  myservo.write(0); 
  digitalWrite(BUZZ_PIN, HIGH);
  delay(500);
}
else 
{
 
  myservo.write(120);                  // sets the servo position according to the scaled value
 
}
//----------------------------------------------------------

}
