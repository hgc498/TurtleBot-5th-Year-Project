int ledPin = 5; // choose the pin for the LED
int inPin = 2;   // choose the input pin (for a pushbutton)
int val = 0;     // variable for reading the pin status
int potPin = A0;
int motorPin = 9;
int potValue = 0;
int motorValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);  // declare LED as output
  pinMode(inPin, INPUT);    // declare pushbutton as input
  pinMode(motorPin, OUTPUT);
}

void loop(){
  val = digitalRead(inPin);  // read input value
  if (val == HIGH) {         // check if the input is HIGH (button released)
    digitalWrite(ledPin, HIGH);  // turn LED ON
    potValue = analogRead(potPin);  
    motorValue = map(potValue, 0, 1023, 0, 255);
    analogWrite(motorPin, motorValue);   
    delay(5000); 
    analogWrite(motorPin, LOW); 
  } else {
    digitalWrite(ledPin, LOW);  // turn LED OFF
  }
}
