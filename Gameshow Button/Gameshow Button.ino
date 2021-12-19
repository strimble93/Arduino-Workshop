// Gameshow button

// Define the pins that the buttons and lights are connected to:
#define p1Button 3
#define p2Button 13
#define p1Red 2
#define p1Yellow 1
#define p1Green 0
#define p2Red 12
#define p2Yellow 11
#define p2Green 10

int holdDelay = 1500;     // amount of time between colour changes

void setup()
{
  // Set up the digital I/O pins
  // Inputs
  pinMode(p1Button, INPUT);
  pinMode(p2Button, INPUT);
  // Outputs
  pinMode(p1Red, OUTPUT);
  pinMode(p1Yellow, OUTPUT);
  pinMode(p1Green, OUTPUT);
  pinMode(p2Red, OUTPUT);
  pinMode(p2Yellow, OUTPUT);
  pinMode(p2Green, OUTPUT);
  // Set initial state for lights - both players yellow first
  digitalWrite(p1Red, LOW);
  digitalWrite(p1Yellow, HIGH);
  digitalWrite(p1Green, LOW);
  digitalWrite(p2Red, LOW);
  digitalWrite(p2Yellow, HIGH);
  digitalWrite(p2Green, LOW);
}

void loop()
{
  if ( digitalRead(p1Button) == HIGH )  // Player 1 pressed button first
  {
    // Turn off yellow lights.
    digitalWrite(p1Yellow, LOW);
    digitalWrite(p2Yellow, LOW);
    // Turn players LED green and opponenets RED
    digitalWrite(p1Green, HIGH);
    digitalWrite(p2Red, HIGH);
    // Hold position for a set time
    delay(holdDelay);
    //Turn LEDs off
    digitalWrite(p1Green, LOW);
    digitalWrite(p2Red, LOW);
    // Set up both LEDs Yellow
    digitalWrite(p1Yellow, HIGH);
    digitalWrite(p2Yellow, HIGH);
  }

  if ( digitalRead(p2Button) == HIGH )  // Player 2 hit button first
  {
    // Turn off yellow lights.
    digitalWrite(p2Yellow, LOW);
    digitalWrite(p1Yellow, LOW);
    // Turn players LED green and opponenets RED
    digitalWrite(p2Green, HIGH);
    digitalWrite(p1Red, HIGH);
    // Hold position for a set time
    delay(holdDelay);
    // Turn LEDS off
    digitalWrite(p2Green, LOW);
    digitalWrite(p1Red, LOW);
    // Set up both LEDs Yellow
    digitalWrite(p2Yellow, HIGH);
    digitalWrite(p1Yellow, HIGH);
  }
}