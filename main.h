#ifndef MAIN_H_
#define MAIN_H_

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

// Maximums and Minimums //TODO
#define MIN_BREAK_PRESSURE_PSI		-1
#define MAX_BREAK_PRESSURE_PSI		-1
#define MAX_BATT_TEMP_F						-1
#define MIN_BATT_VOLTAGE_V				-1
#define MAX_BATT_VOLTAGE_V				-1
#define MIN_BATT_CURRENT_A				-1
#define MAX_VELOCITY_MPS					-1	// meters/second
#define MAX_RETRO_TIMEOUT_S				-1

// Pins
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

// Functions
void getCommands(void);
void init(void);
#endif
