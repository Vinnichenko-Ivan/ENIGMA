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
// class Motor{
//   public: 
//     void setSpeed(int Power);
//     void calibrate(int minPower);
//     void
// };
