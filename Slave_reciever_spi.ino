//Slave_reciever

#include <SPI.h> 


void setup() { 
Serial.begin(9600); 
SPI.begin(); 
pinMode(10, INPUT_PULLUP); // Set SS pin as input with internal pull-up resistor 

} 

void loop() { 
if (digitalRead(10) == LOW) { // Check if the master has selected this slave 
    SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0)); 
    char receivedChar = SPI.transfer(0); 
    SPI.endTransaction(); 
    Serial.print(receivedChar); 
   } 
} 