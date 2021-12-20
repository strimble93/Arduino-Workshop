// Project 7 - Trying out a piezo buzzer
#define PIEZO 3 // Pin 3 is capable of PWM output to drive tones
int del = 500;
void setup()
{
  pinMode(PIEZO, OUTPUT);
}

void loop() 
{
  tone(PIEZO, 490); // 50% PWM signal of 490kHz (Arduino PWM default frequency)
  delay(del);
  noTone(PIEZO);    // Turn off PWM on pin
  delay(del);
}
