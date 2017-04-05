#ifndef APPLICATIONS_UART_H_
#define APPLICATIONS_UART_H_
#include "mbed.h"
#include "../peripherals/LED.hpp"
#include "../peripherals/UART.hpp"


void sendAnalog(AnalogIn pin, Serial uart);

void prompt(AnalogIn pin, Serial uart);

#endif
