#include <Wire.h> //Include the Wire Library
#include <HTInfraredSeeker.h>
#define leftUs 21 //port left us
#define rightUs 23 //port right us
#define backUs 22 //port back us
#define delayUs 50 //delay betweem 
#define pwmA 10
#define digital1A 12
#define digital2A 11
#define pwmB 4
#define digital1B 5 
#define digital2B 6
#define pwmC 9
#define digital1C 7
#define digital2C 8
#define l1p A8 //
#define l2p A7
#define l3p A2
#define l4p A1
#define l5p A0
#define l6p A6
#define l7p A5
#define l8p A3
#define lap A4

class Tech
{
	public:	
		int l1,l2,l3,l4,l5,l6,l7,l8,la,l1k,l2k,l3k,l4k,l5k,l6k,l7k,l8k,lak;
		bool l1b,l2b,l3b,l4b,l5b,l6b,l7b,l8b;
		void motor(char a,int b);
		Tech(bool debug, bool bluetooth);
		int distL=-1,distR=-1,distB=-1,rezet=0;
		int OdistL=-1,OdistR=-1,OdistB=-1;
		int timeUs,azimut,degree=-1;
		unsigned long int timer;
		int numUs=0,Dir,li=0;
		int US(char port);
		int Distance();
		bool debug; 
		bool bluetooth;
		void gyro();
		bool  gete = 0;
		String beta;
		char c = ' ';
		void first(bool debu, bool bluetoot);
		void move(float a, float power,float error);
		int UP();
		void IRlego();
		void line();
		
};
Tech::Tech(bool debu, bool bluetoot){
	Serial1.begin(115200);
	Serial1.println("\n");
	Serial.begin(115200);
	debug=debu;
	bluetooth=bluetoot;
	if(debug){
		Serial.begin(115200);
	}
	if(bluetoot){
		Serial2.begin(9600);
	}
	timer = millis();
	while (azimut == -1) {
    	Tech::gyro();
  	}
	azimut = degree;

}
void Tech::IRlego(){
	InfraredResult InfraredBall = InfraredSeeker::ReadAC();
	Dir = InfraredBall.Direction;
	
}
int Tech::UP(){
	return (degree+540-azimut)%360-180;
}
void Tech::move(float a, float power,float error){
	a = (a) / 57.3; 
	float PB = -(-cos(a) * power)+error; 
	float PC = -(0.5 * cos(a) * power + 0.87 * sin(a) * power)+error; 
	float PA = (0.5 * cos(a) * power - 0.87 * sin(a) * power)-error; 
	 
	if(a <= 0) { 
		motor('A', PA); 
		motor('B', PB); 
		motor('C', PC); 
	} 
	else { 
		motor('C', PC); 
		motor('B', PB); 
		motor('A', PA); 
	} 
}
void Tech::motor(char a,int b){
	if(b>255){
		b=255;
	}
	if(b<-255){
		b=-255;
	}
	if(a=='A'){
		if(b<0){
		digitalWrite(digital1A,0);
                digitalWrite(digital2A,1);
                analogWrite(pwmA,b*-1);
		}
		if(b>0){
		digitalWrite(digital1A,1);
                digitalWrite(digital2A,0);
                analogWrite(pwmA,b);		
		}
	}
	if(a=='B'){
		if(b<0){
		digitalWrite(digital1B,0);
                digitalWrite(digital2B,1);
                analogWrite(pwmB,-b);
		}
		if(b>0){
		digitalWrite(digital1B,1);
                digitalWrite(digital2B,0);
                analogWrite(pwmB,b);		
		}
	}
	if(a=='C'){
		if(b<0){
		digitalWrite(digital1C,0);
                digitalWrite(digital2C,1);
                analogWrite(pwmC,-b);
		}
		if(b>0){
		digitalWrite(digital1C,1);
                digitalWrite(digital2C,0);
                analogWrite(pwmC,b);		
		}
	}
}
void Tech::first(bool debu, bool bluetoot){

	InfraredSeeker::Initialize();
	Serial1.begin(115200);
	Serial1.println("\n");
	debug=debu;
	bluetooth=bluetoot;
	if(debug){
		Serial.begin(115200);
	}
	if(bluetoot){
		Serial2.begin(9600);
	}
	timer = millis();
	while (degree == -1) {
    	Tech::gyro();
  	}
	azimut = degree;
	pinMode(pwmA,OUTPUT);
	pinMode(pwmB,OUTPUT);
	pinMode(pwmC,OUTPUT);
	pinMode(digital1A,OUTPUT);
	pinMode(digital1B,OUTPUT);
	pinMode(digital1C,OUTPUT);
	pinMode(digital2A,OUTPUT);
	pinMode(digital2B,OUTPUT);
	pinMode(digital2C,OUTPUT);
	pinMode(l1p,INPUT);
	pinMode(l2p,INPUT);
	pinMode(l3p,INPUT);
	pinMode(l4p,INPUT);
	pinMode(l5p,INPUT);
	pinMode(l6p,INPUT);
	pinMode(l7p,INPUT);
	pinMode(l8p,INPUT);
	pinMode(lap,INPUT);
	l1k=analogRead(l1p);
	l2k=analogRead(l2p);
	l3k=analogRead(l3p);
	l4k=analogRead(l4p);
	l5k=analogRead(l5p);
	l6k=analogRead(l6p);
	l7k=analogRead(l7p);
	l8k=analogRead(l8p);
	lak=analogRead(lap);
}
void Tech::line(){
	l1=analogRead(l1p)-l1k;
	l2=analogRead(l2p)-l2k;
	l3=analogRead(l3p)-l3k;
	l4=analogRead(l4p)-l4k;
	l5=analogRead(l5p)-l5k;
	l6=analogRead(l6p)-l6k;
	l7=analogRead(l7p)-l7k;
	l8=analogRead(l8p)-l8k;
	if(l1>15)
		l1b=1;
	else
		l1b=0;
	if(l2>30)
		l2b=1;
	else
		l2b=0;
	if(l3>30)
		l3b=1;
	else
		l3b=0;
	if(l4>30)
		l4b=1;
	else
		l4b=0;
	if(l5>30)
		l5b=1;
	else
		l5b=0;
	if(l6>30)
		l6b=1;
	else
		l6b=0;
	if(l7>30)
		l7b=1;
	else
		l7b=0;
	if(l8>30)
		l8b=1;
	else
		l8b=0;

	li++;
	if(debug&&li==100){
		Serial.print(" l1: ");
		Serial.print(l1b);
		Serial.print(" l2: ");
		Serial.print(l2b);
		Serial.print(" l3: ");
		Serial.print(l3b);
		Serial.print(" l4: ");
		Serial.print(l4b);
		Serial.print(" l5: ");
		Serial.print(l5b);
		Serial.print(" l6: ");
		Serial.print(l6b);
		Serial.print(" l7: ");
		Serial.print(l7b);
		Serial.print(" l8: ");
		Serial.println(l8b); 
		li=0;
	}
}

void Tech::gyro(){
  if(Serial1.available()) {
  //  Serial.print("p");
    
    // get the new byte:
    c = (char)Serial1.read();
    // add it to the inputString:
    beta += c;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (c == '\n') {
        Serial1.print("\n");
      if(debug)

	Serial.println(degree);
      degree=beta.toInt();
      beta="";
    }
  }
}
int Tech::Distance(){
	if(debug){
		//Serial.print(" distL: ");
		//Serial.print(distL);
		//Serial.print(" distB: ");
		//Serial.print(distB);
		//Serial.print(" distR: ");
		//Serial.println(distR);
	}
	if(bluetooth){
		Serial2.print(" distL: ");
		Serial2.print(distL);
		Serial2.print(" distB: ");
		Serial2.print(distB);
		Serial2.print(" distR: ");
		Serial2.println(distR);
	}
	if(millis()-timeUs>delayUs){
		timeUs=millis();
		if(numUs==0){
			numUs=1;
			distL=Tech::US('L');
			if(distL==0){
				distL=OdistL;
			}
			else{
				OdistL=distL;
			}
		}
		else if(numUs==1){
			numUs=2;
			distB=Tech::US('B');
			if(distL==0){
				distB=OdistB;
			}
			else{
				OdistB=distB;
			}
		}
		else if(numUs==2){
			numUs=0;
			distR=Tech::US('R');
			if(distL==0){
				distR=OdistR;
			}
			else{
				OdistR=distR;
			}
	 	}	
	}
	return 0;
}

int Tech::US(char port){
	if(port=='L'){
		unsigned long duration, distance;
		pinMode(leftUs,OUTPUT);
		digitalWrite(leftUs, LOW);
		delayMicroseconds(2); 
		digitalWrite(leftUs, HIGH);
		delayMicroseconds(10); 
		digitalWrite(leftUs, LOW); 
		pinMode(leftUs,INPUT);
		duration = pulseIn(leftUs, HIGH, 30000); 
		distance = duration / 58;
		return distance;
	}
	if(port=='R'){
		unsigned long duration, distance;
		pinMode(rightUs,OUTPUT);
		digitalWrite(rightUs, LOW);
		delayMicroseconds(2); 
		digitalWrite(rightUs, HIGH);
		delayMicroseconds(10); 
		digitalWrite(rightUs, LOW); 
		pinMode(rightUs,INPUT);
		duration = pulseIn(rightUs, HIGH, 30000); 
		distance = duration / 58;
		return distance;		
	}

	if(port=='B'){
		unsigned long duration, distance;
		pinMode(backUs,OUTPUT);
		digitalWrite(backUs, LOW);
		delayMicroseconds(2); 
		digitalWrite(backUs, HIGH);
		delayMicroseconds(10); 
		digitalWrite(backUs, LOW); 
		pinMode(backUs,INPUT);
		duration = pulseIn(backUs, HIGH, 30000); 
		distance = duration / 58;
		return distance;
	}

}
class PID{
	public:
		float ki=0,kp=0,kd=0,imax=0;
		long error,errorOld,errorIntegral,errorDeviante;	
		unsigned long dt,dn;
		void first(float kpc,float kic,float kdc,float imaxc);
		double UI(int error);
};
void PID::first(float kpc,float kic,float kdc,float imaxc){
	ki=kic;
	kp=kpc;
	kd=kdc;
	imax=imaxc;
}
double PID::UI(int error){
	dn=millis();
	errorIntegral+=error*(dn-dt);
	if(errorIntegral>imax){
		errorIntegral=imax;
	}
	if(errorIntegral<-imax){
		errorIntegral=-imax;
	}
	errorDeviante=(error-errorOld)/(dn-dt);
	errorOld=error;
	dt=millis();
	return error*kp +errorIntegral*ki+errorDeviante*kd;
}
