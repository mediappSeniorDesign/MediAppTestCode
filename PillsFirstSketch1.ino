
//set up pin ariables
int disk = 0;
int compartment = 0;
int input = 0;
int ticker = 0;

void setup() {
  // put your setup code here, to run once:
    //primary motor 
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enable1Pin, OUTPUT);
    //sleeve motor
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enable2Pin, OUTPUT);
    //ticker sensor
    pinMode(tickerPin, INPUT);
    //enable both
    digitalWrite(enable1Pin, HIGH);
    digitalWrite(enable2Pin, HIGH);
    
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    if ( Serial.available() > 0){
      input = Serial.read();
      disk = input/10;
      compartment = input%10;

      //shift slider to appropriate disk

      //rotate shaft appropriate number of ticks
      int temp = compartment;
      while (temp > 0){
        digitalWrite(motor1pin1, HIGH);
        digitalWrite(motor1pin2, LOW);
        ticker = 0;
        while(ticker == 0){
          ticker = digitalRead(tickerpin);
        }
        temp--;
      }
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);
      //rotate back
      temp = compartment;
      while (temp > 0){
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, HIGH);
        ticker = 0;
        while(ticker == 0){
          ticker = digitalRead(tickerpin);
        }
        temp--;
      }
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);

      //return slider to rest point
    }

    
    
}
