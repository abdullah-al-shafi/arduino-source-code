// Serial Relay - pass UART information between
// the computer and a software serial connection

#include <SoftwareSerial.h>
SoftwareSerial GPRS(7, 8); // RX, TX

void setup()
{
  GPRS.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  while(GPRS.available()) 
    Serial.write(GPRS.read());

  while (Serial.available()) 
      GPRS.write(Serial.read());


  while (Serial.available()) {
    byte b = Serial.read();
    if ( b == '*')
      GPRS.write( 0x1a );         // replace * with ctrl+z
    else
      GPRS.write(b);
  }
}
