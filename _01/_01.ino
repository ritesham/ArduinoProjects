// setup runs just once 
void setup() 
{ // initialize digital pin 13 as an output. 
pinMode(13, OUTPUT); } 
// this loop runs for as long the Arduino has power
void loop() 
{ 
// turn the LED on with HIGH voltage level 
digitalWrite(13, HIGH); 
// wait for a second 
delay(1000); 
delay(1000); 
delay(1000); 
delay(1000); 
// turn the LED off by making the voltage LOW 
digitalWrite(13, LOW); 
delay(1000); 
delay(1000); 
delay(1000); 
delay(1000); 
// wait for a second 
delay(1000); 
}
