#define TRIG_PIN 3  
#define ECHO_PIN 2  
#define BUZZ_PIN 4  
#include <Servo.h>
Servo servoMain;
int pos = 0;

void setup() {

 servoMain.attach(9);
 pinMode(TRIG_PIN, OUTPUT);  
 pinMode(BUZZ_PIN, OUTPUT);
 pinMode(ECHO_PIN, INPUT); 
 Serial.begin(9600); 
}

void loop() {
 digitalWrite(TRIG_PIN, HIGH);  
 delayMicroseconds(10);  
 digitalWrite(TRIG_PIN, LOW);  
 
 int distance = pulseIn(ECHO_PIN, HIGH) / 2 / 29.1; 
 Serial.println(distance); 
 
 delay(100); 
  
 if (distance < 20)  
 {
   digitalWrite(BUZZ_PIN, HIGH); 
   delay(1000); 
   digitalWrite(BUZZ_PIN, LOW);
   servoMain.write(0);
  }
 
 else  
    servoMain.write(120);
    delay(15);   
}
