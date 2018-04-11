void setup(){
  // initialize red light pin
  pinMode(13, OUTPUT);
  // initialize yellow light pin
  pinMode(12, OUTPUT); 
// initialize green light pin 
pinMode(11, OUTPUT); } 
void loop() 
{
  // turn the red light on 
digitalWrite(13, HIGH); 
digitalWrite(12, LOW); 
digitalWrite(11, LOW); 
// wait 
delay(5000); 
// turn the yellow light on together with red 
// at least that's the way they work in some parts of Europe 
digitalWrite(13, HIGH); 
digitalWrite(12, HIGH); 
digitalWrite(11, LOW); 
// wait 
delay(1000); 
// turn the green light on 
digitalWrite(13, LOW);
digitalWrite(12, LOW);
digitalWrite(11, HIGH); 
// wait 
delay(5000); 
// turn the yellow light on 
digitalWrite(13, LOW);
digitalWrite(12, HIGH); 
digitalWrite(11, LOW);
// wait
delay(1000); 
//start over 
}
