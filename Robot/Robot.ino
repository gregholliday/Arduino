#include <PS2X_lib.h>
#include <Servo.h>
#include <include.h>

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
  pinMode(M1Dir, OUTPUT); //Initiates Motor Channel A pin
  pinMode(M1Brk, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(M2Dir, OUTPUT); //Initiates Motor Channel A pin
  pinMode(M2Brk, OUTPUT);  //Initiates Brake Channel A pin
  
}

void loop()
{
  
}
