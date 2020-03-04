#include<Servo.h>
#define DEBUG 1
Servo dropServo(3);
bool dropBox(){
	dropServo.write(0);
	delay(1000);
	dropServo.Write(90);
	if(DEBUG){
		Serial.println("I drop Box");
	}
}
