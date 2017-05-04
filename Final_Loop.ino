
#define IN1 8                                 // stepper motor
#define IN2 9
#define IN3 10
#define IN4 11                                // stepper motor
#define IN5 2                                 // High output for pushButton
#define IN7 4                                 // servo motor
#define IN8 5                                 // servo motor

String inString = "";                         // for passing info
String stringOne = "";
String stringTwo = "";
int R = 0;
int Phi = 0;

int Steps = 0;
boolean Direction = true;                     // for stepper motor
unsigned long last_time;
unsigned long currentMillis;
int steps_left = 671;                         
long time;
                                              // for alarm
const int pushButton = 3;                     // push button input to pin 3
int Buzzer1 = 12;                             // speaker output pin 12
int buttonState = 0;

void setup() {
  
  Serial.begin(9600);                         //opens serial port, sets data rate to 9600bps
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(Buzzer1, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(pushButton, INPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  digitalWrite(IN5, HIGH);
  
}

void loop() {
    if(Serial.available() > 0) {
      communication();
      int Slide(R);                     // need to write algorithm based on R that will determine 
      int Rotation(Phi);                // direction of slide and distance of slide: r and x
      int antiSlide(R); 
      buttonState = digitalRead(pushButton);          
      if(buttonState == LOW) {
        tone(Buzzer1, 400, 200);
        delay(500);
      }
    }
    inString = "";
    stringOne = "";
    stringTwo = "";
}

int communication() {
  int inChar = Serial.read();
  if(isDigit(inChar)) {
    inString += (char)inChar;
  }
  if(inChar == '\n') {
    stringOne.substring(0,2);
    stringTwo.substring(3,5);

    R = stringOne.toInt();
    Phi = stringTwo.toInt();

    return R;
    return Phi;
  }
}

void Slide() {
  int x = 0;
  if(x >= 20) {
    digitalWrite(IN7, HIGH);
    digitalWrite(IN8, LOW);
    delay(x);                     // function based on R needed to determine x
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, LOW);
   }
   if(x <= 20) {
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, HIGH);
    delay(x);                     
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, LOW);
   }
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

void antiSlide() {
  int r = 0;                                    // function based on R needed to determine r
  if(r >= 20) {
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, HIGH);
    delay(r);                     
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, LOW);
  }
  if(r <= 20) {
    digitalWrite(IN7, HIGH);
    digitalWrite(IN8, LOW);
    delay(r);                     
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, LOW);
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

