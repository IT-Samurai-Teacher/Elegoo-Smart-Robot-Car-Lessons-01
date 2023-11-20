/*
 * @ITSamuraiTeacher
 * https://www.youtube.com/@ITSamuraiTeacher
 */
#include "DeviceDriverSet_xxx0.h" // Include the header file for the device driver

/*ULTRASONIC*/
void DeviceDriverSet_ULTRASONIC::DeviceDriverSet_ULTRASONIC_Init(void)
{
  pinMode(ECHO_PIN, INPUT); // Set the ECHO_PIN as an INPUT for the ultrasonic sensor
  pinMode(TRIG_PIN, OUTPUT); // Set the TRIG_PIN as an OUTPUT for the ultrasonic sensor
}

void DeviceDriverSet_ULTRASONIC::DeviceDriverSet_ULTRASONIC_Get(uint16_t *ULTRASONIC_Get /*out*/)
{
  unsigned int tempda_x = 0;
  digitalWrite(TRIG_PIN, LOW); // Send a LOW pulse to TRIG_PIN to prepare for sending out a ping
  delayMicroseconds(2); // Short delay after setting the pin LOW
  digitalWrite(TRIG_PIN, HIGH); // Send a HIGH pulse to TRIG_PIN to send out a ping
  delayMicroseconds(10); // Wait for 10 microseconds for the ping to go out
  digitalWrite(TRIG_PIN, LOW); // Set the TRIG_PIN back to LOW
  tempda_x = ((unsigned int)pulseIn(ECHO_PIN, HIGH) / 58); // Measure the time for echo and calculate distance
  *ULTRASONIC_Get = tempda_x; // Store the calculated distance in the provided pointer variable
}

void DeviceDriverSet_ULTRASONIC::DeviceDriverSet_ULTRASONIC_Test(void)
{
  unsigned int tempda = 0;
  digitalWrite(TRIG_PIN, LOW); // Send a LOW pulse to TRIG_PIN to prepare for sending out a ping
  delayMicroseconds(2); // Short delay after setting the pin LOW
  digitalWrite(TRIG_PIN, HIGH); // Send a HIGH pulse to TRIG_PIN to send out a ping
  delayMicroseconds(10); // Wait for 10 microseconds for the ping to go out
  digitalWrite(TRIG_PIN, LOW); // Set the TRIG_PIN back to LOW
  tempda = ((unsigned int)pulseIn(ECHO_PIN, HIGH) / 58); // Measure the time for echo and calculate distance

  Serial.print("ULTRASONIC="); // Print a label to the serial monitor
  Serial.print(tempda); // Print the calculated distance to the serial monitor
  Serial.println("cm"); // Print the unit (centimeters) and a new line
}
