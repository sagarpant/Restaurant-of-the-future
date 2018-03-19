void doEncoderC() {

  if ( rotating ) delay (1);


  if ( digitalRead(encoderPinA) != A_set ) {
    A_set = !A_set;

    if ( A_set && !B_set )
      encoderPos_l += 1;

    rotating = false;
  }
}


void doEncoderD() {
  if ( rotating ) delay (1);
  if ( digitalRead(encoderPinB) != B_set ) {
    B_set = !B_set;

    if ( B_set && !A_set )
      encoderPos_l -= 1;

    rotating = false;
  }
}
void doEncoderA() {

  if ( rotating1 ) delay (1);


  if ( digitalRead(encoderPinC) != A_set1
 ) {
    A_set1 = !A_set1;
    if ( A_set1 && !B_set1 )
      encoderPos_r += 1;

    rotating1 = false;
  }
}
void doEncoderB() {

  if ( rotating1 ) delay (1);


  if ( digitalRead(encoderPinD) != A_set1 ) {
    A_set1 = !A_set1;

    if ( A_set1 && !B_set1 )
      encoderPos_r -= 1;

    rotating1 = false;
  }
}

