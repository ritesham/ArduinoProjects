#include <NewPing.h>
#include <Servo.h>

Servo myservo;  
int PIEZO_RED_WIRE = 10;
#define TRIGGER_PIN  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
int SERVO_ANGLE = 0;
int j=0;
int check_ang;
int check_son;
int temp;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin (115200);
   myservo.attach(9);
    pinMode(PIEZO_RED_WIRE, OUTPUT);
//  pinMode(trigPin, OUTPUT);
//  pinMode(echoPin, INPUT);
  
}

void loop() 

{
  unsigned int uS = sonar.ping();temp=uS / US_ROUNDTRIP_CM; // Send ping, get ping time in microseconds (uS).
  Serial.print(uS / US_ROUNDTRIP_CM); Serial.print("^");// Convert ping time to distance in cm and print result (0 = outside set distance range)
  if (j==10) {
    for(int i=0;i<100;i++)
          {
                digitalWrite(PIEZO_RED_WIRE, HIGH);
                delayMicroseconds(100);
                digitalWrite(PIEZO_RED_WIRE, LOW);
                delayMicroseconds(100); j=0;} }               
  j++;
  delay(100);
  uS = sonar.ping(); temp=uS / US_ROUNDTRIP_CM; // Send ping, get ping time in microseconds (uS).
  Serial.print(uS / US_ROUNDTRIP_CM);Serial.print("^"); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  if (j==10) {  for(int i=0;i<100;i++)
  {
    digitalWrite(PIEZO_RED_WIRE, HIGH);
    delayMicroseconds(100);
    digitalWrite(PIEZO_RED_WIRE, LOW);
    delayMicroseconds(100); j=0;} }
  j++;
  delay(100);
}


    
