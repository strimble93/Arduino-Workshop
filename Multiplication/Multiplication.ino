// Project 13 - Multiplying a number by two

int number;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  number = 0;     // Set the variable to zero, ready for a new read
  Serial.flush(); // Clear any "junk" out of the serial buffer (this does not actually work as expected, it waits for output to clear.)
  while (Serial.available() == 0)
  {
    // Do nothing until something is entered
  }
  while (Serial.available() > 0)
  {
    number = Serial.read() - '0';
    //Read the number in the serial buffer and remove the ASCII text offset for zero: '0'
  }
  // Show me the number!
  Serial.print("You entered: ");
  Serial.println(number);
  Serial.print(number);
  Serial.print(" multiplied by two is ");
  number = number * 2;
  Serial.println(number);
}