
#include<Servo.h>
int lightval;
int lightpin=A0;
int servopin=9;
Servo myservo;

void setup() {
  Serial.begin(9600);
  pinMode(lightpin,INPUT);
 myservo.attach(servopin);
 pinMode(servopin,OUTPUT);
}

void loop() {
  lightval=analogRead(lightpin);
  Serial.println(lightval);
  delay(100);

voltage = lightval;
float voltage = 5.0*(lightval)/1023;
Serial.print ("volatge= ");
Serial.println(volatge);
delay(1);


}