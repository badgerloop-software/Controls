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
// Pin Macros
#define RETRO_ONE			D2
#define RETRO_TWO			D3
#define RETRO_THREE		D4

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
#include "applications/blinky.h"
#include "peripherals/LED.h"
#include "applications/UARTAnalogTest.h"
#include "peripherals/UART.h"
#include "applications/RetroreflectiveTest.h"
#include <string>

// Functions
void getCommands(void);

#endif
