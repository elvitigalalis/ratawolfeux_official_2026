// 17,18,19,20
// 6,7,8,9
#include <stdio.h>

#include "hardware/uart.h"
#include "pico/stdlib.h"

#include "Drivetrain.h"

int main() {
  stdio_init_all();

  // Encoder leftMotorEncoder = Encoder ()
  // Motor leftMotor = Motor ()

  while (true) {
    printf("Hello, world!\n");
    sleep_ms(1000);
  }

  return 0;
}