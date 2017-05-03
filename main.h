#ifndef MAIN_H_
#define MAIN_H_

//********!***********************
//********* Includes *************
//*************-******_***********
#include "mbed.h"
#include "applications/Blinky.h"
#include "peripherals/LED.h"
#include "applications/UARTAnalogTest.h"
#include "peripherals/UART.h"
#include "applications/RetroreflectiveTest.h"
#include <string>
#include "config.h"


//********!***********************
//********* Macros ***************
//*************-******_***********
// State Machine
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




//********!***********************
//********* Functions ************
//*************-******_***********
void getCommands(void);
void init(void);


//********!***********************
//******* Pin Assignments ********
//*************-******_***********
DigitalIn retro1(RETRO_ONE);
DigitalIn retro2(RETRO_TWO);
DigitalIn retro3(RETRO_THREE);

#endif
