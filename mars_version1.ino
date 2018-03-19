enum PinAssignments
{
  encoderPinA =18,
  encoderPinB = 19,
  encoderPinC = 2,
  encoderPinD = 3,

  motorPinR1 = 4,
  motorPinR2 = 5,
  motorPinL1 = 7,
  motorPinL2 = 6,  
};
//---------------------------------------------------
int maxSpeed = 50;
//---------------------------------------------------
double left_pwm=0;
double right_pwm=0;
//---------------------------------------------------
int error=0;
int d_error = 0;
int pre_error;
double correction=0;
//````````````````````
double kp=2.5;
double kd=0.1;
//`````````````````````
volatile int lastReportedPos_l= 0;
volatile int lastReportedPos_r= 0;
volatile int encoderPos_l= 0;
volatile int encoderPos_r=0; 
//----------------------------------------------------
int pos_l = 0;
int pos_r = 0;
//----------------------------------------------------
static boolean rotating = false;
static boolean rotating1 = false;
boolean A_set = false;
boolean B_set = false;
boolean B_set1 = false;
boolean A_set1 = false;
//-----------------------------------------------------
/*int radius;
int half_distance_between_wheel;
int angle;
int k;*/

bool halt=1;

void setup() {

  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);
  pinMode(encoderPinC, INPUT_PULLUP);
  pinMode(encoderPinD, INPUT_PULLUP);

 

  pinMode(motorPinR1, OUTPUT);
  pinMode(motorPinR2, OUTPUT);

  pinMode(motorPinL1, OUTPUT);
  pinMode(motorPinL2, OUTPUT);

  interrupts();
  attachInterrupt(digitalPinToInterrupt(2), doEncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), doEncoderB, CHANGE);

 attachInterrupt(digitalPinToInterrupt(18), doEncoderC, CHANGE);
attachInterrupt(digitalPinToInterrupt(19), doEncoderD, CHANGE);
  
  //attachInterrupt(0, encoder_funcR, CHANGE);
  //attachInterrupt(1, encoder_funcR, CHANGE);

  //attachInterrupt(0,int_ra,CHANGE);
//  attachInterrupt(1,int_rb,CHANGE);
//  
//  attachInterrupt(4,int_la,CHANGE);
//  attachInterrupt(5,int_lb,CHANGE);


  digitalWrite(motorPinR1, LOW);
  digitalWrite(motorPinR2, LOW);

  digitalWrite(motorPinL1, LOW);
  digitalWrite(motorPinL2, LOW);
  
  Serial.begin(9600);
}


void loop()
{
//  rotating = true;
//  rotating1 = true;
//  
  print_encoder();
  pid();
  test_straight();   
}
