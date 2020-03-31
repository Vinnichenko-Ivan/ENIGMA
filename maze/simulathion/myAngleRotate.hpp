class myAngleRotate
{
	private:
		int myAngle=1;
		void checkAngle();
	public:
		void turnLeft();
		void turnRight();
		int getAngle();
};

void myAngleRotate::checkAngle()
{
	if(myAngle==0)
	{
		myAngle=4;
	}
	else if(myAngle==5)
	{
		myAngle=1;
	}
}

void myAngleRotate::turnLeft()
{
	myAngle--;
    checkAngle();
}

void myAngleRotate::turnRight()
{
	myAngle++;
    checkAngle();
}

int myAngleRotate::getAngle()
{
	return myAngle;
}