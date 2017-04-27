
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

String inString = "";
String stringTwo = "";
int Phi = 0;
int Steps = 0;
boolean Direction = true;
unsigned long last_time;
unsigned long currentMillis;
int steps_left = 671;                         
long time;


void setup() {
  Serial.begin(9600);                         //opens serial port, sets data rate to 9600bps
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}

void loop() {
  if(Serial.available() > 0) {
    int inChar = Serial.read();
  if(isDigit(inChar)) {
    inString += (char)inChar;
  }
  if(inChar == '\n') {
    stringTwo.substring(3,5);
    Phi = stringTwo.toInt();
    }
  }
  int Rotaion();
}

void Rotation() {
  switch(Phi) {
      case 0:
        turnOne(1);
        delay(2000);
        turnOne(0);
        delay(2000);
     case 1:
        turnOne(1);
        turnOne(1);
        delay(2000);
        turnOne(0);
        turnOne(0);
        delay(2000);
     case 2:
        turnOne(1);
        turnOne(1);
        turnOne(1);
        delay(2000);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        delay(2000);
     case 3:
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        delay(2000);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        delay(2000);
     case 4:
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        delay(2000);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        delay(2000);
     case 5:
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        delay(2000);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        delay(2000);
     case 6:
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        delay(2000);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        delay(2000);
     case 7:
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        delay(2000);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        delay(2000);
     case 8:
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        delay(2000);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        delay(2000);
     case 9:
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        delay(2000);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        delay(2000);
     case 10:
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        turnOne(1);
        delay(2000);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        turnOne(0);
        delay(2000);
    }
}

void turnOne(bool dir) {
    Direction = dir;                          
    while(steps_left > 0) {
      currentMillis = micros();
      if(currentMillis - last_time >= 1000) {
        stepper(1);
        time = time + micros() - last_time;
        last_time = micros();
        steps_left--;
      }
    }
    steps_left = 671;
}

void stepper(int xw) {
  for(int x = 0; x < xw; x++) {                
    switch(Steps) {
      case 0:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
       break;
       case 1:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, HIGH);
       break;
       case 2:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
       break;
       case 3:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
       break;
       case 4:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
       break;
       case 5:
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
       break;
       case 6:
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
       break;
       case 7:
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
       break;
       default:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
       break;
    }
    SetDirection();
  }
}

void SetDirection() {
  if(Direction == 1){
    Steps++;
  }
  if(Direction == 0) {
    Steps--;
  }
  if(Steps > 7) {
    Steps = 0;
  }
  if(Steps < 0) {
    Steps = 7;
  }
}

/* This program is meant for testing the communication with the Raspberry Pi
 *  being converted into rotaion
 */
