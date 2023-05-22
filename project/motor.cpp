#include <Arduino.h>
#include "motor.h"
 
Motor::Motor( short int speed, short int speedPin, short int dir, short int dirPin ) 
  : _speed( speed ), _speedPin( speedPin ), _direction( dir ), _directionPin( dirPin )
{
  pinMode( _speedPin, OUTPUT );
  pinMode( _directionPin, OUTPUT );
}

void Motor::sendSerial()
{
  // Serial.println(getSpeed());
}

void Motor::setSpeed( short int speedPin, short int speed )
{
    _speedPin = speedPin;
    _speed = speed;
    analogWrite( _speedPin, _speed );
}

short int Motor::getSpeed()
{
    return _speed;
}

void Motor::setDirection( short int dirPin, short int dir )
{
  _directionPin = dirPin;
  _direction = dir;
  digitalWrite( _directionPin, _direction );

}

void Motor::work()
{
  setDirection( _directionPin, _direction );
  setSpeed( _speedPin, _speed );
}



