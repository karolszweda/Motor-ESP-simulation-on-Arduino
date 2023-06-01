#include "test.h"

#include <Arduino.h>


Test::Test(int pin)
  : _pin(pin)
{
  pinMode(LED_BUILTIN, OUTPUT);
}
void Test::led_work(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

void Test::setPin( char *pin )
{
  _pin = atoi( pin ); 
}