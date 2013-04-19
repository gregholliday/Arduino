const int MRDIR = 12;
const int MRBRK = 9;
const int MRPWM = 3;

const int M2Dir = 13;
const int M2Brk = 8;
const int M2Pwm = 11;

const int MAXSPEED = 255;
const int NORMSPEED = 127;
const int MINSPEED = 80;
const int FULLSTOP = 0;
const int SPEEDINC = 20;

const byte PINGPIN = 2;
const int SERVOPIN = 10;


const int LEFT = 180;
const int RIGHT = 0;
const int CENTER = 90;

const int MINDISTANCE = 6;  //robot stops when object is closer than (in inches)
const int CLEARDISTANCE = 12; //distance in inches considered to be clear to move
const int MAXDISTANCE = 150; //maximum range of sensor

const int SERVOANGLES[] = {180,0,90};
const int SERVODELAY = 2000;

const int OBST_NONE       = 0;  // no obstacle detected
const int OBST_LEFT_EDGE  = 1;  // left edge detected 
const int OBST_RIGHT_EDGE = 2;  // right edge detected
const int OBST_FRONT_EDGE = 3;  // edge detect at both left & right sensors
const int OBST_FRONT      = 4;  // obstacle in front
const int OBST_REAR       = 5;  // obstacle behind 




