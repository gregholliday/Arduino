//writes given angle to servo for given delay in milliseconds
void servoWrite(int angle, long servoDelay)
{
  int pulsewidth = map(angle, 0, 180, 544, 2400); //width in microseconds
  Serial.println(pulsewidth);
  do{
    servo.writeMicroseconds(pulsewidth);
    delay(20); //wait for 20 milliseconds
    servoDelay -= 20;
  }while(servoDelay >=0);
}

void servoLeft(){
  servoWrite(180,2000);
}

void servoRight(){
  servoWrite(0,2000);
}

void servoCenter(){
  servoWrite(90,2000);
}
