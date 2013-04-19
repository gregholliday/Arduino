#include <PS2X_lib.h>
#include <Servo.h>
#include <includes.h>

//Moter A uses pins 
//Direction - D12
//PWM - D3
//Brake - D9
//Current Sensing - A0

//Motor B uses pins
//Direction - D13
//PWM - D11
//Brake - D8
//Current Sensing - A1


Servo servo;


void setup()
{
  Serial.begin(57600);
  
  //Setup the servo
  servo.attach(SERVOPIN);
  servoCenter(CENTER,2000);
  
  //Setup Channel A
  pinMode(MRDIR,OUTPUT); //Initiates Motor Channel A pin
  pinMode(MRBRK, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(MRDIR, OUTPUT); //Initiates Motor Channel A pin
  pinMode(MRBRK, OUTPUT);  //Initiates Brake Channel A pin
  
}

void loop()
{
  
}

void roam()
{
  int distance = lookAt(SERVOANGLES[CENTER]);
  
  if(distance == 0)
  {
    
     moveStop();
     Serial.println("No front sensor");
     return;
  }else if(distance <= MINDISTANCE){
    moveStop();
    int leftDistance = lookAt(SERVOANGLES[LEFT]);
    if(leftDistance > CLEARDISTANCE)
    {
      moveRotate(-90);
    }else {
      delay(500);
      int rightDistance = lookAt(SERVOANGLES[RIGHT]);
      if(rightDistance > CLEARDISTANCE)
      {
        moveRotate(90);
      }else{
        distance = max(leftDistance, rightDistance);
        if(distance < CLEARDISTANCE/2){
          moveRotate(-180);
        }else{
          if(leftDistance > rightDistance){
            moveRotate(-90);
          }else{
            moveRotate(90);
          }
        }
      }
    }
  }
}
