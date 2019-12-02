#define pwmA 11//133 78
#define digital1A 10
#define digital2A 9
class colorSensor{
  public:
    colorSensor();
    void getLight();
    void calibrate(int portIn);
  private:
    int port;
    int calibrateK;
};
void colorSensor::calibrate(int portIn){
  port=portIn;
  pinMode(port,INPUT)
  calibrateK=analogRead(port);
}
