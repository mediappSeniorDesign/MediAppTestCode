
const int pushButton = 3;
int Buzzer1 = 12;
int buttonState = 0;

void setup() {
  pinMode(Buzzer1, OUTPUT);
  pinMode(pushButton, INPUT);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
}

void loop() {
  buttonState = digitalRead(pushButton);
  if(buttonState == LOW) {
      tone(Buzzer1,400,200);
      delay(500);  
  }
  
}



