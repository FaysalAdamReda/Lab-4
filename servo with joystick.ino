#include <Servo.h>

//Include the servo library

Servo servo1;


int joyX =0;
int joyY =1;


int joyVal;

void setup()
{ //attaches our servos on pins PWM 9
  servo1.attach(9);

}

void loop()
{
  //read the value of joystick (between 0-1023)
  joyVal = analogRead(joyX);
  joyVal = map (joyVal, 0, 1023, 0, 180); //servo value between 0-180
  servo1.write(joyVal); //set the servo position according to the joystick value

  joyVal = analogRead(joyY);
  joyVal = map (joyVal, 0, 1023, 0, 180);
  servo1.write(joyVal);
  delay(15);
}