void turnLeft(int spd)
{
  digitalWrite(M2Brk,HIGH); //Brake the left motor
  digitalWrite(M1Dir,HIGH); //Set right motor direction forward
  analogWrite(M1Pwm,spd);
}

void turnRight(int spd)
{
  digitalWrite(M1Brk,HIGH); //Brake the left motor
  digitalWrite(M2Dir,HIGH); //Set right motor direction forward
  analogWrite(M2Pwm,spd);
}

void moveFWD(int spd)
{
  digitalWrite(M1Brk,LOW); //No brake
  digitalWrite(M2Brk,LOW); //No brake
  digitalWrite(M1Dir,HIGH); //Direction FORWARD
  digitalWrite(M2Dir,HIGH); //Direction FORWARD
  
  analogWrite(M1Pwm,spd); 
  analogWrite(M2Pwm,spd);
}

void moveBAK(int spd)
{
  digitalWrite(M1Brk,LOW); //No brake
  digitalWrite(M2Brk,LOW); //No brake
  digitalWrite(M1Dir,LOW); //Direction BACKWARD
  digitalWrite(M2Dir,LOW); //Direction BACKWARD
  
  analogWrite(M1Pwm,spd); 
  analogWrite(M2Pwm,spd);
}
