int btnPin[] = { 0,2,4,7 };
int ledPin[] = { 0,11,10,9 };
int wrongLED = 8;
int buttonState[] = {0,0,0,0 };
int lastButtonState[] = { 0,0,0,0 };
int led = 0;
int btn = 0;
int i = 0;
int ctrl = 0;
int lastBtn = 0;
int redval = 0;
int greenval = 0;
int yellval = 0; // variable for reading the pin status
int potPin = A0;
int motorPin = 5;
int potValue = 0;
int motorValue = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting");
  for (led = 9; led <= 11; led++) { pinMode(led, OUTPUT); }
  for (btn = 2; btn <= 7;  btn++) { pinMode(btn, INPUT);  }
  pinMode(wrongLED, OUTPUT);
}

void loop() {
  for (i = 1; i <= 3; i++) {
    if (wasBtnPushed(i) > 0) {
      if (wasBtnPushed(i) != lastBtn) {
        Serial.print("last_btn_"); Serial.print(lastBtn); Serial.print("   curr_btn_"); Serial.print(i); Serial.print("   initial_ctrl_"); Serial.print(ctrl); 
        if (ctrl == 0 && wasBtnPushed(i) == 1) { ctrl = 1; digitalWrite(ledPin[i], HIGH); }
        if (ctrl == 1 && wasBtnPushed(i) == 2) { ctrl = 2; digitalWrite(ledPin[i], HIGH);}
        if (ctrl == 2 && wasBtnPushed(i) == 3) { ctrl = 3; digitalWrite(ledPin[i], HIGH);}
        if (ctrl == 3 && wasBtnPushed(i) == 3) { ctrl = 3; digitalWrite(ledPin[i], HIGH);}

       
        if (ctrl == 0 && wasBtnPushed(i) == 2) { reset(); }
        if (ctrl == 0 && wasBtnPushed(i) == 3) { reset(); }

  
        if (ctrl == 1 && wasBtnPushed(i) == 3) { reset(); }

  
        if (ctrl == 2 && wasBtnPushed(i) == 1) { reset(); }

        
        Serial.print("   ctrl_"); Serial.println(ctrl);
        lastBtn = wasBtnPushed(i);
        delay(100);
      }
    if (ctrl == 3) { 
      Serial.print("Correct!"); 
      potValue = analogRead(potPin);  
      motorValue = map(potValue, 0, 1023, 0, 255);
      analogWrite(motorPin, motorValue);   
      delay(5000); 
      analogWrite(motorPin, LOW); 
      reset(); 
      }
    }
  }
}

void reset() {
  for(led = 1; led <= 3; led++) {
    digitalWrite(ledPin[led], LOW);
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
  }
  Serial.print("   has_reset");
  ctrl = 0;
  lastBtn = 0;
}

int wasBtnPushed(int x) {
  buttonState[x] = digitalRead(btnPin[x]);
    if (buttonState[x] != lastButtonState[x]) {
      if (buttonState[x] == HIGH) { return x; }
    }
  lastButtonState[x] = buttonState[x];
}
