class memoryCordinate
{
	private:
		vector<int> memoryCordinateX;
		vector<int> memoryCordinateY;
		vector<int> memoryCordinateZ;
		myAngleRotate angle;
		int myCordinateX=0,myCordinateY=0;
		void addElement();
	public:
		memoryCordinate();
		bool searchElement();
		bool left();
		bool forward();
		bool right();
		bool back();
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
}

bool memoryCordinate::left()
{
	angle.turnLeft();
	return 1;
}

bool memoryCordinate::right()
{
	angle.turnRight();
	return 1;
}

bool memoryCordinate::forward()
{
	if(angle.getAngle()==0)
	{
		myCordinateY++;
	}

	else if(angle.getAngle()==1)
	{
		myCordinateX++;
	}

	else if(angle.getAngle()==2)
	{
		myCordinateY--;
	}

	else if(angle.getAngle()==3)
	{
		myCordinateX--;
	}
	addElement();
}

bool memoryCordinate::back()
{
	if(angle.getAngle()==0)
	{
		myCordinateY--;
	}

	else if(angle.getAngle()==1)
	{
		myCordinateX--;
	}

	else if(angle.getAngle()==2)
	{
		myCordinateY++;
	}

	else if(angle.getAngle()==3)
	{
		myCordinateX++;
	}
	addElement();
}

