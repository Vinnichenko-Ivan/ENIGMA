#include <Wire.h> //Include the Wire Library
#include <HTInfraredSeeker.h>
#include <EEPROM.h>
#define leftUs 33 //port left us
#define rightUs 37 //port right us
#define backUs 35 //port back us
#define delayUs 100 //delay betweem 
#define pwmA 12
#define digital1A 10
#define digital2A 11
#define pwmB 9
#define digital1B 8 
#define digital2B 7
#define pwmC 4
#define digital1C 5
#define digital2C 6
#define l1p A2
#define l2p A1//A2
#define l3p A0//A8
#define l4p A7 //
#define l5p A6//A1
#define l6p A5//A2
#define l7p A3
#define l8p A4//5
#define lap A9
#define SignalDiod1 30
#define SignalDiod2 29
#define SignalDiod3 31
#define PupPin 53
#define punchPin 52
#define optoPin A9
#define tsopPered1 A13
#define tsopPered2 A12
#define tsopPered3 A14
#define tsopZad1 A10
#define tsopZad2 A11
#define colorK 30

class puncher{
	private:
		


		long timeOld;
		long time=0;
		int volt=0, deus=0;
	public: 
		int s;
		bool ballTest();
		void S();
		void stepUp();
		void Hpunch();
		void punch();
};

	void puncher::Hpunch(){

			digitalWrite(52,1);
			delay(500);
			digitalWrite(52,0);
			volt=0;	
			

	}
	void puncher::punch(){
		if(volt==2&&ballTest()&&millis()-time>1000){
			digitalWrite(52,1);
			delay(500);
			digitalWrite(52,0);
			volt=0;
			time=millis();	
		}	
		else{
			stepUp();		
		}
	}
	void puncher::stepUp(){
		if(volt==0){
			pinMode(PupPin,OUTPUT);
			digitalWrite(PupPin,1);
			timeOld=millis();
			volt=1;
		}
		if(millis()-timeOld>1000&&volt==1) {
			volt=2;
			pinMode(PupPin,OUTPUT);
			digitalWrite(PupPin,0);					
		}
	}
	void puncher::S(){
		pinMode(optoPin,INPUT);
		pinMode(punchPin,OUTPUT);
		pinMode(punchPin,OUTPUT);
		s=analogRead(optoPin);
	}
	bool puncher::ballTest(){
		if(analogRead(optoPin)<450	)
			return 1;
		else
			return 0;	
	}
class Tech
{
	public:	
		long millisGyro;
		int ezet;
		char lire;
		bool protoco = 0;
		String ceta = "";
		short tsopM = 0;
		void getBluetooth();
		bool roboMod = 0;
		int sector;
		void sectorCount();
		long timerGyro=0;
		void diod(int number,int mode);
		bool button1=1,button2=0,button3=0;
		void button();
		int delataIr,gyroOld;
		void virovn(int err);
		bool d1=0, d2=0, d3=0,gyroD=0;
		int l1,l2,l3,l4,l5,l6,l7,l8,la,l1k,l2k,l3k,l4k,l5k,l6k,l7k,l8k,lak;
		bool l1b,l2b,l3b,l4b,l5b,l6b,l7b,l8b;
		void motor(char a,int b);
		Tech(bool debug, bool bluetooth);
		int distL=-1,distR=-1,distB=-1,rezet=0;
		int OdistL=-1,OdistR=-1,OdistB=-1;
		int oldAzimut,timeUs,azimut,degree=-1;
		unsigned long int timer;
		int numUs=0,Dir,Str,li=0;
		int US(char port);
		void obezd();
		int Distance();
		int irDist;
		int irDelta;
		void eepromWrite();
		void distWrite();
		bool debug; 
		void motorStop();
		bool bluetooth;
		void gyro();
		void angleDrive(float a, float power,float error);
		bool  gete = 0;
		String beta;
		char c = ' ';
		void first(bool debu, bool bluetoot);
		void move(float a, float power,float error);
		int UP(int skos);
		void IRlego();
		void line();
		void irCalibrate();
		bool usTrue();
		int angleGate();
		
};
int Tech::angleGate(){
	if(distR>25 && distR<70)
	{
		return  (atan((213 - distB)/(91-distR))*57);
	}
	else if(distL>25 && distL<70)
	{
		return -(atan((213 - distB)/(91-distL))*57);
	}
	else{
		return 0;
	}
}
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
void Tech::getBluetooth()
{
	if(Serial2.available())
	{
		if(protoco)
		{		
			lire = (char)Serial2.read();
			ceta += lire;
			if (lire == '\n') {
				if(debug&&li==94){
					Serial.println("ceta: ");
					Serial.print(ceta);
				}
				ezet=ceta.toInt();
				ceta="";
				if(ezet == 1){
					roboMod = 1;
				}
				else if(ezet == 0){
					roboMod = 0;
					}
				}
			}
			protoco = 0;
		}
		else
		{
			lire = (char)Serial2.read();
			if(ceta.length() == 3 && lire == '\n')
			{
				protoco = 1;
				ceta = "";
			}
			else if(lire == '6')
				ceta += lire;
			else
				ceta = "";
			
		}
	}
void Tech::obezd()
{
	             if(tsop1.ball() == 1 && tsop2.ball() == 1 && tsopM == 0)
                        {
                                nextDir = 0;
                                if(tsopM == 1)
                                {
                                        while(Tech.Dir == 9 || Tech.Dir == 8 || Tech.Dir == 0)
                                        {
                                                 Tech.IRlego();
                                                 Tech.gyro();
                                                 Tech.move(315, 255, Mreg.UI(Tech.UP(0)));
                                        }
                                        tsopM = 0;
                                }
                                 else if(tsopM == 2)
                                 {
                                        while(Tech.Dir == 1 || Tech.Dir == 2 || Tech.Dir == 0)
                                        {
                                                 Tech.IRlego();
                                                 Tech.gyro();
                                                 Tech.move(235, 255, Mreg.UI(Tech.UP(0)));
                                        }
                                        tsopM = 0;
      
                                 } 
                        }                        
                        else if(tsop1.ball() == 1)
                        {
                                nextDir = 0;
                                Tech.move(235, 255, Mreg.UI(Tech.UP(0)));      
                                tsopM = 1;
                        }
                         else if(tsop2.ball() == 1)
                         {
                                nextDir = 0;
                                Tech.move(315, 255, Mreg.UI(Tech.UP(0)));      
                                tsopM = 2;
                         }
                 
                 
                  else if(Tech.Dir == 0 && tsop1.ball() == 0 && tsop2.ball() == 0)
                  { 
                                nextDir = 0;
                                if(Tech.distL >= Tech.distR)
                                {
                                        while(Tech.Dir == 0 && tsop2.ball() == 0 && tsop1.ball() == 0)
                                        {
                                                Tech.gyro();
                                                Tech.IRlego();
                                                Tech.move(315, 255, Mreg.UI(Tech.UP(0)));
                                        }      
                                }
                                else
                                {
                                        while(Tech.Dir == 0 && tsop2.ball() == 0 && tsop1.ball() == 0)
                                        {
                                                Tech.gyro();
                                                Tech.IRlego();
                                                Tech.move(235, 255, Mreg.UI(Tech.UP(0)));
                                        }      
                                }
                  }
}
void Tech::eepromWrite()
{
	if(button1)
	{
		long long int butStart = millis();
		irDist = Str;
		EEPROM.write(6,Str);
		while(millis() - butStart < 1000)
			continue;
	}
		
}
void Tech::sectorCount()
{
	sector = 0;	
	if(usTrue())
	{
		if(distL>=51&&distR>=51&&distB<=15){sector=2;}
		else if(distL<=51&&distR>=111&&distB<=40&&distB>30){sector=1;}
		else if(distL>=111&&distR<=51&&distB<=40&&distB>30){sector=3;}
		else if(distL>=51&&distR>=51&&distB>15){sector=5;}
		else if(distL<=51&&distR>=111&&distB>40){sector=4;}
		else if(distL>=111&&distR<=51&&distB>40){sector=6;}
		else if(distL<=51&&distR>=111&&distB<30){sector=7;}
		else if(distL>=111&&distR<=51&&distB<30){sector=8;}
	}
	else
		sector = 0;	
	if(bluetooth&&li==92){
		Serial2.print("sector");
		Serial2.println(sector);
		}
	if(debug&&li==92){
		Serial.print("sector");
		Serial.println(sector);
		}
}
void Tech::button(){
button1 = !digitalRead(28);
button2 = !digitalRead(27);
button3 = !digitalRead(26);
}

void Tech::IRlego(){
	InfraredResult InfraredBall = InfraredSeeker::ReadAC();
	Dir = InfraredBall.Direction;
	Str = InfraredBall.Strength;
}
void Tech::virovn(int err)
{
	if(UP(0) >10 || UP(0) <-10)
	{
		motor('A',-err*0.2);
		motor('B',-err*0.2);
		motor('C',-err*0.2);
	} 
	else
	{
		motor('A',0);
		motor('B',0);
		motor('C',0);
	}
}
int Tech::UP(int skos){
	int currentAzimut;
	if(azimut+skos>360)
		currentAzimut = -360 + (azimut+skos);
	else if(azimut+skos<0)
		currentAzimut = 360 + (azimut+skos);
	else
		currentAzimut = azimut + skos;
	//if(bluetooth){
	//	Serial.println(currentAzimut);
	//}	
	return (degree+540-currentAzimut)%360-180;
}
void Tech::irCalibrate()
{
	if(button2)
	{
		long long int startTime = millis();
		IRlego();
		int summ = 0;
		int startStr = Str;
		while(millis() - startTime < 5000)
		{
			IRlego();
			if((millis() - startTime)%54 == 0)
			{
				if(summ == 0)
					summ = abs(Str - startStr);
				else
					summ = (summ + abs(Str - startStr))/2;
				startStr = Str;
			}
		}
		irDelta = summ;
		EEPROM.write(10,summ);	
	}
	
}
void Tech::angleDrive(float a, float power,float error)
{
	a = (a) / 57.3; 
	float PB = (-cos(a) * power)-error; 
	float PC = (0.5 * cos(a) * power + 0.87 * sin(a) * power)-error; 
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
void Tech::move(float a, float power,float error){
/* if((l8b||l7b||l6b)&&(l3b||l4b||l5b)){
a=90;
}
   
else if(l1b||l2b){
    if(a>1&&a<179){
      a=270;
    } 
  }
 else if(l8b){
    if(a>91&&a<269){
      power=0;
    } 
  }
 else if(l7b||l6b){
      a=0; 
  }
 else if(l3b){
    if(a<89&&a>271){
      power=0;
    } 
  }
  if(l4b||l5b){ 
      a=180;
  }*/
	line();
	if((l7b == 1 || l8b == 1))
	{
		power = 255;
		a=270;
	}
	else if(l1b == 1 && l4b == 1 && (a <= 360 && a >= 180))
	{
		while((l3b == 1 && l6b == 1) || (l1b == 1 && l4b == 1)  || (l2b == 1 && l5b == 1))
		{

			line();
			gyro();
			angleDrive(90,255,error);	
		} 
		return;
	}
	
	else if(l2b == 1 && l5b == 1 && (a <= 360 && a >= 180))
	{
		power = 200;
		a = 90;
	}
	else if(l3b == 1 && l6b == 1 && (a <= 360 && a >= 180))
		power = 0;

	else if(l3b == 1 && (a >= 90 && a <= 270))
		power = 0;
	else if(l2b == 1 && (a >= 90 && a <= 270))
	{
		power = 200;
		a = 0;
	}
	else if(l1b == 1)
	{	
		long long int start = millis();
		while(l1b == 1 || l2b == 1 || l3b == 1)
		{

			line();
			gyro();
			angleDrive(0,255,UP(0)*5);	
		} 
		return;
	}
	else if(l6b == 1 && ((a <= 90) || (a <= 360 &&  a >= 270)))
		power = 0;
	else if(l5b == 1 && ((a <= 90) || (a <= 360 &&  a >= 270)))
	{
		power = 200;
		a = 180;
	}
	else if(l4b == 1)
	{	

		while(l4b == 1 || l5b == 1 || l6b == 1)
		{

			line();
			gyro();
			angleDrive(180,255,error);	
		} 
		return;
	}
	angleDrive(a,power,error);
	
		
}
void Tech::distWrite()
{//todo		
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
void Tech::motorStop()
{
	motor('A',0);
	motor('B',0);
	motor('C',0);	
}
void Tech::first(bool debu, bool bluetoot){
	pinMode(SignalDiod1,OUTPUT);
	pinMode(SignalDiod2,OUTPUT);
	pinMode(SignalDiod3,OUTPUT);
	InfraredSeeker::Initialize();
	Serial1.begin(115200);
	irDelta = EEPROM.read(10);
	Serial1.println("\n");
	debug=debu;
	bluetooth=bluetoot;
	if(debug){
		Serial.begin(115200);
	}
	//Serial2.begin(9600);
	//if(bluetoot){
	//	Serial2.begin(9600);
	//}
	irDist = EEPROM.read(7);
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
	/*l1=abs(analogRead(l1p)-l1k);
	l2=abs(analogRead(l2p)-l2k);
	l3=abs(analogRead(l3p)-l3k);
	l4=abs(analogRead(l4p)-l4k);
	l5=abs(analogRead(l5p)-l5k);
	l6=abs(analogRead(l6p)-l6k);
	l7=abs(analogRead(l7p)-l7k);
	l8=abs(analogRead(l8p)-l8k);*/
	if(l1>colorK)
		l1b=1;
	else
		l1b=0;
	if(l2>colorK)
		l2b=1;
	else
		l2b=0;
	if(l3>colorK)
		l3b=1;
	else
		l3b=0;
	if(l4>colorK)
		l4b=1;
	else
		l4b=0;
	if(l5>colorK)
		l5b=1;
	else
		l5b=0;
	if(l6>colorK)
		l6b=1;
	else
		l6b=0;
	if(l7>colorK)
		l7b=1;
	else
		l7b=0;
	if(l8>colorK)
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
		Serial.print(l8b);
		Serial.println();
		Serial.print(" l1: ");
		Serial.print(l1);
		Serial.print(" l2: ");
		Serial.print(l2);
		Serial.print(l3);
		Serial.print(" l4: ");
		Serial.print(l4);
		Serial.print(" l5: ");
		Serial.print(l5);
		Serial.print(" l6: ");
		Serial.print(l6);
		Serial.print(" l7: ");
		Serial.print(l7);
		Serial.print(" l8: ");
		Serial.println(l8); 
		li=-1;
	}
	if(bluetooth&&li==-1){
		Serial2.print(" l1: ");
		Serial2.print(l1b);
		Serial2.print(" l2: ");
		Serial2.print(l2b);
		Serial2.print(" l3: ");
		Serial2.print(l3b);
		Serial2.print(" l4: ");
		Serial2.print(l4b);
		Serial2.print(" l5: ");
		Serial2.print(l5b);
		Serial2.print(" l6: ");
		Serial2.print(l6b);
		Serial2.print(" l7: ");
		Serial2.print(l7b);
		Serial2.print(" l8: ");
		Serial2.print(l8b);
		Serial2.println();
		Serial2.print(" l1: ");
		Serial2.print(l1);
		Serial2.print(" l2: ");
		Serial2.print(l2);
		Serial2.print(" l3: ");
		Serial2.print(l3);
		Serial2.print(" l4: ");
		Serial2.print(l4);
		Serial2.print(" l5: ");
		Serial2.print(l5);
		Serial2.print(" l6: ");
		Serial2.print(l6);
		Serial2.print(" l7: ");
		Serial2.print(l7);
		Serial2.print(" l8: ");
		Serial2.println(l8); 
		li=0;
	}
}
void Tech::diod(int number,int mode){
	if(number==1){
		if(mode==0){
			digitalWrite(SignalDiod1,0);
			d1=0;	
		}
		if(mode==1){
			digitalWrite(SignalDiod1,1);
			d1=1;	
		}	
		if(mode==2){
			if(d1){
				digitalWrite(SignalDiod1,0);
				d1=0;				
			}
			else{
				digitalWrite(SignalDiod1,1);
				d1=1;			
			}	
		}
	}
	if(number==2){
		if(mode==0){
			digitalWrite(SignalDiod2,0);
			d2=0;	
		}
		if(mode==1){
			digitalWrite(SignalDiod2,1);
			d2=1;	
		}	
		if(mode==2){
			if(d2){
				digitalWrite(SignalDiod2,0);
				d2=0;				
			}
			else{
				digitalWrite(SignalDiod2,1);
				d2=1;			
			}	
		}
	}
	if(number==3){
		if(mode==0){
			digitalWrite(SignalDiod3,0);
			d3=0;	
		}
		if(mode==1){
			digitalWrite(SignalDiod3,1);
			d3=1;	
		}	
		if(mode==2){
			if(d3){
				digitalWrite(SignalDiod3,0);
				d3=0;				
			}
			else{
				digitalWrite(SignalDiod3,1);
				d3=1;			
			}	
		}
	}

}
void Tech::gyro(){
	if(Serial1.available()) {
		millisGyro=millis();
		c = (char)Serial1.read();
		beta += c;
		if (c == '\n') {
			Serial1.print("\n");
		if(debug&&li==4){
			Serial.print("degree: ");
			Serial.println(degree);
		}
		if(bluetooth&&li==4){
			Serial2.print("degree: ");
			Serial2.println(degree);
		}
			Serial1.print("\n");
			degree=beta.toInt();
			beta="";
		}
		if(abs(gyroOld-degree)<3&&millis()-timerGyro>5000){
			diod(1,1);
			gyroD=1;
		}
		else if(abs(gyroOld-degree)>3){
			timerGyro=millis();
			gyroOld=degree;
			diod(1,0);
			gyroD=0;
		}
		}
	if(Serial1.available()==0&&millis()-millisGyro>500) {
		Serial1.end();
		Serial1.begin(115200);
		Serial1.print("\n");
	}
	if(Serial1.available()==0&&millis()-millisGyro>1000) {
		diod(2,1);
	}
	else{
		diod(2,0);
	}
}
bool Tech::usTrue()
{
	if(abs(distL + distR + 22-182)<10&&distB!=0&&abs(UP(0))<9){
		if(bluetooth&&li==98){
			Serial2.print("usTrue: ");
			Serial2.println(1);
		}
		if(debug&&li==98){
			Serial.print("usTrue: ");
			Serial.println(1);
		}		
		return 1;
		
		}
		if(bluetooth&&li==98){
		Serial2.print("usTrue: ");
		Serial2.println(0);
	}
	if(debug&&li==98){
		Serial.print("usTrue: ");
		Serial.println(0);
	}
	return 0;  
}

int Tech::Distance(){
	if(debug&&li==99){
		Serial.print(" distL: ");
		Serial.print(distL);
		Serial.print(" distB: ");
		Serial.print(distB);
		Serial.print(" distR: ");
		Serial.println(distR);
	}
	if(bluetooth&&li==99){
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
class Tsop
{
	public:
		short ball();
		short buff[5];
		void first( int port);
		int portArduino;		
		int count;
};
void Tsop::first( int port)
{
	if(port == 1)
		portArduino=tsopPered1;
	else if(port == 2)
		portArduino=tsopPered2;
	else if(port == 3)
		portArduino=tsopPered3;
	else if(port == 4)
		portArduino=tsopZad1;
	else if(port == 5)
		portArduino=tsopZad2;
}
short Tsop::ball()
{
	short status;
	count = 0;
	int num;
	for(int i = 0;i<10;i++)
	{
		if(portArduino == tsopZad2 || portArduino == tsopZad1)
			num = pulseIn(portArduino,1,600);
		else 
			num = pulseIn(portArduino,1,1000);			
		if(num!=0)
		{
			count = i;
			break;
		}	
	}

			Serial.print(count);
			Serial.print(" ");
	
	if(count >= 4){
		status = 1;
	}
	else{
		status = 0;
	}
	bool ans;
	if(portArduino == tsopZad2 || portArduino == tsopZad1)
	{	
		buff[0] = buff[1];
		buff[1] = buff[2];
		buff[2] = status;
		ans = (bool)buff[0] + (bool)buff[1] + (bool)buff[2];
	}
	else
	{
		buff[0] = buff[1];
		buff[1] = buff[2];
		buff[2] = buff[3];
		buff[3] = buff[4];
		buff[4] = status;
		ans = (bool)buff[0] + (bool)buff[1] + (bool)buff[2] + (bool)buff[3] + (bool)buff[4];
	}

	
	return ans;
	
}
class PID{
	public:
		double ki=0,kp=0,kd=0,imax=0;
		double error,errorOld,errorIntegral,errorDeviante;	
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
	
	errorIntegral+=error;//*(millis()-dt);
	if(errorIntegral>imax){
		errorIntegral=imax;
	}
	if(errorIntegral<-imax){
		errorIntegral=-imax;
	}
	errorDeviante=(error-errorOld);
	errorOld=error;
	dt=millis();
//Serial.print(" error ");
//Serial.print(errorDeviante*kd);
//Serial.print(" error ");
//Serial.print(errorIntegral*ki);
//Serial.print(" error ");
//Serial.println(error*kp);
	return error*kp +errorIntegral*ki+errorDeviante*kd;
}
