#include <SPI.h>
 
void setup() {
  Serial.begin(9600);
  SPI.begin();
}
 
void loop() {
  if (Serial.available()) {
    char data = Serial.read();
 
    SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
    digitalWrite(10, LOW); // Select the slave device
 
    // Send data to the slave
    SPI.transfer(data);
 
    digitalWrite(10, HIGH); // Deselect the slave device
    SPI.endTransaction();
  }
}
