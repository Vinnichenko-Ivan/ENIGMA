class memoryCordinate
{
	private:
		vector<int> memoryCordinateX;
		vector<int> memoryCordinateY;
		vector<cordinate> iDontGoHere;
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
		bool iStayInForwardCordinate();
		bool iStayInLeftCordinate();
		bool iStayInBackCordinate();
		bool iStayInRightCordinate();
		void pushTarget(int x,int y);
		cordinate getNearTarget();
		void targetLeft();
		void targetRight();
		void targetBack();
		void targetForward();
};

memoryCordinate::memoryCordinate()
{
	memoryCordinateX.push_back(0);
	memoryCordinateY.push_back(0);
}

void memoryCordinate::pushTarget(int x,int y)
{
	cordinate buff;
	buff.x=x;
	buff.y=y;
	iDontGoHere.push_back(buff);
}

cordinate memoryCordinate::getNearTarget()
{
	cordinate buff=iDontGoHere[iDontGoHere.size()-1];
	iDontGoHere.pop_back();
	while(1&&iDontGoHere.size()!=0)
	{
		if(searchElement(buff.x,buff.y)||buff.x==myCordinateX&& buff.y==myCordinateY)
		{
			iDontGoHere.pop_back();
			buff=iDontGoHere[iDontGoHere.size()-1];
		}
		else
		{
			return buff;
		}
	}
	return buff;
}

void memoryCordinate::targetLeft()
{
	int x=myCordinateX,y=myCordinateY;
	if(angle.getAngle()==1)
	{
		x=myCordinateX-1;
	}

	else if(angle.getAngle()==2)
	{
		y=myCordinateY-1;
	}

	else if(angle.getAngle()==3)
	{
		x=myCordinateX+1;
	}

	else if(angle.getAngle()==4)
	{
		y=myCordinateY+1;
	}
	pushTarget(x, y);
}

void memoryCordinate::targetRight()
{
	int x=myCordinateX,y=myCordinateY;
	if(angle.getAngle()==1)
	{
		x=myCordinateX+1;
	}

	else if(angle.getAngle()==2)
	{
		y=myCordinateY+1;
	}

	else if(angle.getAngle()==3)
	{
		x=myCordinateX-1;
	}

	else if(angle.getAngle()==4)
	{
		y=myCordinateY-1;
	}
	pushTarget( x, y);
}

void memoryCordinate::targetBack()
{
	int x=myCordinateX,y=myCordinateY;
	if(angle.getAngle()==1)
	{
		y=myCordinateY-1;
	}

	else if(angle.getAngle()==2)
	{
		x=myCordinateX-1;
	}

	else if(angle.getAngle()==3)
	{
		y=myCordinateY+1;
	}

	else if(angle.getAngle()==4)
	{
		x=myCordinateX+1;
	}
	pushTarget( x, y);
}

void memoryCordinate::targetForward()
{
	int x=myCordinateX,y=myCordinateY;
	if(angle.getAngle()==1)
	{
		y=myCordinateY+1;
	}

	else if(angle.getAngle()==2)
	{
		x=myCordinateX+1;
	}

	else if(angle.getAngle()==3)
	{
		y=myCordinateY-1;
	}

	else if(angle.getAngle()==4)
	{
		x=myCordinateX-1;
	}
	pushTarget( x, y);
}

bool memoryCordinate::iStayInLeftCordinate()
{
	int x=myCordinateX,y=myCordinateY;
	if(angle.getAngle()==1)
	{
		x=myCordinateX-1;
	}

	else if(angle.getAngle()==2)
	{
		y=myCordinateY-1;
	}

	else if(angle.getAngle()==3)
	{
		x=myCordinateX+1;
	}

	else if(angle.getAngle()==4)
	{
		y=myCordinateY+1;
	}
	return searchElement(x,y);
}

bool memoryCordinate::iStayInRightCordinate()
{
	int x=myCordinateX,y=myCordinateY;
	if(angle.getAngle()==1)
	{
		x=myCordinateX+1;
	}

	else if(angle.getAngle()==2)
	{
		y=myCordinateY+1;
	}

	else if(angle.getAngle()==3)
	{
		x=myCordinateX-1;
	}

	else if(angle.getAngle()==4)
	{
		y=myCordinateY-1;
	}
	return searchElement(x,y);
}

bool memoryCordinate::iStayInBackCordinate()
{
	int x=myCordinateX,y=myCordinateY;
	if(angle.getAngle()==1)
	{
		y=myCordinateY+1;
	}

	else if(angle.getAngle()==2)
	{
		x=myCordinateX-1;
	}

	else if(angle.getAngle()==3)
	{
		y=myCordinateY-1;
	}

	else if(angle.getAngle()==4)
	{
		x=myCordinateX+1;
	}
	return searchElement(x,y);
}

bool memoryCordinate::iStayInForwardCordinate()
{
	int x=myCordinateX,y=myCordinateY;
	if(angle.getAngle()==1)
	{
		y=myCordinateY-1;
	}

	else if(angle.getAngle()==2)
	{
		x=myCordinateX+1;
	}

	else if(angle.getAngle()==3)
	{
		y=myCordinateY+1;
	}

	else if(angle.getAngle()==4)
	{
		x=myCordinateX-1;
	}
	return searchElement(x,y);
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
			return 1;
		}
	}
	return 0;
}