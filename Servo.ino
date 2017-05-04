#define IN7 4
#define IN8 5

/*String inString = "";
  int R = 0;
  int x = 0;
  int r = 0;
*/
void setup() {
  Serial.begin(9600);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
}

void loop() {
/*  if(Serial.available() > 0) {
      communication();
      int Slide(R);
      int antiSlide(R);
      inString = "";
    }
}
void slide() {
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
 void antiSlide() {
   int r = 0;
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
*/
  
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  delay(3000);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);
  delay(2000);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  delay(3000);
}

/*int comminication() {
 * int inChar = Serial.read();
 * if(isDigit(inChar)) {
 * inString += (char)inChar;
 * }
 * if(inChar == '\n') {
 * R = inString.toInt();
 * Serial.println(R);
 * return R;
 * }
 * }
 * 
 * The uncomented code does work to turn the motor continuously
 * in both directions.
 * The code commented out will be used to test and figure out
 * an algorithm for direction and distance of the slide based
 * on R. In addition, it can be used to test and make sure the 
 * arduino is succesfully recieving a string from the Rapsberry
 * Pi and converting it into the R int.
 */
