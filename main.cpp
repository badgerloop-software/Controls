#include "main.h"

int main(void) {
  pc.printf("Hiya\n");
  pc.printf("Type 'help' for a command list");
  pc.printf("Type 'run' to start the pod run\n");
  pc.printf("Type 'runtest x' to run the x state of the state machine.\n");

  while (true) {
    getCommands();
  }
}

void getCommands(void) {
  // if data is available from serial port
  if (pc.readable()) {
    // read data into a buffer
    char rxBuffer[200];
    pc.gets(rxBuffer, 200);
		string command = rxBuffer;
    if (command.compare(RUN) == 0) {
      // run
    } else if (command.substr(0, 7).compare(RUNTEST) == 0) {
      // get state from command and run
    } else if (command.compare(BLINKY) == 0) {
      // blinky();
    } else if (command.compare(ACCEL_TEST) == 0) {
      // printAccel();
    } else if (command.compare(RETRO_TEST) == 0) {
      // retroTest();
    } else if (command.compare(UART_ANALOG_TEST) == 0) {
      // prompt();
    } else if (command.compare(HELP) == 0) {
      pc.printf("'run' - Start a pod run\n");
      pc.printf("'runtest <x>' -  Run the x state of the state machine\n");
      pc.printf("'blinky' - Run the blinky test\n");
      pc.printf("'acceltest' - Run the accelerometer test\n");
      pc.printf("'retrotest' - Run the retroflective sensor test\n");
      pc.printf("'uartanalogtest' - Run the UART analog test\n");
    } else pc.printf("'%s' commmand not recognized", command.c_str());
  }   
}
