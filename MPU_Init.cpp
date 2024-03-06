#include "MPU_Init.h"


void initializeMPU(Adafruit_MPU6050 mpuSensor)
{

  double mpu_Acc_TEST_x[50];
  double mpu_Acc_TEST_y[50];
  double mpu_Acc_TEST_z[50];

  double mpu_Gyro_TEST_x[50];
  double mpu_Gyro_TEST_y[50];
  double mpu_Gyro_TEST_z[50];


  Serial.println("Initializing Gyroscope and Accelerometer Sensor...");

  mpuSensor.setAccelerometerRange(MPU6050_RANGE_8_G); //this sets the maximum range of acceleration we want to be able to see this is +- 8g so thats 8*(9.81 m/s) that we'd be able to see
  mpuSensor.setGyroRange(MPU6050_RANGE_250_DEG); //this sets the gyroscope to what range of degrees we would be able to read

  Serial.println("Beginning iterative test.");

  for(int i; i<30; i++) //accelerometer test
  {
    sensors_event_t a, g, t; //event struct that has defined physical parameters such as acceleration and orientation
    mpuSensor.getEvent(&a, &g, &t); //method that reads event input from sensors, method was built with 3 arguments for temp, acc, and gyro so we have to include temp but we dont have to use it

    mpu_Acc_TEST_x[i] = a.acceleration.x;
    mpu_Acc_TEST_y[i] = a.acceleration.y;
    mpu_Acc_TEST_z[i] = a.acceleration.z;

    Serial.print("Acceleration: x = ");
    Serial.print(mpu_Acc_TEST_x[i]);

    Serial.print(" | y =  ");
    Serial.print(mpu_Acc_TEST_y[i]);

    Serial.print(" | z =  ");
    Serial.println(mpu_Acc_TEST_z[i]);

    Serial.println("");

    mpu_Gyro_TEST_x[i] = g.gyro.x;
    mpu_Gyro_TEST_y[i] = g.gyro.y;
    mpu_Gyro_TEST_z[i] = g.gyro.z;

    Serial.print("Orientation:  x = ");
    Serial.print(mpu_Gyro_TEST_x[i]);

    Serial.print(" | y = ");
    Serial.print(mpu_Gyro_TEST_y[i]);

    Serial.print(" | z = ");
    Serial.println(mpu_Gyro_TEST_z[i]);

    delay(250);
  }
}

float normalize_(float accX, float accY, float accZ)
{
  
}