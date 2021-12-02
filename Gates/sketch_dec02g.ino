#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int RedLED = 11;
int GreenLED = 9;
int YellowLED = 10;
int redval = 0;
int greenval = 0;
int yellval = 0; // variable for reading the pin status
int potPin = A0;
int motorPin = 5;
int potValue = 0;
int motorValue = 0;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(RedLED, OUTPUT);  // declare LED as output
  pinMode(GreenLED, OUTPUT); 
  pinMode(YellowLED, OUTPUT); 
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance > 15 && distance <= 20){
    digitalWrite(RedLED, HIGH); 
  }
  if (distance > 10 && distance <=15){
    digitalWrite(RedLED, HIGH); 
    digitalWrite(YellowLED, HIGH); 
  }
  if(distance > 5 && distance <=10){
    digitalWrite(RedLED, HIGH); 
    digitalWrite(YellowLED, HIGH);
    digitalWrite(GreenLED, HIGH);
    
  }
  if(distance < 5 && distance >=0){

    for (int i = 0; i<= 20; i++){
        digitalWrite(RedLED, HIGH); 
        digitalWrite(YellowLED, HIGH);
        digitalWrite(GreenLED, HIGH);
        delay(100);
        digitalWrite(RedLED, LOW); 
        digitalWrite(YellowLED, LOW);
        digitalWrite(GreenLED, LOW);
        delay(100); 
      }
    digitalWrite(RedLED, HIGH); 
    digitalWrite(YellowLED, HIGH);
    digitalWrite(GreenLED, HIGH);
    potValue = analogRead(potPin);  
    motorValue = map(potValue, 0, 1023, 0, 255);
    analogWrite(motorPin, motorValue);   
    delay(5000); 
    analogWrite(motorPin, LOW);
    
    
  }
  if (distance > 20){
    digitalWrite(RedLED, LOW); 
    digitalWrite(YellowLED, LOW);
    digitalWrite(GreenLED, LOW);
  }
}
