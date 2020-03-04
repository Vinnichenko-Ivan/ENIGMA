
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

class moveControl
{
	private:
		motor leftMotor;
		motor rightMotor;
		char c='';
		string beta="";
		int resetIteration=0;
		int zeroAzimut=0;
		int targetAzimut=0;
		int gyroOld=0;
		int realAzimut=0
		long timerGyro=0;
		bool gyroD=0;
		void azimutControl();
	public:
		moveControl();
		bool setZeroAzimut(int azimut);

};

bool moveControl::zeroAzimut(int a){
	zeroAzimut=a;
	if(DEBUG){
		Serial.println("I set zero Azimut");
	}
	return 1;
}

moveControll::moveControl()
{
	leftMotor.attach(9,10,11);
	rightMotor.attach(8,7,6);
}

void moveControl::gyro(){
	if(SerialGyro.available()) 
	{
		millisGyro=millis();
		c = (char)SerialGyro.read();
		beta += c;
		resetIteration++;
		if(resetIteration==100)
		{
			resetIteration=0;
			SerialGyro.end();
			SerialGyro.begin(115200);
			SerialGyro.print("\n");
		}
		if (c == '\n')
		{
			SerialGyro.print("\n");
			SerialGyro.print("\n");
			realAzimut=beta.toInt();
			beta="";
		}
		if(abs(gyroOld-realAzimut)<3&&millis()-timerGyro>5000)
		{
			gyroD=1;
		}
		else if(abs(gyroOld-realAzimut)>3)
		{
			timerGyro=millis();
			gyroOld=realAzimut;
			gyroD=0;
		}
	}
	if(SerialGyro.available()==0&&millis()-millisGyro>500)
	{
		SerialGyro.end();
		SerialGyro.begin(115200);
		SerialGyro.print("\n");
	}
}
//---------------------------------------------------------------------------------------------------------------------//

class US
{
	private:
		int port;
	public:
};
