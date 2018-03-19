void pid()
{
  error = (encoderPos_r - encoderPos_l );
  d_error=error-pre_error;
  correction = kp*error + kd*d_error;
  pre_error=error;
 
  left_pwm=maxSpeed+correction;
  right_pwm=maxSpeed-correction;
  
  limit(left_pwm);
  limit(right_pwm);
}
void limit(double &x)
{
  if(x>1.5*maxSpeed)
    x=1.5*maxSpeed;
  else if (x<0.5*maxSpeed)
    x=0.5*maxSpeed;
}

