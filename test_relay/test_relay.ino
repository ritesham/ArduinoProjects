int relay =   6;         // assigns pin 10 to variable pwm
int ir1 =     7;                    // assigns pin 7 to IR Sensor Front 1

void setup() 
{  
  pinMode(ir1, INPUT);           // declare IR- Packet as input    
  pinMode(relay, OUTPUT);     // declares pin 3 as output
}

void loop() 
{ 
  if( (digitalRead(ir1) == HIGH))
      digitalWrite(relay, HIGH); 
  else
      digitalWrite(relay, LOW);    
}


