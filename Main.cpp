// 17,18,19,20
// 6,7,8,9
#include <stdio.h>

#include "Robot/Drivetrain.h"
#include "hardware/uart.h"
#include "pico/stdlib.h"

int main() {
  stdio_init_all();

  Encoder leftMotorEncoder = Encoder(20);
  Encoder rightMotorEncoder = Encoder(7);
  Motor leftMotor = Motor(18, 19, &leftMotorEncoder, true);
  Motor rightMotor = Motor(6, 7, &rightMotorEncoder);
  ToF leftToF = ToF(11, 'L');
  ToF frontToF = ToF(12, 'F');
  ToF rightToF = ToF(13, 'R');
  IMU imu = IMU(5);

  Drivetrain drivetrain =
      Drivetrain(&leftMotor, &rightMotor, &leftToF, &frontToF, &rightToF, &imu);

  while (true) {
    printf("Hello, world!\n");
    sleep_ms(1000);
  }

  return 0;
}