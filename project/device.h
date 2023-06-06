#ifndef DEVICE_H
#define DEVICE_H


class Device {
public:
  Device();
  ~Device();
  virtual void setPin( char *) = 0;
  // virtual int getNumberDevices() = 0;
private:
  unsigned int _devices = 0;
};

#endif
