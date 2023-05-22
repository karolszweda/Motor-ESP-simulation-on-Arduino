#ifndef SENSOR_H
#define SENSOR_H

#include "device.h"

class Sensor : public Device {
private:
    short int _pin;
    short int _value;
    
public: 
    Sensor( char* );
    virtual void sendSerial() override; 
    bool getValue(); //Read value from sensor
    void work();
};

#endif 