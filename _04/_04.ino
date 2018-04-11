// we'll use trigPin for emitting
int trigPin = 13; 
// we'll listen for the pulse on the echoPin 
int echoPin = 12; 
// variables for calculations
long duration, distance_inch, distance_cm; 
void setup() 
{
  // initialize serial communication 
Serial.begin (9600); 
// initialize pins
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}
void loop() 
{
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
}

