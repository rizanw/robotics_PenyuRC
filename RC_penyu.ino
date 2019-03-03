//input driver motor kiri
#define LM1      A0 //PB4 in1  //2 pd2
#define LM2      A1 //PB5 in2  //3 pd3
//input driver motor kanan
#define RM1      A2 //PB0 in3  //7 pd7
#define RM2      A3 //PD7 in4  //8 pb0

  char state;

void setup(){
    Serial.begin(9600);
    pinMode(LM1, OUTPUT);
    pinMode(LM2, OUTPUT);
    pinMode(RM1, OUTPUT);
    pinMode(RM2, OUTPUT);
}

void loop() {
    if(Serial.available() > 0){     
      state = Serial.read();
      if (state == 'S'){
      motor_stop();
      }else if (state == 'F') {
      drive_forward();
    }else if (state == 'B') {
      drive_backward();
    }else if (state == 'R') {
        turn_right();
    }else if (state == 'L') {
      turn_left();
    }else if (state == 'H') {
      turn_left_backward();
    }else if (state == 'J') {
      turn_right_backward();
    }else if (state == 'G') {
      turn_left();
    }else if (state == 'I') {
        turn_right();
    }
    delay(10);
 } 
 	  
}

// function to stop the robot
void motor_stop(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
}

//function to drive the robot forward
void drive_forward(){   
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
}

//function to drive the robot backward
void drive_backward(){   
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
}

//function to turn the robot left
void turn_left(){  
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
}

//function to turn the robot right
void turn_right(){
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
}

void turn_right_backward(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
}

void turn_left_backward(){
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
}



