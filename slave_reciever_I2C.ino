#include <Wire.h> 

void setup() { 
Wire.begin(8); // join i2c bus with address 8 
Wire.onReceive(receiveEvent); // register receive event 
Serial.begin(9600); // initialize serial monitor 

}
void loop() { 
} 

void receiveEvent(int howMany) { 
while (Wire.available()) { 
char c = Wire.read(); // receive byte as character 
Serial.print(c); // print the character 
} 

}          