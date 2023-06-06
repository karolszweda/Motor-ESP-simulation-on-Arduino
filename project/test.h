#include "device.h"

class Test : public Device {
  public:
    Test(int);
    void led_work();
    void setPin( char * ) override;
  private:
    int _pin;
};