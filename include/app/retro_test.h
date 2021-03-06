#ifndef APPLICATIONS_RETROREFLECTIVE_H_
#define APPLICATIONS_RETROREFLECTIVE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "mbed.h"
#include "../configs/config.h"

/*
 * returns the distance traveled (stripeCount*distanceBetweenStripes)
 */
double getDistance();

/*
 * returns the average velocity (distance since last strip / time elapsed since last strip)
 */
double getSpeed(int stripeCount, double previousTimeStamp, double currentTimeStamp);

void retroTest();


#endif

