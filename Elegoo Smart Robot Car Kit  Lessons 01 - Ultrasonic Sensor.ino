/*
 * @ITSamuraiTeacher
 * https://www.youtube.com/@ITSamuraiTeacher
 */
#include <Arduino.h>
#include <Servo.h>
#include "DeviceDriverSet_xxx0.h" // Include the Elegoo library

DeviceDriverSet_ULTRASONIC myUltrasonic; // Create an ultrasonic object
Servo myServo; // Create a servo object

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud
  myUltrasonic.DeviceDriverSet_ULTRASONIC_Init(); // Initialize the ultrasonic sensor
  myServo.attach(10); // Attach the servo motor to pin 10 (Servo 1)
}

void loop() {
  uint16_t distance; // Variable to store the distance measurement

  for(int angle = 0; angle <= 180; angle += 30) { // Rotate servo from 0 to 180 degrees in steps
    myServo.write(angle); // Set servo position
    delay(500); // Wait for servo to reach position

    myUltrasonic.DeviceDriverSet_ULTRASONIC_Get(&distance); // Get distance measurement
    Serial.print("Distance at angle ");
    Serial.print(angle);
    Serial.print(": ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(1000); // Wait before next measurement
  }
}
