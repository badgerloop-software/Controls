#include "blinky.hpp"
#include "mbed.h"

DigitalOut led2(LED2);

void blinky(float seconds) {
  while(1) {
    led2 = 1;
    wait(1);
    led2 = 0;
    wait(1);
  }
}
