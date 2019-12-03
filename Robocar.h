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
