/* CONTROLS THE STEPPER MOTOR USING THE JOYSTICK, THE MAIN THEME OF THIS CODE IS THAT IT IS A JOYSTICK INPUT*/ 
 
#include <Stepper.h> 
  
const int stepsPerRevolution = 2048;  // Number of steps per revolution for the stepper motor 
const int rpm = 15;                    // Speed in revolutions per minute 
const int X_pin = A1;                  // Joystick X-axis input pin 
  
// Define the stepper motor control pins 
Stepper myStepper(stepsPerRevolution, 2, 3, 4, 5); // Pin 2, 3, 4, 5 control the stepper motor 
  
void setup() { 
  myStepper.setSpeed(rpm);  // Set the stepper motor speed (15 RPM) 
  Serial.begin(9600);       // Initialize serial communication for debugging (optional) 
} 
  
void loop() { 
  int joystickValue = analogRead(X_pin);  // Read joystick X-axis value (0 to 1023) 
  
  // Debugging: Print joystick value to the serial monitor (optional) 
  Serial.println(joystickValue); 
  
  // Move the motor depending on the joystick position 
  if (joystickValue < 400) { 
    myStepper.step(-30);  // Move motor counterclockwise (30 steps) 
  } else if (joystickValue > 600) { 
    myStepper.step(30);   // Move motor clockwise (30 steps) 
  } 
  
  delay(100);  // Small delay to control the frequency of joystick updates 
} 