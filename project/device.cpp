#include "device.h"

Device::Device()
{
  _devices++;
}
Device::~Device()
{
  _devices--;
}
// Device::getNumberDevices()
// {
//   return _devices;
// }