#ifndef MAIN_H_
#define MAIN_H_

//********* Includes *************
#include "mbed.h"
#include <string>

#include "../configs/config.h"

#include "../app/blinky.h"
#include "../app/analog_test.h"
#include "../app/retro_test.h"

#include "../periph/LED.h"

#include "../common/UART.h"
//********************************

//********* Macros ***************
// State Machine
#define FAULT   0
#define IDLE    1
#define READY   2
#define PUSHING 3
#define COAST   4
#define BRAKING 5
//********************************

// Commands
#define BLINKY "blinky"
#define ACCEL_TEST "acceltest"
#define RETRO_TEST "retrotest"
#define UART_ANALOG_TEST "uartanalogtest"
#define RUN "run"
#define HELP "help"
#define RUNTEST "runtest"

//********* Functions ************
void getCommands(void);
void init(void);
//********************************

//******* Pin Assignments ********
DigitalIn retro1(RETRO_ONE);
DigitalIn retro2(RETRO_TWO);
DigitalIn retro3(RETRO_THREE);
//********************************

#endif
