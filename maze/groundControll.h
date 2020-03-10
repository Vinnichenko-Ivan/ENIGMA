#include<Servo.h>
#include<string.h>
//#include<cmath.h>
#include <SoftwareSerial.h>


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
		int portA,portB,portC;//c-PWM
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

class moveControl
{
	private:
		
		motor leftMotor;
		motor rightMotor;
		PID turnRegulator;
		PID goRegulator;
		char c;
		String beta;
		int resetIteration=0;
		int zeroAzimut=0;
		int targetAzimut=0;
		int gyroOld=0;
		int programAzimut=0;
		
		long timerGyro=0;
		long millisGyro=0;
		bool gyroD=0;
		int azimutControl(int azimut);
		SoftwareSerial SerialGyro =  SoftwareSerial(12, 4);
		

	public:
		int realAzimut=0;
		moveControl();
		void setZeroAzimut(int azimut);
		bool setTargetAzimut(int azimut);
		void gyro();
		void testMotor();
		void turnTo(int currentAzimut);
};

void moveControl::turnTo(int currentAzimut)
{
	rightMotor.setPower(-((realAzimut+540-currentAzimut)%360-180)*5);
	leftMotor.setPower(((realAzimut+540-currentAzimut)%360-180)*5);
}

void moveControl::testMotor()
{
	rightMotor.setPower(255);
	leftMotor.setPower(-255);
	delay(500);
	rightMotor.setPower(-255);
	leftMotor.setPower(255);
	delay(500);
	rightMotor.setPower(-255);
	leftMotor.setPower(-255);
	delay(500);
	rightMotor.setPower(255);
	leftMotor.setPower(255);
	delay(500);
	rightMotor.setPower(0);
	leftMotor.setPower(0);
	delay(500);
}

int moveControl::azimutControl(int azimut)
{
	if(azimut<0)
	{
		azimut=360-azimut%360;
	}
	if(azimut>0)
	{
		azimut=azimut%360;
	}
	return azimut;
}

bool moveControl::setTargetAzimut(int azimut)
{
	targetAzimut=azimutControl(azimut);
	return 1;
}

void moveControl::setZeroAzimut(int a)
{
	zeroAzimut=a;
	if(DEBUG){
		Serial.println("I set zero Azimut");
	}
	return 1;
}

moveControl::moveControl()
{
	pinMode(12,INPUT);
	leftMotor.attach(9,10,11);
	rightMotor.attach(7,8,6);
	turnRegulator.calibrate(5,0,0,0);
	goRegulator.calibrate(5,0,0,0);
	if(DEBUG)
	{
		Serial.println("I attach my motor!");
	}
}

void moveControl::gyro(){
	realAzimut=(int)(floor((float)(pulseIn(12, 1)/10)));
}
//---------------------------------------------------------------------------------------------------------------------//

class US
{
	private:
		int port;
		char filterType='z';//z-zero filter, n- non filter
	public:
		int getDistanse();
		void attach(int portIn, char filterIn);
};

void US::attach(int portIn, char filterIn)
{
	port=portIn;
	filterType=filterIn;
}

int US::getDistanse()
{
	long duration, distance;
	pinMode(port,OUTPUT);
	digitalWrite(port, LOW);
	delayMicroseconds(2); 
	digitalWrite(port, HIGH);
	delayMicroseconds(10); 
	digitalWrite(port, LOW); 
	pinMode(port,INPUT);
	duration = pulseIn(port, HIGH, 30000); 
	distance = duration / 58;
	if(filterType='z'&&distance==0)
	{
		distance=10000;
	}
	return distance;
}
