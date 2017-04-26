#ifndef MAIN_H_
#define MAIN_H_

// Macros 
// State machine macros
#define FAULT   0
#define IDLE    1
#define READY   2
#define PUSHING 3
#define COAST   4
#define BRAKING 5
// Commands
#define BLINKY "blinky"
#define ACCEL_TEST "acceltest"
#define RETRO_TEST "retrotest"
#define UART_ANALOG_TEST "uartanalogtest"
#define RUN "run"
#define HELP "help"
#define RUNTEST "runtest"

// Includes
#include "mbed.h"
#include "applications/blinky.hpp"
#include "peripherals/LED.hpp"
#include "applications/UARTAnalogTest.hpp"
#include "peripherals/UART.hpp"
#include "applications/RetroreflectiveTest.hpp"
#include <string>

// Functions
void getCommands(void);

#endif
