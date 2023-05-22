#include <Arduino.h>
#include "sensor.h"


Sensor::Sensor( char *pin )
 : _pin( pin ) {
   pinMode( pin, INPUT_PULLUP );
 }

void Sensor::sendSerial()
{
  // Serial.println( "sHI" );
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
    //add led indicator
    sendSerial();
  } else {
    _value = false;
  }
}
