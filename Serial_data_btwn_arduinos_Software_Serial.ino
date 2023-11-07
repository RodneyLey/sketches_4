#include <SoftwareSerial.h>

SoftwareSerial mySerial (2, 3);
void setup() {
  // Open the serial communication with the baud rate of 9600
  mySerial.begin(9600);
  Serial.begin(9600); // Initialize the serial monitor
}
 
void loop() {
  // Check if there is any data available to read from the serial monitor
  if (Serial.available() > 0) {
    // Read the incoming data from the serial monitor
    String input = Serial.readString();
   
    // Send the data to the other Arduino
    mySerial.println(input);
  }
}
