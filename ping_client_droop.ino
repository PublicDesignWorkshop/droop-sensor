int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

void setup(){
  Serial.begin(9600);
  Serial.println("Beginning ... "); 

  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"clie1");
  Mirf.payload = 1;
  Mirf.channel = 90;
  Mirf.config();
}

void loop(){
  sensorValue = analogRead(sensorPin);    
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  
  Mirf.setTADDR((byte *)"serv1");
  Mirf.send((byte *)&sensorValue);
  while(Mirf.isSending()){}
  
  delay(1000);
} 
  
  
  
