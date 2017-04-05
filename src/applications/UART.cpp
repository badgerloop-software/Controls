#include "UART.hpp"

// Sends analog signal found from pin over UART.
void sendAnalog(AnalogIn pin, Serial* uart) {
  while(true) {
    led2 = !led2;
    uart->putc(pin.read_u16() >> 8);
    wait(1);
  }
}

void uartInterrupt() {

}

// receives analog value from UART
void receiveAnalog(Serial* uart) {
  uart->attach(&uartInterrupt);
  while(true) {
    led2 = !led2;
    if (uart->readable()) {
      pc.printf("The voltage is %i", uart->getc() * (5 / 256));
    }
  }

}

void prompt(AnalogIn pin, Serial* uart) {
  while(true) {
    pc.printf("Enter 't' for transmitter or 'r' for receiver\n");
    led1 = !led1;
    if (pc.readable()) {
      if (pc.getc() == 't') sendAnalog(pin, uart);
      else if (pc.getc() == 'r') receiveAnalog(uart);
    }
    wait(2);
  }
}
