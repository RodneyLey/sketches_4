#include <SoftwareSerial.h> 

SoftwareSerial mySerial(2 ,3); // RX, TX 

void setup() { 
// Open the serial communication with the baud rate of 9600 
mySerial.begin(9600); 
Serial.begin(9600); // Initialize the serial monitor 
}
void loop() { 
// Check if there is any data available to read 
if (mySerial.available() > 0) { 
// Read the incoming data and print it to the serial monitor 
Serial.println(mySerial.readString()); 
} 

} 