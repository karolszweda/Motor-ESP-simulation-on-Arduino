#ifndef DEVICE_H
#define DEVICE_H


class Device {
public:
  virtual void sendSerial() = 0;
  virtual ~Device();
private:
// static short int devices;
};

#endif
