#ifndef SENSOR_H
#define SENSOR_H

#include "device.h"

class Sensor : public Device {
private:
    short int _pin;
    short int _value;
    
public: 
    Sensor( char* );
    void setPin( char* ) override; 
    bool getValue(); //Read value from sensor
    void work();
};

#endif 