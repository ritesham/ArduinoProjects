#define TRIG_PIN 3  
 #define ECHO_PIN 2  
 #define BUZZ_PIN 4  
 void setup() {  
  pinMode(TRIG_PIN, OUTPUT);  
  pinMode(ECHO_PIN, INPUT); 
 Serial.begin(9600); 
 }  
 void loop() {  
  digitalWrite(TRIG_PIN, HIGH);  
  delay(1);  
  digitalWrite(TRIG_PIN, LOW);  
  int distance = pulseIn(ECHO_PIN, HIGH) / 2 / 29.1; 
 Serial.println(distance); 
 delay(500); 
  if (distance < 100)  
   tone(BUZZ_PIN,20);// map(distance, 0, 100, 1000, 15), 100);  
  else  
   delay(100);  
 } 
