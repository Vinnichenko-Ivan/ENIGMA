#include <Servo.h>
#define pwmA 11//133 78
#define digital1A 10//110
#define digital2A 9
class colorSensor{
  public:
   //colorSensor();
    int getLight();
    void calibrate(int portIn);
  private:
    int port;
    int calibrateK;
};
int colorSensor::getLight(){
  return calibrateK-analogRead(port);
}
void colorSensor::calibrate(int portIn){
  port=portIn;
  pinMode(port,INPUT);
  calibrateK=analogRead(port);
}
class Motor{
  public: 
    void setSpeed(int Power);
    void calibrate(int minPower);
    void stop();
  private:
    int minimalPower;
};
void Motor::calibrate(int minPower){
  minimalPower=minPower;
}
void Motor::setSpeed(int Power){
  if(Power>0){
    Power>100?Power=100:Power=Power;
    digitalWrite(digital1A,HIGH);
    digitalWrite(digital2A,LOW);
    analogWrite(pwmA,map(Power,0,100,minimalPower,255));
  }
  if(Power<0){
    Power<-100?Power=100:Power=-Power;
    digitalWrite(digital1A,LOW);
    digitalWrite(digital2A,HIGH);
    analogWrite(pwmA,map(Power,0,100,minimalPower,255));
  }
}
void Motor::stop(){
    digitalWrite(digital1A,LOW);
    digitalWrite(digital2A,LOW);
    analogWrite(pwmA,0);
}
class PID{
  public:
    double ki=0,kp=0,kd=0,imax=0;
    double error,errorOld,errorIntegral,errorDeviante;  
    unsigned long dt,dn;
    void calibrate(float kpc,float kic,float kdc,float imaxc);
    double UI(int error);
};
void PID::calibrate(float kpc,float kic,float kdc,float imaxc){
  ki=kic;
  kp=kpc;
  kd=kdc;
  imax=imaxc;
}
double PID::UI(int error){ 
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
class turnMotor{
  public:
    void calibrate(int angelLeftIn,int angelRightIn,int angelStraightIn,int servoPortIn);
    void setTurn(int angel);
  private:
    Servo myservo;
    int angelStraight,angelRight,angelLeft,servoPort,pos;
};
void turnMotor::calibrate(int angelLeftIn,int angelRightIn,int angelStraightIn,int servoPortIn){
  angelRight=angelRightIn;
  angelLeft=angelLeftIn;
  angelStraight=angelStraightIn; 
  servoPort=servoPortIn;
  myservo.attach(servoPort);
}
void turnMotor::setTurn(int angel){
  pos=angelStraight+angel;
  pos>angelLeft?pos=angelLeft:pos<angelRight?pos=angelRight:pos=pos;
  myservo.write(pos);
}
