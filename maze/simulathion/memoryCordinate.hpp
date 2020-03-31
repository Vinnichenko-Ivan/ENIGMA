class memoryCordinate
{
	private:
		vector<int> memoryCordinateX;
		vector<int> memoryCordinateY;
		int lenght=1;
		void addElement();
	public:
		myAngleRotate angle;	
		int myCordinateX=0,myCordinateY=0;
		memoryCordinate();
		bool searchElement(int xIn,int yIn);
		bool turnLeft();
		bool goForward();
		bool turnRight();
		bool goBack();
};

memoryCordinate::memoryCordinate()
{
	memoryCordinateX.push_back(0);
	memoryCordinateY.push_back(0);
}

void memoryCordinate::addElement()
{
	memoryCordinateX.push_back(myCordinateX);
	memoryCordinateY.push_back(myCordinateY);
	lenght++;
}

bool memoryCordinate::turnLeft()
{
	angle.turnLeft();
	return 1;
}

bool memoryCordinate::turnRight()
{
	angle.turnRight();
	return 1;
}

bool memoryCordinate::goForward()
{
	if(angle.getAngle()==1)
	{
		myCordinateY--;
	}

	else if(angle.getAngle()==2)
	{
		myCordinateX++;
	}

	else if(angle.getAngle()==3)
	{
		myCordinateY++;
	}

	else if(angle.getAngle()==4)
	{
		myCordinateX--;
	}
	addElement();
}

bool memoryCordinate::goBack()
{
	if(angle.getAngle()==1)
	{
		myCordinateY++;
	}

	else if(angle.getAngle()==2)
	{
		myCordinateX--;
	}

	else if(angle.getAngle()==3)
	{
		myCordinateY--;
	}

	else if(angle.getAngle()==4)
	{
		myCordinateX++;
	}
	addElement();
}

bool memoryCordinate::searchElement(int xIn,int yIn)
{
	int count=0;
	for(int i=0;i<lenght;i++)
	{
		if(memoryCordinateX[i]==xIn&&memoryCordinateY[i]==yIn){
			count++;
		}
	}
	return count;
}