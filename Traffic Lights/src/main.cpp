// Controlling Traffic Lights
#include <Arduino.h>

// Define the pins that the buttons and lights are connected to:
#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10

#define yellowBlinkTime 500 // 0.5 seconds for the yellow light blink

bool trafficWest = true;    // west = true, east = false
int flowTime = 10000;       // amount of time to let traffic flow
int changeDelay = 2000;     // amount of time between colour changes

void setup()
{
  // Set up the digital I/O pins
  // Inputs
  pinMode(westButton, INPUT);
  pinMode(eastButton, INPUT);
  // Outputs
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);
  // Set initial state for lights - west side is green first
  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
}

void loop()
{
  if ( digitalRead(westButton) == HIGH )  // Request west>east traffic flow
  {
    if (!trafficWest) // Only continue if traffic is flowing east.
    {
      trafficWest = true;
      digitalWrite(eastGreen, LOW); // Change east facing light green to yellow
      digitalWrite(eastYellow, HIGH);
      delay(changeDelay);
      digitalWrite(eastYellow,LOW); // Change east facing from yellow to red
      digitalWrite(eastRed, HIGH);
      delay(flowTime);  // Delay for remaining traffic to pass
      for (int i = 0; i < 5; i++) // Blink yellow light
      {
        digitalWrite(westYellow, HIGH);
        delay(yellowBlinkTime);
        digitalWrite(westYellow, LOW);
        delay(yellowBlinkTime);
      }
      digitalWrite(westRed, LOW); // Change west facing light red to green
      digitalWrite(westGreen, HIGH);
    }
  }

  if ( digitalRead(eastButton) == HIGH )  // Request east>west traffic flow
  {
    if (trafficWest) // Only continue if traffic is flowing west.
    {
      trafficWest = false;
      digitalWrite(westGreen, LOW); // Change west facing light green to yellow
      digitalWrite(westYellow, HIGH);
      delay(changeDelay);
      digitalWrite(westYellow,LOW); // Change west facing from yellow to red
      digitalWrite(westRed, HIGH);
      delay(flowTime);  // Delay for remaining traffic to pass
      for (int i = 0; i < 5; i++) // Blink yellow light
      {
        digitalWrite(eastYellow, HIGH);
        delay(yellowBlinkTime);
        digitalWrite(eastYellow, LOW);
        delay(yellowBlinkTime);
      }
      digitalWrite(eastRed, LOW); // Change west facing light red to green
      digitalWrite(eastGreen, HIGH);
    }
  }
}