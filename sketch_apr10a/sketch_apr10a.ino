char state;
int flag=0;        //makes sure that the serial only prints once the state
int stateStop=0;
void setup() {
    // sets the pins as outputs:
    //-----------------------------
    
    //-----------------------------
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void loop() {
  //if some date is sent, reads it and saves in state
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }   
    // if the state is '1' the DC motor will go forward
    if (state == 'f') {
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW); 
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
    }
    
    // if the state is '2' the motor will turn left
    else if (state == 'l') {
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW); 
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
       
    }
    // if the state is '3' the motor will Stop
    else if (state == 'r' || stateStop == 1) {
        digitalWrite(8, LOW);
        digitalWrite(9, LOW); 
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        
    }
    // if the state is '4' the motor will turn right
    else if (state == 'R') {
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW); 
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(12, LOW);
        
    }
    // if the state is '5' the motor will Reverse
    else if (state == 's') {
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH); 
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        
    }
   
}
