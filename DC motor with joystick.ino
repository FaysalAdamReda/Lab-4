//motor speed direction joystick 

int enB = 5;
int in3 = 4;
int in4 = 4;
int x;
int Speed;

void setup() {
pinMode(enB,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(A1,INPUT);
Serial.begin(9660);
}
// PIN setup

void loop() {
  x= analogRead(A1);
  Serial.println(x);

// joystick reading on x - axis  
if (x<500){
x = map(x,500,0,0,255);
digitalWrite(in3,HIGH);
digitalWWrite(in4,LOW);
analogWrite(enB,x);
}
//

if (x>520){
x = map(x,520,1023,0,255);
digitalWrite(in3,LOW);
digitalWWrite(in4,HIGH);
analogWrite(enB,x);
}

// fan stops at this position
else if (x > 508 && x < 515){
digitalWrite(in3,LOW);
digitalWWrite(in4,LOW);
analogWrite(enB,LOW);
}

}