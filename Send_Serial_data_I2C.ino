#include <Wire.h>
 
void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600); // initialize serial monitor
}
 
void loop() {
  // Check if there is any data available to read from the serial monitor
  if (Serial.available() > 0) {
    // Read the incoming data from the serial monitor
    String input = Serial.readString();
   
    // Send the data to the slave Arduino (device address 8)
    Wire.beginTransmission(8);
    Wire.print(input);
    Wire.endTransmission();
   
    delay(100); // delay for 100ms
  }
}
