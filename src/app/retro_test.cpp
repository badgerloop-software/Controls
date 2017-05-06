#include "../../include/app/retro_test.h"

InterruptIn event(D2);
Timer timer;
int previousTimeStamp = 0;
int currentTimeStamp = 0;
int stripCount = 0;
bool retroFlag = 0;
const int DISTANCE_BETWEEN_STRIPS = 5;

void retroInterrupt() {
    pc.printf(" -In retroInterrupt\n");
    stripCount++;
    retroFlag = 1;
    previousTimeStamp = currentTimeStamp;
    currentTimeStamp = timer.read_ms();
    pc.printf(" -RetroFlag = %d\n", retroFlag);
}

void retroTest() {
    double distanceTravelled = 0;
    double speed = 0;

    timer.start();
    currentTimeStamp = timer.read_ms(); // time is read in miliseconds

    pc.printf("In retroTest\n");

    event.rise(&retroInterrupt); // calls retroInterrupt when a rising edge occurs

    while(1) {
      wait(.5); // without this, nothing prints in the if statement
      if (retroFlag) {
        distanceTravelled = getDistance();
        speed = getSpeed(stripCount, previousTimeStamp, currentTimeStamp);

        pc.printf("Strip count = %d\n",stripCount);
        pc.printf("Distance Travelled = %f\n", distanceTravelled);
        pc.printf("Speed = %f\n", speed);

        retroFlag = 0;
      }
    }
}

double getDistance() {
    return stripCount*DISTANCE_BETWEEN_STRIPS;
}

// time is measured in miliseconds
double getSpeed(int distance, double previousTime, double currentTime) {
    double timeElapsed = currentTime - previousTime;
    return distance / timeElapsed;
}

