#ifndef MOTOR_H
#define MOTOR_H

#include "device.h"


class Motor : public Device
{
private:
   short int _speed, _speedPin, _direction, _directionPin;

public:
    Motor( short int, short int, short int, short int);

    void setPin( char* ) override;

    void setSpeed( short int, short int ); 

    short int getSpeed();

    void setDirection( short int, short int );

    void work();

    friend class ESP;
};

#endif