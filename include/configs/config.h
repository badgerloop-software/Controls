#ifndef CONFIG_H_
#define CONFIG_H_

static Serial pc(USBTX, USBRX);

// Maximums and Minimums //TODO
#define MIN_BREAK_PRESSURE_PSI		-1
#define MAX_BREAK_PRESSURE_PSI		-1
#define MAX_BATT_TEMP_F						-1
#define MIN_BATT_VOLTAGE_V				-1
#define MAX_BATT_VOLTAGE_V				-1
#define MIN_BATT_CURRENT_A				-1
#define MAX_VELOCITY_MPS					-1	// meters/second
#define MAX_RETRO_TIMEOUT_S				-1

// Pins Assignments
// Digital Pins
#define RETRO_ONE					D2
#define RETRO_TWO					D3
#define RETRO_THREE				D4
#define PRES_PROP_ONE			-1
#define PRES_PROP_TWO			-1
#define PRES_BRAKE_ONE		-1
#define PRES_BRAKE_TWO		-1

#endif
