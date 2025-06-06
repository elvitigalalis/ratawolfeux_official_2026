#ifndef TOF_H
#define TOF_H

#include "../vl53l0x_api_rp2040/core/inc/vl53l0x_api.h"
#include "../vl53l0x_api_rp2040/platform/inc/vl53l0x_rp2040.h"

class ToF {
 public:
  ToF(int xShutToFPin, char ToFPosition);
  ~ToF();

  float getToFDistanceFromWallMM();

 private:
  void setUpToFPin(int xShutToFPin);
  void resetToFToZeroDegrees(int xShutToFPin);
  void setUpToFSensor(int xShutToFPin, char ToFPosition);
  void setUpToFContinuousSensing();

  VL53L0X_Dev_t ToFSensor;
};

#endif