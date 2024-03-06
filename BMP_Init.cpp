#include "BMP_Init.h"

void initializeBMP(Adafruit_BMP3XX bmpSensor)
{
  Serial.println("Initializing Temperature and Pressure Sensor...");
 
  float bmpSensor_temp_TEST[100];
  float bmpSensor_press_TEST[100];
  float bmpSensor_press_dif;
  float bmpSensor_temp_dif;

  if(!bmpSensor.begin_I2C()) //starts the mpu sensor by calling the begin method, if false it does the proceeding code
  {
    Serial.println("bmpSensor Not found..."); 

    while(!bmpSensor.begin_I2C()) //while the sensor begin method is still false it will run indefinitely until otherwise
    {
      delay(10);
    }
  }

  Serial.println("Beginning iterative test.");
  Serial.println("------------------");

  for(int i = 0; i < 30; i++)
  {
    bmpSensor_press_TEST[i] = bmpSensor.readPressure();

    Serial.print("Pressure: ");
    Serial.print(bmpSensor_press_TEST[i]/6894.757);
    Serial.println(" Psi");


    bmpSensor_temp_TEST[i] = bmpSensor.readTemperature();

    Serial.print("Temperature: ");
    Serial.print((bmpSensor_temp_TEST[i] * 1.8) + 32);
    Serial.println(" F");

    Serial.println("");

    i++;

    delay(250);
  }
}

//normalize z axis before nozzle ignition
