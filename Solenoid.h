#include "Arduino.h"
#ifndef SOLENOID_H
#define SOLENOID_H
//header files declare functions


class Solenoid
{
  public:
    Solenoid(int pin);
    void activate();

  private:
    int _pin;
}

#endif