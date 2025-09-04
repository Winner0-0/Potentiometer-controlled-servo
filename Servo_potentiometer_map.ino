#include <LiquidCrystal.h> 
#include <Servo.h>         

//(RS, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

Servo winserv;

// To define the analog pin connected to the potentiometer.
const int potentiometerPin = A0;

// raw potentiometer value (0-1023)
int rawPotValue;

// mapped servo value (0-180)
int servoPosition;

void setup() {
  winserv.attach(9);
  lcd.begin(16, 2);

  lcd.print("S&P machine >:]");
  delay(1000); 
  lcd.clear(); 
}

void loop() {
  rawPotValue = analogRead(potentiometerPin);
  servoPosition = map(rawPotValue, 0, 1023, 0, 180);
  
  winserv.write(servoPosition);

  delay(15);

  lcd.setCursor(0, 0);
  lcd.print("Position: ");
  
  lcd.setCursor(0, 1);
  // Clear the rest of the line to prevent ghosting from previous longer numbers
  lcd.print("                "); 
  lcd.setCursor(0, 1);          
  lcd.print(servoPosition);      
  lcd.print(" Degrees");
}

