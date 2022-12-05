

#include <IRremote.h>


int IRpin = 6;  // pin for the IR sensor


IRrecv irrecv(IRpin);

decode_results results;


int motor_speed_del = 25,motor_speed=50;

void setup()

{

  Serial.begin(9600);

  Serial.println("IR Remote controlled stepper motor");

  irrecv.enableIRIn();  // Start the receiver

   pinMode(8,OUTPUT); // stepper motor pins as outputs

  pinMode(9,OUTPUT);

  pinMode(10,OUTPUT);

  pinMode(11,OUTPUT);

}


void loop() 

{

while(!(irrecv.decode(&results)));// if no button is pressed, wait until no               //code is received  

 if (irrecv.decode(&results)) //when code is received 

    {

      if(results.value==2210)  // if button 1 is pressed

        {

          Serial.println("Motor will rotate 1 revolution");

          rotate_motor(1); // rotate motor 1 revolutions

        }

      else if(results.value==6308) // if button 2 is pressed

        {

          Serial.println("Motor will rotate 2 revolution");

          rotate_motor(2); // rotate motor 2 revolutions

        }  

       else if(results.value==2215) // same for button 3, 4 and 5 

        {

          Serial.println("Motor will rotate 3 revolution");

          rotate_motor(3);

        }  

       else if(results.value==6312) 

        {

          Serial.println("Motor will rotate 4 revolution");

          rotate_motor(4);

        } 

       else if(results.value==2219) 

        {

          Serial.println("Motor will rotate 5 revolution");

          rotate_motor(5);

        }   

       else if(results.value==6338) //if volume up button is pressed

         {

            if(motor_speed_del>10) motor_speed_del-=5; //decrease the delay

            Serial.print("Motor speed increased to ");

            motor_speed = 60000/(motor_speed_del*48);// calculate RPM            

            Serial.println(motor_speed);             // display RPM    

         }

      else if(results.value==6292) // if volume down button is pressed 

        {

            if(motor_speed_del<50) motor_speed_del+=5; //increase delay 

            Serial.print("Motor speed decreased to ");

            motor_speed = 60000/(motor_speed_del*48); // calculate RPM

            Serial.println(motor_speed);    // display it

        }

      delay(200);     // wait for 0.2 sec 

      irrecv.resume();        // ready to receive next code

    }

 }

// function to rotate stepper motor

void rotate_motor(int r) 

  {

    int x; 

    for(x=0;x<r*12;x++) // rotate motor desire number of rotations

    {

      digitalWrite(8,HIGH);

      delay(motor_speed_del);

      digitalWrite(8,LOW);

      digitalWrite(9,HIGH);

      delay(motor_speed_del);

      digitalWrite(9,LOW);

      digitalWrite(10,HIGH);

      delay(motor_speed_del);

      digitalWrite(10,LOW);

      digitalWrite(11,HIGH);

      delay(motor_speed_del);

      digitalWrite(11,LOW);

    }

  }

###