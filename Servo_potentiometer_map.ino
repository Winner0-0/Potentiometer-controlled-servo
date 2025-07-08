#include <LiquidCrystal.h> // Include the LiquidCrystal library for LCD display
#include <Servo.h>         // Include the Servo library for controlling the servo motor

// Initialize the LCD with the pin connections: (RS, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

Servo winserv;

// Define the analog pin connected to the potentiometer.
// Using 'const int' is good practice for pin assignments.
// Assuming the potentiometer is connected to Analog Pin A0.
// If it's connected to a different analog pin (e.g., A1, A2), change 'A0' accordingly.
const int potentiometerPin = A0;

// raw potentiometer value (0-1023)
int rawPotValue;

// mapped servo value (0-180)
int servoPosition;

void setup() {
  winserv.attach(9);
  lcd.begin(16, 2);

  lcd.print("S&P machine >:]");
  delay(1000); // Keep the message on screen for 1 second
  lcd.clear(); // Clear the LCD after the delay
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
  lcd.print("                "); // Print spaces to clear the line
  lcd.setCursor(0, 1);           // Reset cursor
  lcd.print(servoPosition);      // Display the current servo position
  lcd.print(" Degrees");
}
