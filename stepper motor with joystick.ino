// include Arduino stepper motor library
#include <Stepper.h>
 
// define number of steps per revolution
#define STEPS 32

// Create Instance of Stepper Class
// Specify Pins used for motor coils
// The pins used are 8,9,10,11 
// Connected to ULN2003 Motor Driver In1, In2, In3, In4 
// Pins entered in sequence 1-3-2-4 for proper step sequencing
// define stepper motor control pins
#define IN1  11
#define IN2  10
#define IN3   9
#define IN4   8
 
// initialize stepper library
Stepper stepper(STEPS, IN4, IN2, IN3, IN1);
 
// joystick pot output is connected to Arduino A0
#define joystick  A0
 
void setup()
{
// Nothing  (Stepper Library sets pins as outputs)
}
 
void loop()
{
  int val = analogRead(joystick);
 
  // if the joystic is in the middle ===> stop the motor
  if(  (val > 500) && (val < 523) )
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
 
  else
  {
    // move the motor in the first direction
   if (val >= 523)
    {
      // map the speed between 5 and 500 rpm
      int speed_ = map(val, 523, 1023, 5, 500);
      // set motor speed
      stepper.setSpeed(speed_);
 
      // move the motor (1 step)
      stepper.step(1);
 
      val = analogRead(joystick);
    }
 
    // move the motor in the other direction
    if (val <= 500)
    {
      // map the speed between 5 and 500 rpm
      int speed_ = map(val, 500, 0, 5, 500);
      // set motor speed
      stepper.setSpeed(speed_);
 
      // move the motor (1 step)
      stepper.step(-1);
 
      val = analogRead(joystick);
    }
 
  }
 
}
