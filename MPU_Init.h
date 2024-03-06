#ifndef MPU_INIT_H
#define MPU_INIT_H

#include <Adafruit_MPU6050.h>


void initializeMPU(Adafruit_MPU6050 mpu);
float normalize_(float accX, float accY, float accZ);

#endif