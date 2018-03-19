#define left_pwm 7
#define left_dir 6
#define right_pwm 5
#define right_dir 4

#define proxi_right 18
#define proxi_left 19

long count_right=0;
long count_left=0;
long rpm=0;
double t=0;
double pre_t=0;
long 
t_count=5000;
int pwm = 50;
int i=0;
double error, pre_error, d_error, cor = 0.0;
double Kp=5.0;
double Kd=0.0;

void setup() {
  // put your setup code here, to run once:
pinMode(proxi_left,INPUT);
pinMode(proxi_right,INPUT);
pinMode(left_pwm,OUTPUT);
pinMode(left_dir,OUTPUT);
pinMode(right_dir,OUTPUT);
pinMode(right_pwm,OUTPUT);
attachInterrupt(digitalPinToInterrupt(proxi_right),isr_right,CHANGE);
attachInterrupt(digitalPinToInterrupt(proxi_left),isr_left,CHANGE);
Serial.begin(9600);
}

void isr_right()
{
 
 count_right++;
}

void isr_left()
{
  
 i++;
 if(i%2==0)
 {count_left++;}
}
void loop() 
{
  while(count_left<=t_count||count_right<=t_count)
  {
    if(count_left<=t_count&&count_right<=t_count)
    {
      pid(pwm);
    }
    else if(count_left>t_count&&count_right<=t_count)
    {
      pid(pwm);
      analogWrite(left_pwm,0);
    }
    else if(count_right>t_count&&count_left<=t_count)
    {
      pid(pwm);
      analogWrite(right_pwm,0);
    }
    print_pwm();
  }
  analogWrite(right_pwm,0);
  analogWrite(left_pwm,0);
  
}
