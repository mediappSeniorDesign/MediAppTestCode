
String inString = "";                 // string to hold input
String stringOne = "";                // sub string one
String stringTwo = "";                // sub string two
int R = 0;
int Phi = 0;

void setup() {
  Serial.begin(9600);                 // open serial communication
}

void loop() {
  while(Serial.available() > 0) {
    int inChar = Serial.read();       // convert the incoming byte to a char
    if(isDigit(inChar)) {             
      inString += (char)inChar;       // add char to the string
    }
    if(inChar == '\n') {              // if you get a newline
      stringOne.substring(0,2);     // break the string into two strings
      stringTwo.substring(3,5);

      R = stringOne.toInt();      // convert both strings to integers
      Phi = stringTwo.toInt();
      
      Serial.print("INTs: ");         // print the integers
      Serial.println(R);
      Serial.println(Phi);
      Serial.print("String: ");       // print the original string
      Serial.println(inString);
      inString = "";                  // clear the strings for new input:
      stringOne = "";
      stringTwo = "";
    }
  }
}


// Serial communicates on digital pins 0(RX) and 1(TX)
