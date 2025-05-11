#include <SoftwareSerial.h>

SoftwareSerial HC12(10, 11); // RX, TX

void setup() {
  HC12.begin(9600);

  // Motor pins for L298N motor shield
  pinMode(3, OUTPUT); // Motor A
  pinMode(11, OUTPUT); // Motor A
  pinMode(5, OUTPUT); // Motor B
  pinMode(6, OUTPUT); // Motor B
}

void loop() {
  if (HC12.available()) {
    char cmd = HC12.read();
    controlMotors(cmd);
  }
}

void controlMotors(char c) {
  switch (c) {
    case 'F': // Forward
      analogWrite(3, 200);
      analogWrite(11, 0);
      analogWrite(5, 200);
      analogWrite(6, 0);
      break;
    case 'B': // Backward
      analogWrite(3, 0);
      analogWrite(11, 200);
      analogWrite(5, 0);
      analogWrite(6, 200);
      break;
    case 'L': // Left turn
      analogWrite(3, 0);
      analogWrite(11, 200);
      analogWrite(5, 200);
      analogWrite(6, 0);
      break;
    case 'R': // Right turn
      analogWrite(3, 200);
      analogWrite(11, 0);
      analogWrite(5, 0);
      analogWrite(6, 200);
      break;
    case 'S': // Stop
      analogWrite(3, 0);
      analogWrite(11, 0);
      analogWrite(5, 0);
      analogWrite(6, 0);
      break;
  }
}
