int RedLED = 11;
int GreenLED = 6;
int YellowLED = 10;
int wrongLED = 5;
int Redbutton= 2;
int Greenbutton = 4;
int Yellowbutton = 7;
int redval = 0;
int greenval = 0;
int yellval = 0; // variable for reading the pin status
int potPin = A0;
int motorPin = 9;
int potValue = 0;
int motorValue = 0;

void setup() {
  pinMode(RedLED, OUTPUT);  // declare LED as output
  pinMode(GreenLED, OUTPUT); 
  pinMode(YellowLED, OUTPUT); 
  pinMode(wrongLED, OUTPUT);
  pinMode(Redbutton, INPUT); 
  pinMode(Greenbutton, INPUT);
  pinMode(Yellowbutton, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop(){

  redval = digitalRead(Redbutton); // read input value
  greenval = digitalRead(Greenbutton);
  yellval = digitalRead(Yellowbutton);
//  if (redval == HIGH) 
//  {         // check if the input is HIGH (button released)
//    digitalWrite(RedLED, HIGH);  // turn LED ON
//    delay(5000);
//
//  } 
//  else if (greenval == HIGH) 
//  {         // check if the input is HIGH (button released)
//    digitalWrite(GreenLED, HIGH);  // turn LED ON
//    delay(5000);
//
//  } 
//  else if (yellval == HIGH) 
//  {         // check if the input is HIGH (button released)
//    digitalWrite(YellowLED, HIGH);  // turn LED ON
//    delay(5000);
//
//  } 

  if(yellval == HIGH)
  {
    
    delay(1000);
    if (greenval == HIGH){
      
      digitalWrite(GreenLED, HIGH);
      digitalWrite(YellowLED, HIGH);
      potValue = analogRead(potPin);  
      motorValue = map(potValue, 0, 1023, 0, 255);
      analogWrite(motorPin, motorValue);   
      delay(5000); 
      analogWrite(motorPin, LOW);
      digitalWrite(YellowLED, LOW);
      digitalWrite(GreenLED, LOW);
      
    }
    
     }
   else if (redval == HIGH && yellval == HIGH)
     {
      digitalWrite(wrongLED, HIGH);
      delay(100);
      digitalWrite(wrongLED, LOW);
      delay(100);
       digitalWrite(wrongLED, HIGH);
      delay(100);
       digitalWrite(wrongLED, LOW);
      delay(100);
       digitalWrite(wrongLED, HIGH);
      delay(100);
       digitalWrite(wrongLED, LOW);
      delay(100);
       digitalWrite(wrongLED, HIGH);
      delay(100);
       digitalWrite(wrongLED, LOW);
      delay(100);
      digitalWrite(YellowLED, LOW);
      digitalWrite(RedLED, LOW);
     }
 
  
}
