#include "esp.h"
#include "sensor.h"
#include "motor.h"
#include <Arduino.h>


ESP::ESP(Sensor *sensor, Motor *motor)
    : _sensor( sensor), _motor( motor )
{  
  _motorSpeed = _motor->getSpeed();
}

void ESP::work()
{
    if ( _sensor->getValue() == true ){
        _motor->setSpeed(6, _motorSpeed / 2);
        Serial.println("050");
        delay( 1000 );
    } else {
        Serial.println("100");
        delay( 1000 );
        _motor->setSpeed( 6, _motorSpeed );

    }
}