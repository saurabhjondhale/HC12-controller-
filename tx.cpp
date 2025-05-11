#include <SoftwareSerial.h>

SoftwareSerial HC12(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    HC12.write(command);
  }
}
