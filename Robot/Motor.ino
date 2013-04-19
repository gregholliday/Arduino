void turnLeft(int spd)
{
  digitalWrite(MLBRK,HIGH); //Brake the left motor
  digitalWrite(MRDRK,HIGH); //Set right motor direction forward
  analogWrite(MRPWM,spd);
}

void turnRight(int spd)
{
  digitalWrite(MRBRK,HIGH); //Brake the left motor
  digitalWrite(MLDIR,HIGH); //Set right motor direction forward
  analogWrite(MLDIR,spd);
}

void moveFwd(int spd)
{
  digitalWrite(MRBRK,LOW); //No brake
  digitalWrite(MLBRK,LOW); //No brake
  digitalWrite(MLDIR,HIGH); //Direction FORWARD
  digitalWrite(MRDIR,HIGH); //Direction FORWARD
  
  analogWrite(MRPWM,spd); 
  analogWrite(MLPWM,spd);
}

void moveBak(int spd)
{
  digitalWrite(MRBRK,LOW); //No brake
  digitalWrite(MLBRK,LOW); //No brake
  digitalWrite(MRDIR,LOW); //Direction BACKWARD
  digitalWrite(MLDIR,LOW); //Direction BACKWARD
  
  analogWrite(MRPWM,spd); 
  analogWrite(MLPWM,spd);
}

void moveStop()
{
  analogWrite(MRPWM,FULLSTOP);
  analogWrite(MLPWM,FULLSTOP);
}


