#include <Arduino.h>
#include "sensor.h"


Sensor::Sensor( char *pin )
 : _pin( pin ) {
   pinMode( pin, INPUT_PULLUP );
 }

void Sensor::setPin( char *pin )
{
  _pin = pin;
}
bool Sensor::getValue()
{
  if( _value == true )
    return true;
  else 
    return false;
}

void Sensor::work()
{
  if ( digitalRead( _pin ) == LOW ){
    _value = true;
    // setPin();
  } else {
    _value = false;
  }
}
