class myAngleRotate
{
	private:
		int myAngle=0;
		void checkAngle();
	public:
		void turnLeft();
		void turnRight();
		int getAngle();
};

void myAngleRotate::checkAngle()
{
	if(myAngle==-1)
	{
		myAngle=3;
	}
	else if(myAngle==4)
	{
		myAngle=0;
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