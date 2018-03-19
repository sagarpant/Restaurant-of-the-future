void pid(int a)
{
  error = count_left - count_right;
  d_error = error - pre_error;
  cor = Kp * error + Kd * d_error;
  pre_error = error;


   if(count_left<=120&&count_right<=120)
  {digitalWrite(right_dir,LOW);
  digitalWrite(left_dir,LOW);}

   else if(count_left>120&&count_right>120&&count_left<=136&&count_right<=136)
  {digitalWrite(right_dir,LOW);
  digitalWrite(left_dir,HIGH);}


   else if(count_left>136&&count_right>136&&count_left<=151&&count_right<=151)
  {digitalWrite(right_dir,LOW);
  digitalWrite(left_dir,LOW);}

  else
  {analogWrite(left_pwm, a-cor);
  analogWrite(right_pwm, a+cor);}
  
  analogWrite(left_pwm, a-cor);
  analogWrite(right_pwm, a+cor);
}

void print_pwm()
{
    Serial.print("count_left ");
    Serial.print(count_left);
    Serial.print(" count right ");
    Serial.print(count_right);
    Serial.print(" error ");
    Serial.print(error);
    Serial.print(" correction ");
    Serial.println(cor);
}

