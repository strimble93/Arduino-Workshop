// Knight rider K.I.T.T

int dtime = 100;            // Delay 
bool positive = true;       // LED increase or decrease
int a = 1;                  // General variable for the loop
int b = 3;                  // Selected LED variable

void setup() 
{
  // Setup serial for debugging purposes
  Serial.begin(9600);

  // Pin set up on PWM pins
  pinMode(3, OUTPUT);       // LED 1
  pinMode(5, OUTPUT);       // LED 2
  pinMode(6, OUTPUT);       // LED 3
  pinMode(9, OUTPUT);       // LED 4
  pinMode(10, OUTPUT);      // LED 5
}

// Used to return the pin number for the LED number requested
int LEDselect(int loopNo)
{
  if (loopNo == 1)
  {
    return 3;
  }
  else if (loopNo == 2)
  {
    return 5;
  }
  else if (loopNo == 3)
  {
    return 6;
  }
  else if (loopNo == 4)
  {
    return 9;
  }
  else if (loopNo == 5)
  {
    return 10;
  }
}

// Using PWM make the LED start dim and get brighter.
// Looks a bit rubbish when breath is small.
void breathe(int LED, int breath)               // LED - Selecyed LED, breath - total duration of function in milliseconds.
{
  int d = (breath*1000L/510);                   // Total time(ms) = d(us)/1000 * 510(steps)

  for ( int a = 0 ; a < 256; a++ )
  {
    analogWrite(LED, a);
    delayMicroseconds(d);
  }
  for ( int a = 255 ; a >= 0; a-- )
  {
    analogWrite(LED, a);
    delayMicroseconds(d);
  }
}

void loop() 
{
  b = LEDselect(a);             // Get the pin number for required LED number

//  breathe(b,dtime);

  
  digitalWrite(b, HIGH);        // Set pin high to turn LED on
  delay(dtime);                     // Delay for d uS
  digitalWrite(b, LOW);         // Set pin low to turn off LED.
  

  if (positive)
  {
    a++;
  }
  else 
  {
    a--;
  }
  
  if (a == 1)
  {
    positive = true;
  }
  else if (a == 5)
  {
    positive = false;
  }

}
