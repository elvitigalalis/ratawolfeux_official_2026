#ifndef IMU_H
#define IMU_H

#include "pico/stdlib.h"

class IMU {
 public:
  IMU(int uartRXPin = 5);
  ~IMU();

  float getIMUYawDegreesNeg180ToPos180();
  void resetIMUYawToZero();
  float getNewYawAfterAddingDegrees(float degreesToAdd);

 private:
  void setUpIMUCommunication();
  void setUpIMUInterrupts();
  static void processIMURXInterruptData();
  static void convertPacketDataToUsableYaw();

  const int uartRXPin;
  static volatile uint8_t IMUBufferForYaw[19];
  static float robotYawNeg180To180Degrees;
  static float resetOffSet;
};
#endif