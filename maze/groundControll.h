#include<Servo.h>
#define DEBUG 1
class dropServo
{
	private:
		Servo dropServo;
	public:
		bool dropBox();
		dropServo();
};

dropServo::dropServo()
{
		dropServo.attach(3);
}

bool dropServo::dropBox()
{
	dropServo.write(0);
	delay(1000);
	dropServo.write(90);
	if(DEBUG){
		Serial.println("I drop Box");
	}
}
//----------------------------------------------------------------------------------------------------------------//

class PID
{
  public:
    double ki=0,kp=0,kd=0,imax=0;
    double error,errorOld,errorIntegral,errorDeviante;  
    unsigned long dt,dn;
    void calibrate(float kpc,float kic,float kdc,float imaxc);
    double UI(int error);
};

void PID::calibrate(float kpc,float kic,float kdc,float imaxc)
{
  ki=kic;
  kp=kpc;
  kd=kdc;
  imax=imaxc;
}

double PID::UI(int error)
{ 
  errorIntegral+=error*(millis()-dt);
  if(errorIntegral>imax){
    errorIntegral=imax;
  }
  if(errorIntegral<-imax){
    errorIntegral=-imax;
  }
  errorDeviante=(error-errorOld);
  errorOld=error;
  dt=millis();
  return error*kp +errorIntegral*ki+errorDeviante*kd;
}
//-------------------------------------------------------------------------------------------------------------------//

class moveControll
{
	private:
		int maxPower(int power);
	public:
		moveControll();
};

moveControll::moveControll()
{
	pinMode(11,OUTPUT);
	pinMode(10,OUTPUT);
	pinMode(9,OUTPUT);
	pinMode(8,OUTPUT);
	pinMode(7,OUTPUT);
	pinMode(6,OUTPUT);
}

int moveControll:maxPower(int power)
{
	if(power<-255)
	{
		return -255;
	}
	else if(power>255)
	{
		return 255;
	}
	else
	{
		return power;	
	}
}
//---------------------------------------------------------------------------------------------------------------------//

class US
{
	private:
		int port;
	public:
};
