void encoder_funcR() {
  if(!digitalRead(2)) {
    encoderPos_r++;
  }
}

void encoder_funcL() {
  if(!digitalRead(18)) {
    encoderPos_l++;
  }
} 
