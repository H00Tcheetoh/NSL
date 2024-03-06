#include <LoRa.h>
#include <RTClib.h>

#include "MPU_Init.h"
#include "BMP_Init.h"

//pinout defintion
int solenoidPin = 1;

//global variable declaration
bool avionicsMPU_init = false;
bool avionicsBMP_init = false;
bool solenoid_init = false;

//lora setups
int LoRa_msg_count;
const int csPin;
const int resetPin;
const int irqPin;

Adafruit_MPU6050 avionics_mpu;
LoRaClass sendModule;

void setup() {
  // put your setup code here, to run once:

  //normal value for the mpu z axis
  //parameter setups
  float currentAltitude;
  float targetAltitude = 400;
  float TOA = 12000; //time of apogee
  unsigned long long currentTime = 0; //logs current flight time, currently needs its functionality added to count

  pinMode(solenoidPin, OUTPUT);
  Adafruit_BMP3XX ejectionBMP;
  Adafruit_MPU6050 ejectionMPU;
  
  initializeBMP(ejectionBMP);
  initializeMPU(ejectionMPU);
  float currentPres; //current pressure for the loop
  float prevPres; //previous pressure for the loop
  //check solenoid
}


void loop() {
  // put your main code here, to run repeatedly:
  prevPres = currentPres; // save the last pressure
  currentPres  = digitalRead(bmp.getprss); // read new pressure

  if (currentTime > TOA || bmp.getprss)
  {
    if(mpu.acc < 0)
    {
      //check LoRa function
      if(checkLoRa)
      {
        digitalWrite(solenoidPin, HIGH); //SOLENOID ON and ejects payload with solenoid
      }
    }
    else if(BMP.getposs = poss@400ft)
    {
      digitalWrite(solenoidPin, HIGH); //SOLENOID ON and ejects payload with solenoid
    }
  }
}



bool LoRa_INIT()
{
  LoRa.setPins(csPin, resetPin, irqPin);

  Serial.println("Lora Initialization Test...");

  for(int i = 1; i < 11; i++)
  {
    LoRa.beginPacket();
    LoRa.println("Transmitting Message #: ");
    LoRa.print(LoRa_msg_count);
    LoRa.endPacket();

    LoRa_msg_count++;

    delay(500);
  }

  if(LoRa_msg_count == 10)
  {
    return true;
    Serial.println("LoRa Module Initialized");
  }


}


