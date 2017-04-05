#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "RetroreflectiveTest.hpp"
#include "mbed.h"

InterruptIn event(D2);
Timer timer;
int previousTimeStamp = 0;
int currentTimeStamp = 0;
int stripCount = 0;
bool retroFlag = 0;
const int DISTANCE_BETWEEN_STRIPS = 5;

void retroInterrupt(){
    stripCount++;
    retroFlag = 1;
    previousTimeStamp = currentTimeStamp;
    currentTimeStamp = timer.read_ms();
}

int main() {
    double distanceTravelled = 0;
    double speed = 0;

    timer.start();
    currentTimeStamp = timer.read_ms(); // time is read in miliseconds

    while(1) {
      event.rise(&retroInterrupt); // calls retroInterrupt when a rising edge occurs
      if (retroFlag) {
        distanceTravelled = getDistance(stripCount, DISTANCE_BETWEEN_STRIPS);
        speed = getSpeed(stripCount, previousTimeStamp, currentTimeStamp);

        printf("Strip count = %d",stripCount);
        printf("Distance Travelled = %f", distanceTravelled);
        printf("Speed = %f", speed);

        retroFlag = 0;
      }
    }
}

double getDistance(){
    return stripCount*DISTANCE_BETWEEN_STRIPS;
}

// time is measured in miliseconds
double getSpeed(double distance, double previousTime, double currentTime){
    double timeElapsed = currentTime-previousTime;
    return distance/timeElapsed;
}
