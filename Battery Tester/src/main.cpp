// Battery cell tester project
#include <Arduino.h>

// Define pins that are used
#define newLED 0 // Green LED
#define okLED 1 // Yellow LED
#define oldLED 2 // Red LED
#define bVoltage 0 // Battery under test


// Set up some global variables
int analogValue = 0;
float highVoltage = 1.6;
float voltage = 0;
float lowVoltage = 1.4;
int ledDelay = 2000;

void setup()
{
  // Digital I/O pins
  pinMode(newLED, OUTPUT);
  pinMode(okLED, OUTPUT);
  pinMode(oldLED, OUTPUT);
}

void loop()
{
  analogValue = analogRead(bVoltage); // Read the battery voltage
  voltage = 0.0048 * analogValue;     // Convert it from ADC reading value to voltage
  // Determine voltage level and turn on relevant LED
  if (voltage >= highVoltage)
  {
    digitalWrite(newLED, HIGH);
    delay(ledDelay);
    digitalWrite(newLED, LOW);
  }
  else if ( (voltage < highVoltage) && (voltage > lowVoltage) )
  {
    digitalWrite(okLED, HIGH);
    delay(ledDelay);
    digitalWrite(okLED, LOW);
  }
  // If below a certain threshold then there is no battery connected
  else if ( (voltage <= lowVoltage) && (voltage > 0.5) )
  {
    digitalWrite(oldLED, HIGH);
    delay(ledDelay);
    digitalWrite(oldLED, LOW);
  }
}