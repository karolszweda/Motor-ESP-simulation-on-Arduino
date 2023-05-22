#ifndef ESP_H 
#define ESP_H 

#include "sensor.h"
#include "motor.h"
class ESP 
{
public:
    ESP( Sensor *sensor, Motor *motor );
    void work();
private:
    Sensor *_sensor;
    Motor *_motor; 
    int _motorSpeed;
};

#endif