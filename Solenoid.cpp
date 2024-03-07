#include "Arduino.h"
#include "Solenoid.h"
//source files describe functions

Solenoid::Solenoid(int pin) //constructor
{
  _pin = pin;
}

Solenoid::activate() //random method
{
  digitalWrite(_pin, HIGH);
  delay(10000);
  digitalWrite(_pin, LOW);
}
