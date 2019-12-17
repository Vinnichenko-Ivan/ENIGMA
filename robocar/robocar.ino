#include "robocar.h"
colorSensor colorLeft1;
colorSensor colorLeft2;
colorSensor colorLeft3;
colorSensor colorRight1;
colorSensor colorRight2;
colorSensor colorRight3;
Motor Motor;
PID PID;
turnMotor turnMotor;
void setup() {
Serial.begin(115200);
colorRight3.calibrate(A0);
colorRight2.calibrate(A1);
colorRight1.calibrate(A2);
colorLeft1.calibrate(A5);
colorLeft2.calibrate(A4);
colorLeft3.calibrate(A3);
Motor.calibrate(110);
PID.calibrate(0.05,0,0,0);
turnMotor.calibrate(133,78,(133+78)/2,6);
}

void loop() {
turnMotor.setTurn(PID.UI(colorLeft1.getLight()+colorLeft2.getLight()*1.5-colorRight1.getLight()-colorRight2.getLight()*1.5));
Motor.setSpeed(50);
//Serial.print(" UI: ");
//Serial.print(PID.UI(colorLeft1.getLight()+colorLeft2.getLight())*1.5-colorRight1.getLight()-colorRight2.getLight()*1.5);
//Serial.print(" l3: ");
//Serial.print(colorLeft3.getLight());
//Serial.print(" l2: ");
//Serial.print(colorLeft2.getLight());
//Serial.print(" l1: ");
//Serial.print(colorLeft1.getLight());
//Serial.print(" r1: ");
//Serial.print(colorRight1.getLight());
//Serial.print(" r2: ");
//Serial.print(colorRight2.getLight());
//Serial.print(" r3: ");
//Serial.println(colorRight3.getLight());
//delay(250);
}
