
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
	if(errorIntegral>imax)
	{
		errorIntegral=imax;
	}
	if(errorIntegral<-imax)
	{
		errorIntegral=-imax;
	}
	errorDeviante=(error-errorOld);
	errorOld=error;
	dt=millis();
	return error*kp +errorIntegral*ki+errorDeviante*kd;
}
//-------------------------------------------------------------------------------------------------------------------//

class motor
{
	private:
		int maxPower(int power);
		int portA,portB,PortC;//c-PWM
	public:
		void attach(int a,int b,int c);
		void setPower(int power);
};

void motor::attach(int a,int b,int c)
{
	portA=a;
	portB=b;
	portC=c;
	pinMode(portA,OUTPUT);
	pinMode(portB,OUTPUT);
	pinMode(portC,OUTPUT);
}

int motor::maxPower(int power)
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

void motor::setPower(int power)
{
	power=maxPower(power);
	if(power>0)
	{
		digitalWrite(portA,HIGH);
		digitalWrite(portB,LOW);
		analogWrite(portC,abs(power));
	}
	else if(power<0)
	{
		digitalWrite(portA,LOW);
		digitalWrite(portB,HIGH);
		analogWrite(portC,abs(power));
	}
	else
	{
		digitalWrite(portA,LOW);
		digitalWrite(portB,LOW);
		analogWrite(portC,abs(power));
	}
}
//-------------------------------------------------------------------------------------------------------------------//

class moveControll
{
	private:
		motor leftMotor;
		motor rightMotor;
	public:
		moveControll();
};

moveControll::moveControll()
{
	leftMotor.attach(9,10,11);
	rightMotor.attach(8,7,6);
}

//---------------------------------------------------------------------------------------------------------------------//

class US
{
	private:
		int port;
	public:
};
