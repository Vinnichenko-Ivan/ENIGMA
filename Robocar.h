#define pwmA 10
#define digital1A 8
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
  calibrateK=analogRead(port);
}
