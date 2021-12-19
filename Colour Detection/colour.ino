#include <Wire.h>
#include "Adafruit_TCS34725.h"
 
/* Example code for the Adafruit TCS34725 breakout library */
 
/* Initialise with default values (int time = 2.4ms, gain = 1x) */
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();
 
/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

int potPin = A0;
int motorPin = 9;
int potValue = 0;
int motorValue = 0;
#define LED 5
 
void setup(void) {
Serial.begin(9600);
 
if (tcs.begin()) {
Serial.println("Found sensor");
} else {
Serial.println("No TCS34725 found ... check your connections");
while (1);
}

pinMode(motorPin, OUTPUT);
pinMode(LED, OUTPUT); 

}

void loop(void) {

  uint16_t r, g, b, c;
 
  tcs.getRawData(&r, &g, &b, &c);
  
  r = r/255;
  g = g/255;
  b = b/255;

  if (r > 7 && r < 23 && g > 2 && g < 11 && b > 1 && b < 9){
    Serial.println("RED");   
    //servo stuff get it to rotate
    //For Clock wise motion , in_1 = High , in_2 = Low

     potValue = analogRead(potPin);  
     motorValue = map(potValue, 0, 1023, 0, 255);
     analogWrite(motorPin, motorValue);   
     delay(5000); 
     analogWrite(motorPin, LOW); 
  }
  
  else if (r > 5 && r < 20 && g > 9 && g < 30 && b > 3 && b < 20){
    Serial.println("GREEN");
    digitalWrite(LED, HIGH);
    delay(5000); 
    digitalWrite(LED, LOW);
  }
 
  else if (r > 3 && r < 11 && g > 7 && g < 17 && b > 6 && b < 25){ 
    Serial.println("BLUE");
    digitalWrite(LED, HIGH);
    delay(5000); 
    digitalWrite(LED, LOW);
  }

  else {
    Serial.println("NO COLOUR");
  }

}
