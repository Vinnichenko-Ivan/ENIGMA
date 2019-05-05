#include<motor.h>
#include <Wire.h> //Include the Wire Library
#include <HTInfraredSeeker.h>
Motor m;
Line l;
US us;
int witch = 182, lenght = 553, x, y, kpv = -6, str,blacksqart=55;
bool stoper = 0;
bool ball = 0, zakrutie = 0, leftColor, rightColor;
long time_punch = 0;
bool power  = 0, charge = 0;
long time_power = 0;
bool debug = 1, gete = 0, ate = 1, rb, lb, sb, bb;
String beta;
char c = ' ';
int degree = -1, kp = 5, count = 0;
long timeOld, timeNew, timer = 0;
int pozitiondegree, azimut, degreeToTarget;

void gyro();
int getdegree();

void back() {
  if (bb) {
    m.motors(255 - degreeToTarget * kp, 1);
    m.motors(0, 2); //straight
    m.motors(-255 - degreeToTarget * kp, 3);
  }
    else{
        m.motors(degreeToTarget * kpv, 1);
    m.motors(degreeToTarget * kpv, 2); //straight
    m.motors(degreeToTarget * kpv, 3);
    }
}
void straight() {
  if (sb) {
    m.motors(-255 - degreeToTarget * kp, 1);
    m.motors(0, 2); //straight
    m.motors(255 - degreeToTarget * kp, 3);
  }
  else{
        m.motors(degreeToTarget * kpv, 1);
    m.motors(degreeToTarget * kpv, 2); //straight
    m.motors(degreeToTarget * kpv, 3);
    }
}
void left() {
  if (lb) {
    m.motors(-110 - degreeToTarget * kp, 1); //left
    m.motors(250 - degreeToTarget * kp, 2);
    m.motors(-110 - degreeToTarget * kp, 3);
  }
    else{
       m.motors(degreeToTarget * kpv, 1);
    m.motors(degreeToTarget * kpv, 2); //straight
    m.motors(degreeToTarget * kpv, 3);
    }
}
void right() {

  if (rb) {
    m.motors(110 - degreeToTarget * kp, 1); //left
    m.motors(-250 - degreeToTarget * kp, 2);
    m.motors(110 - degreeToTarget * kp, 3);
  }
    else{
        m.motors(degreeToTarget * kpv, 1);
    m.motors(degreeToTarget * kpv, 2); //straight
    m.motors(degreeToTarget * kpv, 3);
    }


}
void punch() {

  if (power && charge) {
    digitalWrite(53, 1);
    delay(100);
    digitalWrite(53, 0);
    power = 0;
    charge = 0;
  }
}
void setup() {
  l.calibrate();
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);
  timeNew = 0;
  //pinMode(52, INPUT);//TODO knopka
  InfraredSeeker::Initialize();
  //Serial1.println("\n");
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  m.ports(3, 2, 4, 6, 7, 5, 8, 9, 10);
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.print(" Dir ");
  Serial1.println("\n");
  timer = millis();
  while (degree == -1) {
    gyro();
  }
  azimut = degree;
  Serial.print(" Dir ");
}
void testPunch() {

  if (power == 0 && charge == 0) {
    digitalWrite(52, 1);
    time_power = millis();
    charge = 1;
  }
  if (millis() - time_power > 1500 && charge) {
    digitalWrite(52, 0);
    power  = 1;
    charge = 1;
  }

}
void loop() {
  rb = 1;
  lb = 1;
  sb = 1;
  bb = 1;
  testPunch();
  us.dist();
  l.line();
  // Serial.print(" Dir ");
  gyro();
  degreeToTarget = getdegree() ;
  // ball=digitalRead(52);
  InfraredResult InfraredBall = InfraredSeeker::ReadAC();
  int Dir = InfraredBall.Direction;
  str = InfraredBall.Strength;
  int inzone = 0;
  if ( us.distanceRight + us.distanceLeft < 162 || us.distanceBack < 55 && ( us.distanceRight > blacksqart &&  us.distanceLeft > blacksqart) && us.distanceBack > 45) {
    inzone = 1;
  }
    if (inzone == 0) {
    if (us.distanceRight < blacksqart) {
      rb = 0;
    }
     if (us.distanceLeft < blacksqart) {
      lb = 0;
    }
     if ( us.distanceBack > 55) {
      sb = 0;
    }
     if (us.distanceBack < 45) {
      bb = 0;
    }
  }
  if (debug && millis() - timeNew > 1000) {
    timeNew = millis();
    Serial.print(" rb ");
    Serial.print(rb);
    Serial.print(" lb ");
    Serial.print(lb);
    Serial.print(" sb ");
    Serial.print(sb);
    Serial.print(" bb ");
    Serial.print(bb);
    Serial.print(" inzone ");
    Serial.print(inzone);
    Serial.print(" Dir ");
    Serial.print(Dir);
    Serial.print(" str ");
    Serial.print(str);
    Serial.print(" right ");
    Serial.print(l.right);
    Serial.print(" rightD ");
    Serial.print(l.rightD);
    Serial.print(" leftD ");
    Serial.print(l.leftD);
    Serial.print(" left ");
    Serial.print(l.left);
    Serial.print(" rightB ");
    Serial.print(l.rightB);
    Serial.print(" rightDB ");
    Serial.print(l.rightDB);
    Serial.print(" leftDB ");
    Serial.print(l.leftDB);
    Serial.print(" leftB ");
    Serial.print(l.leftB);
    Serial.print(" distanceLeft ");
    Serial.print( us.distanceLeft);
    Serial.print(" distanceRight ");
    Serial.print( us.distanceRight);
    Serial.print(" distanceBack ");
    Serial.print( us.distanceBack);
    Serial.print(" degreeToTarget ");
    Serial.print(degreeToTarget);
    Serial.print(" azimut ");
    Serial.print(azimut);
    Serial.print(" degree ");
    Serial.println(degree);
  }

  if (l.rightB || l.rightDB || l.leftB || l.leftDB)
  {
    if (l.rightB || l.rightDB) {
      for (int i = 0; i < 1300; i++) {
        left();
        gyro();
        lb = 1;
      }
    }
    else if (l.leftB || l.leftDB) {
      for (int i = 0; i < 1300; i++) {
        rb = 1;
        gyro();
        right();
      }
    }
  }
  else if (Dir == 5 && str > 200 && ate) {
    straight();
    punch();
  }
  else if (Dir == 1 || Dir == 2 && str > 200) {
    if(bb){
    m.motors(125 - degreeToTarget * kp, 1); //left
    m.motors(-130 - degreeToTarget * kp, 2);
    m.motors(-125 - degreeToTarget * kp, 3); //left
    }
    else{
      m.STOP();
      }
  }
  else if (Dir == 9 || Dir == 8 && str > 200) {
    if(bb){
    m.motors(125 - degreeToTarget * kp, 1); //left
    m.motors(130 - degreeToTarget * kp, 2);
    m.motors(-125 - degreeToTarget * kp, 3); //left
    }
        else{
      m.STOP();
      }
  }

  else if ( us.distanceBack < 40) {
    straight();
  }

  else if (Dir < 5 && Dir != 0) {
    left();
  }
  else if (Dir > 5) {
    right();
  }
  else if ( us.distanceBack > 55) {
    back();
  }
  else if ( us.distanceBack < 45) {
    straight();
  }
  else if (Dir == 5 || Dir == 0) {
    //left();
    //
    m.motors(degreeToTarget * kpv, 1);
    m.motors(degreeToTarget * kpv, 2); //straight
    m.motors(degreeToTarget * kpv, 3);//}
  }
}
void gyro() {

  if (Serial1.available()) {

    // get the new byte:
    c = (char)Serial1.read();
    //Serial.print(c);
    // add it to the inputString:
    beta += c;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (c == '\n') {

      degree = beta.toInt();
      beta = "";
      gete = 1;
      // Serial.println(degree);
      // Serial1.println("\n");
    }
  }
  if (gete && millis() - timer > 50) {
    Serial1.println("\n");
    timer = millis();
    gete = 0;
  }
}



int getdegree() {
  return (degree + 540 - azimut) % 360 - 180;
}
