#include "mbed.h"

DigitalOut myled(LED1);
DigitalOut led2(LED2);

Serial pc(USBTX, USBRX);

int main() {
  while(1) {
    led2 = 1;
    wait(1);
    led2 = 0;
    wait(1);
  }
}
