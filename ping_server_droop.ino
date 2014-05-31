#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

void setup(){
  Serial.begin(9600);
  Serial.println("Listening..."); 

  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"serv1");
  Mirf.payload = 1;
  Mirf.channel = 90;
  Mirf.config();
}

void loop()
{

  byte c; 

  if( Mirf.dataReady() )
  {
     // well, get it
     Mirf.getData(&c);

    // ... and write it out to the PC
     Serial.print("Received Value: ");
     Serial.println(c);
  }
  delay(100);
}
