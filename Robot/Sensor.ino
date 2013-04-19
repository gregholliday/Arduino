int pingGetDistance(int pingPin){
  long duration, cm;
  
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin,LOW);
  
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin,HIGH,20000);
  
  if(duration >= 20000)
    duration = 10000;
    
  cm = microsecondsToCentimeters(duration);
  Serial.println((cm * 10)/25);
  return (cm * 10)/25;
}

long microsecondsToCentimeters(long microseconds){
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds /29 /2;
}

boolean lookForObstacle(int obstacle)
{
  switch(obstacle)
  {
    case OBST_FRONT:
      return lookAt(servoAngles[CENTER]) <= MIN_DISTANCE;
    case OBST_FRONT_EDGE:
      irEdgeDetect(LEFT) && irEdgeDetect(RIGHT);
    case OBST_LEFT_EDGE:
      return irEdgeDetect(LEFT);
    case OBST_RIGHT_EDGE:
      return irEdgeDetect(RIGHT);
  }
  return false;
}

int lookAt(int angle)
{
  servoWrite(angle,SERVODELAY);
  
  int distance, samples;
  long cume;
  distance = samples = cume = 0;
  
  for(int i=0; i<4; i++)
  {
    distance = pingGetDistance(PINGPIN);
    if(distance > 0)
    {
      samples++;
      cume += distance;
    }
  }
  if(samples > 0)
    distance = cume / samples;
  else
    distance = 0;
    
  if(angle != SERVOANGLES[CENTER])
  {
    Serial.print("Looking at dir ");
    Serial.print(angle), Serial.print(" distance= ");
    Serial.print.println(distance);
    servoWrite(SERVOANGLES[CENTER],SERVODELAY / 2);
  }
  return distance;
}

boolean checkMovement()
{
 boolean isClear = true;
 
 if(moveGetState() == MOV_FORWARD)
 {
   if(lookForObstacle(OBST_FRONT) == true)
   {
     isClear = false;
   }
   return isClear;
 }
}



